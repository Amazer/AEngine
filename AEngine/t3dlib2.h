#ifndef T3DLIB2
#define T3DLIB2

// prototype functions
int DInput_Init(void);
void DInput_Shutdown(void);


int DInput_Init_Keyboard(void);
int DInput_Init_Mouse(void);
int DInput_Init_Joystic(int min_x = -256,
	int max_x = 256,
	int min_y = -256,
	int max_y = 256,
	int dead_zone = 10);		// dead zone 比例

void DInput_Release_Joystic(void);
void DInput_Release_Mouse(void);
void DInput_Release_Keyboard(void);

int DInput_Read_Keyboard(void);
int DInput_Read_Mouse(void);

int DInput_Read_Joystic(void);

// EXTERNALS //////////////////////////////////////////////

extern HWND main_window_handle; // save the window handle
extern HINSTANCE main_instance; // save the instance

// 全局变量
LPDIRECTINPUT8				lpdi;		// input object
LPDIRECTINPUTDEVICE8		lpdikey;	// dinput keyboard
LPDIRECTINPUTDEVICE8		lpdimouse;	// dinput mouse
LPDIRECTINPUTDEVICE8		lpdijoy;	// dinput joy

GUID						joystickGUID;		// 主游戏摇杆的guid
char						joyname[80];		// 游戏摇杆名称

 UCHAR						keyboard_state[256];			// 键盘状态表
 DIMOUSESTATE				mouse_state;					// 鼠标状态
 DIJOYSTATE					joy_state;						// 摇杆状态
 int						joystick_found;					// 指出游戏摇杆是否插入

#endif // !T3DLIB2
