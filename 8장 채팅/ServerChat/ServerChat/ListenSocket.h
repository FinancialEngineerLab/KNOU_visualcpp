#pragma once

//아래 헤더화일을추가한다
#include "ClientSocket.h"

// CListenSocket 명령 대상입니다.

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();
	virtual void OnAccept(int nErrorCode);

	//연결된 클라이언트 소켓 리스트
	CPtrList m_ptrClientSocketList;
    
	void CloseClientSocket(CClientSocket* pClient);
	void SendChatDataAll(TCHAR* pszBuffer);

};


