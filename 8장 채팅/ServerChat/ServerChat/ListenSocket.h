#pragma once

//�Ʒ� ���ȭ�����߰��Ѵ�
#include "ClientSocket.h"

// CListenSocket ��� ����Դϴ�.

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();
	virtual void OnAccept(int nErrorCode);

	//����� Ŭ���̾�Ʈ ���� ����Ʈ
	CPtrList m_ptrClientSocketList;
    
	void CloseClientSocket(CClientSocket* pClient);
	void SendChatDataAll(TCHAR* pszBuffer);

};


