// ListenSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ServerChat.h"
#include "ListenSocket.h"
//아래 헤더화일을 추가한다
#include "ClientSocket.h"
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수

void CListenSocket::OnAccept(int nErrorCode)
{
	//새로운 클라이언트가 접속을 시도하였으므로
	//해당 연결요청을 받아들이고 (Accept) 클라이언트 소켓 리스트에 추가한다.
	CClientSocket* pClient = new CClientSocket;
	if(Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		m_ptrClientSocketList.AddTail(pClient);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("OnAccept함수 실패."));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


//////////////////////////////////////////////////////////////////////////////
//프로그램 종료 전에 연결된 클라이언트 소켓을 모두 닫고
//할당한 메모리를 해제하고 네트워크 연결을 모두 종료한다.
void CListenSocket::CloseClientSocket(CClientSocket *pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);
	if(pos != NULL)
	{
		//실제로 연결을 종료한다.
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
//한 클라이언트에게 받은 채팅 메시지를 연결된 모든 클라이언트에게
//동일한 내용을 전송한다.
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
