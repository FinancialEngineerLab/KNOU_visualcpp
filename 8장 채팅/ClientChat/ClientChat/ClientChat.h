
// ClientChat.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CClientChatApp:
// �� Ŭ������ ������ ���ؼ��� ClientChat.cpp�� �����Ͻʽÿ�.
//

class CClientChatApp : public CWinAppEx
{
public:
	CClientChatApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CClientChatApp theApp;