
// ServerChatDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

//�Ʒ� ���ȭ���� �߰��Ѵ�
#include "ListenSocket.h"

// CServerChatDlg ��ȭ ����
class CServerChatDlg : public CDialog
{
// �����Դϴ�.
public:
	CServerChatDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SERVERCHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List;
	CListenSocket* m_pListenSocket;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy(); 
};
