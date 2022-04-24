#include <windows.h>

class CStudent
{
public:
	LPCTSTR   m_pName;
	int		m_Age;
	int		m_Number;
	int		m_Grade;
	

	void	SetName(LPCTSTR pName);
	void	SetAge(int age);
	void    Print(HDC hdc, int x, int y); 

	};
