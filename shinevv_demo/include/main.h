#ifndef SHINEVV_DEMO_MAIN_H
#define SHINEVV_DEMO_MAIN_H

#include "windows.h"
#include "shinevv.h"
#include <map>
#include <string>
#include <iostream>
#include <locale>
#include <codecvt>

typedef std::map<std::string, HWND> MemberWindowMap;

typedef std::pair<std::string, HWND> MemberWindowPair;

#define MEMBER_ID "lisa100"
#define DISPLAY_NAME L"³Â²ß"
#define WIDTH 640
#define HEIGHT 480

#define WM_NEW_REMOTEWINDOWS WM_USER+0x1000
#define WM_CLOSE_WINDOW WM_USER+0x1001


LRESULT CALLBACK VVCreateWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int VVCreateWindow(HWND &hwndMain, int winNum, int width, int height, const char* pTitle);

void OnJoined(ErrorCode eCode) {
	printf("OnJoined eCode = %d\n", (int)eCode);
}

void OnDisConnected() {

}

void OnNewMemberJoined(const char* pMemberId, const char* pDisplayName) {
	printf("OnNewMemberJoined pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
}

void OnModifyLocalAudioStatus(bool bOpen) {
	printf("OnModifyLocalAudioStatus bOpen = %d\n", bOpen);
}

void OnModifyLocalVideoStatus(bool bOpen) {
	printf("OnModifyLocalVideoStatus bOpen = %d\n", bOpen);
}

void OnMemberLeft(const char* pMemberId, const char* pDisplayName) {
	printf("OnMemberLeft pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
}

void OnMemberEnableVideo(const char* pMemberId, const char* pDisplayName);

void OnMemberDisableVideo(const char* pMemberId, const char* pDisplayName, void* pRenderWin);

void OnMemberUnMuteAudio(const char* pMemberId, const char* pDisplayName) {
	printf("OnMemberUnMuteAudio pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
}

void OnMemberMuteAudio(const char* pMemberId, const char* pDisplayName) {
	printf("OnMemberMuteAudio pMemberId = %s, pDisplayName = %s\n", pMemberId, pDisplayName);
}

void OnSessionError(const char* reason) {
	printf("OnSessionError reason = %s\n", reason);
}

void GetVideoDevicesResult(const DeviceInfo sDeviceInfos[], int nDeviceNum) {
	for (int i = 0; i < nDeviceNum; i++) {
		printf("video device[%d], name = %s, index = %d\n", i, sDeviceInfos[i].pDeviceName, sDeviceInfos[i].nDeviceIndex);
	}
}

void GetAudioDevicesResult(const DeviceInfo sDeviceInfos[], int nDeviceNum) {
	for (int i = 0; i < nDeviceNum; i++) {
		printf("audio device[%d], name = %s, index = %d\n", i, sDeviceInfos[i].pDeviceName, sDeviceInfos[i].nDeviceIndex);
	}
}

void SetCameraIndexRes(bool succ) {
	printf("SetCameraIndexRes = %d\n", succ);
}

#endif
