
// BallDoc.h : CBallDoc Ŭ������ �������̽�
//


#pragma once


class CBallDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CBallDoc();
	DECLARE_DYNCREATE(CBallDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CBallDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


