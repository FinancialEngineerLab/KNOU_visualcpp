#include <windows.h>

#define ID_OK_BTN	2000

#define ID_OK_BTN2	3000

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"HelloAPI";
LPCTSTR ChildClassName = L"ChildWin";


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);     //메인윈도우 클래스 등록

	WndClass.lpfnWndProc = ChildWndProc;      //차일드 윈도우 프로시저
	WndClass.lpszClassName = ChildClassName; //차일드 윈도우 클래스이름
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass,			//윈도우클래스 이름
		L"컴퓨터과학과 3학년",			    //윈도우타이틀
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,   //윈도우스타일
		200, 200,							//윈도우가 보일때 X Y좌표
		1000, 1000,							//윈도우의 폭과 높이				
		(HWND)NULL,							//부모윈도우 핸들
		(HMENU)NULL,						//윈도우가 가지는 메뉴핸들
		hInstance,							//인스턴스핸들
		NULL);								//여분의 데이터

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	LPCTSTR text = L"학번:이름: ";
	switch (iMessage) {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 160, 100, text, lstrlen(text));
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_CREATE:
	{
		HWND hChildWnd = CreateWindow(
			ChildClassName,     		// 차일드 윈도우 클래스 이름 
			L"2022-2 수강 교과목 정보",            	// 윈도우 타이틀 
			WS_OVERLAPPEDWINDOW | WS_CHILD,  // 윈도우  스타일 
			150,       		// 윈도우 보일 때 x 좌표 
			150,       		// 윈도우 보일 때 y 좌표 
			500,       		// 윈도우 폭
			350,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)1000,        	// 차일드 윈도우ID 
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터			

		ShowWindow(hChildWnd, SW_SHOW);

		hChildWnd = CreateWindow(
			L"button",        		// 윈도우 클래스 이름 
			L"수강신청",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			300,       		// 윈도우 보일 때 x 좌표 
			530,       		// 윈도우 보일 때 y 좌표 
			100,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_OK_BTN,   	// 컨트롤 ID
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd) 	return -1;


		return 0;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_OK_BTN)
		{
			MessageBox(hWnd, L"수강신청을 확정하시겠습니까?.", L"확정안내", MB_OK);
		}

		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}


LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LPCTSTR text = L"2학기 개설과목";
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 140, 50, text, lstrlen(text));
		EndPaint(hWnd, &ps);
		return 0;
	}

	case WM_CREATE:
	{
		HWND hChildWnd2 = CreateWindow(
			L"button",        		// 윈도우 클래스 이름 
			L"클라우드컴퓨팅",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			50,       		// 윈도우 보일 때 x 좌표 
			150,       		// 윈도우 보일 때 y 좌표 
			150,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_OK_BTN,   	// 컨트롤 ID
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd2) 	return -1;

		HWND hChildWnd3 = CreateWindow(
			L"button",        		// 윈도우 클래스 이름 
			L"컴퓨터구조",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			250,       		// 윈도우 보일 때 x 좌표 
			150,       		// 윈도우 보일 때 y 좌표 
			150,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_OK_BTN,   	// 컨트롤 ID
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd3) 	return -1;


		HWND hChildWnd4 = CreateWindow(
			L"button",        		// 윈도우 클래스 이름 
			L"JSP 프로그래밍",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			50,       		// 윈도우 보일 때 x 좌표 
			250,       		// 윈도우 보일 때 y 좌표 
			150,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_OK_BTN,   	// 컨트롤 ID
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd4) 	return -1;

		HWND hChildWnd5 = CreateWindow(
			L"button",        		// 윈도우 클래스 이름 
			L"컴파일러구성",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			250,       		// 윈도우 보일 때 x 좌표 
			250,       		// 윈도우 보일 때 y 좌표 
			150,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_OK_BTN2,   	// 컨트롤 ID
			g_hInst,           		// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd5) 	return -1;
		return 0;
	}

	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_OK_BTN)
		{
			MessageBox(hWnd, L"수강신청이 완료되었습니다.", L"신청안내", MB_OK);
		}

		if (LOWORD(wParam) == ID_OK_BTN2)
		{
			MessageBox(hWnd, L"이미 수강한 과목입니다.", L"신청안내", MB_OK);
		}
		return 0;
	}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
