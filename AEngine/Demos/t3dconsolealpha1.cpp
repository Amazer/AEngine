// 游戏控制台框架
#define WIN32_LEAN_AND_MEAN // 不使用MFC

#include <windows.h>		// Windows 头文件
#include <windowsx.h>		// 包含大量的宏
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

// 常量 //////////////////////////////////
// windows 使用的常量
#define WINDOW_CLASS_NAME "WINCLASS1"
#define WINDOW_TITLE "T3D Graphics Console Alpha 1.0"
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

// 用于异步方式读取键盘输入
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)

// 游戏控制台原型
int Game_Init(void *param=NULL);
int Game_Main(void *param=NULL);
int Game_Shutdown(void *param=NULL);

// 消息回调方法
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

// 全局变量
HWND main_window_handle = NULL;
HINSTANCE main_instance = NULL;
char buffer[256];					// 用于打印文本


// 所有Windows程序的入口
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

// 游戏流程函数实现

int Game_Init(void *param/* =NULL */)
{
	// 游戏初始化函数

	// 成功返回
	return 1;
}// end Game_Init

int Game_Shutdown(void *param/* =NULL */)
{
	// 退出游戏 释放资源

	// 成功返回
	return 1;
}// end Game_Shutdown

// 游戏核心方法
int Game_Main(void *param/* =NULL */)
{
	// 每帧调用

	// 游戏逻辑

	// 检测用户是否要退出
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(main_window_handle, WM_DESTROY, 0, 0);
	}// end if

	// 成功返回
	return 1;
}// end Game_Main
