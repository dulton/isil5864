#ifndef __ISIL_FM_PLAY_H__
#define __ISIL_FM_PLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include "config.h"
#include "isil_fm_file_allocate.h"
#include "isil_fm_h264.h"

#define PLAY_MAX_CHANNEL  PER_CHIP_MAX_CHAN_NUM
/*����ͬʱ���ŵĿͻ��������Ŀ*/
#define MAX_PLAYER_NUM  PLAY_MAX_CHANNEL

/*play root dir path len*/
#define PLAY_ROOT_DIR_MAX_LEN (32)

#define FILE_FD_BASE 256


#define NEW_PB_API
/*file play*/
/*MSG_TYPE_FM_SEARCH*/
//MsgType : 	MSG_TYPE_FM_SEARCH
//pMsg	   :	MSG_FM_SEARCH
typedef struct
{
	unsigned 	char	ucType;//rec type;if 0,all type
	S_REC_DATE_TIME     stStart;//must
	S_REC_DATE_TIME     stEnd;//must
	unsigned char	    ucDeviceName[32];
	unsigned char       ucChannel;//start from 1~N,must,if 0xff, all channel
	char		    	ucReserved[45];
    int                 iFd;
}MSG_FM_SEARCH;

/*MSG_TYPE_FM_SEARCH_RESULT*/
//MsgType : 	MSG_TYPE_FM_SEARCH_RESULT
//pMsg	   :	MSG_FM_SEARCH_RESULT

typedef struct
{
    unsigned long	    lFlag;				/* У���־ 0x0FFEABCD*/
	unsigned char		ucType;
	unsigned char		ucChNumber;		// ͨ����0~N
	char				cURL[30];		// �豸��ַ
	char				cDeviceName[32] ; // �豸����
    char			    cChannelName[32];// ͨ������
	S_REC_TIME      	stStart;// ¼������ʱ���ͼƬץ��ʱ��
	unsigned char       ucFileExName[4] ;
	char            	cFilePath[64];
}MSG_FM_SEARCH_RESULT_1;


typedef struct
{
	int					   s32MsgNum;
	MSG_FM_SEARCH_RESULT_1 ResultEntry[0];
}MSG_FM_SEARCH_RESULT;

/*MSG_TYPE_FM_REMOTE_OPEN*/
//MsgType : MSG_TYPE_FM_REMOTE_OPEN
//pMsg: MSG_FM_REMOTE_OPEN
typedef struct
{
    char    cFileNames[10][64]; //file path
    int     lFileCount; // file count , <= 10
    unsigned int reserve;//�Է�session��ַ
    int (*callback)( void*arg1, int type,void* arg2);
}MSG_FM_REMOTE_OPEN;

/*MSG_TYPE_FM_REMOTE_GET_FILEINFO*/
//MsgType : MSG_TYPE_FM_REMOTE_GET_FILEINFO
//pMsg: MSG_FM_REMOTE_OPERATOR

typedef struct
{
    unsigned long    ulTimeLength;
    unsigned long    ulBeginTimeStamp;
	unsigned long    ulEndTimeStamp;
    unsigned long    ulFileSize;
    unsigned long    ulMaxKeyFrameInterval;
    unsigned long    ulFileFd;
}MSG_FM_REMOTE_FILEINFO;


typedef struct
{
    union _FM_PLAY_CTL
    {
        unsigned long           lTimePosition;
        unsigned long           lFilePosition;
        float                   fPercent;
        char                    cLoop;
        char                    cDirection;
        char                    cKeyFrame;
        unsigned char           cReserve;

    	struct _stReadParam
    	{
    		unsigned long lReadLength; //ȡ���ݳ���
    		unsigned long lReadDataID; //����ش���ID������ʶ���Ƿ�Ϊ��ǰ��ȡ���ݿ� = NET_PACKET_HEAD.lFrameID
    	}xReadParam;

    	struct _stGetFramesParam
    	{
    		long lFrameCount;   //֡��
    		long lFrameDelay;	//֡���ӳ�(����)
    	}xFrameParam;
    }FM_PLAY_CTL;

    unsigned int uiPlayFd;
}MSG_FM_REMOTE_OPERATOR;


typedef struct
{
    unsigned long     ulTimePosition;
}MSG_FM_REMOTE_GET_CURTIME_ACK;



/*player cfg,set player config*/
typedef struct
{
    unsigned long   lTimePosition;  // set will play timeposition
    float           fPercent;       // seek position
    char            cLoop;          // loop play
    char            cDirection;     // play order
    char            cKeyFrame;      // only play key frame or not
    char            cPause;			//0:play, 1: pause
    long            lFrameCount;    // required how many frames
    long            lFrameDelay;    // interval between sending frame
    unsigned long   ulOffset;
    int             iGopNum;        //��¼��һ�ν�Ҫ�����ļ���GopNum�Ĳ���λ��
    int             iNalNum;        //��¼��һ�ν�Ҫ�����ļ���Nalλ��
    #if 0
    int             iSaveFlag;      //save current gop and nal
    int             iSave_gop;      
    int             iSave_nal;
    #endif
}ISIL_FM_PLAY_CFG;

/*rec current playing status*/
typedef struct
{
    int                 lFileCount; // file count , <= 10
    unsigned long       ulTimeBegin[10];  //����Ҫ�򿪵�ÿ���ļ��Ŀ�ʼʱ��
    unsigned long       ulTimeEnd[10];  //����Ҫ�򿪵�ÿ���ļ��Ľ���ʱ��
    int                 fileindexfd;//index00.bin's fd
    int                 datafd[10];//isilxx.data's fd
    int                 dataindexfd[10];//xx.bin's fd
    unsigned int        datastart[10];
    unsigned int        recindexstart[10];
    int                 startGopNum[10];//save gopnum of the start point
}ISIL_FM_PLAY_OPEN_INFO;

typedef struct
{
    unsigned long   lTimePosition;  // rec current playing timeposition
    char            cLoop;          // rec current loop status
    char            cDirection;     // rec current play order
    char            cKeyFrame;      // rec current whether playing keyframe or not
    char            cFrameBack;//֡�˱�ʶ
    long            lFrameCount;    // required how many frames
    long            lFrameDelay;    // interval between sending frame
    unsigned long   ulOffset;
    int             iPlayingID;//����ļ�����ʱ����¼��ǰ���ŵ����ĸ��ļ�
    int             iGopNum;//��¼��ǰ���ڲ����ļ���GopNum�Ĳ���λ��
    int             iNalNum;//��¼���ڲ����ļ���Nalλ��
}ISIL_FM_PLAY_STATUS;

/*����ʱ�����ͻ��˵��ļ�·��ת��ΪFM�ڲ������ݽṹ*/
typedef struct
{
    unsigned int        u32FileID;
    unsigned int        u32Channel;
    S_REC_DATE_TIME     stStartDT;
}ISIL_FM_PLAY_CONVERT_PATH;

/*�ļ��������ݽṹ*/
typedef struct
{
    unsigned int             u32PlayerFd;//ÿ���ͻ���fd
    ISIL_FM_PLAY_CFG         PlayerCfg;//���������ò���,��ѭ�����ŵȵ�
    ISIL_FM_PLAY_STATUS      PlayerStatus;//������״̬��¼,�統ǰ����λ�õ�
    MSG_FM_REMOTE_FILEINFO   stFileInfo;// current playing file base info
    ISIL_FM_PLAY_OPEN_INFO   stOpenInfo;// open file info
}ISIL_FM_PLAY_PLAYER;

/*�ļ�����ʱԭʼ���ݽṹ*/
typedef struct
{
    int             s32FrameCnt;
    stDriverFrame   Frame[0];
}ISIL_FM_PLAY_FrameData;



/*send frame data struct*/
//========================================================
//ÿ֡����:
//ISIL_FRAME_HEAD + DATA(a/v)
//========================================================
#define	ISIL_FRAME_HEAD_FLAG	0x71010000

enum _eISIL_FRAME_TYPE
{
	ISIL_FRAME_TYPE_A      = 0x01,  //audio
	ISIL_FRAME_TYPE_PIC    = 0x11,  //mjpeg
	ISIL_FRAME_TYPE_MAIN_I = 0x21,
	ISIL_FRAME_TYPE_MAIN_P = 0x22,
	ISIL_FRAME_TYPE_MAIN_B = 0x23,
	ISIL_FRAME_TYPE_SUB_I  = 0x31,  //sub video
	ISIL_FRAME_TYPE_SUB_P  = 0x32,
	ISIL_FRAME_TYPE_SUB_B  = 0x33,
    ISIL_FRAME_TYPE_USER_A = 0x50,  //
	ISIL_FRAME_TYPE_USER_B = 0x60,
};
/*
enum _eISIL_FRAME_TYPE
{
    ISIL_FRAME_TYPE_A      = 0x01,  //��Ƶ��
    ISIL_FRAME_TYPE_PIC    = 0x11,  //ͼƬ��eg.mjpeg....
    ISIL_FRAME_TYPE_MAIN_I = 0x21,  //����Ƶ
    ISIL_FRAME_TYPE_MAIN_P = 0x22,
    ISIL_FRAME_TYPE_MAIN_B = 0x23,
    ISIL_FRAME_TYPE_SUB_I  = 0x31,  //����Ƶ
    ISIL_FRAME_TYPE_SUB_P  = 0x32,
    ISIL_FRAME_TYPE_SUB_B  = 0x33,
    ISIL_FRAME_TYPE_USER_A = 0x50,  //
    ISIL_FRAME_TYPE_USER_B = 0x60,
};
*/

enum  _eISIL_VIDEO_ENCODE_TYPE
{
	ISIL_VENCODE_NONE   = 0x00,
	ISIL_VENCODE_H264   =  0x01 ,
    ISIL_VENCODE_MJPEG  = 0x41
};

/*
enum  _eISIL_VIDEO_ENCODE_TYPE
{
    ISIL_VENCODE_NONE   = 0x00,
    ISIL_VENCODE_H264   = 0x01,
    ISIL_VENCODE_MJPEG  = 0x81
};
*/

enum  _eISIL_AUDIO_ENCODE_TYPE
{
	ISIL_AENCODE_NONE   = 0x80,
	ISIL_AENCODE_PCM    = 0x81,
	ISIL_AENCODE_ALAW   = 0x82,
	ISIL_AENCODE_ULAW   = 0x83,
	ISIL_AENCODE_ADPCM  = 0x84,
    ISIL_AENCODE_IMAADPCM = 0x85
};

/*
enum  _eISIL_AUDIO_ENCODE_TYPE
{
ISIL_AENCODE_NONE   = 0x00,
ISIL_AENCODE_PCM    = 0x01,
ISIL_AENCODE_ALAW   = 0x02,
ISIL_AENCODE_ULAW   = 0x03,
ISIL_AENCODE_ADPCM  = 0x04,
ISIL_AENCODE_IMAADPCM = 0x05
};
*/

//========================================================
//ÿ֡���ݿ��ܰ������NAL
//DATA(a/v) = (ISIL_NAL_HEAD+NAL)+.....
//========================================================

//NAL����ͷ
typedef struct
{
	unsigned long cNalType:8;     //�� ISIL_File_Def.h �ļ��� eISIL_NAL_TYPE
	unsigned long lNalSize:24;
    unsigned char pNalData[0];  //�������
}ISIL_NAL_HEAD;

//����Ƶ����֡ͷ
typedef struct
{
	unsigned long	lFrameFlag;			//֡ͷ��ʶ
	unsigned short	nFrameType;			//����֡��־ eFrameType
	unsigned short  nHeadSize;          //֡ͷ��С
	unsigned long	lFrameSize;			//֡���ݴ�С(data)
    unsigned long   lTimeStamp;			//�Ժ���Ϊ��λ��ʱ���(��������Χ���0��ʼ)
	unsigned long   lEncodeType;
	unsigned long   lReserve;
    ISIL_NAL_HEAD    stFrameNalHead[0];
}ISIL_FRAME_DATA;

typedef struct
{
    unsigned long     lTimePosition; // frame time
    unsigned long     lDisplay; 	 // �Ƿ���ʾ��0����ʾ
    ISIL_FRAME_DATA	  stFrameData;	 // frame data
}MSG_FM_REMOTE_SEND_FRAME_DATA;

#ifdef NEW_PB_API
typedef struct
{
    eframe_type naltype;//nal type
    size_t      nallen;//nal len
}PB_NAL_INFO;

typedef struct
{
    int     nalcnt;//nal count
    int     fd;//data file's fd
    size_t  offset;//offset in file
    size_t  len;//len
    unsigned int ts;//timestap
    PB_NAL_INFO nal[3];
}PB_FRAME_INFO;

#endif


//ISIL_FM_PLAY_STATUS RecPlayingStatus;
//ISIL_FM_PLAY_CFG RecPlayingCfg;
extern ISIL_FM_PLAY_PLAYER  Player[MAX_PLAYER_NUM];//��¼Զ�̲����������



/*�����ļ���ز���*/
extern int ISIL_FM_SEACH_SearchFile(MSG_FM_SEARCH* search_condition, void *buff);

extern int ISIL_FM_PLAY_Open(unsigned int u32id, MSG_FM_REMOTE_OPEN stOpen, MSG_FM_REMOTE_FILEINFO *stFileInfo);
extern MSG_FM_REMOTE_FILEINFO* ISIL_FM_PLAY_GetFileInfo(unsigned int u32id);

/*set ts len, end_ts - start_ts, for gui or pc*/
extern int ISIL_FM_PLAY_SetTSLen(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern long ISIL_FM_PLAY_GetTSLen(unsigned int u32id);

/*set really timestamp, as same as save file, for driver request frame*/
extern int ISIL_FM_PLAY_SetTS(unsigned int u32id, unsigned long ts);

extern int ISIL_FM_PLAY_SetSeek(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern int ISIL_FM_PLAY_SetLoop(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern int ISIL_FM_PLAY_SetDirection(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern int ISIL_FM_PLAY_SetKeyFrame(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern int ISIL_FM_PLAY_SetFrameCount(unsigned int u32id, MSG_FM_REMOTE_OPERATOR FileOperate);
extern int ISIL_FM_PLAY_GetFrameDelay(unsigned int u32id);
extern int ISIL_FM_PLAY_GetFrameCnt(unsigned int u32id);
extern int ISIL_FM_PLAY_SetPause(unsigned int u32id);
extern int ISIL_FM_PLAY_SetPlay(unsigned int u32id);
extern int ISIL_FM_PLAY_SetStop(unsigned int u32id);


extern int ISIL_FM_PLAY_ReadFile(void* argv, unsigned int u32id, int *CallBackRetValue);

extern int ISIL_FM_PLAY_InitPlayer(int s32Num);
extern int ISIL_FM_PLAY_InitAllPlayer();
extern int ISIL_FM_PLAY_ClearPlayerByFd(unsigned int u32id);

extern int ISIL_FM_PLAY_SearchPlayerByFd(unsigned int u32id);
extern int ISIL_FM_PLAY_GetPlayerIndex(unsigned int u32id);
extern int ISIL_FM_PLAY_SetPlayDir(char *RootDir);

extern int ISIL_FM_PLAY_GetCfgFrameCnt(unsigned int u32id);
extern int ISIL_FM_PLAY_ClearCfgFrameCnt(unsigned int u32id);

extern int ISIL_FM_PLAY_GetPlayedFrameCnt(unsigned int u32id);
extern int ISIL_FM_PLAY_ClearPlayedFrameCnt(unsigned int u32id);

extern int ISIL_FM_PLAY_ParsingFile(unsigned int winid, PB_FRAME_INFO* frameinfo);

extern int ISIL_FM_PLAY_GetFileData(int filefd, size_t offset, size_t datalen, void* buff);

#ifdef __cplusplus
   }
#endif

#endif


