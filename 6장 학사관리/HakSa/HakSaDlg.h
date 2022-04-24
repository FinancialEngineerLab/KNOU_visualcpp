
// HakSaDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CHakSaDlg 대화 상자
class CHakSaDlg : public CDialog
{
// 생성입니다.
public:
	CHakSaDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HAKSA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CString m_HakBun;  // 학번
	CString m_Name;  // 이름
	CString m_ListData;   //  입력된 지역대학 이름 
	
	BOOL m_ChkBox1;  // 졸업논문제출여부 체크 상태	
	CListBox m_List;   // 지역대학리스트박스	
	CComboBox m_Combo;  // 지역대학 콤보상자
	CButton m_ChkBox2;	// 수강신청여부 체크박스
	int m_Radio1;   // 출석수업

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
	
	void SetRadioStatus(void); // 라디오 버튼의 상태 셋팅
};
