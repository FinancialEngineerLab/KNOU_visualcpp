
// HakSa.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHakSaApp:
// �� Ŭ������ ������ ���ؼ��� HakSa.cpp�� �����Ͻʽÿ�.
//

class CHakSaApp : public CWinAppEx
{
public:
	CHakSaApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHakSaApp theApp;