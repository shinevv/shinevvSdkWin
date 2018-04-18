
// demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "demoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdemoDlg dialog



CdemoDlg::CdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_strIP = "vvroom.shinevv.cn";

	m_iPort = 3443;

	m_strRoomId = "1030";

	m_strNickName = "jack";

	// 禁音
	m_bEnableAudio1=TRUE;
	// 本地禁视
	m_bEnableVideo1 = TRUE;

	// 禁音
	m_bEnableAudio2 = TRUE;
	// 本地禁视
	m_bEnableVideo2 = TRUE;

	// 禁音
	m_bEnableAudio3 = TRUE;
	// 本地禁视
	m_bEnableVideo3 = TRUE;

	// 禁音
	m_bEnableAudio4 = TRUE;
	// 本地禁视
	m_bEnableVideo4 = TRUE;

}

void CdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IP, m_strIP);
	DDX_Text(pDX, IDC_PORT, m_iPort);
	DDX_Text(pDX, IDC_ROOMID, m_strRoomId);
	DDX_Text(pDX, IDC_NICKNAME, m_strNickName);
	DDX_Control(pDX, IDC_PENTYPE, m_ctlPenType);
	DDX_Control(pDX, IDC_PENSIZE, m_ctlPenSize);
	DDX_Control(pDX, IDC_PENCOLOR, m_ctlPenColor);
	DDX_Control(pDX, IDC_CAMERA_LIST, m_ctlCameraList);
	DDX_Control(pDX, IDC_BAORD, m_ctlBoard);
	DDX_Control(pDX, IDC_VIDEO1, m_ctlVideo1);
	DDX_Control(pDX, IDC_VIDEO2, m_ctlVideo2);
	DDX_Control(pDX, IDC_VIDEO3, m_ctlVideo3);
	DDX_Control(pDX, IDC_VIDEO4, m_ctlVideo4);
	DDX_Check(pDX, IDC_ENABLEAUDIO1, m_bEnableAudio1);
	DDX_Check(pDX, IDC_ENABLEVIDEO1, m_bEnableVideo1);

	DDX_Check(pDX, IDC_ENABLEAUDIO2, m_bEnableAudio2);
	DDX_Check(pDX, IDC_ENABLEVIDEO2, m_bEnableVideo2);

	DDX_Check(pDX, IDC_ENABLEAUDIO3, m_bEnableAudio3);
	DDX_Check(pDX, IDC_ENABLEVIDEO3, m_bEnableVideo3);

	DDX_Check(pDX, IDC_ENABLEAUDIO4, m_bEnableAudio4);
	DDX_Check(pDX, IDC_ENABLEVIDEO4, m_bEnableVideo4);
}

BEGIN_MESSAGE_MAP(CdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_JOINROOM, &CdemoDlg::OnBnClickedJoinroom)
	ON_BN_CLICKED(IDC_LEAVEROOM, &CdemoDlg::OnBnClickedLeaveroom)
	ON_MESSAGE(WM_JOIN_SUCCESS, &CdemoDlg::OnMessageJoinSuccess)
	ON_MESSAGE(WM_JOIN_FAIL, &CdemoDlg::OnMessageJoinFail)
	ON_MESSAGE(WM_MEMBER_ENABLE_VIDEO, &CdemoDlg::OnMessageMemberEnableVideo)
	ON_BN_CLICKED(IDC_ENABLEAUDIO1, &CdemoDlg::OnBnClickedEnableaudio1)
	ON_BN_CLICKED(IDC_ENABLEVIDEO1, &CdemoDlg::OnBnClickedEnablevideo1)
	ON_BN_CLICKED(IDC_ENABLEAUDIO2, &CdemoDlg::OnBnClickedEnableaudio2)
	ON_BN_CLICKED(IDC_ENABLEVIDEO2, &CdemoDlg::OnBnClickedEnablevideo2)
	ON_BN_CLICKED(IDC_ENABLEAUDIO3, &CdemoDlg::OnBnClickedEnableaudio3)
	ON_BN_CLICKED(IDC_ENABLEVIDEO3, &CdemoDlg::OnBnClickedEnablevideo3)
	ON_BN_CLICKED(IDC_ENABLEAUDIO4, &CdemoDlg::OnBnClickedEnableaudio4)
	ON_BN_CLICKED(IDC_ENABLEVIDEO4, &CdemoDlg::OnBnClickedEnablevideo4)
	ON_CBN_SELCHANGE(IDC_CAMERA_LIST, &CdemoDlg::OnCbnSelchangeCameraList)
	ON_CBN_SELCHANGE(IDC_PENTYPE, &CdemoDlg::OnCbnSelchangePentype)
	ON_CBN_SELCHANGE(IDC_PENSIZE, &CdemoDlg::OnCbnSelchangePensize)
	ON_CBN_SELCHANGE(IDC_PENCOLOR, &CdemoDlg::OnCbnSelchangePencolor)
	ON_WM_MOVE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CdemoDlg message handlers

BOOL CdemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_shinevv = CreateShinevvInstance();

	InitSDK(m_shinevv, (void*)this, OnJoined, OnDisConnected,
		OnNewMemberJoined, OnMemberLeft, OnModifyLocalAudioStatus, OnModifyLocalVideoStatus, OnMemberEnableVideo,
		OnMemberDisableVideo, OnMemberUnMuteAudio, OnMemberMuteAudio, OnSessionError);

	GetVideoDevices(m_shinevv, GetVideoDevicesResult);

	m_ctlPenType.SetCurSel(0);

	m_ctlPenSize.SetCurSel(0);

	m_ctlPenColor.SetCurSel(0);

	//m_ctlBoard.ModifyStyle( 0, WS_CLIPCHILDREN);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CdemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CdemoDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	// TODO: Add your message handler code here
	if (!m_shinevv)
		return;

	RECT rect;
	::GetWindowRect(m_ctlBoard.GetSafeHwnd(), &rect);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	MovePalette(m_shinevv, rect.left, rect.top, width, height, NULL);
}

void CdemoDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	if (!m_shinevv)
		return;

	DestoryPaletteInstance(m_shinevv);

	LeaveRoom(m_shinevv);

	ReleaseSdk(m_shinevv);

	DestoryShinevvInstance();

	ClearShinevv();
}


void CdemoDlg::OnBnClickedJoinroom()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	std::string pRoomId(CW2A(m_strRoomId.GetString()));

	srand((unsigned)time(NULL));
	m_strLocalMemberId = std::to_string(rand() % 10000000);
	const char* pMemberId = m_strLocalMemberId.c_str();

	std::string pDisplayName(CW2A(m_strNickName.GetString()));

	std::string pServerIp(CW2A(m_strIP.GetString()));

	JoinRoom(m_shinevv, pRoomId.c_str(), MediaType::Video, pMemberId, pDisplayName.c_str(), pServerIp.c_str(), m_iPort, "123");
}

void CdemoDlg::OnBnClickedLeaveroom()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	LeaveRoom(m_shinevv);
}

void CdemoDlg::OnCbnSelchangeCameraList()
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlCameraList.GetCurSel();

	CString cstrCamera;

	m_ctlCameraList.GetLBText(nIndex, cstrCamera);

	SetVideoDevice(m_shinevv, m_cameraIndexMap[cstrCamera], NULL);
}

void CdemoDlg::OnCbnSelchangePentype()
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlPenType.GetCurSel();

	CString strPenType;

	m_ctlPenType.GetLBText(nIndex, strPenType);

	PenType nType;
	if (strPenType == L"Line") {
		nType = PenType::LINE_PEN;
	}
	else if (strPenType == L"Circle") {
		nType = PenType::ELLIPSE_PEN;
	}
	else if (strPenType == L"Rect") {
		nType = PenType::RECT_PEN;
	}
	else if (strPenType == L"Earser") {
		nType = PenType::ERASER_PEN;
	}

	SetPalettePenType(m_shinevv, nType, NULL);
}


void CdemoDlg::OnCbnSelchangePensize()
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlPenSize.GetCurSel();

	CString strPenSize;

	m_ctlPenSize.GetLBText(nIndex, strPenSize);

	float fSize;
	if (strPenSize == L"3") {
		fSize = 3.0f;
	}
	else if (strPenSize == L"4") {
		fSize = 4.0f;
	}
	else if (strPenSize == L"5") {
		fSize = 5.0f;
	}

	SetPalettePenWidth(m_shinevv, fSize, NULL);
}


void CdemoDlg::OnCbnSelchangePencolor()
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlPenColor.GetCurSel();

	CString strPenColor;

	m_ctlPenColor.GetLBText(nIndex, strPenColor);

	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	if (strPenColor == L"Red") {
		r = 255;
		g = 0;
		b = 0;
	}
	else if (strPenColor == L"Green") {
		r = 0;
		g = 255;
		b = 0;
	}
	else if (strPenColor == L"Bule") {
		r = 0;
		g = 0;
		b = 255;
	}

	SetPalettePenColor(m_shinevv, r, g, b, NULL);
}


void CdemoDlg::OnBnClickedEnableaudio1()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (m_bEnableAudio1)
		ModifyAudioStatus(m_shinevv, true);
	else
		ModifyAudioStatus(m_shinevv, false);
}

void CdemoDlg::OnBnClickedEnablevideo1()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (m_bEnableVideo1)
		ModifyAudioStatus(m_shinevv, true);
	else
		ModifyAudioStatus(m_shinevv, false);
}

void CdemoDlg::OnBnClickedEnableaudio2()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId2.empty()) {
		if (m_bEnableAudio2)
			EnableMemberAudio(m_shinevv, m_strRemoteMemberId2.c_str(), NULL);
		else
			DisableMemberAudio(m_shinevv, m_strRemoteMemberId2.c_str(), NULL);
	}	
}


void CdemoDlg::OnBnClickedEnablevideo2()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId2.empty()) {
		if (m_bEnableVideo2)
			EnableMemberVideo(m_shinevv, m_strRemoteMemberId2.c_str(), NULL);
		else
			DisableMemberVideo(m_shinevv, m_strRemoteMemberId2.c_str(), NULL);
	}
}


void CdemoDlg::OnBnClickedEnableaudio3()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId3.empty()) {
		if (m_bEnableAudio3)
			EnableMemberAudio(m_shinevv, m_strRemoteMemberId3.c_str(), NULL);
		else
			DisableMemberAudio(m_shinevv, m_strRemoteMemberId3.c_str(), NULL);
	}
}


void CdemoDlg::OnBnClickedEnablevideo3()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId3.empty()) {
		if (m_bEnableVideo3)
			EnableMemberVideo(m_shinevv, m_strRemoteMemberId3.c_str(), NULL);
		else
			DisableMemberVideo(m_shinevv, m_strRemoteMemberId3.c_str(), NULL);
	}
}


void CdemoDlg::OnBnClickedEnableaudio4()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId4.empty()) {
		if (m_bEnableAudio4)
			EnableMemberAudio(m_shinevv, m_strRemoteMemberId4.c_str(), NULL);
		else
			DisableMemberAudio(m_shinevv, m_strRemoteMemberId4.c_str(), NULL);
	}
}


void CdemoDlg::OnBnClickedEnablevideo4()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	if (!m_strRemoteMemberId4.empty()) {
		if (m_bEnableVideo4)
			EnableMemberVideo(m_shinevv, m_strRemoteMemberId4.c_str(), NULL);
		else
			DisableMemberVideo(m_shinevv, m_strRemoteMemberId4.c_str(), NULL);
	}
}


//process message 
LRESULT CdemoDlg::OnMessageJoinSuccess(WPARAM, LPARAM) {
	if (!m_shinevv)
		return 0;

	SetRenderWindow(m_shinevv, m_strLocalMemberId.c_str(), (void*)m_ctlVideo1.GetSafeHwnd(), true);

	HWND boardWindow = m_ctlBoard.GetSafeHwnd();

	RECT rect;
	::GetWindowRect(boardWindow, &rect);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	CreatePaletteInstance(m_shinevv, (void*)boardWindow, rect.left, rect.top, width, height, true, NULL);

	OnCbnSelchangePentype();
	OnCbnSelchangePensize();
	OnCbnSelchangePencolor();
	return 0;
}

LRESULT CdemoDlg::OnMessageJoinFail(WPARAM, LPARAM) {
	if (!m_shinevv)
		return 0;

	LeaveRoom(m_shinevv);

	return 0;
}

LRESULT CdemoDlg::OnMessageMemberEnableVideo(WPARAM wParam, LPARAM lParam) {
	if (!m_shinevv)
		return 0;

	CString *csMemberId = (CString*)lParam;

	std::string strMemberId(CW2A(csMemberId->GetString()));

	mapMemberWindow::iterator it = m_memberWindowMap.find(std::string(strMemberId));
	if (it != m_memberWindowMap.end()) {
		SetRenderWindow(m_shinevv, strMemberId.c_str(), (void*)it->second, false);
	}

	if (csMemberId) {
		delete csMemberId;
		csMemberId = NULL;
	}

	return 0;
}

//call back 
void OnJoined(void* userData, ErrorCode eCode) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	if (eCode == ErrorCode::VVSuccess) {
		::PostMessage(demo_instance->GetSafeHwnd(), WM_JOIN_SUCCESS, NULL, NULL);
	}
	else {
		::PostMessage(demo_instance->GetSafeHwnd(), WM_JOIN_FAIL, NULL, NULL);
	}
}

void OnDisConnected(void* userData) {

}

void OnNewMemberJoined(void* userData, const char* pMemberId, const char* pDisplayName) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	HWND remoteWindow = NULL;
	if (demo_instance->m_strRemoteMemberId2.empty()) {
		demo_instance->m_strRemoteMemberId2 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo2.GetSafeHwnd();
	}
	else if (demo_instance->m_strRemoteMemberId3.empty()) {
		demo_instance->m_strRemoteMemberId3 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo3.GetSafeHwnd();
	}
	else {
		demo_instance->m_strRemoteMemberId4 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo4.GetSafeHwnd();
	}

	mapMemberWindow::iterator it = demo_instance->m_memberWindowMap.find(std::string(pMemberId));
	if (it != demo_instance->m_memberWindowMap.end()) {
		demo_instance->m_memberWindowMap.erase(std::string(pMemberId));
	}

	demo_instance->m_memberWindowMap.insert(pairMemberWindow(std::string(pMemberId), remoteWindow));
}

void OnMemberLeft(void* userData, const char* pMemberId, const char* pDisplayName) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	mapMemberWindow::iterator it = demo_instance->m_memberWindowMap.find(std::string(pMemberId));
	if (it != demo_instance->m_memberWindowMap.end()) {
		demo_instance->m_memberWindowMap.erase(std::string(pMemberId));
	}

	if (demo_instance->m_strRemoteMemberId2 == pMemberId) {
		demo_instance->m_strRemoteMemberId2.clear();
	}
	else if (demo_instance->m_strRemoteMemberId3 == pMemberId) {
		demo_instance->m_strRemoteMemberId3.clear();
	}
	else {
		demo_instance->m_strRemoteMemberId4.clear();
	}
}

void OnModifyLocalAudioStatus(void* userData, bool bOpen) {

}

void OnModifyLocalVideoStatus(void* userData, bool bOpen) {

}

void OnMemberEnableVideo(void* userData, const char* pMemberId, const char* pDisplayName) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	CString *csMemberId = new CString(pMemberId);

	::PostMessage(demo_instance->GetSafeHwnd(), WM_MEMBER_ENABLE_VIDEO, NULL, (LPARAM)(csMemberId));
}

void OnMemberDisableVideo(void* userData, const char* pMemberId, const char* pDisplayName, void* pRenderWin) {

}

void OnMemberUnMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName) {

}

void OnMemberMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName) {

}

void OnSessionError(void* userData, const char* reason) {

}

void GetVideoDevicesResult(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	for (int i = 0; i < nDeviceNum; i++) {
		CString cameraName(sDeviceInfos[i].pDeviceName);
		demo_instance->m_ctlCameraList.AddString(cameraName);

		demo_instance->m_cameraIndexMap[cameraName] = sDeviceInfos[i].nDeviceIndex;
	}
}

void GetAudioDevicesResultCallBack(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum) {

}

void SetCameraIndexRes(void* userData, bool succ) {

}
