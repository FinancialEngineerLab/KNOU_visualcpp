// ListenSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ServerChat.h"
#include "ListenSocket.h"
//�Ʒ� ���ȭ���� �߰��Ѵ�
#include "ClientSocket.h"
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket ��� �Լ�

void CListenSocket::OnAccept(int nErrorCode)
{
	//���ο� Ŭ���̾�Ʈ�� ������ �õ��Ͽ����Ƿ�
	//�ش� �����û�� �޾Ƶ��̰� (Accept) Ŭ���̾�Ʈ ���� ����Ʈ�� �߰��Ѵ�.
	CClientSocket* pClient = new CClientSocket;
	if(Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		m_ptrClientSocketList.AddTail(pClient);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("OnAccept�Լ� ����."));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


//////////////////////////////////////////////////////////////////////////////
//���α׷� ���� ���� ����� Ŭ���̾�Ʈ ������ ��� �ݰ�
//�Ҵ��� �޸𸮸� �����ϰ� ��Ʈ��ũ ������ ��� �����Ѵ�.
void CListenSocket::CloseClientSocket(CClientSocket *pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);
	if(pos != NULL)
	{
		//������ ������ �����Ѵ�.
		if(pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();
		}

		m_ptrClientSocketList.RemoveAt(pos);
		delete pClient;
	}
}

//////////////////////////////////////////////////////////////////////////////
//�� Ŭ���̾�Ʈ���� ���� ä�� �޽����� ����� ��� Ŭ���̾�Ʈ����
//������ ������ �����Ѵ�.
void CListenSocket::SendChatDataAll(TCHAR* pszBuffer)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while(pos != NULL)
	{
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if(pClient != NULL)
		{
			pClient->Send(pszBuffer, lstrlen(pszBuffer) * 2);
		}
	}
}
