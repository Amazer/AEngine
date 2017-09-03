// ��Ϸ����̨���
#define WIN32_LEAN_AND_MEAN // ��ʹ��MFC

#include <windows.h>		// Windows ͷ�ļ�
#include <windowsx.h>		// ���������ĺ�
#include <mmsystem.h>
#include <iostream>			// iostream.h
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <io.h>
#include <fcntl.h>

// ���� //////////////////////////////////
// windows ʹ�õĳ���
#define WINDOW_CLASS_NAME "WINCLASS1"
#define WINDOW_TITLE "T3D Graphics Console Alpha 1.0"
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

// �����첽��ʽ��ȡ��������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)

// ��Ϸ����̨ԭ��
int Game_Init(void *param=NULL);
int Game_Main(void *param=NULL);
int Game_Shutdown(void *param=NULL);

// ��Ϣ�ص�����
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

// ȫ�ֱ���
HWND main_window_handle = NULL;
HINSTANCE main_instance = NULL;
char buffer[256];					// ���ڴ�ӡ�ı�


// ����Windows��������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX winclass;
	HWND hwnd;
	MSG msg;
	HDC hdc;
	PAINTSTRUCT ps;

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
		WINDOW_TITLE,
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
	main_instance = hInstance;
	main_window_handle = hwnd;

	ShowWindow(hwnd, SW_SHOW);

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

	Game_Init();

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

	Game_Shutdown();
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

// ��Ϸ���̺���ʵ��

int Game_Init(void *param/* =NULL */)
{
	// ��Ϸ��ʼ������

	// �ɹ�����
	return 1;
}// end Game_Init

int Game_Shutdown(void *param/* =NULL */)
{
	// �˳���Ϸ �ͷ���Դ

	// �ɹ�����
	return 1;
}// end Game_Shutdown

// ��Ϸ���ķ���
int Game_Main(void *param/* =NULL */)
{
	// ÿ֡����

	// ��Ϸ�߼�

	// ����û��Ƿ�Ҫ�˳�
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(main_window_handle, WM_DESTROY, 0, 0);
	}// end if

	// �ɹ�����
	return 1;
}// end Game_Main
