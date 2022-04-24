// ConnectSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ClientChat.h"
#include "ConnectSocket.h"

//�Ʒ� ���ȭ���� �߰��Ѵ�
#include "ClientChatDlg.h"

// CConnectSocket

CConnectSocket::CConnectSocket()
{
}

CConnectSocket::~CConnectSocket()
{
}


// CConnectSocket ��� �Լ�


/////////////////////////////////////////////////////////////////////////////
//�������� �޽����� �������� �� ȣ��Ǵ� �Լ�.
void CConnectSocket::OnReceive(int nErrorCode) 
{
	TCHAR szBuffer[1024];
	
     memset( szBuffer, 0x00, sizeof(szBuffer));

	//������ �����͸� �����Ѵ�.
	if(Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		//������ �޽����� ����Ʈ�� ����Ѵ�.
		CClientChatDlg* pMain = (CClientChatDlg*)AfxGetMainWnd();
		pMain->m_List.AddString(szBuffer);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}
	
	CSocket::OnReceive(nErrorCode);
}

/////////////////////////////////////////////////////////////////////////////
//������ ������ ����Ǵ� �������� ȣ��Ǵ� �Լ�.
void CConnectSocket::OnClose(int nErrorCode) 
{
	//��Ʈ��ũ ��/����� �ߴ��ϰ� ������ �ݴ´�.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("������ ������ ����Ǿ����ϴ�."));
	PostQuitMessage(0);
}
