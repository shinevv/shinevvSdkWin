
// demoDlg.h : header file
//

#pragma once
#include "afxwin.h"

#include "shinevv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include "afxcolorbutton.h"
#include "afxcmn.h"

typedef std::map<std::string, HWND> mapMemberWindow;
typedef std::pair<std::string, HWND> pairMemberWindow;

typedef std::map<CString, int> mapCameraIndex;
typedef std::pair<CString, int> pairCameraIndex;

#define WM_JOIN_SUCCESS				WM_USER+0x110
#define WM_JOIN_FAIL				WM_USER+0x111
#define WM_MEMBER_ENABLE_VIDEO		WM_USER+0x112
#define WM_MEMBER_DISBLE_VIDEO      WM_USER+0x113

// CdemoDlg dialog
class CdemoDlg : public CDialogEx
{
// Construction
public:
	CdemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ip地址
	CString m_strIP;
	// 服务器端口
	int m_iPort;
	// 房间号
	CString m_strRoomId;
	// 昵称
	CString m_strNickName;
	// 摄像头列表
	CComboBox m_ctlCameraList;

	// 画笔类型
	CComboBox m_ctlPenType;
	// 画笔大小
	//CComboBox m_ctlPenSize;
	// 画笔颜色
	//CComboBox m_ctlPenColor;
	// 电子白板
	CStatic m_ctlBoard;

	// 本地视频
	CStatic m_ctlVideo1;
	// 远端视频1
	CStatic m_ctlVideo2;
	// 远端视频2
	CStatic m_ctlVideo3;
	// 远端视频3
	CStatic m_ctlVideo4;
	// 本地禁音
	BOOL m_bEnableAudio1;
	// 本地禁视
	BOOL m_bEnableVideo1;

	// 禁音
	BOOL m_bEnableAudio2;
	// 禁视
	BOOL m_bEnableVideo2;

	// 禁音
	BOOL m_bEnableAudio3;
	// 禁视
	BOOL m_bEnableVideo3;

	// 禁音
	BOOL m_bEnableAudio4;
	// 禁视
	BOOL m_bEnableVideo4;

	void* m_shinevv = NULL;

	std::string m_strLocalMemberId;
	std::string m_strRemoteMemberId2;
	std::string m_strRemoteMemberId3;
	std::string m_strRemoteMemberId4;

	mapMemberWindow m_memberWindowMap;
	mapCameraIndex m_cameraIndexMap;

	afx_msg void OnBnClickedJoinroom();
	afx_msg void OnBnClickedLeaveroom();

	afx_msg LRESULT OnMessageJoinSuccess(WPARAM, LPARAM);
	afx_msg LRESULT OnMessageJoinFail(WPARAM, LPARAM);
	afx_msg LRESULT OnMessageMemberEnableVideo(WPARAM, LPARAM);
	afx_msg void OnBnClickedEnableaudio1();
	afx_msg void OnBnClickedEnablevideo1();
	afx_msg void OnBnClickedEnableaudio2();
	afx_msg void OnBnClickedEnablevideo2();
	afx_msg void OnBnClickedEnableaudio3();
	afx_msg void OnBnClickedEnablevideo3();
	afx_msg void OnBnClickedEnableaudio4();
	afx_msg void OnBnClickedEnablevideo4();
	afx_msg void OnCbnSelchangeCameraList();
	afx_msg void OnCbnSelchangePentype();
	afx_msg void OnCbnSelchangePensize();
	afx_msg void OnCbnSelchangePencolor();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnDestroy();
	// room token
	CString m_token;
	CMFCColorButton m_ctlPenColor;
	afx_msg void OnBnClickedPencolor();
	UINT m_iPenSize;
	afx_msg void OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_ctlA1;
	CButton m_ctlV1;
	CButton m_ctlA2;
	CButton m_ctlV2;
	CButton m_ctlA3;
	CButton m_ctlV3;
	CButton m_ctlA4;
	CButton m_ctlV4;


	private:
		void ModifyVideoStatus(std::string memberid, bool bOpen);
		void ModifyAudioStatus(std::string memberid, bool bOpen);
		void ShowMemberVideoWnd(std::string memberid, bool bShow);
		void Reset();
protected:
	afx_msg LRESULT OnMemberDisbleVideo(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnClose();
	BOOL m_bEnableAudio5;
	CButton m_ctlA5;
	CButton m_ctlA6;
	BOOL m_bEnableAudio6;
	CButton m_ctlA7;
	BOOL m_bEnableAudio7;
	CButton m_ctlA8;
	BOOL m_bEnableAudio8;
	CStatic m_ctlVideo5;
	CStatic m_ctlVideo6;
	CStatic m_ctlVideo7;
	CStatic m_ctlVideo8;
	CButton m_ctlV5;
	BOOL m_bEnableVideo5;
	CButton m_ctlV6;
	BOOL m_bEnableVideo6;
	CButton m_ctlV7;
	BOOL m_bEnableVideo7;
	CButton m_ctlV8;
	BOOL m_bEnableVideo8;
	std::string m_strRemoteMemberId5;
	std::string m_strRemoteMemberId6;
	std::string m_strRemoteMemberId7;
	std::string m_strRemoteMemberId8;
	afx_msg void OnClickedEnablevideo5();
	afx_msg void OnClickedEnablevideo6();
	afx_msg void OnClickedEnablevideo7();
	afx_msg void OnClickedEnablevideo8();
	afx_msg void OnClickedEnableaudio5();
	afx_msg void OnClickedEnableaudio6();
	afx_msg void OnClickedEnableaudio7();
	afx_msg void OnClickedEnableaudio8();
};

void OnJoined(void* userData, ErrorCode eCode);

void OnDisConnected(void* userData);

void OnNewMemberJoined(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberLeft(void* userData, const char* pMemberId, const char* pDisplayName);

void OnModifyLocalAudioStatus(void* userData, bool bOpen);

void OnModifyLocalVideoStatus(void* userData, bool bOpen);

void OnMemberEnableVideo(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberDisableVideo(void* userData, const char* pMemberId, const char* pDisplayName/*, void* pRenderWin*/);

void OnMemberUnMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName);

void OnSessionError(void* userData, const char* reason);

void OnRecvUserMessage(void* userData, const char* pHistoryMessage);

void GetVideoDevicesResult(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum);

void GetAudioDevicesResultCallBack(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum);

void SetCameraIndexRes(void* userData, bool succ);

void OnMemberEnableScreenShare(void* userData, const char* pMemberId, const char* pDisplayName);
void OnMemberDisableScreenShare(void* userData, const char* pMemberId, const char* pDisplayName);
void onEnableMemberVideoResult(void* userData, bool bSucc, const char* pMemberId);
void onDisableMemberVideoResult(void* userData, bool bSucc, const char* pMemberId);

