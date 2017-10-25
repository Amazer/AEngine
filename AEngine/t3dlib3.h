#ifndef T3DLIB3
#define T3DLIB3

#define DM_NUM_SEGMENTS 64			// �ɴ洢���ڴ���midi����

// midi object state ����
#define MIDI_NULL		0			// δ����
#define	MIDI_LOADED		1
#define	MIDI_PLAYING	2			// �Ѽ��أ��������ڲ���
#define MIDI_STOPPED	3			// �Ѽ��أ�����û�в���

#define MAX_SOUNDS		256			// ϵͳ��ͬʱ���ص����������

// ������������״̬ ����
#define	SOUND_NULL		0
#define SOUND_LOADED	1
#define SOUND_PLAYING	2
#define	SOUND_STOPPED	3

// ΢��ֱ�
#define DSVOLUME_TO_DB(volume) ((DWORD)(-30*(100-volume)))

// �Ӷ��ֽڸ�ʽת��΢Unicode
#define MULTI_TO_WIDE(x,y) MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,y,-1,x,_MAX_PATH)

typedef struct pcm_sound_typ
{
	LPDIRECTSOUNDBUFFER			dsbuffer;			// directsound������
	int							state;
	int							rate;				// �����ٶ�
	int							size;				
	int							id;
}pcm_sound,*pcm_sound_ptr;

typedef struct DMUSIC_MIDI_TYP
{
	IDirectMusicSegment			*dm_segment;			// directmusic��
	IDirectMusicSegmentState	*dm_segstate;		
	int							id;
	int							state;		
}DMUSIC_MIDI,*DMUSIC_MIDI_PTR;


// DirectSound ȫ�ֱ���

LPDIRECTSOUND				lpds;			// directsound�ӿ�ָ��
DSBUFFERDESC				dsbd;			// directsound��������
DSCAPS						dscaps;			// caps
HRESULT						dsresult;			
DSBCAPS						dsbcaps;		// directsound������caps

pcm_sound					sound_fx[MAX_SOUNDS];		// ��������������
WAVEFORMATEX				pcmwf;						// ͨ�ò���ʽ�ṹ

// DirectMusic ȫ�ֱ���
IDirectMusicPerformance		*dm_perf;		// directmusic���ܹ�����
IDirectMusicLoader			*dm_loader;		

// ���ڴ洢���е�directmusic midi����
DMUSIC_MIDI					dm_midi[DM_NUM_SEGMENTS];
int							dm_active_id;				// ��ǰ���ڻ״̬��midi��


// DirectSound ����ԭ��
int DSound_Init(void);
int DSound_Shutdown(void);
int DSound_Load_WAV(char *filename);
int DSound_Replicate_Sound(int source_id);			// Ҫ���Ƶ�������ID
int DSound_Play_Sound(int id,	// Ҫ���ŵ�������ID
	int flags = 0,				// 0��DSBPLAY_LOOPING
	int volume = 0,
	int rate = 0,
	int pan = 0);

int DSound_Stop_Sound(int id);
int DSound_Stop_All_Sounds(void);

int DSound_Delete_Sound(int id);
int DSound_Delete_All_Sounds(void);

int DSound_Status_Sound(int id);
int DSound_Set_Sound_Volume(int id, int vol);

// freq ����Ƶ��(0,100000)
int DSound_Set_Sound_Freq(int id, int freq);

// pan ���ǿ��(-10000,10000)
int DSound_Set_Sound_Pan(int id, int pan);


// DirectMusic ����ԭ��
int DMusic_Init(void);
int DMusic_Shutdown(void);

int DMusic_Load_MIDI(char *filename);
int DMusic_Delete_MIDI(int id);
int DMusic_Delete_All_MIDI(void);
int DMusic_Play(int id);
int DMusic_Stop(int id);
int DMusic_State_MIDI(int id);

#endif
