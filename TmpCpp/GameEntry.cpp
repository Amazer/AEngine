#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <math.h>
#include <stdlib.h>

#define WINCLASSNAME "WINCLASS1"
#define WNDNAME "EngineEntry"


LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

void TestPixel(HWND hwnd);
void TestLine(HWND hwnd);
void TestRectangle(HWND hwnd);
void Game_Main(HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wclass;
	wclass.cbSize = sizeof(WNDCLASSEX);
	wclass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;
	wclass.lpfnWndProc = WinProc;
	wclass.cbClsExtra = 0;
	wclass.cbWndExtra = 0;
	wclass.hInstance = hInstance;
	wclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wclass.lpszMenuName = NULL;
	wclass.lpszClassName = WINCLASSNAME;
	wclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wclass);
	HWND hwnd;
	if (!(hwnd = CreateWindowEx(
		NULL,
		WINCLASSNAME,
		WNDNAME,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,
		1024, 720,
		NULL,
		NULL,
		hInstance,
		NULL)))
	{
		//		sprintf("error !! create window failed");
		MessageBox(NULL, "Create window Error!", "Error", MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nShowCmd);


//	MessageBox(NULL, "Create window ok!", "ok", MB_OK);

	MSG msg;
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
		Game_Main(hwnd);
	}
	return 0;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		int virtual_code = (int)wparam;
		if (virtual_code == VK_ESCAPE)
		{
			PostQuitMessage(0);
			return 0;
		}
	}
	break;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;
		RECT rect;
		GetClientRect(hwnd, &rect);

		InvalidateRect(hwnd, &rect, true);

		hdc = BeginPaint(hwnd, &ps);
//		TestPixel(hwnd);
//		TestLine(hwnd);
		TestRectangle(hwnd);

		EndPaint(hwnd, &ps);
	}
	break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void TestPixel(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	RECT rect;
	GetClientRect(hwnd, &rect);

	int win_w = rect.right;
	int win_h = rect.bottom;

	for (int i = 0, imax = (win_w + win_h) * 10; i < imax; ++i)
	{
		int x = rand() % win_w;
		int y = rand() % win_h;
		COLORREF  color = RGB(rand() % 255, rand() % 255, rand() % 255);
		SetPixel(hdc, x, y, color);
	}

	ReleaseDC(hwnd, hdc);

}


void TestLine(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	RECT rect;
	GetClientRect(hwnd, &rect);

	int win_w = rect.right;
	int win_h = rect.bottom;

	for (int i = 0, imax = (win_w + win_h) / 10; i < imax; ++i)
	{
		COLORREF  color = RGB(rand() % 255, rand() % 255, rand() % 255);
		HPEN hpen = CreatePen(PS_SOLID, 4, color);
		HPEN old_hpen;
		old_hpen = (HPEN)SelectObject(hdc, hpen);
		int x = rand() % win_w;
		int y = rand() % win_h;
		if (i == 0)
		{
			MoveToEx(hdc, x, y, NULL);
		}
		else
		{
			LineTo(hdc, x, y);
		}
		SelectObject(hdc, old_hpen);
		DeleteObject(hpen);
	}


	ReleaseDC(hwnd, hdc);

}

void TestRectangle(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	RECT rect;
	GetClientRect(hwnd, &rect);

	int win_w = rect.right;
	int win_h = rect.bottom;

	for (int i = 0, imax = (win_w + win_h) / 10; i < imax; ++i)
	{
		COLORREF  color = RGB(rand() % 255, rand() % 255, rand() % 255);
//		HPEN hpen = CreatePen(PS_SOLID, 4, color);
//		HPEN old_hpen;
//		old_hpen = (HPEN)SelectObject(hdc, hpen);

		HBRUSH hbrush = CreateSolidBrush(color);
//		HBRUSH hbrush = CreateHatchBrush(HS_CROSS, color);
//		HBRUSH hbrush = CreateHatchBrush(HS_BDIAGONAL, color);
		HBRUSH old_brush = (HBRUSH)SelectObject(hdc, hbrush);
		int x = rand() % win_w;
		int y = rand() % win_h;
		Rectangle(hdc, x, y, x + rand() % 200, y + rand() % 200);
//		SelectObject(hdc, old_hpen);
//		DeleteObject(hpen);
		SelectObject(hdc, old_brush);
		DeleteObject(hbrush);
	}


	ReleaseDC(hwnd, hdc);


}

void Game_Main(HWND hwnd)
{
}