
// HakSaDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CHakSaDlg ��ȭ ����
class CHakSaDlg : public CDialog
{
// �����Դϴ�.
public:
	CHakSaDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HAKSA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CString m_HakBun;  // �й�
	CString m_Name;  // �̸�
	CString m_ListData;   //  �Էµ� �������� �̸� 
	
	BOOL m_ChkBox1;  // ���������⿩�� üũ ����	
	CListBox m_List;   // �������и���Ʈ�ڽ�	
	CComboBox m_Combo;  // �������� �޺�����
	CButton m_ChkBox2;	// ������û���� üũ�ڽ�
	int m_Radio1;   // �⼮����

	afx_msg void OnBnClickedBtnHakbun();
	afx_msg void OnBnClickedBtnHakbunChk();
	afx_msg void OnBnClickedBtnName();
	afx_msg void OnBnClickedBtnNameChk();
	afx_msg void OnBnClickedBtnList();
	afx_msg void OnBnClickedBtnCombo();
	afx_msg void OnBnClickedBtnDelList();
	afx_msg void OnBnClickedBtnDelCombo();
	afx_msg void OnLbnDblclkList();
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnBnClickedChkbox1();
	afx_msg void OnBnClickedChkbox2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	
	void SetRadioStatus(void); // ���� ��ư�� ���� ����
};
