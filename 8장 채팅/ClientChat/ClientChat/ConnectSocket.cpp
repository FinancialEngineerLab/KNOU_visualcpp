// ConnectSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ClientChat.h"
#include "ConnectSocket.h"

//아래 헤더화일을 추가한다
#include "ClientChatDlg.h"

// CConnectSocket

CConnectSocket::CConnectSocket()
{
}

CConnectSocket::~CConnectSocket()
{
}


// CConnectSocket 멤버 함수


/////////////////////////////////////////////////////////////////////////////
//서버에서 메시지가 도착했을 때 호출되는 함수.
void CConnectSocket::OnReceive(int nErrorCode) 
{
	TCHAR szBuffer[1024];
	
     memset( szBuffer, 0x00, sizeof(szBuffer));

	//실제로 데이터를 수신한다.
	if(Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		//수신한 메시지를 리스트에 출력한다.
		CClientChatDlg* pMain = (CClientChatDlg*)AfxGetMainWnd();
		pMain->m_List.AddString(szBuffer);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}
	
	CSocket::OnReceive(nErrorCode);
}

/////////////////////////////////////////////////////////////////////////////
//서버와 연결이 종료되는 시점에서 호출되는 함수.
void CConnectSocket::OnClose(int nErrorCode) 
{
	//네트워크 입/출력을 중단하고 소켓을 닫는다.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("서버와 연결이 종료되었습니다."));
	PostQuitMessage(0);
}
