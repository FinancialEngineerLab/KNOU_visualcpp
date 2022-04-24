// ClientSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ServerChat.h"
#include "ClientSocket.h"

//아래 두개의 헤더화일을 추가한다
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


// CClientSocket 멤버 함수


//////////////////////////////////////////////////////////////////////////////
//소켓 리스트에 접근하기 위해서 Listen 소켓의 주소를 저장해둔다.
void CClientSocket::SetListenSocket(CAsyncSocket *pSocket)
{
	m_pListenSocket = pSocket;
}

//////////////////////////////////////////////////////////////////////////////
//클라이언트로부터 메시지를 수신함.
//이 함수는 수신할 데이터가 있을 때 호출된다.
void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString tmp = _T("");
	CString strIPAddress = _T("");
	UINT uPortNumber = 0;

	TCHAR szBuffer[1024];
    memset( szBuffer, 0x00, 1024 );

	//연결된 클라이언트의 IP주소와 포트 번호를 알아낸다.
	GetPeerName(strIPAddress, uPortNumber);
	//실제로 데이터를 수신한다.
	if(Receive(szBuffer, 1024) > 0)
	{
		//데이터를 수신하였다면 받은 메시지를 리스트에 출력한다.
		CServerChatDlg* pMain = (CServerChatDlg*)AfxGetMainWnd();
		tmp.Format(_T("[%s] : %s"), strIPAddress, szBuffer);
		pMain->m_List.AddString(tmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() -1);

		//연결된 모든 클라이언트에 해당 메시지를 전송한다.
		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);
	}

	CSocket::OnReceive(nErrorCode);
}

//////////////////////////////////////////////////////////////////////////////
//클라이언트와의 연결이 종료되기 전에 호출되는 함수.
void CClientSocket::OnClose(int nErrorCode) 
{
	CSocket::OnClose(nErrorCode);

	//클라이언트와 연결이 종료되었으므로 해당 소켓을 닫고
	//연결을 종료한다.
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}
