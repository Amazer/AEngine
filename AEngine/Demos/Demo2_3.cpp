// 一个完整的Windows程序
#define WIN32_LEAN_AND_MEAN // 不使用MFC

#include <windows.h>		// Windows 头文件
#include <windowsx.h>		// 包含大量的宏
#include <stdio.h>
#include <math.h>

#define  WINDOW_CLASS_NAME="WINCLASS1"

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


// 所有Windows程序的入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

	MessageBox(NULL, "message....", "Msg", MB_OK | MB_ICONEXCLAMATION);

	return 0;
}
