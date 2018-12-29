
// demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "demoDlg.h"
#include "afxdialogex.h"
#include "shinevv.h"

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
	//, m_token(_T("f40901bbca5ccd1e1ff0524072c0ee16"))
	, m_token(_T("9136ecd559356e6a74a4c69718b2d4b7"))
	, m_iPenSize(3)
	, m_bEnableAudio5(FALSE)
	, m_bEnableAudio6(FALSE)
	, m_bEnableAudio7(FALSE)
	, m_bEnableAudio8(FALSE)
	, m_bEnableVideo5(FALSE)
	, m_bEnableVideo6(FALSE)
	, m_bEnableVideo7(FALSE)
	, m_bEnableVideo8(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_strIP = "134.175.141.160";// "sdk.sl.shinevv.com";

	m_iPort = 3443;

	m_strRoomId = "1";

	m_strNickName = "jack";

	// ½ûÒô
	m_bEnableAudio1=TRUE;
	// ±¾µØ½ûÊÓ
	m_bEnableVideo1 = TRUE;

	// ½ûÒô
	m_bEnableAudio2 = TRUE;
	// ±¾µØ½ûÊÓ
	m_bEnableVideo2 = TRUE;

	// ½ûÒô
	m_bEnableAudio3 = TRUE;
	// ±¾µØ½ûÊÓ
	m_bEnableVideo3 = TRUE;

	// ½ûÒô
	m_bEnableAudio4 = TRUE;
	// ±¾µØ½ûÊÓ
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
	//DDX_Control(pDX, IDC_PENSIZE, m_ctlPenSize);
	//DDX_Control(pDX, IDC_PENCOLOR, m_ctlPenColor);
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
	DDX_Text(pDX, IDC_TOKEN, m_token);
	DDV_MaxChars(pDX, m_token, 64);
	DDX_Control(pDX, IDC_PENCOLOR, m_ctlPenColor);
	DDX_Text(pDX, IDC_PENSIZE, m_iPenSize);
	DDV_MinMaxUInt(pDX, m_iPenSize, 3, 20);
	DDX_Control(pDX, IDC_ENABLEAUDIO1, m_ctlA1);
	DDX_Control(pDX, IDC_ENABLEVIDEO1, m_ctlV1);
	DDX_Control(pDX, IDC_ENABLEAUDIO2, m_ctlA2);
	DDX_Control(pDX, IDC_ENABLEVIDEO2, m_ctlV2);
	DDX_Control(pDX, IDC_ENABLEAUDIO3, m_ctlA3);
	DDX_Control(pDX, IDC_ENABLEVIDEO3, m_ctlV3);
	DDX_Control(pDX, IDC_ENABLEAUDIO4, m_ctlA4);
	DDX_Control(pDX, IDC_ENABLEVIDEO4, m_ctlV4);
	DDX_Check(pDX, IDC_ENABLEAUDIO5, m_bEnableAudio5);
	DDX_Control(pDX, IDC_ENABLEAUDIO5, m_ctlA5);
	DDX_Control(pDX, IDC_ENABLEAUDIO6, m_ctlA6);
	DDX_Check(pDX, IDC_ENABLEAUDIO6, m_bEnableAudio6);
	DDX_Control(pDX, IDC_ENABLEAUDIO7, m_ctlA7);
	DDX_Check(pDX, IDC_ENABLEAUDIO7, m_bEnableAudio7);
	DDX_Control(pDX, IDC_ENABLEAUDIO8, m_ctlA8);
	DDX_Check(pDX, IDC_ENABLEAUDIO8, m_bEnableAudio8);
	DDX_Control(pDX, IDC_VIDEO5, m_ctlVideo5);
	DDX_Control(pDX, IDC_VIDEO6, m_ctlVideo6);
	DDX_Control(pDX, IDC_VIDEO7, m_ctlVideo7);
	DDX_Control(pDX, IDC_VIDEO8, m_ctlVideo8);
	DDX_Control(pDX, IDC_ENABLEVIDEO5, m_ctlV5);
	DDX_Check(pDX, IDC_ENABLEVIDEO5, m_bEnableVideo5);
	DDX_Control(pDX, IDC_ENABLEVIDEO6, m_ctlV6);
	DDX_Check(pDX, IDC_ENABLEVIDEO6, m_bEnableVideo6);
	DDX_Control(pDX, IDC_ENABLEVIDEO7, m_ctlV7);
	DDX_Check(pDX, IDC_ENABLEVIDEO7, m_bEnableVideo7);
	DDX_Control(pDX, IDC_ENABLEVIDEO8, m_ctlV8);
	DDX_Check(pDX, IDC_ENABLEVIDEO8, m_bEnableVideo8);
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
	//ON_CBN_SELCHANGE(IDC_PENCOLOR, &CdemoDlg::OnCbnSelchangePencolor)
	ON_WM_MOVE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_PENCOLOR, &CdemoDlg::OnBnClickedPencolor)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &CdemoDlg::OnDeltaposSpin)
	ON_MESSAGE(WM_MEMBER_DISBLE_VIDEO, &CdemoDlg::OnMemberDisbleVideo)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_ENABLEVIDEO5, &CdemoDlg::OnClickedEnablevideo5)
	ON_BN_CLICKED(IDC_ENABLEVIDEO6, &CdemoDlg::OnClickedEnablevideo6)
	ON_BN_CLICKED(IDC_ENABLEVIDEO7, &CdemoDlg::OnClickedEnablevideo7)
	ON_BN_CLICKED(IDC_ENABLEVIDEO8, &CdemoDlg::OnClickedEnablevideo8)
	ON_BN_CLICKED(IDC_ENABLEAUDIO5, &CdemoDlg::OnClickedEnableaudio5)
	ON_BN_CLICKED(IDC_ENABLEAUDIO6, &CdemoDlg::OnClickedEnableaudio6)
	ON_BN_CLICKED(IDC_ENABLEAUDIO7, &CdemoDlg::OnClickedEnableaudio7)
	ON_BN_CLICKED(IDC_ENABLEAUDIO8, &CdemoDlg::OnClickedEnableaudio8)
END_MESSAGE_MAP()

// CdemoDlg message handlers

BOOL CdemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	srand((unsigned)time(NULL));
	m_strLocalMemberId = std::to_string(rand() % 10000000);

	m_shinevv = CreateShinevvInstance();

	//InitSDK(m_shinevv, (void*)this, OnJoined, OnDisConnected,
	//	OnNewMemberJoined, OnMemberLeft, OnModifyLocalAudioStatus, OnModifyLocalVideoStatus, OnMemberEnableVideo,
	//	OnMemberDisableVideo, OnMemberUnMuteAudio, OnMemberMuteAudio, OnRecvUserMessage, OnSessionError);



	//GetVideoDevices(m_shinevv, GetVideoDevicesResult);

	m_ctlPenType.SetCurSel(0);
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN);
	pSpin->SetRange32(3, 20);
	pSpin->SetBase(10);
	m_ctlPenColor.EnableOtherButton(_T("更多"));
	m_ctlPenColor.SetColor(RGB(0, 0, 0));
	UpdateData(FALSE);
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

	//DestoryPaletteInstance(m_shinevv);

	//LeaveRoom(m_shinevv);

	//ReleaseSdk(m_shinevv);

	DestoryShinevvInstance();

	ClearShinevv();
}


void CdemoDlg::OnBnClickedJoinroom()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	InitSDK(m_shinevv, (void*)this, OnJoined, OnDisConnected,
		OnNewMemberJoined, OnMemberLeft, OnMemberEnableVideo,
		OnMemberDisableVideo, OnMemberEnableScreenShare,
		OnMemberDisableScreenShare, OnMemberUnMuteAudio,
		OnMemberMuteAudio, OnRecvUserMessage, OnSessionError);

	std::string pRoomId(CW2A(m_strRoomId.GetString()));


	const char* pMemberId = m_strLocalMemberId.c_str();

	std::string pDisplayName(CW2A(m_strNickName.GetString()));

	std::string pServerIp(CW2A(m_strIP.GetString()));
	
	std::string pToken(CW2A(m_token.GetString()));

	JoinRoom(m_shinevv, pRoomId.c_str(), MediaType::Video, pMemberId, pDisplayName.c_str(), pServerIp.c_str(), m_iPort, pToken.c_str());

	m_bEnableAudio1 = false;
	m_bEnableVideo1 = false;
	UpdateData(FALSE);
}

void CdemoDlg::OnBnClickedLeaveroom()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	DestoryPaletteInstance(m_shinevv);
	LeaveRoom(m_shinevv);
	ReleaseSdk(m_shinevv);
	Reset();
}

void CdemoDlg::Reset() {
	CButton * pJoin = (CButton*)GetDlgItem(IDC_JOINROOM);
	pJoin->ShowWindow(TRUE);
	CButton * pLeva = (CButton*)GetDlgItem(IDC_LEAVEROOM);
	pLeva->ShowWindow(FALSE);
	m_ctlVideo1.ShowWindow(FALSE);
	m_ctlV1.ShowWindow(FALSE);
	m_ctlA1.ShowWindow(FALSE);
	m_strRemoteMemberId2.clear();
	m_strRemoteMemberId3.clear();
	m_strRemoteMemberId4.clear();
	m_strRemoteMemberId5.clear();
	m_strRemoteMemberId6.clear();
	m_strRemoteMemberId7.clear();
	m_strRemoteMemberId8.clear();

	m_ctlVideo2.ShowWindow(FALSE);
	m_ctlV2.ShowWindow(FALSE);
	m_ctlA2.ShowWindow(FALSE);

	m_ctlVideo3.ShowWindow(FALSE);
	m_ctlV3.ShowWindow(FALSE);
	m_ctlA3.ShowWindow(FALSE);

	m_ctlVideo4.ShowWindow(FALSE);
	m_ctlV4.ShowWindow(FALSE);
	m_ctlA4.ShowWindow(FALSE);

	m_ctlVideo5.ShowWindow(FALSE);
	m_ctlV5.ShowWindow(FALSE);
	m_ctlA5.ShowWindow(FALSE);

	m_ctlVideo6.ShowWindow(FALSE);
	m_ctlV6.ShowWindow(FALSE);
	m_ctlA6.ShowWindow(FALSE);

	m_ctlVideo7.ShowWindow(FALSE);
	m_ctlV7.ShowWindow(FALSE);
	m_ctlA7.ShowWindow(FALSE);

	m_ctlVideo8.ShowWindow(FALSE);
	m_ctlV8.ShowWindow(FALSE);
	m_ctlA8.ShowWindow(FALSE);

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

	SetPalettePenWidth(m_shinevv, m_iPenSize, NULL);
}


void CdemoDlg::OnCbnSelchangePencolor()
{
	// TODO: Add your control notification handler code here
	//int nIndex = m_ctlPenColor.GetCurSel();

	CString strPenColor;

	//m_ctlPenColor.GetLBText(nIndex, strPenColor);

	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	if (strPenColor == L"Red") {
		r = 255;
	}
	else if (strPenColor == L"Green") {
		g = 255;
	}
	else if (strPenColor == L"Bule") {
		b = 255;
	}

	SetPalettePenColor(m_shinevv, r, g, b, NULL);
}

void CdemoDlg::ModifyVideoStatus(std::string memberid, bool bOpen) {

	if (memberid.empty()) return;

	if (!bOpen) {
		EnableMemberVideo(m_shinevv, memberid.c_str(), onEnableMemberVideoResult);
	}
	else
	{
		DisableMemberVideo(m_shinevv, memberid.c_str(), onDisableMemberVideoResult);
	}
}
void CdemoDlg::ModifyAudioStatus(std::string memberid, bool bOpen) {
	if (memberid.empty()) return;
	if (!bOpen) {
		EnableMemberAudio(m_shinevv, memberid.c_str(), NULL);
	}
	else
	{
		DisableMemberAudio(m_shinevv, memberid.c_str(), NULL);
	}
}

void CdemoDlg::ShowMemberVideoWnd(std::string memberid, bool bShow) {
	if (memberid.compare(m_strLocalMemberId) == 0) {
		m_ctlVideo1.ShowWindow(bShow);
	}else 	if (memberid.compare(m_strRemoteMemberId2) == 0) {
		m_ctlVideo2.ShowWindow(bShow);
	}
	else if(memberid.compare(m_strRemoteMemberId3) == 0) {
		m_ctlVideo3.ShowWindow(bShow);
	}
	else if (memberid.compare(m_strRemoteMemberId4) == 0) {
		m_ctlVideo4.ShowWindow(bShow);
	}
	else if (memberid.compare(m_strRemoteMemberId5) == 0) {
		m_ctlVideo5.ShowWindow(bShow);
	}
	else if (memberid.compare(m_strRemoteMemberId6) == 0) {
		m_ctlVideo6.ShowWindow(bShow);
	}
	else if (memberid.compare(m_strRemoteMemberId7) == 0) {
		m_ctlVideo7.ShowWindow(bShow);
	}
	else if (memberid.compare(m_strRemoteMemberId8) == 0) {
		m_ctlVideo8.ShowWindow(bShow);
	}
}


void CdemoDlg::OnBnClickedEnableaudio1()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strLocalMemberId, m_bEnableAudio1);
}

void CdemoDlg::OnBnClickedEnablevideo1()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyVideoStatus(m_strLocalMemberId, m_bEnableVideo1);
}

void CdemoDlg::OnBnClickedEnableaudio2()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId2, m_bEnableAudio2);
}


void CdemoDlg::OnBnClickedEnablevideo2()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId2, m_bEnableVideo2);
}


void CdemoDlg::OnBnClickedEnableaudio3()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId3, m_bEnableAudio3);
}


void CdemoDlg::OnBnClickedEnablevideo3()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId3, m_bEnableVideo3);
}


void CdemoDlg::OnBnClickedEnableaudio4()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId4, m_bEnableAudio4);
}


void CdemoDlg::OnBnClickedEnablevideo4()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId4, m_bEnableVideo4);
}


//process message 
LRESULT CdemoDlg::OnMessageJoinSuccess(WPARAM, LPARAM) {
	if (!m_shinevv)
		return 0;
	CButton * pJoin = (CButton*)GetDlgItem(IDC_JOINROOM);
	pJoin->ShowWindow(FALSE);
	CButton * pLeva = (CButton*)GetDlgItem(IDC_LEAVEROOM);
	pLeva->ShowWindow(TRUE);

	m_ctlVideo1.ShowWindow(TRUE);
	m_ctlA1.ShowWindow(TRUE);
	m_ctlV1.ShowWindow(TRUE);
	SetRenderWindow(m_shinevv, m_strLocalMemberId.c_str(), (void*)m_ctlVideo1.GetSafeHwnd(), true);

	HWND boardWindow = m_ctlBoard.GetSafeHwnd();

	RECT rect;
	::GetWindowRect(boardWindow, &rect);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	CreatePaletteInstance(m_shinevv, (void*)boardWindow, rect.left, rect.top, width, height, true, NULL);

	OnCbnSelchangePentype();
	OnCbnSelchangePensize();
	OnBnClickedPencolor();
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
	if (it == m_memberWindowMap.end()) {
		if (strMemberId.compare(m_strLocalMemberId)==0)
		{
			SetRenderWindow(m_shinevv, strMemberId.c_str(), (void*)m_ctlVideo1.GetSafeHwnd(), true);
		}
	}
	ShowMemberVideoWnd(strMemberId, TRUE);

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
		demo_instance->m_ctlVideo2.ShowWindow(TRUE);
		demo_instance->m_ctlA2.ShowWindow(TRUE);
		demo_instance->m_ctlV2.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio2 = false;
		demo_instance->m_bEnableVideo2 = false;
		demo_instance->UpdateData(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId3.empty()) {
		demo_instance->m_strRemoteMemberId3 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo3.GetSafeHwnd();
		demo_instance->m_ctlVideo3.ShowWindow(TRUE);
		demo_instance->m_ctlA3.ShowWindow(TRUE);
		demo_instance->m_ctlV3.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio3 = false;
		demo_instance->m_bEnableVideo3 = false;
		demo_instance->UpdateData(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId4.empty()) {
		demo_instance->m_strRemoteMemberId4 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo4.GetSafeHwnd();
		demo_instance->m_ctlVideo4.ShowWindow(TRUE);
		demo_instance->m_ctlA4.ShowWindow(TRUE);
		demo_instance->m_ctlV4.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio4 = false;
		demo_instance->m_bEnableVideo4 = false;
		demo_instance->UpdateData(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId5.empty()) {
		demo_instance->m_strRemoteMemberId5 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo5.GetSafeHwnd();
		demo_instance->m_ctlVideo5.ShowWindow(TRUE);
		demo_instance->m_ctlA5.ShowWindow(TRUE);
		demo_instance->m_ctlV5.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio5 = false;
		demo_instance->m_bEnableVideo5 = false;
		demo_instance->UpdateData(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId6.empty()) {
		demo_instance->m_strRemoteMemberId6 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo6.GetSafeHwnd();
		demo_instance->m_ctlVideo6.ShowWindow(TRUE);
		demo_instance->m_ctlA6.ShowWindow(TRUE);
		demo_instance->m_ctlV6.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio6 = false;
		demo_instance->m_bEnableVideo6 = false;
		demo_instance->UpdateData(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId7.empty()) {
		demo_instance->m_strRemoteMemberId7 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo7.GetSafeHwnd();
		demo_instance->m_ctlVideo7.ShowWindow(TRUE);
		demo_instance->m_ctlA7.ShowWindow(TRUE);
		demo_instance->m_ctlV7.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio7 = false;
		demo_instance->m_bEnableVideo7 = false;
		demo_instance->UpdateData(FALSE);
	}
	else {
		demo_instance->m_strRemoteMemberId8 = pMemberId;
		remoteWindow = demo_instance->m_ctlVideo8.GetSafeHwnd(); 
		demo_instance->m_ctlVideo8.ShowWindow(TRUE);
		demo_instance->m_ctlA8.ShowWindow(TRUE);
		demo_instance->m_ctlV8.ShowWindow(TRUE);
		demo_instance->m_bEnableAudio8 = false;
		demo_instance->m_bEnableVideo8 = false;
		demo_instance->UpdateData(FALSE);
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
		demo_instance->m_ctlVideo2.ShowWindow(FALSE);
		demo_instance->m_ctlA2.ShowWindow(FALSE);
		demo_instance->m_ctlV2.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId3 == pMemberId) {
		demo_instance->m_strRemoteMemberId3.clear();
		demo_instance->m_ctlVideo3.ShowWindow(FALSE);
		demo_instance->m_ctlA3.ShowWindow(FALSE);
		demo_instance->m_ctlV3.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId4 == pMemberId) {
		demo_instance->m_strRemoteMemberId4.clear();
		demo_instance->m_ctlVideo4.ShowWindow(FALSE);
		demo_instance->m_ctlA4.ShowWindow(FALSE);
		demo_instance->m_ctlV4.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId5 == pMemberId) {
		demo_instance->m_strRemoteMemberId5.clear();
		demo_instance->m_ctlVideo5.ShowWindow(FALSE);
		demo_instance->m_ctlA5.ShowWindow(FALSE);
		demo_instance->m_ctlV5.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId6 == pMemberId) {
		demo_instance->m_strRemoteMemberId6.clear();
		demo_instance->m_ctlVideo6.ShowWindow(FALSE);
		demo_instance->m_ctlA6.ShowWindow(FALSE);
		demo_instance->m_ctlV6.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId7 == pMemberId) {
		demo_instance->m_strRemoteMemberId7.clear();
		demo_instance->m_ctlVideo7.ShowWindow(FALSE);
		demo_instance->m_ctlA7.ShowWindow(FALSE);
		demo_instance->m_ctlV7.ShowWindow(FALSE);
	}
	else if (demo_instance->m_strRemoteMemberId8 == pMemberId) {
		demo_instance->m_strRemoteMemberId8.clear();
		demo_instance->m_ctlVideo8.ShowWindow(FALSE);
		demo_instance->m_ctlA8.ShowWindow(FALSE);
		demo_instance->m_ctlV8.ShowWindow(FALSE);
	}
}

void OnModifyLocalAudioStatus(void* userData, bool bOpen) {

}

void OnModifyLocalVideoStatus(void* userData, bool bOpen) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;
	demo_instance->m_ctlVideo1.ShowWindow(bOpen);
	if (bOpen) {
		SetRenderWindow(demo_instance->m_shinevv, demo_instance->m_strLocalMemberId.c_str(), (void*)demo_instance->m_ctlVideo1.GetSafeHwnd(), true);
	}
}

void OnMemberEnableVideo(void* userData, const char* pMemberId, const char* pDisplayName) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	CString *csMemberId = new CString(pMemberId);

	::PostMessage(demo_instance->GetSafeHwnd(), WM_MEMBER_ENABLE_VIDEO, NULL, (LPARAM)(csMemberId));
}

void OnMemberDisableVideo(void* userData, const char* pMemberId, const char* pDisplayName/*, void* pRenderWin*/) {
	CdemoDlg* demo_instance = (CdemoDlg*)userData;

	CString *csMemberId = new CString(pMemberId);

	::PostMessage(demo_instance->GetSafeHwnd(), WM_MEMBER_DISBLE_VIDEO, NULL, (LPARAM)(csMemberId));
}

void OnMemberEnableScreenShare(void* userData, const char* pMemberId, const char* pDisplayName) {}
void OnMemberDisableScreenShare(void* userData, const char* pMemberId, const char* pDisplayName) {}

void OnMemberUnMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName) {

}

void OnMemberMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName) {

}

void OnRecvUserMessage(void* userData, const char* pHistoryMessage) {

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

void onEnableMemberVideoResult(void* userData, bool bSucc, const char* pMemberId) {
	if(bSucc){
		OnMemberEnableVideo(userData, pMemberId, NULL);
	}
}
void onDisableMemberVideoResult(void* userData, bool bSucc, const char* pMemberId) {
	if (bSucc) {
		OnMemberDisableVideo(userData, pMemberId, NULL);
	}
}
void onEnableMemberAudioResult(void* userData, bool bSucc, const char* pMemberId) {}
void onDisableMemberAudioResult(void* userData, bool bSucc, const char* pMemberId) {}

void CdemoDlg::OnBnClickedPencolor()
{
	// TODO: Add your control notification handler code here
	COLORREF color = m_ctlPenColor.GetColor();
	SetPalettePenColor(m_shinevv, GetRValue(color), GetGValue(color), GetBValue(color), NULL);
}



void CdemoDlg::OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	m_iPenSize = m_iPenSize + pNMUpDown->iDelta;
	if (m_iPenSize < 3)m_iPenSize = 3;
	if (m_iPenSize > 20)m_iPenSize = 20;
	SetPalettePenWidth(m_shinevv, m_iPenSize, NULL);
	*pResult = 0;
}


afx_msg LRESULT CdemoDlg::OnMemberDisbleVideo(WPARAM wParam, LPARAM lParam)
{

	CString *csMemberId = (CString*)lParam;

	std::string strMemberId(CW2A(csMemberId->GetString()));

	ShowMemberVideoWnd(strMemberId, FALSE);

	if (csMemberId) {
		delete csMemberId;
		csMemberId = NULL;
	}
	return 0;
}


void CdemoDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	OnBnClickedLeaveroom();
	CDialogEx::OnClose();
}


void CdemoDlg::OnClickedEnablevideo5()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId5, m_bEnableVideo5);
}


void CdemoDlg::OnClickedEnablevideo6()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId6, m_bEnableVideo6);
}


void CdemoDlg::OnClickedEnablevideo7()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId7, m_bEnableVideo7);
}


void CdemoDlg::OnClickedEnablevideo8()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;

	UpdateData(TRUE);
	ModifyVideoStatus(m_strRemoteMemberId8, m_bEnableVideo8);
}


void CdemoDlg::OnClickedEnableaudio5()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId5, m_bEnableAudio5);
}


void CdemoDlg::OnClickedEnableaudio6()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId6, m_bEnableAudio6);
}


void CdemoDlg::OnClickedEnableaudio7()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId7, m_bEnableAudio7);
}


void CdemoDlg::OnClickedEnableaudio8()
{
	// TODO: Add your control notification handler code here
	if (!m_shinevv)
		return;
	UpdateData(TRUE);
	ModifyAudioStatus(m_strRemoteMemberId8, m_bEnableAudio8);
}
