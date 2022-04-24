// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ServerChat.h"
#include "ClientSocket.h"

//�Ʒ� �ΰ��� ���ȭ���� �߰��Ѵ�
#include "ListenSocket.h"
#include "ServerChatDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
: m_pListenSocket(NULL)
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�


//////////////////////////////////////////////////////////////////////////////
//���� ����Ʈ�� �����ϱ� ���ؼ� Listen ������ �ּҸ� �����صд�.
void CClientSocket::SetListenSocket(CAsyncSocket *pSocket)
{
	m_pListenSocket = pSocket;
}

//////////////////////////////////////////////////////////////////////////////
//Ŭ���̾�Ʈ�κ��� �޽����� ������.
//�� �Լ��� ������ �����Ͱ� ���� �� ȣ��ȴ�.
void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString tmp = _T("");
	CString strIPAddress = _T("");
	UINT uPortNumber = 0;

	TCHAR szBuffer[1024];
    memset( szBuffer, 0x00, 1024 );

	//����� Ŭ���̾�Ʈ�� IP�ּҿ� ��Ʈ ��ȣ�� �˾Ƴ���.
	GetPeerName(strIPAddress, uPortNumber);
	//������ �����͸� �����Ѵ�.
	if(Receive(szBuffer, 1024) > 0)
	{
		//�����͸� �����Ͽ��ٸ� ���� �޽����� ����Ʈ�� ����Ѵ�.
		CServerChatDlg* pMain = (CServerChatDlg*)AfxGetMainWnd();
		tmp.Format(_T("[%s] : %s"), strIPAddress, szBuffer);
		pMain->m_List.AddString(tmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() -1);

		//����� ��� Ŭ���̾�Ʈ�� �ش� �޽����� �����Ѵ�.
		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);
	}

	CSocket::OnReceive(nErrorCode);
}

//////////////////////////////////////////////////////////////////////////////
//Ŭ���̾�Ʈ���� ������ ����Ǳ� ���� ȣ��Ǵ� �Լ�.
void CClientSocket::OnClose(int nErrorCode) 
{
	CSocket::OnClose(nErrorCode);

	//Ŭ���̾�Ʈ�� ������ ����Ǿ����Ƿ� �ش� ������ �ݰ�
	//������ �����Ѵ�.
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}
