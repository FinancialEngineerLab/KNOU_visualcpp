
// Shopping.h : Shopping ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CShoppingApp:
// �� Ŭ������ ������ ���ؼ��� Shopping.cpp�� �����Ͻʽÿ�.
//

class CShoppingApp : public CWinApp
{
public:
	CShoppingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShoppingApp theApp;
