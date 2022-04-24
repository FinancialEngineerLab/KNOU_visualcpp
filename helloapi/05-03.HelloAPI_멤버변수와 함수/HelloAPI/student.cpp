#include "student.h"


//이름을 설정한다.
void	CStudent::SetName(LPCTSTR pName)
{
	m_pName = pName;
}

//나이를 설정
void	CStudent::SetAge (int age)
{
	m_Age = age;
}

//멤버의 내용을 출력한다.
void CStudent::Print(HDC hdc, int x, int y)
{	
	TCHAR buf[256];
	wsprintf(buf, L"<이름> : %s  <나이> : %d", m_pName, m_Age); 
	TextOut(hdc, x, y, buf, lstrlen(buf));
	
}
