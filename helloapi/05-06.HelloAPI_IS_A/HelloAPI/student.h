#include <windows.h>

class CPerson
{
public:
	LPCTSTR	m_pName;
	int		m_Age;

	 CPerson(LPCTSTR pName, int age);
	 void Print(HDC hdc, int x, int y);    
	};

class CStudent: public CPerson
{
public:	
	int		m_Number;
	int		m_Grade;
	
	CStudent(LPCTSTR pName, int age , int num);
    void  Print(HDC hdc, int x, int y);	
	};

class CProfessor: public CPerson
{
	LPCTSTR m_pMajor;
	LPCTSTR m_pDep;

public :
	CProfessor(LPCTSTR pName, int age, LPCTSTR m_Major);
	void Print(HDC hdc, int x, int y);
};

