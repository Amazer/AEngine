#ifndef T3DLIB3
#define T3DLIB3

#define DM_NUM_SEGMENTS 64			// 可存储到内存中midi节数

// midi object state 变量
#define MIDI_NULL		0			// 未加载
#define	MIDI_LOADED		1
#define	MIDI_PLAYING	2			// 已加载，并且正在播放
#define MIDI_STOPPED	3			// 已加载，但是没有播放

#define MAX_SOUNDS		256			// 系统可同时加载的最大声音数

// 数字声音对象状态 变量
#define	SOUND_NULL		0
#define SOUND_LOADED	1
#define SOUND_PLAYING	2
#define	SOUND_STOPPED	3

// 微软分贝
#define DSVOLUME_TO_DB(volume) ((DWORD)(-30*(100-volume)))

// 从多字节格式转换微Unicode
#define MULTI_TO_WIDE(x,y) MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,y,-1,x,_MAX_PATH)

typedef struct pcm_sound_typ
{
	LPDIRECTSOUNDBUFFER			dsbuffer;			// directsound缓冲区
	int							state;
	int							rate;				// 播放速度
	int							size;				
	int							id;
}pcm_sound,*pcm_sound_ptr;

typedef struct DMUSIC_MIDI_TYP
{
	IDirectMusicSegment			*dm_segment;			// directmusic节
	IDirectMusicSegmentState	*dm_segstate;		
	int							id;
	int							state;		
}DMUSIC_MIDI,*DMUSIC_MIDI_PTR;


// DirectSound 全局变量

LPDIRECTSOUND				lpds;			// directsound接口指针
DSBUFFERDESC				dsbd;			// directsound描述参数
DSCAPS						dscaps;			// caps
HRESULT						dsresult;			
DSBCAPS						dsbcaps;		// directsound缓冲区caps

pcm_sound					sound_fx[MAX_SOUNDS];		// 声音缓冲区数组
WAVEFORMATEX				pcmwf;						// 通用波形式结构

// DirectMusic 全局变量
IDirectMusicPerformance		*dm_perf;		// directmusic性能管理器
IDirectMusicLoader			*dm_loader;		

// 用于存储所有的directmusic midi队形
DMUSIC_MIDI					dm_midi[DM_NUM_SEGMENTS];
int							dm_active_id;				// 当前处于活动状态的midi节


// DirectSound 函数原型
int DSound_Init(void);
int DSound_Shutdown(void);
int DSound_Load_WAV(char *filename);
int DSound_Replicate_Sound(int source_id);			// 要复制的声音的ID
int DSound_Play_Sound(int id,	// 要播放的声音的ID
	int flags = 0,				// 0或DSBPLAY_LOOPING
	int volume = 0,
	int rate = 0,
	int pan = 0);

int DSound_Stop_Sound(int id);
int DSound_Stop_All_Sounds(void);

int DSound_Delete_Sound(int id);
int DSound_Delete_All_Sounds(void);

int DSound_Status_Sound(int id);
int DSound_Set_Sound_Volume(int id, int vol);

// freq 播放频率(0,100000)
int DSound_Set_Sound_Freq(int id, int freq);

// pan 相对强度(-10000,10000)
int DSound_Set_Sound_Pan(int id, int pan);


// DirectMusic 函数原型
int DMusic_Init(void);
int DMusic_Shutdown(void);

int DMusic_Load_MIDI(char *filename);
int DMusic_Delete_MIDI(int id);
int DMusic_Delete_All_MIDI(void);
int DMusic_Play(int id);
int DMusic_Stop(int id);
int DMusic_State_MIDI(int id);

#endif
