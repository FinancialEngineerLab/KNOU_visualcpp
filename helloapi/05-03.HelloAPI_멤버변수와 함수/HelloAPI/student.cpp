#include "student.h"


//�̸��� �����Ѵ�.
void	CStudent::SetName(LPCTSTR pName)
{
	m_pName = pName;
}

//���̸� ����
void	CStudent::SetAge (int age)
{
	m_Age = age;
}

//����� ������ ����Ѵ�.
void CStudent::Print(HDC hdc, int x, int y)
{	
	TCHAR buf[256];
	wsprintf(buf, L"<�̸�> : %s  <����> : %d", m_pName, m_Age); 
	TextOut(hdc, x, y, buf, lstrlen(buf));
	
}
