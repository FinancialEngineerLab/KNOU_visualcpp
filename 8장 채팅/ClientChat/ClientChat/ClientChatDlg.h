
// ClientChatDlg.h : ��� ����
//

#pragma once


//�Ʒ����ȭ���� �߰��Ѵ�
#include "ConnectSocket.h"
#include "afxwin.h"

// CClientChatDlg ��ȭ ����
class CClientChatDlg : public CDialog
{
// �����Դϴ�.
public:
	CClientChatDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CLIENTCHAT_DIALOG };

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
	CConnectSocket m_Socket;
	CListBox  m_List;
	CString   m_csMessage;
	afx_msg void OnBnClickedButtonSend();
	
};
