#pragma once
#include "sdk_util.h"

class IMeetingChatCtrlEventWrap
{
public:
	virtual void onChatMsgNotifcation(ZOOM_SDK_NAMESPACE::IChatMsgInfo* chatMsg, const wchar_t* ccc) = 0;
	virtual void onChatStatusChangedNotification(ZOOM_SDK_NAMESPACE::ChatStatus* status_) = 0;
};

class CSDKChatControllerWorkFlow:ZOOM_SDK_NAMESPACE::IMeetingChatCtrlEvent
{
public:
	CSDKChatControllerWorkFlow();
	virtual ~CSDKChatControllerWorkFlow();

public:
	//IMeetingChatCtrlEvent
	virtual void onChatMsgNotifcation(ZOOM_SDK_NAMESPACE::IChatMsgInfo* chatMsg, const wchar_t* ccc);
	virtual void onChatStatusChangedNotification(ZOOM_SDK_NAMESPACE::ChatStatus* status_);
	virtual void onChatMsgDeleteNotification(const wchar_t* msgID, ZOOM_SDK_NAMESPACE::SDKChatMessageDeleteType deleteBy) {}
	virtual void onShareMeetingChatStatusChanged(bool isStart) {}

	//workflow
public:
	void SetEvent(IMeetingChatCtrlEventWrap* pSink);
	bool InitController();
	void UnInit();
	ZOOM_SDK_NAMESPACE::SDKError SendChatMsg(unsigned int receiver, wchar_t* content, ZOOM_SDK_NAMESPACE::SDKChatMessageType msgType);
	ZOOM_SDK_NAMESPACE::IUserInfo* GetUserInfoByID(unsigned int userid);

protected:
	IMeetingChatCtrlEventWrap* m_meeting_chat_event;
	bool bInited;
	ZOOM_SDK_NAMESPACE::IMeetingChatController* m_meeting_chat_ctr;
	ZOOM_SDK_NAMESPACE::IMeetingParticipantsController* m_meeting_participants_ctr;

};