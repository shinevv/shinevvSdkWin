#include "../include/main.h"

HWND _mainWindow;

MemberWindowMap _member_win_map;

void* _instance = NULL;

std::string _roomId;

std::string _local_peer_id;

std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> _convert;

LRESULT CALLBACK VVCreateWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		break;
	case WM_CHAR:
		switch (wParam)
		{

		case 'q':
		{
			_instance = CreateShinevvInstance();

			if (_instance)
				printf("CreateShinevvInstance %d\n", (int)_instance);

			break;
		}
		case 'w':
		{
			DestoryShinevvInstance();

			_instance = NULL;

			printf("DestoryShinevvInstance OK\n");

			break;
		}
		case 'e':
		{
			printf("InitSDK\n");

			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
			std::string u8str = convert.to_bytes(DISPLAY_NAME);

			_local_peer_id = MEMBER_ID;

			InitSDK(_instance, _roomId.c_str(), MediaType::Video, _local_peer_id.c_str(), u8str.c_str(), "vvroom.shinevv.cn", 3443, "312", OnJoined, OnDisConnected,
				OnNewMemberJoined, OnMemberLeft, OnModifyLocalAudioStatus, OnModifyLocalVideoStatus, OnMemberEnableVideo, OnMemberDisableVideo, OnMemberUnMuteAudio, OnMemberMuteAudio, OnSessionError);

			break;
		}
		case 'r':
		{
			printf("ReleaseSdk\n");

			ReleaseSdk(_instance);

			break;
		}
		case 't':
		{
			printf("JoinRoom\n");

			SetRenderWindow(_instance, _local_peer_id.c_str(), (void*)_mainWindow, true);

			JoinRoom(_instance);

			break;
		}
		case 'y':
		{
			printf("LeaveRoom\n");

			LeaveRoom(_instance);

			MemberWindowMap::iterator it = _member_win_map.begin();

			for (it; it != _member_win_map.end(); it++)
			{
				auto win = it->second;

				CloseWindow(win);
			}

			_member_win_map.clear();

			break;
		}
		case 'l':// clear shinevv
		{
			ClearShinevv();

			break;
		}
		case 'a':// disable camera
		{
			if (_instance) {
				ModifyVideoStatus(_instance, false);
			}

			break;
		}
		case 's': //enable camera
		{
			if (_instance) {
				SetRenderWindow(_instance, MEMBER_ID, (void*)_mainWindow, true);

				ModifyVideoStatus(_instance, true);
			}
			break;
		}
		case 'z'://mute audio
		{
			if (_instance) {
				ModifyAudioStatus(_instance, false);
			}
			break;
		}
		case 'x'://resume audio
		{
			if (_instance) {
				ModifyAudioStatus(_instance, true);
			}
			break;
		}
		case 'd':
		{
			if (_instance) {
				EnableMemberVideo(_instance, _member_win_map.begin()->first.c_str(), NULL);
			}

			break;
		}
		case 'f':
		{
			if (_instance) {
				DisableMemberVideo(_instance, _member_win_map.begin()->first.c_str(), NULL);
			}

			break;
		}
		case 'c':
		{
			if (_instance) {
				EnableMemberAudio(_instance, _member_win_map.begin()->first.c_str(), NULL);
			}

			break;
		}
		case 'v':
		{
			if (_instance) {
				DisableMemberAudio(_instance, _member_win_map.begin()->first.c_str(), NULL);
			}

			break;
		}
		case '0':
		{
			if (_instance) {
				SetVideoDevice(_instance,1, NULL);
			}

			break;
		}
		default:
			break;
		}
		break;
	case WM_COMMAND:
		break;
	case WM_NEW_REMOTEWINDOWS:
	{
		HWND remoteWindow = NULL;

		const char*  pDisplayName = (const char*)lParam;

		if (pDisplayName != NULL) {
			VVCreateWindow(remoteWindow, 0, WIDTH, HEIGHT, pDisplayName);
		}

		const char*  pMemberId = (const char*)wParam;
		if (pMemberId != NULL > 0 && _instance) {
			char szMemberId[255];
			strcpy(szMemberId, pMemberId);
			SetRenderWindow(_instance, szMemberId, (void*)remoteWindow, true);
		}

		_member_win_map.insert(MemberWindowPair(pMemberId, remoteWindow));

		break;
	}
	case WM_CLOSE_WINDOW:
	{
		HWND  hWnd = (HWND)lParam;
		CloseWindow(hWnd);
		// release .....

		const char* pMemberId = (const char*)wParam;

		MemberWindowMap::iterator it = _member_win_map.find(pMemberId);
		if (it != _member_win_map.end()) {
			_member_win_map.erase(it);
		}


		break;
	}
	case WM_CLOSE:
	{
		CloseWindow(hWnd);
		// release .....

		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

int VVCreateWindow(HWND &hwndMain, int winNum, int width, int height, const char* pTitle)
{
	static HINSTANCE hinst = NULL;
	if (hinst == NULL) {

		hinst = GetModuleHandle(0);
		WNDCLASSEX wcx;
		wcx.hInstance = hinst;
		wcx.lpszClassName = TEXT("VideoRenderTest");
		wcx.lpfnWndProc = (WNDPROC)VVCreateWindowProc;
		wcx.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wcx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcx.lpszMenuName = NULL;
		wcx.cbSize = sizeof(WNDCLASSEX);
		wcx.cbClsExtra = 0;
		wcx.cbWndExtra = 0;
		wcx.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

		// Register our window class with the operating system.
		// If there is an error, exit program.
		if (!RegisterClassEx(&wcx))
		{
			MessageBox(0, TEXT("Failed to register window class!"), TEXT("Error!"), MB_OK | MB_ICONERROR);
			return 0;
		}
	}

	// Create the main window.
	hwndMain = CreateWindowEx(
		0, // no extended styles
		TEXT("VideoRenderTest"), // class name
		pTitle, // window name
		WS_OVERLAPPEDWINDOW | WS_MAXIMIZE, // overlapped window
		800, // horizontal position
		0, // vertical position
		width, // width
		height, // height
		(HWND)NULL, // no parent or owner window
		(HMENU)NULL, // class menu used
		hinst, // instance handle
		NULL); // no window creation data

	if (!hwndMain)
		return -1;

	ShowWindow(hwndMain, SW_SHOWDEFAULT);
	UpdateWindow(hwndMain);
	return 0;
}

void OnMemberEnableVideo(const char* pMemberId, const char* pDisplayName)  {
	printf("OnMemberEnableVideo pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
	if (_instance) {
		::SendMessage(_mainWindow, WM_NEW_REMOTEWINDOWS, (WPARAM)pMemberId, (LPARAM)(pDisplayName));
	}
}

void OnMemberDisableVideo(const char* pMemberId, const char* pDisplayName, void* pRenderWin)  {
	printf("OnMemberDisableVideo pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
	::SendMessage(_mainWindow, WM_CLOSE_WINDOW, (WPARAM)pMemberId, (LPARAM)(pRenderWin));
	//ShowWindow((HWND)pRenderWin, SW_HIDE);
}

int main() {
	std::cout << "Please input RoomId:" << std::endl;

	std::cin >> _roomId;

	VVCreateWindow(_mainWindow, 0, WIDTH, HEIGHT, TEXT("Local Camera"));

	MSG msg;
	BOOL bRet;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}