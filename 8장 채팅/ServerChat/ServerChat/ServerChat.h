
// ServerChat.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CServerChatApp:
// �� Ŭ������ ������ ���ؼ��� ServerChat.cpp�� �����Ͻʽÿ�.
//

class CServerChatApp : public CWinAppEx
{
public:
	CServerChatApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CServerChatApp theApp;