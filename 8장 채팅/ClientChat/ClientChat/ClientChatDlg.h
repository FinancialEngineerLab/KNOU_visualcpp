
// ClientChatDlg.h : 헤더 파일
//

#pragma once


//아래헤더화일을 추가한다
#include "ConnectSocket.h"
#include "afxwin.h"

// CClientChatDlg 대화 상자
class CClientChatDlg : public CDialog
{
// 생성입니다.
public:
	CClientChatDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CLIENTCHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
