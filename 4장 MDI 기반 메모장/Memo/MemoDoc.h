
// MemoDoc.h : CMemoDoc Ŭ������ �������̽�
//


#pragma once


class CMemoDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMemoDoc();
	DECLARE_DYNCREATE(CMemoDoc)

// Ư���Դϴ�.
public:
 CEdit  m_Edit;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CMemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


