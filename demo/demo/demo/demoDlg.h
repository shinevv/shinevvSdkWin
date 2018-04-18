
// demoDlg.h : header file
//

#pragma once
#include "afxwin.h"

#include "shinevv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

typedef std::map<std::string, HWND> mapMemberWindow;
typedef std::pair<std::string, HWND> pairMemberWindow;

typedef std::map<CString, int> mapCameraIndex;
typedef std::pair<CString, int> pairCameraIndex;

#define WM_JOIN_SUCCESS				WM_USER+0x110
#define WM_JOIN_FAIL				WM_USER+0x111
#define WM_MEMBER_ENABLE_VIDEO		WM_USER+0x112

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
	// ip��ַ
	CString m_strIP;
	// �������˿�
	int m_iPort;
	// �����
	CString m_strRoomId;
	// �ǳ�
	CString m_strNickName;
	// ����ͷ�б�
	CComboBox m_ctlCameraList;

	// ��������
	CComboBox m_ctlPenType;
	// ���ʴ�С
	CComboBox m_ctlPenSize;
	// ������ɫ
	CComboBox m_ctlPenColor;
	// ���Ӱװ�
	CStatic m_ctlBoard;

	// ������Ƶ
	CStatic m_ctlVideo1;
	// Զ����Ƶ1
	CStatic m_ctlVideo2;
	// Զ����Ƶ2
	CStatic m_ctlVideo3;
	// Զ����Ƶ3
	CStatic m_ctlVideo4;
	// ���ؽ���
	BOOL m_bEnableAudio1;
	// ���ؽ���
	BOOL m_bEnableVideo1;

	// ����
	BOOL m_bEnableAudio2;
	// ����
	BOOL m_bEnableVideo2;

	// ����
	BOOL m_bEnableAudio3;
	// ����
	BOOL m_bEnableVideo3;

	// ����
	BOOL m_bEnableAudio4;
	// ����
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
};

void OnJoined(void* userData, ErrorCode eCode);

void OnDisConnected(void* userData);

void OnNewMemberJoined(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberLeft(void* userData, const char* pMemberId, const char* pDisplayName);

void OnModifyLocalAudioStatus(void* userData, bool bOpen);

void OnModifyLocalVideoStatus(void* userData, bool bOpen);

void OnMemberEnableVideo(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberDisableVideo(void* userData, const char* pMemberId, const char* pDisplayName, void* pRenderWin);

void OnMemberUnMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName);

void OnMemberMuteAudio(void* userData, const char* pMemberId, const char* pDisplayName);

void OnSessionError(void* userData, const char* reason);

void GetVideoDevicesResult(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum);

void GetAudioDevicesResultCallBack(void* userData, const DeviceInfo sDeviceInfos[], int nDeviceNum);

void SetCameraIndexRes(void* userData, bool succ);

