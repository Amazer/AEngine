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
	int dead_zone = 10);		// dead zone ����

void DInput_Release_Joystic(void);
void DInput_Release_Mouse(void);
void DInput_Release_Keyboard(void);

int DInput_Read_Keyboard(void);
int DInput_Read_Mouse(void);

int DInput_Read_Joystic(void);

// EXTERNALS //////////////////////////////////////////////

extern HWND main_window_handle; // save the window handle
extern HINSTANCE main_instance; // save the instance

// ȫ�ֱ���
LPDIRECTINPUT8				lpdi;		// input object
LPDIRECTINPUTDEVICE8		lpdikey;	// dinput keyboard
LPDIRECTINPUTDEVICE8		lpdimouse;	// dinput mouse
LPDIRECTINPUTDEVICE8		lpdijoy;	// dinput joy

GUID						joystickGUID;		// ����Ϸҡ�˵�guid
char						joyname[80];		// ��Ϸҡ������

 UCHAR						keyboard_state[256];			// ����״̬��
 DIMOUSESTATE				mouse_state;					// ���״̬
 DIJOYSTATE					joy_state;						// ҡ��״̬
 int						joystick_found;					// ָ����Ϸҡ���Ƿ����

#endif // !T3DLIB2
