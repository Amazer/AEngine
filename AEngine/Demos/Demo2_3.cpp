// 一个完整的Windows程序
#define WIN32_LEAN_AND_MEAN // 不使用MFC

#include <windows.h>		// Windows 头文件
#include <windowsx.h>		// 包含大量的宏
#include <stdio.h>
#include <math.h>

#define  WINDOW_CLASS_NAME "WINCLASS1"

// 消息回调方法
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

void Game_Main();


// 所有Windows程序的入口
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

//	UpdateWindow(hwnd);			//将一条WM_PAINT发送给窗口，以刷新其内容

	// get message 是需要等待，有事件才返回

	//	while (GetMessage(&msg,NULL,0,0))
	//	{
	//		TranslateMessage(&msg);		//加速转换消息
	//
	//		DispatchMessage(&msg);		//分发消息
	//	}
	
	// --------------------------------

	// use PeekMessage，如果有消息才处理

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
	PAINTSTRUCT ps;		// 用于paint的数据结构
	HDC hdc;			// 设备场景句柄
	switch (msg)
	{
	case WM_CREATE:				//Create
	{
		// 执行初始化代码

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