
// MemoDoc.cpp : CMemoDoc Ŭ������ ����
//

#include "stdafx.h"
#include "Memo.h"

#include "MemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemoDoc

IMPLEMENT_DYNCREATE(CMemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMemoDoc, CDocument)
END_MESSAGE_MAP()


// CMemoDoc ����/�Ҹ�

CMemoDoc::CMemoDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMemoDoc::~CMemoDoc()
{
}

BOOL CMemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMemoDoc serialization

void CMemoDoc::Serialize(CArchive& ar)
{
	CString data;
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		m_Edit.GetWindowText(data);
		ar << data;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> data;
		m_Edit.SetWindowText(data);
	}
}


// CMemoDoc ����

#ifdef _DEBUG
void CMemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMemoDoc ���
