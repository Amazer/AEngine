// T3DLIB1.H - Header file for T3DLIB1.CPP game engine library

// watch for multiple inclusions
#ifndef T3DLIB1
#define T3DLIB1

// DEFINES ////////////////////////////////////////////////

// default screen values, these are all overriden by the 
// call to DDraw_Init() and are just here to have something
// to set the globals to instead of constant values
#define SCREEN_WIDTH        640  // size of screen
#define SCREEN_HEIGHT       480
#define SCREEN_BPP          8    // bits per pixel
#define MAX_COLORS_PALETTE  256


#define DEFAULT_PALETTE_FILE "PALDATA2.PAL"

// used for selecting full screen/windowed mode
#define SCREEN_FULLSCREEN    0
#define SCREEN_WINDOWED      1

// bitmap defines
#define BITMAP_ID            0x4D42 // universal id for a bitmap
#define BITMAP_STATE_DEAD    0
#define BITMAP_STATE_ALIVE   1
#define BITMAP_STATE_DYING   2 
#define BITMAP_ATTR_LOADED   128

#define BITMAP_EXTRACT_MODE_CELL  0
#define BITMAP_EXTRACT_MODE_ABS   1

// directdraw pixel format defines, used to help
// bitmap loader put data in proper format
#define DD_PIXEL_FORMAT8        8
#define DD_PIXEL_FORMAT555      15
#define DD_PIXEL_FORMAT565      16
#define DD_PIXEL_FORMAT888      24
#define DD_PIXEL_FORMATALPHA888 32 


// defines for BOBs
#define BOB_STATE_DEAD         0    // this is a dead bob
#define BOB_STATE_ALIVE        1    // this is a live bob
#define BOB_STATE_DYING        2    // this bob is dying
#define BOB_STATE_ANIM_DONE    1    // done animation state
#define MAX_BOB_FRAMES         64   // maximum number of bob frames
#define MAX_BOB_ANIMATIONS     16   // maximum number of animation sequeces

#define BOB_ATTR_SINGLE_FRAME   1   // bob has single frame
#define BOB_ATTR_MULTI_FRAME    2   // bob has multiple frames
#define BOB_ATTR_MULTI_ANIM     4   // bob has multiple animations
#define BOB_ATTR_ANIM_ONE_SHOT  8   // bob will perform the animation once
#define BOB_ATTR_VISIBLE        16  // bob is visible
#define BOB_ATTR_BOUNCE         32  // bob bounces off edges
#define BOB_ATTR_WRAPAROUND     64  // bob wraps around edges
#define BOB_ATTR_LOADED         128 // the bob has been loaded
#define BOB_ATTR_CLONE          256 // the bob is a clone

// screen transition commands
#define SCREEN_DARKNESS  0         // fade to black
#define SCREEN_WHITENESS 1         // fade to white
#define SCREEN_SWIPE_X   2         // do a horizontal swipe
#define SCREEN_SWIPE_Y   3         // do a vertical swipe
#define SCREEN_DISOLVE   4         // a pixel disolve
#define SCREEN_SCRUNCH   5         // a square compression
#define SCREEN_BLUENESS  6         // fade to blue
#define SCREEN_REDNESS   7         // fade to red
#define SCREEN_GREENNESS 8         // fade to green

// defines for Blink_Colors
#define BLINKER_ADD           0    // add a light to database  
#define BLINKER_DELETE        1    // delete a light from database
#define BLINKER_UPDATE        2    // update a light
#define BLINKER_RUN           3    // run normal

// pi defines
#define PI         ((float)3.141592654f)
#define PI2        ((float)6.283185307f)
#define PI_DIV_2   ((float)1.570796327f)
#define PI_DIV_4   ((float)0.785398163f) 
#define PI_INV     ((float)0.318309886f) 

// fixed point mathematics constants
#define FIXP16_SHIFT     16
#define FIXP16_MAG       65536
#define FIXP16_DP_MASK   0x0000ffff
#define FIXP16_WP_MASK   0xffff0000
#define FIXP16_ROUND_UP  0x00008000

// work Mcro
// async read keyboard inputs
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)

// ����5.5.5��ʽ��16λ��ɫֵ
#define _RGB16BIT555(r,g,b) ((b&31)+((g&31)<<5)+((r&31)<<10))
// ����5.6.5��ʽ��16λ��ɫֵ
#define _RGB16BIT565(r,g,b) ((b&31)+((g&31)<<6)+((r&31)<<11))
// ����8.8.8��ʽ��24λ��ɫֵ
#define _RGB24BIT(r,g,b) (r+(g<<8)+(b<<16))
// ����A.8.8.8��ʽ��32λ��ɫֵ
#define _RGB32BIT(a,r,g,b) (r+(g<<8)+(b<<16)+(a<<24))

// λ�����
#define SET_BIT(word,bit_flag) ((word)=((word)|(bit_flag)))
#define RESET_BIT(word,bit_flag) ((word)=((word)&(-bit_flag)))

// ��ʼ��һ��direct draw �ṹ����������������ݲ������ֶ� dwSize
#define DDRAW_INIT_STRUCT(ddstruct){ memset(&ddstruct, 0, sizeof(ddstruct)); ddstruct.dwSize = sizeof(ddstruct); }

// ���ڼ����������ʽ�бȽϴ�ͱȽ�С��һ��
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

// ���ڽ�������������ֵ
#define SWAP(a,b,t) {t=a;a=b;b=t}

// ��ѧ��
#define DEG_TO_RAD(ang) ((ang)*PI/180.0)
#define RAD_TO_DEG(rads) ((rads)*180.0/PI)

#define RAND_RANGE(x,y)	((x)+rand()%((y)-(x)+1))

// TYPES /////////////////////////////////

// �����޷�������
typedef unsigned short	USHORT;
typedef unsigned short	WORD;
typedef unsigned char	UCHAR;
typedef unsigned char	BYTE;
typedef unsigned int	QUAD;

// .BMP�ļ�λͼ�����ṹ
typedef struct BITMAP_FILE_TAG
{
	BITMAPFILEHEADER	bitmapfileheader;		// ����λͼͷ�ļ�
	BITMAPINFOHEADER	bitmapinfoheader;		// ������ɫ�����ڵ�������Ϣ
	PALETTEENTRY		palette[256];			// �洢��ɫ��
	UCHAR				*buffer;				// ָ�����ݵ�ָ��
}BITMAP_FILE, *BITMAP_FILE_PTR;

// BOB
typedef struct BOB_TYP
{
	int		state;		
	int		anim_state;
	int		attr;
	float	x, y;				// λ��
	float	xv, yv;				// �ٶ�
	int		width, height;
	int		width_fill;			// ����ǿ�Ʊ���Ŀ��Ϊ8�ı���
	int		bpp;				// ÿ������ռ�õ�λ��
	int		counter_1;
	int		counter_2;
	int		max_count_1;
	int		max_count_2;
	int		varsI[16];			// ���Ϊ16������ջ
	float	varsF[16];			// ���Ϊ16�ĸ�����ջ
	int		curr_frame;
	int		num_frames;			// �ܶ���֡��
	int		curr_animation;		// ��ǰ����������
	int		anim_counter;		// ���ڸ������л���ʱ
	int		anim_index;			// ����Ԫ������
	int		anim_count_max;		// ��֡�����л�����
	int		*animations[MAX_BOB_ANIMATIONS];		// ��������
	LPDIRECTDRAWSURFACE7 images[MAX_BOB_FRAMES];	// λͼͼ�� DD ����
} BOB, BOB_PTR;

// ��λͼͼ��
typedef struct BITMAP_IMAGE_TYP
{
	int state;
	int attr;
	int x, y;
	int width, height;
	int num_bytes;			// ���ֽ���
	int bpp;				// ÿ������ռ�ö���λ
	UCHAR	*buffer;		// λͼ�е�����
}BITMAP_IMAGE,*BITMAP_IMAGE_PTR;

// ����ƽṹ
typedef struct BLINKER_TYP {
	// ���û�����
	int color_index;
	PALETTEENTRY on_color;		// ��ʱ��ɫ��RGBֵ
	PALETTEENTRY off_color;		// ��ʱ��ɫ��RGBֵ
	int on_time;				// ����������֡
	int off_time;				// �س�������֡

	// �ڲ���Ա
	int counter;				// ״̬�л�������
	int state;					// ��Դ״̬��1 ����-1 �أ�0 �ޣ�Ч
}BLINKER,*BLINKER_PTR;

// 2D����
typedef struct VERTEX2DI_TYP
{
	int x, y;		// ��������
	
}VERTEX2DI,*VERTEX2DI_PTR;

typedef struct VERTEX2DF_TYP
{
	float x, y;
}VERTEX2DF,*VERTEX2DF_PTR;

// 2D�����
typedef struct POLYGON2D_TYP
{
	int		state;
	int		num_verts;		// ������
	int		x0, y0;			// ����λ��
	int		xv, yv;			// ��ʼ�ٶ�
	DWORD	color;			// ������PALLETTENTRY
	VERTEX2DF *vlist;		// ָ�򶥵��б��ָ��
}POLYGON2D,*POLYGON2D_PTR;

// ������
typedef struct MATRIX3X3_TYP
{
	union 
	{
		float M[3][3];			// �����鷽ʽ�洢
								// �����к���˳��洢
		struct  
		{
			float M00, M01, M02;
			float M10, M11, M12;
			float M20, M21, M22;
		};	// end explicit names
	};	// end union
}MATRIX3X3,*MATRIX3X3_PTR;

typedef struct MATRIX1X3_TYP
{
	union
	{
		float M[3];
		struct 
		{
			float M00, M01, M02;
		};	// end explicit names

	};// end union
}MATRIX1X3,*MATRIX1X3_PTR;

typedef struct MATIRX3X2_TYP
{
	union 
	{
		float M[3][2];
		struct  
		{
			float M00, M01, M02;
			float M10, M11, M12;
		};// end explicit names
	};// end union
}MATRIX3X2, *MATRIX3X2_PTR;

typedef struct MATRIX1X2_TYP
{
	union  
	{
		float M[1][2];
		struct   
		{
			float M00, M01;
		};	// end struct
	};// end union
}MATRIX1X2,*MATRIX1X2_PTR;


// ����ԭ�� PROTYPES /////////////////////////////////

// DirectDraw functions
int DDraw_Init(int width, int height, int bpp, int windowed = 0);
int DDraw_Shutdown(void);
LPDIRECTDRAWCLIPPER DDraw_Attach_Clipper(LPDIRECTDRAWSURFACE7 lpdds, int num_rects, LPRECT clip_list);
LPDIRECTDRAWSURFACE7 DDraw_Create_Surface(int width, int height, int mem_flags =0 , USHORT color_key_value =0);
int DDraw_Flip(void);
int DDraw_Wait_For_Vsync(void);
int DDraw_Fill_Surface(LPDIRECTDRAWSURFACE7 lpdds, USHORT color, RECT *client = NULL);

UCHAR *DDraw_Lock_Surface(LPDIRECTDRAWSURFACE7 lpdds, USHORT color, RECT *client = NULL);
int DDraw_Unlock_Surface(LPDIRECTDRAWSURFACE7 lpdds);

UCHAR *DDraw_Lock_Primary_Surface(void);
int DDraw_Unlock_Primary_Surface(void);

UCHAR *DDraw_Lock_Back_Surface(void);
int DDraw_Unlock_Back_Surface(void);

// BOB functions
int Create_BOB(BOB_PTR bob, int x, int y, int width, int height,
	int  num_frames, int arrt,
	int mem_flags = 0, USHORT color_key_value = 0, int bpp = 8);

int Clone_BOB(BOB_PTR source, BOB_PTR dest);
int Destroy_BOB(BOB_PTR bob);

int Draw_BOB(BOB_PTR bob, LPDIRECTDRAWSURFACE dest);
int Draw_Scaled_BOB(BOB_PTR bob, LPDIRECTDRAWSURFACE7 dest);

int Draw_BOB16(BOB_PTR bob, LPDIRECTDRAWSURFACE7 dest);
int Draw_Scaled_BOB16(BOB_PTR bob, LPDIRECTDRAWSURFACE7 dest);

int Load_Frame_BOB(BOB_PTR bob, BITMAP_FILE_PTR bitmap,
	int frame, int cx, int cy, int mode);
int Load_Frame_BOB16(BOB_PTR bob, BITMAP_FILE_PTR bitmap, int frame,
	int cx, int cy, int mode);
int Animate_BOB(BOB_PTR bobo);
int Move_BOB(BOB_PTR bob);

int Load_Animation_BOB(BOB_PTR bob, int anim_index,
	int num_frames, int *sequence);
int Set_Pos_BOB(BOB_PTR bob, int x, int y);
int Set_Vel_BOB(BOB_PTR bob, int vx, int vy);
int Set_Anim_Speed_BOB(BOB_PTR bob, int speed); 
int Set_Animation_BOB(BOB_PTR bob, int anim_index);
int Hide_BOB(BOB_PTR bob);
int Show_BOB(BOB_PTR bob);
int Collision_BOBS(BOB_PTR bob1, BOB_PTR bob2);

// utility functions
DWORD Get_Clock(void);
DWORD Start_Clock(void);
DWORD Wait_Clock(DWORD count);

int Collision_Test(int x1, int y1, int w1, int h1,
	int x2, int y2, int w2, int h2);

int Color_Scan(int x1, int y1, int x2, int y2,
	UCHAR scan_start, UCHAR scan_end,
	UCHAR *scan_buffer, int scan_lpitch);

int Color_Scan16(int x1, int y1, int x2, int y2,
	UCHAR scan_start, UCHAR scan_end,
	UCHAR *scan_buffer, int scan_lpitch);

// Graphic functions
int Draw_Clip_Line(int x0, int y0, int x1, int y1, int color, UCHAR *dest_buffer, int lpitch);
int Draw_Clip_Line16(int x0, int y0, int x1, int y1, int color, USHORT *dest_buffer, int lpitch);

int Clip_Line(int &x1, int &y1, int &x2, int &y2);

int Draw_Line(int xo, int yo, int x1, int y1, int color, UCHAR *vb_start, int lpitch);
int Draw_Line16(int xo, int yo, int x1, int y1, int color, UCHAR *vb_start, int lpitch);

int Draw_Pixel(int x, int y, int color, UCHAR *video_buffer, int lpitch);
int Draw_Rectangle(int x1, int y1, int x2, int y2, int color, LPDIRECTDRAWSURFACE7 lpdds);


void HLine(int x1, int x2, int y, int color, UCHAR *vbuffer, int lpitch);
void VLine(int y1, int y2, int x, int color, UCHAR *vbuffer, int lpitch);
void HLine16(int x1, int x2, int y, int color, UCHAR *vbuffer, int lpitch);
void VLine16(int x1, int x2, int y, int color, UCHAR *vbuffer, int lpitch);

// palette functions
int Set_Palette_Entry(int color_index, LPPALETTEENTRY color);
int Get_Palette_Entry(int color_index, LPPALETTEENTRY color);
int Load_Palette_From_File(char *filename, LPPALETTEENTRY palette);
int Save_Palette_To_File(char *filename, LPPALETTEENTRY palette);
int Save_Palette(LPPALETTEENTRY sav_palette);
int Set_Palette(LPPALETTEENTRY set_palette);
int Rotate_Colors(int start_index, int end_index);
int Blink_Colors(int command, BLINKER_PTR new_light, int id);

// simple bitmap iamge functions
int Create_Bitmap(BITMAP_IMAGE_PTR image, int x, int y, int width, int height, int bpp = 8);
int Destroy_Bitmap(BITMAP_IMAGE_PTR image);
int Draw_Bitmap(BITMAP_IMAGE_PTR source_bitmap, UCHAR *dest_buffer, int lpitch, int transparent);
int Draw_Bitmap16(BITMAP_IMAGE_PTR source_bitmap, UCHAR *dest_buffer, int lpitch, int transparent);

int Load_Image_Bitmap(BITMAP_IMAGE_PTR image, BITMAP_FILE_PTR bitmap, int cx, int cy, int mode);
int Load_Image_Bitmap16(BITMAP_IMAGE_PTR image, BITMAP_FILE_PTR bitmap, int cx, int cy, int mode);

int Scroll_Bitmap(BITMAP_IMAGE_PTR image, int dx, int dy = 0);

int Copy_Bitmap(BITMAP_IMAGE_PTR dest_bitmap, int dest_x, int dest_y, BITMAP_IMAGE_PTR source_bitmap, int source_x, int source_y, int width, int height);

int Flip_Bitmap(UCHAR *image, int bytes_per_line, int height);

// Load bitmap file functions
int Load_Bitmap_File(BITMAP_FILE_PTR image, char *filename);
int Unload_Bitmap_File(BITMAP_FILE_PTR image);

// GDI Functions
int Draw_Text_GDI(char *text, int x, int y, COLORREF color, LPDIRECTDRAWSURFACE7 lpdds);
int Draw_Text_GDI(char *text, int x, int y, int color, LPDIRECTDRAWSURFACE7 lpdds);

// error functions
int Open_Error_File(char *filename, FILE *fp_override = NULL);
int Close_Error_File(void);
int Write_Error(char *string, ...);


// 2d,8 or 18 bit triangles rendering functions
void Draw_Top_Tri(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_Bottom_Tri(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);

void Draw_Top_Tri16(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_Bottom_Tri16(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);

void Draw_Top_TriFP(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_Triangle_2D(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_Triangle_2D16(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_TriangleFP_2D(int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);
void Draw_QuadFP_2D(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch);

// ͨ��2D��8/18λ�������Ⱦ�ͱ任����
void Draw_Filled_Polygon2D(POLYGON2D poly, UCHAR *vbuffer, int mempitch);
void Draw_Filled_Polygon2D16(POLYGON2D_PTR poly, UCHAR *vbuffer, int mempitch);

int Translate_Polygon2D(POLYGON2D poly, int dx, int dy);
int Rotate_Polygon2D(POLYGON2D poly, int theta);
int Scale_Polygon2D(POLYGON2D poly, float sx, float sy);

void Build_Sin_Cos_Tables(void);

int Translate_Polygon2D_Mat(POLYGON2D_PTR poly, int dx, int dy);
int Rotate_Polygon2D_Mat(POLYGON2D_PTR poly, int theta);
int Scale_Polygon2D_Mat(POLYGON2D_PTR poly, float sx, float sy);

int Draw_Polygon2D(POLYGON2D_TYP poly, UCHAR *vbuffer, int lpitch);
int Draw_Polygon2D16(POLYGON2D_PTR poly, UCHAR *vbuffer, int lpitch);

// Math functions	
int Fast_Distance_2D(int x, int y);
int Fast_Distance_3D(float x, float y, float z);

// collision detection functions
int Find_Bounding_Box_Poly2D(POLYGON2D_PTR poly, float &min_x, float &max_x, float &min_y, float &max_y);

int Mat_Mul_1X2_3X2(MATRIX1X2_PTR ma, MATRIX3X2_PTR mb, MATRIX1X2_PTR mprod);
int Mat_Mul_1X3_3X3(MATRIX1X3_PTR ma, MATRIX3X3_PTR mb, MATRIX1X3_PTR mprod);
int Mat_Mul_3X3(MATRIX3X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR mprod);

inline int Mat_Init_3X2(MATRIX3X2_PTR ma,
	float m00, float m01,
	float m10, float m11,
	float m20, float m21);

// memory operator functions
inline void Mem_Set_WORD(void *dest, USHORT data, int count);
inline void Mem_Set_QUAD(void *dest, USHORT data, int count);

// INLINE FUNCTIONS ////////////////////////	
inline void Mem_Set_WORD(void *dest, USHORT data, int count)
{
	_asm
	{
		mov edi, dest; edi points to destination memory
		mov ecx, cunt; number of 16 - bits words to move
		mov ax, data;	16 - bit data
		rep stosw;		move data
	}	// end asm
}// end Mem_Set_WORD

inline void Mem_Set_QUAD(void *dest, USHORT data, int count)
{
	_asm
	{
		mov edi, dest;
		mov ecx, count;
		mov eax, data;
		rep stosd;
	}
}// end Mem_Set_QUAD

////////////////////////////////////////////////////////////
inline void Draw_QuadFP_2D(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int color, UCHAR *dest_buffer, int mempitch)
{
	// draws a 2D quadrilateral
	Draw_TriangleFP_2D(x0, y0, x1, y1, x3, y3, color, dest_buffer, mempitch);
	Draw_TriangleFP_2D(x1, y1, x2, y2, x3, y3, color, dest_buffer, mempitch);
}// end Draw_QuadFP_2D

/////////////////////////////////////////////////////////////
inline int Mat_Init_3X2(MATRIX3X2_PTR ma, float m00, float m01, float m10, float m11, float m20, float m21)
{
	ma->M[0][0] = m00; ma->M[0][1] = m01;
	ma->M[1][0] = m10; ma->M[1][1] = m11;
	ma->M[2][0] = m20; ma->M[2][1] = m21;
	return (1);
}// end Mat_Init_3X2

// ȫ�ֱ���///////////////////////////////
FILE *fp_error;							// general error file
char error_filename[80];				// error file name

//////////////////////
LPDIRECTDRAW7 lpdd;						// drect draw object
LPDIRECTDRAWSURFACE7	lpddsprimary;	// dd������
LPDIRECTDRAWSURFACE7	lpddsback;		// dd������
LPDIRECTDRAWPALETTE		lpddpal;		// ָ��dd��ɫ���ָ��
LPDIRECTDRAWCLIPPER		lpddcliper;		// ����ָ�򸱻����dd�ü�����
LPDIRECTDRAWCLIPPER		lpddcliperwin;	// ���ڴ��ڵ�dd�ü�����

PALETTEENTRY	palette[256];			// ��ɫ��
PALETTEENTRY	sav_palette[256];		// ���ڱ����ɫ��

DDSURFACEDESC2	ddsd;					// dd surface�������ṹ
DDBLTFX			ddbltfx;				// �������
DDSCAPS2		ddscaps;				// dd surface���ܽṹ
HRESULT			ddrval;					// dd���÷��صĽ��
UCHAR			*primary_buffer;		// ����Ƶ����
UCHAR			*back_buffer;			// ����Ƶ����
int				primary_lpitch;			// ����Ƶ������ �п��
int				back_lpitch;			// ����Ƶ������ �п��
BITMAP_FILE		bitmap8bit;
BITMAP_FILE		bitmap16bit;
BITMAP_FILE		bitmap24bit;

DWORD			start_clock_count;		// ���ڼ�ʱ
int				windowed_mode;			// ��¼dd�Ƿ��ڴ���ģʽ


// ��������ü�ʱʹ�õĲü�����
int				min_clip_x,
				max_clip_x,
				min_clip_y,
				max_clip_y;

// ����DD_Init()ʱ��������Щ������ֵ
int				screen_width,
				screen_height,
				screen_bpp,
				screen_windowed;
int				dd_pixel_format;		// Ĭ�����ظ�ʽ

int				window_client_x0;		// �洢dd����ģʽʱ���ͻ��������Ͻǵ�λ��
int				window_client_y0;

// ���ڴ洢���ұ�
float			cos_look[360];
float			sin_look[360];

// ָ��RGB16��ɫ���ɺ�����ָ�룬�����������ֱ�����5.5.5��5.6.5��ʽ����ɫֵ
USHORT(*RGB16Bit)(int r, int g, int b);

USHORT RGB16Bit565(int r, int g, int b);
USHORT RGB16Bit555(int r, int g, int b);

int debug_total_polys_per_frame;
int debug_polys_list_per_frame;
int debug_polys_clipped_per_frame;
int debug_polys_rendered_per_frame;
int debug_backfaces_removed_per_frame;
int debug_objects_removed_per_frame;
int debug_total_transformations_per_frame;

#endif
