// һ��������Windows����
#define WIN32_LEAN_AND_MEAN // ��ʹ��MFC

#include <windows.h>		// Windows ͷ�ļ�
#include <windowsx.h>		// ���������ĺ�
#include <stdio.h>
#include <math.h>

#define  WINDOW_CLASS_NAME="WINCLASS1"

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


// ����Windows��������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

	MessageBox(NULL, "message....", "Msg", MB_OK | MB_ICONEXCLAMATION);

	return 0;
}
