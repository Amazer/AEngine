// һ��������Windows����
#define WIN32_LEAN_AND_MEAN // ��ʹ��MFC

#include <windows.h>		// Windows ͷ�ļ�
#include <windowsx.h>		// ���������ĺ�
#include <stdio.h>
#include <math.h>

#define  WINDOW_CLASS_NAME "WINCLASS1"

// ��Ϣ�ص�����
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

void Game_Main();


// ����Windows��������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX winclass;
	HWND hwnd;
	MSG msg;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	winclass.lpfnWndProc = WinProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	winclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.lpszMenuName = NULL;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winclass))
	{
		return 0;
	}

	hwnd = CreateWindowEx(NULL,
		WINDOW_CLASS_NAME,
		"Demo2_3",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,				// window's style
		0, 0,
		1280, 720,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hwnd)
	{
		return 0;
	}


	ShowWindow(hwnd, nShowCmd);

//	UpdateWindow(hwnd);			//��һ��WM_PAINT���͸����ڣ���ˢ��������

	// get message ����Ҫ�ȴ������¼��ŷ���

	//	while (GetMessage(&msg,NULL,0,0))
	//	{
	//		TranslateMessage(&msg);		//����ת����Ϣ
	//
	//		DispatchMessage(&msg);		//�ַ���Ϣ
	//	}
	
	// --------------------------------

	// use PeekMessage���������Ϣ�Ŵ���

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}

		Game_Main();
	}
	// --------------------------------

	return msg.wParam;
}
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT ps;		// ����paint�����ݽṹ
	HDC hdc;			// �豸�������
	switch (msg)
	{
	case WM_CREATE:				//Create
	{
		// ִ�г�ʼ������

		return 0;
	}
	break;
	case WM_PAINT:				//paint
	{

		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		return 0;
	}
	break;
	case WM_DESTROY:			//destory
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	}

	return (DefWindowProc(hwnd, msg, wparam, lparam));
}		//end WinProc

void Game_Main()
{

}