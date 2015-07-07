#ifndef _ISIL_MESSAGE_STRUCT_H_
#define _ISIL_MESSAGE_STRUCT_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include "msg_config.h"
#include "isil_type.h"
#include "isil_common.h"
#include "isil_encoder.h"
#include "isil_decoder.h"
#include "isil_vi.h"
#include "isil_codec_chip_ctl.h"
#include "isil_test_sdk.h"


/*define messages type*/
#define MSG_TAG						0xffff
#define MSG_TYPE_ASK_LOGIN			0xA000	/* �����¼*/
#define MSG_TYPE_ACK_LOGIN			0xA001  /* Ӧ���¼*/

#define MSG_TYPE_ASK_REALPLAY		0xA100	/* ����ʵʱ����*/
#define MSG_TYPE_ACK_REALPLAY		0xA101	/* ��Ӧʵʱ����*/


#define MSG_TYPE_ASK_TALK 			0xA200	/* ���������Ի�*/
#define MSG_TYPE_ACK_TALK 			0xA201	/* Ӧ�������Ի�*/

#define MSG_TYPE_ASK_BROADCAST		0xA300	/* ����㲥*/
#define MSG_TYPE_ACK_BROADCAST		0xA301	/* Ӧ��㲥*/

#define MSG_TYPE_ASK_AUTOSEARCH 	0xA400	/* �����Զ������豸*/
#define MSG_TYPE_ACK_AUTOSEARCH 	0xA400	/* Ӧ���Զ������豸*/

#define MSG_TYPE_PCTODEV_REQ		0xA002	/* PC->�豸����*/
#define MSG_TYPE_DEVTOPC_RET		0xA003	/* �豸�ظ�PC */
#define MSG_TYPE_DEVTOPC_REQ		0xA004	/* �豸-> PC����*/
#define MSG_TYPE_PCTODEV_RET		0xA005	/* PC �ظ��豸*/

#define MSG_TYPE_FILE               0xA500  /*�ط��ļ���Ϣ*/

#define MSG_TYPE_GETCFG             0xC001  /* ��ȡ�豸����*/
#define MSG_TYPE_SETCFG             0xC002  /* �����豸����*/
#define MSG_TYPE_FILE_ABOUT         0xC003  /*�ļ�����ز������������򿪡��رյ�*/


/*define information element type*/

/*******************IE type class begin *****************/

/*******************type class 0  **********************/

#define IE_TYPE_ASK_LOGIN			0xA000	/* �����¼*/
#define IE_TYPE_ACK_LOGIN			0xA001  /* Ӧ���¼*/
#define IE_TYPE_ASK_REALPLAY		0xA100	/* ����ʵʱ����*/
#define IE_TYPE_ACK_REALPLAY		0xA101	/* ��Ӧʵʱ����*/
#define IE_TYPE_ASK_TALK 			0xA200	/* ���������Ի�*/
#define IE_TYPE_ACK_TALK 			0xA201	/* Ӧ�������Ի�*/
#define IE_TYPE_ASK_BROADCAST		0xA300	/* ����㲥*/
#define IE_TYPE_ACK_BROADCAST		0xA301	/* Ӧ��㲥*/
#define IE_TYPE_ASK_AUTOSEARCH 		0xA400	/* �����Զ������豸*/
#define IE_TYPE_ACK_AUTOSEARCH 		0xA401	/* Ӧ���Զ������豸*/
#define IE_TYPE_PCTODEV_REQ			0xA002	/* PC->�豸����*/
#define IE_TYPE_DEVTOPC_RET			0xA003	/* �豸�ظ�PC */
#define IE_TYPE_DEVTOPC_REQ			0xA004	/* �豸-> PC����*/
#define IE_TYPE_PCTODEV_RET			0xA005	/* PC �ظ��豸*/

/*******************type class 1  **********************/

#define	IE_TYPE_SYSTEM_REBOOT			1000
#define	IE_TYPE_SYSTEM_SHUTDOWN			1002


/*******************type class 2 **********************/

#define	IE_TYPE_GET_DEVICECFG			1100
#define	IE_TYPE_SET_DEVICECFG			1102
#define	IE_TYPE_GET_DEVICEBASECFG		1104
#define	IE_TYPE_SET_DEVICEBASECFG		1106
#define	IE_TYPE_GET_NETCFG				1108
#define	IE_TYPE_SET_NETCFG				1110
#define	IE_TYPE_GET_USERCFG				1112
#define	IE_TYPE_SET_USERCFG				1114
#define IE_TYPE_GET_USERGROUPCFG		1116	  /*��ȡ�û������*/
#define IE_TYPE_SET_USERGROUPCFG		1118	  /*�����û������*/

#define	IE_TYPE_GET_PTZPROTOCOL			1120
#define IE_TYPE_GET_DEVICEPOWER			1122
#define ISIL_GET_USERPOWER_LEVEL	        1124	 //��ȡ�û�Ȩ�ޣ��磺admin ��ȡ user Ȩ��

#define IE_TYPE_GET_CHANNEL_ENCPRI      1126   //��ȡ����ͨ�������ȼ���
#define IE_TYPE_GET_CHANNEL_REALFPS     1128   //��ȡ����ͨ����ǰ��ʵ��֡����

#define IE_TYPE_GET_MJPEGCFG            1240     //��ȡͨ��MJPEG����
#define IE_TYPE_SET_MJPEGCFG            1242     //����ͨ��MJPEG����


/*******************type class 3 **********************/

#define IE_TYPE_GET_STREAMCFG			1200
#define IE_TYPE_SET_STREAMCFG			1202
#define IE_TYPE_GET_VIDEOMOTIONCFG		1204
#define IE_TYPE_SET_VIDEOMOTIONCFG		1206
#define IE_TYPE_GET_VIDEOSHELTERCFG		1208
#define IE_TYPE_SET_VIDEOSHELTERCFG		1210
#define IE_TYPE_GET_VIDEOMASKCFG		1212
#define IE_TYPE_SET_VIDEOMASKCFG		1214
#define IE_TYPE_GET_VIDEOLOSTCFG		1216
#define IE_TYPE_SET_VIDEOLOSTCFG    	1218
#define IE_TYPE_GET_VIDEOSIGNALCFG     	1220
#define IE_TYPE_SET_VIDEOSIGNALCFG      1222
#define IE_TYPE_GET_ENCODECFG   		1224
#define IE_TYPE_SET_ENCODECFG    		1226
#define IE_TYPE_GET_VIDEOOVERLAYCFG		1228
#define IE_TYPE_SET_VIDEOOVERLAYCFG 	1230

/*******************type class 4 **********************/
/*
#define IE_TYPE_GET_ALARMINCFG			1400
#define IE_TYPE_SET_ALARMINCFG			1402
#define IE_TYPE_GET_OUTCTRLCFG			1404
#define IE_TYPE_SET_OUTCTRLCFG			1406
*/
#define IE_TYPE_GET_ALARMINCFG	        1400     //��ȡ�����������
#define IE_TYPE_SET_ALARMINCFG          1402	 //���ñ����������
#define IE_TYPE_GET_ALARMINCFG_ALL      1404     //��ȡ��������������������ݷ��ش�С/sizeof()ȷ������
#define IE_TYPE_SET_ALARMINCFG_ALL      1406     //���ñ��������������������[��С/sizeof()]ȷ������
#define IE_TYPE_GET_OUTCTRLCFG	        1408     //��ȡ������Ʋ���
#define IE_TYPE_SET_OUTCTRLCFG          1410	 //����������Ʋ���
#define IE_TYPE_GET_OUTCTRLCFG_ALL	    1412     //��ȡ������Ʋ��������ݷ���[��С/sizeof()]ȷ������
#define IE_TYPE_SET_OUTCTRLCFG_ALL      1414	 //����������Ʋ���������[��С/sizeof()]ȷ������
#define IE_TYPE_GET_OUTCTRLCTRL         1416	 //�����������״̬
#define IE_TYPE_SET_OUTCTRLCTRL         1418	 //�����������״̬
#define IE_TYPE_GET_OUTCTRLCTRL_ALL     1420	 //���������������״̬,����[��С/sizeof()]ȷ������
#define IE_TYPE_SET_OUTCTRLCTRL_ALL     1422	 //���������������״̬,����[��С/sizeof()]ȷ������


/*******************type class 5 **********************/

#define IE_TYPE_SET_PTZCTRL				1500
#define IE_TYPE_GET_COMMCFG				1502
#define IE_TYPE_SET_COMMCFG				1504
#define IE_TYPE_SET_COMM_SENDDATA		1506
#define IE_TYPE_SET_COMM_STARTCAPDATA	1508
#define IE_TYPE_SET_COMM_STOPCAPDATA	1510
#define IE_TYPE_GET_PTZCFG				1512
#define IE_TYPE_SET_PTZCFG				1514
#define IE_TYPE_GET_PTZPRESETCFG		1516
#define IE_TYPE_SET_PTZPRESETCFG		1518
#define IE_TYPE_SET_SHOOTIMAGE			1520
#define IE_TYPE_SET_MANUALSTARTRECORD   1522     /*�ֶ���������¼��*/
#define IE_TYPE_SET_MANUALSTOPRECORD    1524     /*�ֶ�����ֹͣ¼��*/

#define IE_TYPE_SET_UPDATE              1600     /*�豸����*/

#define IE_TYPE_GET_REALPLAYINFO        1700     /*��ȡ����ʵʱ����Ϣ���˿ڣ����ӷ�ʽ��*/
#define IE_TYPE_GET_TALKINFO            1702     /*��ȡ�����Խ���Ϣ���˿ڣ����ӷ�ʽ��*/
#define IE_TYPE_GET_BROADCASTINFO       1704     /*��ȡ�����㲥��Ϣ���˿ڣ����ӷ�ʽ��*/
#define IE_TYPE_GET_PLAYBACKINFO        1706     /*��ȡ�����ط���Ϣ���˿ڣ����ӷ�ʽ��*/


/*******************type class 6**********************/

#define IE_TYPE_DEVTOC_ALARMSTATUS		1900
#define IE_TYPE_DEVTOC_PARAMCHANGED		1902

/*******************type class 7**********************/

#define IE_TYPE_GET_ALARMLINKAGECFG    	1920
#define IE_TYPE_SET_ALARMLINKAGECFG     1922
#define IE_TYPE_GET_ALARMSTATUS         1924
#define IE_TYPE_SET_ALARMSTATUS   		1926
#define IE_TYPE_GET_ALARMDETAILSTATUS 	1928

/*******************IE type class end*****************/

#define IE_TYPE_FILE_OPEN	            2000
#define IE_TYPE_FILE_CLOSE	            2002
#define IE_TYPE_FILE_GET_FILEINFO		2004
#define IE_TYPE_FILE_GET_POSITION		2006
#define IE_TYPE_FILE_SET_POSITION		2008
#define IE_TYPE_FILE_SET_PERCENT		2010
#define IE_TYPE_FILE_SET_LOOP			2012
#define IE_TYPE_FILE_SET_READ_ORDER		2014
#define IE_TYPE_FILE_SET_READ_KEYFRAME	2016
#define IE_TYPE_FILE_GET_FRAMES			2018

#define IE_TYPE_FILE_READ_SEEKPOS		2030
#define IE_TYPE_FILE_READ			    2032

#define IE_TYPE_FILE_SEARCH				2040
#define IE_TYPE_NET_ALIVE               3000

#define IE_TYPE_NET_CLOSE               4000

/*��IDE/USBר��*/
#define IE_TYPE_FILE_AUTO_START_REC			0xB000

/*�Զ������豸�˿�*/
#define ISIL_SEARCHDEV_RECVFROMCLIENTPORT 64020
#define ISIL_SEARCHDEV_SENDTOCLIENTPORT   64021

#define IE_TYPE_GET_H264FEATURECFG        11000  //��ȡH264��������
#define IE_TYPE_SET_H264FEATURECFG        11002  //����H264��������

/*for local gui messages id*/
/*ISIL MediaSDK��������*/
#define ISIL_ENC_H264_CFG			0x0041
#define ISIL_ENC_MJPG_CFG			0x0042
#define ISIL_ENC_AUDIO_CFG			0x0043
#define ISIL_ENC_NOREALTIME_CFG		0x0044
#define ISIL_VI_ANALOG_CFG			0x0045

#define ISIL_MANUAL_REC              0x0046
#define ISIL_CHN_MAP                 0x0047

//#define ISIL_LOCAL_SEARCH_FILE       0x07f8
#define ISIL_DIAPLAY_PORT_MODE_CFG  0x0048

#define ISIL_OPEN_FILE               0x0049
#define ISIL_CLOSE_FILE              0x0050
#define ISIL_GET_FILE_FRAME          0X0051
#define ISIL_FILE_GET_POSITION		 0X0052
#define ISIL_FILE_SET_POSITION		 0X0052
#define ISIL_FILE_GET_FILEINFO		 0X0053

#define ISIL_FILE_SET_PERCENT		 0X0054
#define ISIL_FILE_SET_LOOP			 0X0055
#define ISIL_FILE_SET_READ_ORDER	 0X0056
#define ISIL_FILE_SET_READ_KEYFRAME	 0X0057

#define ISIL_FILE_READ_SEEKPOS		 0X0058
#define ISIL_FILE_READ			     0X0059

#define ISIL_SET_SUB_WIN             0X0060
#define ISIL_BIND_FILE_WINDOW        0X0061
#define ISIL_STOP_FILE_PLAY          0X0062
#define ISIL_SET_FILE_PLAYMODE       0X0063
#define ISIL_SET_FILE_AVSYNC         0x0064
#define ISIL_SET_VIDEO_STDANDARD     0x0065

#define ISIL_TEST_RW				 0x0066
#define ISIL_ALARM_TYPE_CFG			 0x0067
#define ISIL_OSDINFO_CFG             0x0068

#define ISIL_CHIP_CHN_MAP			 0x0069


#define ISIL_GET_DEFAULT_PARM        0x0080
#define ISIL_DEV_USER_END_CFG		 1000




/*Some const define*/

/**************************Begin*****************************/
#define CONNECT_TIMEOUT (200000)


/*��ʾ������Ϣ����,0:PC,1:local*/
#define ISIL_PC_MSG 0
#define ISIL_LOCAL_MSG 1

typedef struct _ISIL_MSG_HEADER_STRU
{
	U16 nMsgTag; 	/*message header tag, 0xffff*/
	U16 nMsgType; 	/*message header type*/
	U32 lMsgLen;	/*message length*/
	U16 nMsgNum;	/*mesage number*/
	U16 nReserve;	/*Reserved, must is 0*/
	U32 lMsgCrc;	/*Message header CRC*/
}ISIL_MSG_HERADE_S;

/*General ask informationg element from net */
typedef struct _ISIL_NET_IE_ASK_STRU
{
	U16 nAskType;
	U16 nAskLength;
	U32 lReserve;
}ISIL_NET_IE_ASK_S;

/*General ask informationg element from net */
typedef struct _ISIL_NET_IE_ACK_STRU
{
	U16 nAckType;
	U16 nAckLength;
	U32 lReserve;
	S32 iAckFlag;
}ISIL_NET_IE_ACK_S;

typedef struct _ISIL_ACK_DATA_STRU
{
	void *data;
	S32 iAckFlag;
    U16 iLen;
	U16 nIEType;

}ISIL_ACK_DATA_S;

/*Alarm linkage type*/
enum eISIL_ALARM_TYPE
{
	ISIL_ALARM_TYPE_VIDEO_MOTION  = 1,
	ISIL_ALARM_TYPE_VIDEO_SHELTER = 2,
	ISIL_ALARM_TYPE_VIDEO_LOST    = 3,
	ISIL_ALARM_TYPE_ALARMIN    = 4,
	ISIL_ALARM_TYPE_OUTCTRL    = 5,
	ISIL_ALARM_TYPE_VIDEO_MAX,
};

enum eISIL_LINKAGE_TYPE
{
	ISIL_LINKAGE_TYPE_PC_EVENT      = 0,
	ISIL_LINKAGE_TYPE_OUTCTRL       = 1,
	ISIL_LINKAGE_TYPE_PTZ           = 2,
	ISIL_LINKAGE_TYPE_STREAM_RECORD = 3,
	ISIL_LINKAGE_TYPE_PIC_SHOOT     = 4,
	ISIL_LINKAGE_TYPE_MAX,
};

enum ISIL_NET_PROTOCOL_TYPE
{
    ISIL_LINKTYEP_TCP = 0,
    ISIL_LINKTYEP_UDP,
    ISIL_LINKTYEP_BROADCAST,
    ISIL_LINKTYEP_MULTICAST,
};

/*������������*/
enum eISIL_NET_LINK_TYPE
{
    ISIL_NET_LINK_AUDIO   = 0x01, //��Ƶ��
    ISIL_NET_LINK_MAIN_I  = 0x02, //�������ؼ�֡��
    ISIL_NET_LINK_MAIN    = 0x04, //������ (ISIL_NET_LINK_MAIN_I ��Ч��
    ISIL_NET_LINK_SUB_I   = 0x08, //�������ؼ�֡��
    ISIL_NET_LINK_SUB     = 0x10, //������ (ISIL_NET_LINK_SUB_I ��Ч��
    ISIL_NET_LINK_PIC     = 0x80, //ͼƬ��
};

/*��������*/
enum eISIL_UPDATE_TYPE
{
	ISIL_UPDATE_TYPE_KERNEL	    = 1,  //�����ں�
	ISIL_UPDATE_TYPE_OCX			,     //�����ؼ�
	ISIL_UPDATE_TYPE_WEBPAGE		,     //����ҳ��
	ISIL_UPDATE_TYPE_YUNTAI01	,     //������̨Э��01
	ISIL_UPDATE_TYPE_YUNTAI02	,     //������̨Э��02
	ISIL_UPDATE_TYPE_YUNTAI03	,     //������̨Э��03
	ISIL_UPDATE_TYPE_YUNTAI04	,     //������̨Э��04
	ISIL_UPDATE_TYPE_YUNTAI05	,     //������̨Э��05
	ISIL_UPDATE_TYPE_YUNTAI06	,     //������̨Э��06
	ISIL_UPDATE_TYPE_YUNTAI07	,     //������̨Э��07
	ISIL_UPDATE_TYPE_YUNTAI08	,     //������̨Э��08
	ISIL_UPDATE_TYPE_YUNTAI09	,     //������̨Э��09
	ISIL_UPDATE_TYPE_YUNTAI10	,     //������̨Э��10
	ISIL_UPDATE_TYPE_YUNTAI11	,     //������̨Э��11
	ISIL_UPDATE_TYPE_YUNTAI12	,     //������̨Э��12
	ISIL_UPDATE_TYPE_YUNTAI13	,     //������̨Э��13
	ISIL_UPDATE_TYPE_YUNTAI14	,     //������̨Э��14
	ISIL_UPDATE_TYPE_YUNTAI15	,     //������̨Э��15
	ISIL_UPDATE_TYPE_YUNTAI16	,     //������̨Э��16
	ISIL_UPDATE_TYPE_YUNTAI17	,     //������̨Э��17
	ISIL_UPDATE_TYPE_YUNTAI18	,     //������̨Э��18
	ISIL_UPDATE_TYPE_YUNTAI19	,     //������̨Э��19
	ISIL_UPDATE_TYPE_YUNTAI20	,     //������̨Э��20
	ISIL_UPDATE_TYPE_YUNTAI21	,     //������̨Э��21
	ISIL_UPDATE_TYPE_YUNTAI22	,     //������̨Э��22
	ISIL_UPDATE_TYPE_YUNTAI23	,     //������̨Э��23
	ISIL_UPDATE_TYPE_YUNTAI24	,     //������̨Э��24
	ISIL_UPDATE_TYPE_YUNTAI25	,     //������̨Э��25
	ISIL_UPDATE_TYPE_YUNTAI26	,     //������̨Э��26
	ISIL_UPDATE_TYPE_YUNTAI27	,     //������̨Э��27
	ISIL_UPDATE_TYPE_YUNTAI28	,     //������̨Э��28
	ISIL_UPDATE_TYPE_YUNTAI29	,     //������̨Э��29
	ISIL_UPDATE_TYPE_YUNTAI30	,     //������̨Э��30
	ISIL_UPDATE_TYPE_YUNTAI31	,     //������̨Э��31
	ISIL_UPDATE_TYPE_YUNTAI32	,     //������̨Э��32
	ISIL_UPDATE_TYPE_YUNTAI33	,     //������̨Э��33
	ISIL_UPDATE_TYPE_YUNTAI34	,     //������̨Э��34
	ISIL_UPDATE_TYPE_YUNTAI35	,     //������̨Э��35
	ISIL_UPDATE_TYPE_YUNTAI36	      //������̨Э��36
};

/*���ڲ�����*/
enum COM_DataBit
{
	DATA_BIT_5 = 5,
	DATA_BIT_6 = 6,
	DATA_BIT_7 = 7,
	DATA_BIT_8 = 8,
	DATA_BIT_OTHER,
};

/*��������*/
enum COM_FlowCtrl
{
	FLOW_CTRL_NO = 0,
	FLOW_CTRL_SOFT,
	FLOW_CTRL_HARD
};

typedef enum _eISIL_AUDIO_W_TYPE
{

	ISIL_AUDIO_PCM_W,
	ISIL_AUDIO_ALAW_W,
	ISIL_AUDIO_ULAW_W,
	ISIL_AUDIO_ADPCM_W,
}ISIL_MEDIASDK_AUDIO_W_TYPE;

typedef enum _eISIL_STREAM_BITRATE_TYPE_W
{
	ISIL_STREAM_BITRATE_TYPE_CBR_W = 0,     //
	ISIL_STREAM_BITRATE_TYPE_VBR_W = 1,     //
	ISIL_STREAM_BITRATE_TYPE_CQP_W = 2,     // fix QP

}ISIL_STREAM_BITRATE_TYPE_W;

typedef enum _eISIL_STREAM_BITRATE_MODE_W
{
    ISIL_STREAM_BITRATE_MODE_DEFAULT_W = 0,
	ISIL_STREAM_BITRATE_MODE_QUALITY_W = 1,  //quality
	ISIL_STREAM_BITRATE_MODE_FLUX_W    = 2   //flux
}ISIL_STREAM_BITRATE_MODE_W;

/*
*������ģ�齻����������Ϣ����
*/

/*#define COM_MAX_BAUDRATE_NUM	14*/

#define COM_DATA_LEN 256
#define MAX_COM_FD   10
#define COM_RS232 0
#define COM_RS485 1
#define COM_TYPE_CNT 2

#define COM_STOPBIT_1 1
#define COM_STOPBIT_2 2

#define COM_CHECK_NO 	0
#define COM_CHECK_O		1	/*Odd*/
#define COM_CHECK_E		2	/*even*/
#define COM_CHECK_1		3	/*all 1*/
#define COM_CHECK_0		4	/*all 0*/

#define COM_SELECT_TIME	100000

/*�����������ͣ�PC�򱾵�GUI*/
#define ISIL_LOCAL_SET_PARAM 1
#define ISIL_PC_SET_PARAM    2

#define ISIL_LOCAL_ENC_MJPEG 3
#define ISIL_LOCAL_ENC_AUDIO 4
#define ISIL_LOCAL_NOT_RT_ENC  5


#define ISIL_ENCODE_H264_TYPE 0
#define ISIL_ENCODE_MJPEG_TYPE 1
#define ISIL_ENCODE_AUDIO_TYPE 2




/*ISIL COM port Config*/
typedef struct _ISIL_COM_CFG_STRU
{
	U08 cComType;
	U08 cComNo;
	U08 cReserve[2];
	U32 lBaudrate;
	U08 cDatabit;
	U08 cStopbit;
	U08 cCheckType;
	U08 cFlowctrl;
}ISIL_COM_CFG_S;


/*COM ctrl*/
typedef struct _ISIL_COMM_CTRL_STRU
{
	U08 cComType;
	U08 cCOMMNo;
	U16 nDataLength;
	ISIL_COM_CFG_S stCOMMConfig;
	U08 cData[COM_DATA_LEN];
}ISIL_COMM_CTRL_S;

/*ISIL ptz protocal Config*/
typedef struct _ISIL_PTZ_PROTOCOL_STRU
{
	U08 cEnable;
	U08 nReserve[3];
	S08 sName[ISIL_NAME_LEN];
}ISIL_PTZ_PROTOCOL_S;

/*ISIL PTZ config*/
typedef struct _ISIL_PTZ_CFG_STRU
{
	U08 cComType;
	U08 cCOMMNo;
	U08 cValid;
	U08 cDecoderAddr;
	S08 sName[ISIL_NAME_LEN];
} ISIL_PTZ_CFG_S;

/*ISIL PTZ preset information*/
typedef struct _ISIL_PTZPRESET_CFG_STRU
{
	U08 cEnable;
	U08 cPosition;
	U08 cReserve[2];
	S08 sName[ISIL_NAME_LEN];
} ISIL_PTZPRESET_CFG_S;

/*ISIL PTZ control*/
typedef struct _ISIL_PTZ_CTRL_STRU
{
	U08 cCOMMNo;
	U08 cPTZType;
	U08 cPTZCmd;
	U08 cData1;
	U08 cReserve[4];
} ISIL_PTZ_CTRL_S;

/*ʱ��*/
typedef struct _tagISIL_TIME
{
	unsigned short nYear;   //��,��2008
	unsigned char  cMonth;  //��
	unsigned char  cDay;    //��
	unsigned char  cHour;   //ʱ
	unsigned char  cMinute; //��
	unsigned char  cSecond; //��
	unsigned char  cReserve;
}ISIL_TIME;


typedef struct _ISIL_SCHEDTIME_STRU
{
	U08 cStartHour;
	U08 cStartMin;
	U08 cStopHour;
	U08 cStopMin;
}ISIL_SCHEDTIME_S;

typedef struct _ISIL_VIDEO_MOTION_CFG_STRU
{
	U08 cDetectOpen;
	U08 cDetectLevel;
	U16 lAutoClearTime;
	U32 lMotionRect[24];
	ISIL_SCHEDTIME_S  stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];
}ISIL_VIDEO_MOTION_CFG_S;
typedef struct _ISIL_VIDEO_SHELTER_CFG_STRU
{
	U08 cDetectOpen;
	U08 cDetectLevel;
	U16 lAutoClearTime;
	U32    lShelterRect[24];
	ISIL_SCHEDTIME_S  stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];
}ISIL_VIDEO_SHELTER_CFG_S;


/*ISIL video mask Config*/
typedef struct _ISIL_VIDEO_MASK_CFG_STRU
{
	U08 cDetectOpen;
	U08 cReserve[3];
	U32 lMaskArea[24];
	ISIL_SCHEDTIME_S stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];
}ISIL_VIDEO_MASK_CFG_S;

/*ISIL video  lostConfig*/
typedef struct _ISIL_VIDEO_LOST_CFG_STRU
{
	U08 cDetectOpen;
	U08 cReserve;
	U16 nAutoClearTime;
	ISIL_SCHEDTIME_S stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];
}ISIL_VIDEO_LOST_CFG_S;

typedef struct _ISIL_ALARMIN_CFG_STRU
{
	S08 sName[ISIL_NAME_LEN];
    ISIL_COM_CFG_S stCOMMConfig;
	U08 cDetectOpen;
	U08 cAlarmInType;
	U16 nAutoClearTime;
	ISIL_SCHEDTIME_S stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];
}ISIL_ALARMIN_CFG_S;

typedef struct _ISIL_OUTCTRL_CFG_STRU
{
    char sName[ISIL_NAME_LEN];                               //����
	ISIL_COM_CFG_S stCOMMConfig;					            //��������
	unsigned char cStartSize;							    //���������
    unsigned char sStartCmd[256];                           //��������
	unsigned char cStopSize;							    //ֹͣ�����
	unsigned char sStopCmd[256];    			            //��������
	U08 cOutCtrlType;
	U08 cReserve;
	U16 nAutoClearTime;

} ISIL_OUTCTRL_CFG_S;


//�����������
typedef struct _tagISIL_OUTCTRL_CTRL
{
	char sName[ISIL_NAME_LEN];                               //����
	unsigned char    cOutCtrlType;							//�����������,�豸�˸��ݲ�ͬ���ͣ�ȷ�������壬���ǵ�ƽ
	unsigned char    cOpen;							        //����  0:�� 1����
	unsigned short   nAutoClearTime;						//�Զ����ʱ��

}ISIL_OUTCTRL_CTRL;


typedef struct _ISIL_LINKAGE_PTZ_CFG_STRU
{
	U08 cChannelNo;
	U08 cEnablePreset;
	U08 cPresetNo;
	U08 cEnableCruise;
	U08 cCruiseNo;
	U08 cEnablePTZ;
	U08 cPTZTrack;
	U08 cReserve;
} ISIL_LINKAGE_PTZ_CFG_S;

typedef struct _ISIL_LINKAGE_RECORD_CFG_STRU
{
	U08 cChannelNo;
	U08 cRecord;
	U08 cRecordSaveMode;
	U08 cRecordTime;
} ISIL_LINKAGE_RECORD_CFG_S;

typedef struct _ISIL_LINKAGE_SHOOT_CFG_STRU
{
	U08 cChannelNo;
	U08 cShoot;
	U08 cShootSaveMode;
	U08 cShootInterval;
	U32 lShootNum;
} ISIL_LINKAGE_SHOOT_CFG_S;

typedef struct _ISIL_LINKAGE_OUTCTRL_CFG /*�������*/
{
	unsigned char  cChannelNo;       /*����ͨ����*/
	unsigned char  cOutCtrl;         /*�������*/
	unsigned short nAutoClearTime;   /*�������,�Զ����ʱ��(��λ��),-1��ʾ��Ӧ���ֶ�����*/

}ISIL_LINKAGE_OUTCTRL_CFG;


typedef struct _ISIL_LINKAGE_PC_EVENT_CFG_STRU
{
	U08 cChannelNo;
	U08 cType;
	U08 cEvent[30];
} ISIL_LINKAGE_PC_EVENT_CFG_S;

typedef struct _ISIL_RET_SEARCH_DEVICE_INFO_STRU
{
	U32 lDeviceID;
	U32 lDeviceClass;
	U32 lDeviceType;
	S08 sDeviceName[ISIL_NAME_LEN];
	S08 sSerialNumber[ISIL_SERIALNO_LEN];
	S08 sIPAddr[ISIL_IPADDR_LEN];
	S08 sNetMask[ISIL_IPADDR_LEN];
	S08 sGateWay[ISIL_IPADDR_LEN];
	S08 sMultiCastIP[ISIL_IPADDR_LEN];
	S08 sDnsAddr[ISIL_IPADDR_LEN];

	U16 nNetInterface;
	U16 nDataPort;
	U16 nWebPort;
	U16 nMultiCastPort;

	U08 cMACAddr[ISIL_MACADDR_LEN];

	U08 cChannelCount;
	U08 cAlarmInCount;
	U08 cOutCtrlCount;
	U08 cRS232Count;
	U08 cRS485Count;
	U08 cNetworkPortCount;
	U08 cDiskCtrlCount;
	U08 cDiskCount;
	U08 cDecordCount;
	U08 cVGACount;
	U08 cUSBCount;
	U08 cStandard;
} ISIL_RET_SEARCH_DEVICE_INFO_S;

typedef struct _ISIL_ALARM_STATUS_STRU
{
	S08 sName[ISIL_NAME_LEN];
    ISIL_TIME time;
	U08 cAlarmType;
	U08 cChannelNo;
	U16 nPCEventBufSize;
} ISIL_ALARM_STATUS_S;

typedef struct _ISIL_ALARM_STATUS_TO_PC
{
	ISIL_ALARM_STATUS_S alarmStatus;
	U08* pPaylode;
}ISIL_ALARM_STATUS_TO_PC_S;


typedef struct _ISIL_ALARM_LINKAGE_STATUS_STRU
{
	U08 cChannelNo;
	U08 cLinkageType;
	U08 cLinkageState;
	U08 cLinkageState2;
	U08 cLinkageState3;
	U08 cLinkageState4;
	U08 cReserve[2];
} ISIL_ALARM_LINKAGE_STATUS_S;

typedef struct _ISIL_VIDEO_SIGNAL_CFG_STRU
{
	U08 cBrightness;
	U08 cHue;
	U08 cSaturation;
	U08 cContrast;
}ISIL_VIDEO_SIGNAL_CFG_S;

typedef struct
{
	U08 cBrightness;
	U08 cHue;
	U08 cSaturation;
	U08 cContrast;
    /*������ʽ*/
    U08 cVideoStandard;
    U08 cReserve[3];
}ISIL_VIDEO_SIGNAL_CFG_EX;


typedef struct _ISIL_ENCODE_INFO_STRU
{


    unsigned char     cChannelPri;         //����ͨ�����ȼ���[1,4]
    unsigned char     cStreamType;         //������       1-��Ƶ�� 2-��Ƶ�� 3-������
    unsigned char     cAudioType;          //��Ƶ��������(��ͨ��) 0-PCM    3-ADPCM
    unsigned char     cAudioBitAlign;      //��Ƶλ��     0-16bit  1-8bit
    unsigned char     cAudioSampleRate;    //��Ƶ������   0-8k 1-16k 2-32k 3-44k 4-48k
    unsigned char     cImageSize;          //��Ƶ�ߴ�     0-QQCIF,1-QCIF,2-HALF_CIF,3-CIF,4-2CIF,5-HALF_D1,6-4CIF,7-D1, 0xff-��Ч
    unsigned char     cRCType;             //���ʿ������� 0-CBR 1-VBR 2-CQP
    unsigned char     cBitMode;            //���ʿ���ģʽ 1-�������� 2-��������
    unsigned char     cImageQuality;       //ͼ�������Ӳ��[0,5],��cRCType=1ʱ��Ч
    unsigned char     cIQP;                //����I֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cPQP;                //����P֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cBQP;                //����B֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cFPS;                //֡��P[1-25],N[1,30]
    unsigned char     cHorizontalFlip;     //ˮƽ��ת,0-default,1-��ת
    unsigned char     cVerticalFlip;       //��ֱ��ת,0-default,1-��ת
    unsigned char     cReserve[5];         //
    unsigned short    nBitRate;            //����[128-3000](KBits)
    unsigned short    nGOPIntervals;       //GOP���[1-65535]
    unsigned short    nIFrameIntervals;    //I֡���[1-512]
    unsigned short    nBPFrameInterval;    //BP֡���[1-512]
    unsigned short    nWidthMBSize;        //��cImageSize=0xffʱ��Ч����Ƶ���, 720/16=45
    unsigned short    nHeightMBSize;       //��cImageSize=0xffʱ��Ч����Ƶ�߶�, 480/16=30
}ISIL_ENCODE_INFO_S;
typedef struct
{

    unsigned char     cChannelPri;         //����ͨ�����ȼ���[1,4]
    unsigned char     cStreamType;         //������       1-��Ƶ�� 2-��Ƶ�� 3-������
    unsigned char     cAudioType;          //��Ƶ��������(��ͨ��) 0-PCM    3-ADPCM
    unsigned char     cAudioBitAlign;      //��Ƶλ��     0-16bit  1-8bit
    unsigned char     cAudioSampleRate;    //��Ƶ������   0-8k 1-16k 2-32k 3-44k 4-48k
    unsigned char     cImageSize;          //��Ƶ�ߴ�     0-QQCIF,1-QCIF,2-HALF_CIF,3-CIF,4-2CIF,5-HALF_D1,6-4CIF,7-D1, 0xff-��Ч
    unsigned char     cRCType;             //���ʿ������� 0-CBR 1-VBR 2-CQP
    unsigned char     cBitMode;            //���ʿ���ģʽ 1-�������� 2-��������
    unsigned char     cImageQuality;       //ͼ�������Ӳ��[0,5],��cRCType=1ʱ��Ч
    unsigned char     cIQP;                //����I֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cPQP;                //����P֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cBQP;                //����B֡QP[0,51],��cRCType=2ʱ��Ч
    unsigned char     cFPS;                //֡��P[1-25],N[1,30]
    unsigned char     cHorizontalFlip;     //ˮƽ��ת,0-default,1-��ת
    unsigned char     cVerticalFlip;       //��ֱ��ת,0-default,1-��ת
    unsigned char     cReserve[5];         //
    unsigned short    nBitRate;            //����[128-3000](KBits)
    unsigned short    nGOPIntervals;       //GOP���[1-65535]
    unsigned short    nIFrameIntervals;    //I֡���[1-512]
    unsigned short    nBPFrameInterval;    //BP֡���[1-512]
    unsigned short    nWidthMBSize;        //��cImageSize=0xffʱ��Ч����Ƶ���, 720/16=45
    unsigned short    nHeightMBSize;       //��cImageSize=0xffʱ��Ч����Ƶ�߶�, 480/16=30

}ISIL_ENCODE_INFO_EX;

//MJPEG����
typedef struct _tagISIL_MJPEG_CFG
{
    U08     cImageSize;          //��Ƶ�ߴ�     0-CIF 1-QCIF, 2-2CIF, 3-4CIF, 4-QQCIF
    U08     cImageQuality;       //ͼ������     [9,51]
    U08     cFPS;                //֡��[1-10]
    U08     cEnable;             //������Ĭ�� 1
    unsigned short    nWidthMBSize;        //��cImageSize=0xffʱ��Ч����Ƶ���, 720/16=45
	unsigned short    nHeightMBSize;       //��cImageSize=0xffʱ��Ч����Ƶ�߶�, 480/16=30
}ISIL_MJPEG_CFG;


/*ISIL Encode  Config*/
typedef struct _ISIL_ENCODE_CFG_STRU
{
	U08 cEncodeEnable;
	U08 cEncode2Enable;
	U08 cReserve[2];
	ISIL_ENCODE_INFO_S stStreamEncode;
	ISIL_ENCODE_INFO_S stStreamEncode2;
} ISIL_ENCODE_CFG_S;

typedef struct
{
	U08 cEncodeEnable;
	U08 cEncode2Enable;
	U08 cReserve[2];
	ISIL_ENCODE_INFO_EX stStreamEncode;
	ISIL_ENCODE_INFO_EX stStreamEncode2;
} ISIL_ENCODE_CFG_EX;


typedef struct _ISIL_OVERLAY_CFG_STRU
{
	S08 sChannelName[ISIL_NAME_LEN];
	U16 nNameTopLeftX;
	U16 nNameTopLeftY;
	U08 cShowName;
	U08 cShowTime;
	U08 cTimeType;
	U08 cDispWeek;
	U08 cTimeAttrib;
	U08 cReserve[3];
	U16 nTimeTopLeftX;
	U16 nTimeTopLeftY;

	struct tagTextStream
	{
		U08 cShowString;
		S08 sText[ISIL_SUBTITLE_LEN+3];
		U16 nTextTopLeftX;
		U16 nTextTopLeftY;
	} stText[4];
} ISIL_OVERLAY_CFG_S;

//�ƻ�¼��
typedef struct _ISIL_SCHRECORD_CFG
{
	U08 cRecordOpen;							        //�ƻ�¼�񿪹�  0:��  1:��
	U08 cReserve[3];
	ISIL_SCHEDTIME_S	 stSchTable[ISIL_DAYS_MAX][ISIL_TIMESEGMENT_MAX];	//���ʱ���

}ISIL_SCHRECORD_CFG;
//�豸��¼���������
typedef struct _tagISIL_DEVRECORD_CFG
{
	struct tagDiskInfo
	{
		char          cDisk[15];                 //
		char          cSelect;                   //0:ûѡ�У�1��ѡ��
		unsigned long lDiskSize;	             //�ռ��С(M)
		unsigned long lFreeSize;		         //���ÿռ��С(M)

	}stDiskInfo[64];                    //�����б�

	unsigned long lSysFreeDiskSwitch;	//��ϵͳ��ʣ����ٿռ�ʱ����¼��(M)
	unsigned long lFreeDiskSwitch;		//����ϵͳ��ʣ����ٿռ�ʱ����¼��(M)

	unsigned char cOverWrite;		    //���ǲ���(0?¼��ֹͣ,1-¼���Զ�����)
	unsigned char cPacketFlag;		    //�����ʶ(0?��ʱ����,1-�Դ�С���)
	unsigned char cReserve[2];

	union
	{
		unsigned long lPacketTime;		//���ʱ��(��)
		unsigned long lPacketSize;		//�����С(K)
	}PacketInfo;


}ISIL_DEVRECORD_CFG;


//ͨ��¼���������
typedef struct _ISIL_RECORD_CFG
{
	U32 lPreRecordTime;	    //Ԥ¼ʱ��     (����)
	U32 lExtRecordTime;	    //�ӳ�¼��ʱ�� (����)
    U32 lAlarmRecordTime;	    //�澯¼��ʱ�䳤��(����)

	U08 cRecordStream;		//eISIL_NET_LINK_TYPE, ���Զ�����ϣ������ĺ�
	U08 cReserve[3];

}ISIL_RECORD_CFG;


typedef struct _ISIL_STREAM_CFG_STRU
{
	U08 cEncodeEnable;
	U08 cOverlayEnable;
	U08 cMotionEnable;
	U08 cShelterEnable;
	U08 cMaskEnable;
	U08 cLostEnable;
	U08 cSignalEnable;
    U08 cSchRecordEnable;
    U08 cRecordEnable;
	U08 cPTZEnable;
	U08 cPTZPresetEnable;
	U08 cReserve;
	ISIL_ENCODE_CFG_S stStreamEncode;
	ISIL_OVERLAY_CFG_S stVideoOverlay;
	ISIL_VIDEO_MOTION_CFG_S stVideoMotion;
	ISIL_VIDEO_SHELTER_CFG_S stVideoShelter;
	ISIL_VIDEO_MASK_CFG_S stVideoMask;
	ISIL_VIDEO_LOST_CFG_S stVideoLost;
	ISIL_VIDEO_SIGNAL_CFG_S stVideoSignal;
    ISIL_SCHRECORD_CFG     stSchRecord;                //�ƻ�¼��
	ISIL_RECORD_CFG        stRecord;                   //ͨ��¼���������
    /*����TODO*/
    ISIL_MJPEG_CFG         stMJPEGCfg;                 //MJpeg����
	ISIL_PTZ_CFG_S stPTZCfg;
    /*����TODO*/
    ISIL_COM_CFG_S          stComCfg;                   //��������
    ISIL_PTZPRESET_CFG_S stPTZPrsetCfg[ISIL_PTZ_PRSET_MAX];
} ISIL_STREAM_CFG_S;



/*��������ͨ��������ݽṹ*/
typedef struct _NET_INFO_DATA
{
	U32 lIPAddr;
	U16 nPort;
	U16 nChannel;
	S08 szUserName[ISIL_NAME_LEN];
	S08 szPassword[ISIL_PASSWORD_LEN];
	S08 szName[ISIL_NAME_LEN];
	U16 nLinkProtocol;           /*eISIL_NET_PROTOCOL_TYPE*/
	U16 nReserve;
}ISIL_NET_INFO_DATA_S;

typedef struct _NET_REALPLAY
{
	S08 szUserName[ISIL_NAME_LEN];
	S08 szPassword[ISIL_PASSWORD_LEN];
	char szDeviceName[ISIL_NAME_LEN];       /*�豸����*/
	unsigned long lDeviceID;
    /*
    �������� eISIL_NET_LINK_TYPE �е��������,
    0 ��ϵͳ���������ô���
    */
	U16 nLinkType;
    U16 nReserve;

}ISIL_NET_REALPLAY_S;

typedef struct _ASK_NETINFO
{
    /*eISIL_NET_PROTOCOL_TYPE*/
    U16 nLinkProtocol;
	U16 nReserve;

}ISIL_ASK_NETINFO_S;

/*¼��ʱ��*/
typedef struct _ISIL_REC_TIME
{
	unsigned char  cHour;   	/*ʱ*/
	unsigned char  cMinute; 	/*��*/
	unsigned char  cSecond;		/*��*/
	unsigned char  cReserve;	/*����(4�ֽڶ���)*/
}ISIL_REC_TIME;


/* �豸/�ļ���¼��Ϣ(��ѯ���)*/
typedef struct _ISIL_LOG_DEVICE
{
	unsigned long	lFlag;				/* У���־ 0x0FFEABCD*/
	unsigned char	cType;
	unsigned char	cChannelNum;		/* ͨ����0~N*/
	char			szURL[30];			/* �豸��ַ*/
	char			szDeviceName[32];	/* �豸����*/
	char			szChannelName[32];	/* ͨ������*/
	ISIL_REC_TIME    stStart;			/* ¼������ʱ���ͼƬץ��ʱ��*/
	char            szFileExt[4];
	char            szFilePath[260];

}ISIL_LOG_DEVICE;

typedef struct _ISIL_NETFILE_OPEN
{
	char szUserName[ISIL_NAME_LEN];
	char szPassword[ISIL_PASSWORD_LEN];
	char szDeviceName[ISIL_NAME_LEN];       /*�豸����*/
	unsigned long lDeviceID;
	char szFileNames[10][64];
	unsigned short nFileCount;
	unsigned short nLinkType;
}ISIL_NETFILE_OPEN;

typedef struct _ISIL_FILE_BASE_INFO
{
	unsigned long lTimeLength;          //�ļ�����ʱ�䳤��(���� ms)
	unsigned long lBeginTimeStamp;      //�ļ�����ʼʱ���(���� ms)
	unsigned long lEndTimeStamp;        //�ļ��Ľ���ʱ���(���� ms)
	unsigned long lFileSize;            //�ļ���С(BYTE)
	unsigned long lMaxKeyFrameInterval; //���ؼ�֡���

}ISIL_FILE_BASE_INFO;

typedef union _ISIL_NET_FILE_COMMAND
{
	unsigned long lTimePosition;
	unsigned long lFilePosition;
	float fPercent;
	unsigned char cIsLoop;
	unsigned char cIsOrder;
	unsigned char cIsKeyFrame;
	unsigned char cReserve;

	struct stReadParam
	{
		unsigned long lReadLength; //ȡ���ݳ���
		unsigned long lReadDataID; //����ش���ID������ʶ���Ƿ�Ϊ��ǰ��ȡ���ݿ� = NET_PACKET_HEAD.lFrameID
	}xReadParam;

	struct stGetFramesParam
	{
		long lFrameCount;   //֡��
		long lFrameDelay;	//֡���ӳ�(����)
	}xFrameParam;
}NET_FILE_COMMAND;

typedef struct _tagIE_FILE_COMMAND
{
	ISIL_NET_IE_ASK_S   stAsk;
    NET_FILE_COMMAND xNetCmd;

}IE_FILE_COMMAND;



typedef enum
{
    ISIL_SEARCH_STOP = 0,
    ISIL_SEARCH_DEV,
    ISIL_SEARCH_FILE,
    ISIL_SEARCH_CHANNEL,
}ISIL_SEARCH_CLASS;

/* ��ѯ�豸/�ļ�(��ѯ����)����NVS��DVR�����ļ�ʱ������ʹ�øýṹ��*/
typedef struct _ISIL_SEARCH_EVNET
{
    unsigned long lFlag; // У���־ 0x0FFEABCD
    unsigned char cCommand; // 0 ֹͣ����, 1 ���豸 , 2 ���ļ� , 3 �豸��ͨ��
    unsigned char cFileType; // 1 AV , 2 JPG
    unsigned char cEventType; // 1 �ֶ�¼�� �� 2 ��ʱ¼�� �� 3 ����¼��
    unsigned char cAlarmType; // 0 ���б������ͣ�1 �ƶ�������2 �ڵ�����, 4 ��Ƶ��ʧ��8 ̽ͷ����
    unsigned char cChannelNum; // ͨ����0~N
    unsigned char cReserve[3];
    ISIL_TIME stStart; // ¼���ץ����ʼʱ��
    ISIL_TIME stEnd; // ¼���ץ�Ľ���ʱ��
    char szDeviceName[32]; // �豸����
    char szReserve[44];
} ISIL_SEARCH_EVNET;

/*�ṩ��USB/IDEר��*/
#define DEVPATHMAXLEN 32

typedef struct
{
    char dev_path[DEVPATHMAXLEN];
    char mount_point[DEVPATHMAXLEN];
}ISIL_NODE_PATH;

/**************************ISIL time CFG parameter begin****************************/

/*Time struct*/
typedef struct _ISIL_TIME_STRU
{
	U16 nYear;
	U08 cMonth;
	U08 cDay;
	U08 cHour;
	U08 cMinute;
	U08 cSecond;
	U08 cReserve;
}ISIL_TIME_S;
/**************************ISIL time CFG parameter end****************************/

typedef struct _ISIL_NET_CFG_STRU
{
	U32 lSize;/*net config size = sizeof(ISIL_NET_CFG_S) */
	U32 lIPAddr;
	U32 lNetMask;
	U32 lGateWay;
	U32 lMultiCastIP;

	U16 nNetInterface;
	U16 nDataPort;
	U16 nWebPort;
	U16 nMultiCastPort;
	U08 cMACAddr[ISIL_MACADDR_LEN];

	U08 cDHCP;
	U08 cPppoeOpen;
	U08 cDdnsOpen;
	U08 cReserve;
	S08 sPppoeName[ISIL_NAME_LEN];
	S08 sPppoePass[ISIL_PASSWORD_LEN];

	U32 lPppoeTimesl;/*online time*/
	U32 lPppoeIPAddr; /*PPP OE IP Address*/
	S08 sDdnsName[ISIL_NAME_LEN];
	S08 sDdnsPass[ISIL_PASSWORD_LEN];
	S08 sDdnsIP[ISIL_DDNS_IP_LEN];

	U16 nDdnsPortNo;
	U16 nDdnsMapDataPort;
	U16 nDdnsMapWebPort;
	U16 nReserve;
}ISIL_NET_CFG_S;


/**************************ISIL base CFG parameter begin****************************/

/*Device base config*/
typedef struct _ISIL_DEV_BASE_CFG_STRU
{
	S08 sDeviceName[ISIL_NAME_LEN];
	S08 sSerialNumber[ISIL_SERIALNO_LEN];
	U32 lDeviceID;
	/*
	*******************************************************************

	      b31                                              b15                                                   b0
		|----------------------------|-------------------------------|
			SW main ver number                 SW sub ver numer

	******************************************************************
	*/
	U32 lSoftwareVersion;
	U32 lSoftwareBuildDate;

	/*
	******************************************************************

	      b31                                              b15                                                   b0
		|----------------------------|-------------------------------|
			DSP main ver number                             DSP sub ver numer

	******************************************************************
	*/
	U32 lDSPSoftwareVersion;
	U32 lDSPSoftwareBuildDate;
	U32 lPanelVersion;

	/*
	******************************************************************

	      b31                                              b15                                                   b0
		|----------------------------|-------------------------------|
			HW main ver number                             HW sub ver numer

	******************************************************************
	*/
	U32 lHardwareVersion;
	U32 lDeviceClass;
	U32 lDeviceType;

	U08 cChannelCount;
	U08 cAlarmInCount;
	U08 cOutCtrlCount;
	U08 cRS232Count;
	U08 cRS485Count;
	U08 cNetworkPortCount;
	U08 cDiskCtrlCount;
	U08 cDiskCount;

	U08 cDecordCount;
	U08 cVGACount;
	U08 cUSBCount;
	U08 cStandard;
	ISIL_TIME_S stSysTime;
	S08 ReservedData[6];
}ISIL_DEV_BASE_CFG_S;
/**************************ISIL base CFG parameter end****************************/



/********************ISIL DEV CFG parameter begin***********************/

/*ISIL DEV Config*/
typedef struct _ISIL_DEV_CFG_STRU
{
	U08 cDeviceBaseEnable;
	U08 cNetEnable;
	U08 cPTZProEnable;
	U08 cReserve;
	ISIL_DEV_BASE_CFG_S stDeviceBase;
	ISIL_NET_CFG_S stNet;
	ISIL_PTZ_PROTOCOL_S stPTZProtocol[ISIL_PTZ_PROTOCOL_MAX];
}ISIL_DEV_CFG_S;

/*ISIL Media sdk*/
/*************Video h264 encoding cfg***************/
typedef struct
{
	unsigned char streamType; // main/assistant stream ;
	unsigned char channel_enable[2];
	unsigned char cReserve;
	VENC_H264_CFG venc_h264cfg[2];
	VENC_H264_FEATURE venc_h264feature[2];
	VENC_H264_RC venc_h264rc[2];
}VENC_H264_INFO;



/*************video mjpg encoding cfg**************/

typedef struct
{
    unsigned char streamType;// main/assistant stream ;
    unsigned char channel_enable[2];
	unsigned char cReserve;
	VENC_MJPG_CFG venc_mjpg_cfg[2];
}VENC_MJPG_INFO;

typedef struct
{	unsigned char streamType;
    unsigned char channel_enable;
     unsigned char cReserve[2];
	VENC_AUD_CFG venc_audio_cfg;
} VENC_AUDIO_INFO;



typedef struct
{
	ENC_CTL_VD_CFG vdcfg;
	int  vdmode;
}ENC_CTL_VD_INFO;

typedef struct
{
	unsigned int change_mask_flag;
	VI_CH_CFG vichcfg;
	VI_CH_VIDEOTYPE videostd;
}VI_ANALOG_INFO;

typedef struct
{
	/*
	 * 0:disable;  1:enable ;If all parameters of the
	 * following set to 0/1 then the current channel
	 * is diasble/enable
	 * */
	 unsigned char ucMainStream;
	 unsigned char ucSubStream;
	 unsigned char ucMotionJPEG;
	 unsigned char ucAudio;
}LOC_GUI_RECORD_CTL;

typedef struct
{
    unsigned char logicChID;
    unsigned char phyChipID;
    unsigned char phyChID;
    unsigned char imageSize;//0:D1,1:HALF D1, 2:CIF, 3:HCIF,4,QCIF }CH_LOGIC2PHY_MAP;
}LOC_GUI_CHN_MAP;


typedef struct _ISIL_RECT{
    unsigned int  iSubWin_x; //��ʼX����λ��
    unsigned int  iSubWin_y; //��ʼY����λ��
    unsigned int  iSubWin_XSize; //X ���
    unsigned int  iSubWin_YSize;    //Y ���
}ISIL_LOCCALGUI_RECT;
typedef struct _ISIL_SUB_WINDOWS{
    unsigned char  iPort;     /*vo port*/
    unsigned char  iPhase;  /*phase in port0-N*/
    unsigned char  cImageType; //0:palyback ,1:preview
    unsigned char  cSubWindowsNum;//
    ISIL_LOCCALGUI_RECT   stSubWindows[0];//����cSubWindowsNum��̬����SubWindows��
}ISIL_SUB_WINDOWS;

#if 0
typedef struct _ISIL_SUB_WINDOWS_BIND{
    unsigned long lVi_chId;// preview vi channel ID
    unsigned long lLogicId; //file fd
    unsigned long lDisplayId;// display positions
    // unsigned char cReserved[2];
    //unsigned char cFileName[64];
    ISIL_SUB_WINDOWS stSubInfo;
}ISIL_SUB_WINDOWS_BIND;
#endif

typedef enum _ISIL_VI_PYTE{
     TYPE_PLAYBACK = 0,
     TYPE_PREVIEW,
     TYPE_LOOPBACK,
}ISIL_EM_VITYPE;

typedef struct _ISIL_SUB_WINDOWS_BIND{
	ISIL_EM_VITYPE emViType;
	unsigned long lChipId;
	unsigned long lVi_chId;// preview/loopback channelID or fileFd;
	unsigned long lDisplayId;// display positions
	//   unsigned char cReserved[2];
	//unsigned char cFileName[64];
	ISIL_SUB_WINDOWS stSubInfo;
}ISIL_SUB_WINDOWS_BIND;

#if 0
struct  x_speed
{
	enum  X_MODE    mode;//the mode specified
	unsigned long   x_speed_value;//the real speed value
};

typedef struct _ISIL_VDEC_CH_MODE
{
    unsigned char loop; //0: not loop,  1: loop
    unsigned char  direction;  //0: backward 1: forward
    unsigned char key_frame;//0: frame one by one 1:only for key frames
    unsigned char is_continue;//0: stop after display one frame
                              //1: continue after after display one frame
    int x_speed;// -1 means nonsense
}ISIL_VDEC_CH_MODE;
#endif

/**/
enum ISIL_DISPLAY_INTERFACE_MODE{
     ISIL_DISPLAY_INTERFACE_MODE_27M = 0,
     ISIL_DISPLAY_INTERFACE_MODE_54M,
     ISIL_DISPLAY_INTERFACE_MODE_108M,
     ISIL_DISPLAY_INTERFACE_MODE_HD,
     ISIL_DISPLAY_INTERFACE_MODE_RESERVE,
};

enum ISIL_INTERLEAVE_MODE{
     ISIL_INTERLEAVE_MODE_BYTE = 0,
     ISIL_INTERLEAVE_MODE_FRAME,
     ISIL_INTERFACE_MODE_RESERVED,
};


typedef struct _ISIL_DIAPLAY_PORT_MODE{
     unsigned int i_port;
     enum ISIL_DISPLAY_INTERFACE_MODE e_mode;
     enum ISIL_INTERLEAVE_MODE e_interleave;
}ISIL_DIAPLAY_PORT_MODE;

/*enum ISIL_VIDEO_STANDARD{
     ISIL_VIDEO_STANDARD_PAL,
     ISIL_VIDEO_STANDARD_NTSC,
     ISIL_VIDEO_STANDARD_USER_DEFINE,
};
*/

struct ISIL_display_video_standard{
     enum ISIL_VIDEO_STANDARD e_video_standard;
};

enum CHIP_TEST_TYPE{
	ISIL_TEST_REG = 0,
	ISIL_TEST_DDR,
	ISIL_TEST_MPB,
	ISIL_TEST_I2C,
	ISIL_TEST_GPIO,
};

typedef struct _TEST_REG{
	enum CHIP_TEST_TYPE type;
	struct reg_info reg;
	unsigned int len;
    unsigned char buffer[0];
}ISIL_TEST_REG_INFO;

typedef struct _TEST_DDR{
	enum CHIP_TEST_TYPE type;
	struct ddr_info ddr;
	unsigned int len;
    unsigned char buffer[0];
}ISIL_TEST_DDR_INFO;

typedef struct _TEST_MPB{
	enum CHIP_TEST_TYPE type;
	struct mpb_info mpb;
	unsigned int len;
    unsigned char buffer[0];
}ISIL_TEST_MPB_INFO;

typedef struct _TEST_I2C{
	enum CHIP_TEST_TYPE type;
	struct i2c_info i2c;
	unsigned int len;
	unsigned char buffer[0];
}ISIL_TEST_I2C_INFO;

typedef struct _TEST_GPIO{
	enum CHIP_TEST_TYPE type;
	struct gpio_info gpio;
}ISIL_TEST_GPIO_INFO;

typedef struct _ALARM_TYPE
{
	unsigned long alarmtype;
}ISIL_ALARM_TYPE;





/***************************************************************************/
/*���½ṹ�ǲ�ͬ����乫�õ�*/

typedef struct
{
	S32 channel;
	ISIL_VIDEO_MOTION_CFG_S sMotionCfg;
}G_VIDEO_MOTION_CFG_S;

typedef struct
{
	S32 channel;
	ISIL_VIDEO_SHELTER_CFG_S sShelterCfg;
}G_VIDEO_SHELTER_CFG_S;


/*ISIL video mask Config*/
typedef struct
{
	S32 channel;
	ISIL_VIDEO_MASK_CFG_S sMaskCfg;
}G_VIDEO_MASK_CFG_S;

/*ISIL video  lostConfig*/
typedef struct
{
	S32 channel;
	ISIL_VIDEO_LOST_CFG_S sLostCfg;
}G_VIDEO_LOST_CFG_S;

typedef struct
{
	S32 channel;
	ISIL_ALARMIN_CFG_S sAlarmInCfg;
}G_ALARMIN_CFG_S;

typedef struct
{
	S32 channel;
	ISIL_OUTCTRL_CTRL sOutCtlCfg;
} G_OUTCTRL_CFG_S;

typedef struct
{
	ISIL_LINKAGE_PTZ_CFG_S sLinkagePtzCfg;
} G_LINKAGE_PTZ_CFG_S;

typedef struct
{
	ISIL_LINKAGE_RECORD_CFG_S sLinkageRecCfg;
} G_LINKAGE_RECORD_CFG_S;

typedef struct
{
	ISIL_LINKAGE_SHOOT_CFG_S sLinkageShootCfg;
} G_LINKAGE_SHOOT_CFG_S;

typedef struct
{
	ISIL_LINKAGE_PC_EVENT_CFG_S sLinkagePcEventCfg;
} G_LINKAGE_PC_EVENT_CFG_S;


typedef struct
{
	S32 channel;
    S32 cmdType;
	ISIL_VIDEO_SIGNAL_CFG_EX sVideoSignalCfg;
}G_VIDEO_SIGNAL_CFG_S;

typedef struct
{
    S32 channel;
    S32 cmdType;
    VI_ANALOG_INFO cfg;
}G_LOCAL_VI_ANALOG_INFO;

typedef struct
{
	S32 channel;
	ISIL_ENCODE_INFO_S sEncodeInfo;

}G_ENCODE_INFO_S;

/*ISIL Encode  Config*/
typedef struct
{
	S32 channel;
    S32 parmType;/*PC or local gui*/
	ISIL_ENCODE_CFG_EX sEncodeCfg;
}G_ENCODE_CFG_S;

typedef struct
{
	S32 channel;
    S32 parmType;/*PC or local gui*/
	VENC_H264_INFO sEncodeCfg;
}G_LOCAL_ENCODE_CFG_S;

typedef struct
{
	S32 channel;
    S32 parmType;/*PC or local gui*/
	VENC_MJPG_INFO sMjpegCfg;
}G_LOCAL_MJPEG_CFG_S;

typedef struct
{
	S32 channel;
    S32 parmType;/*PC or local gui*/
	VENC_AUD_CFG sAudioCfg;
}G_LOCAL_AUDIO_CFG_S;

typedef struct
{
	S32 channel;
    S32 parmType;/*PC or local gui*/
	ENC_CTL_VD_INFO sVDCfg;
}G_LOCAL_VD_CFG_S;



typedef struct
{
	S32 channel;
	ISIL_OVERLAY_CFG_S sOverlayerCfg;
} G_OVERLAY_CFG_S;

typedef struct
{
	S32 channel;
	ISIL_STREAM_CFG_S sStreamCfg;
}G_STREAM_CFG;

typedef struct _ISIL_FILE_OPT
{
    ISIL_NETFILE_OPEN isil_file_open;
    unsigned int reserve;
    int (*callback)( void*arg1, int type,void* arg2);
}ISIL_FILE_OPT;

typedef struct _ISIL_NET_CLOSE
{
	unsigned int reserve;
}ISIL_NET_CLOSE;

typedef struct _ISIL_MJ_CFG
{
    S32 channel;
    ISIL_MJPEG_CFG cfg;
}G_MJPEG_CFG;

typedef struct _ISIL_PC_H264_FEATURE_CFG
{
    S32 channel;
    VENC_H264_FEATURE cfg[2];
}G_PC_H264_FEATURE_CFG;

typedef struct _PLAY_MOD
{
    unsigned int fd;
    VDEC_CH_MODE mod;
}G_ISIL_PLAY_MOD;

typedef struct _FILE_AV_SYNC
{
    unsigned int fd;
}G_FILE_AV_SYNC;


/*ISIL VIDEO PARAM SET*/
typedef enum{
    VIDEO_STREAM_TYPE = 0,
    AV_STREAM_TYPE    = 1,
    AUDIO_STREAM_TYPE = 2,
}ISIL_DRV_STREAM_TYPE;

typedef enum{
    QQCIF_VIDEO_IMG = 0,
    QCIF_VIDEO_IMG,
    HALF_CIF_VIDEO_IMG,
    CIF_VIDEO_IMG,
    TWO_CIF_VIDEO_IMG,
    HALF_D1_VIDEO_IMG,
    FOUR_CIF_VIDEO_IMG,
    D1_VIDEO_IMG,
}ISIL_VIDEO_SIZE_TYPE_W;

/*
typedef enum{
	MJPEG_CIF =0,
	MJPEG_QCIF,
	MJPEG_2CIF,
	MJPEG_4CIF,
    MJPEG_QQCIF
}ISIL_MJPEG_SIZE_TYPE_W;
*/



typedef enum{
    ISIL_CHANGE_ENCODE_RC = 0,
    ISIL_SOLID_ENCODE_RC  = 1,
}ISIL_VIDEO_RC_TYPE;


typedef enum{
    ISIL_VIDEO_IMG_QUALITY_BEST = 0,
    ISIL_VIDEO_IMG_QUALITY_BETTER = 1,
    ISIL_VIDEO_IMG_QUALITY_WELL   = 2,
    ISIL_VIDEO_IMG_QUALITY_NORMAL = 3,
    ISIL_VIDEO_IMG_QUALITY_WORSE  = 4,
    ISIL_VIDEO_IMG_QUALITY_WORST  = 5,
}ISIL_VIDEO_QUALITY_TYPE;


#define REC_ONLY_AUDIO (0x01)//audio stream
#define REC_MAIN_VIDEO (0x02)//video master stream
#define REC_SUB_VIDEO  (0x04)//video sub stream
#define REC_ONLY_MJPG  (0x08)//mjpg stream

typedef struct
{
	int			    lChannel;
	unsigned char   ucRecType;
    unsigned char   ucRecSubType;//��¼������
	unsigned char   u8Stream;//REC_ONLY_AUDIO/REC_MAIN_VIDEO/REC_SUB_VIDEO/REC_ONLY_MJPG
	char		    cReserved;
}MSG_FM_START_REC;

//ucRecType: enum eISIL_LOG_TYPE

/*MSG_TYPE_FM_STOP_REC*/
//lMsgType : 	MSG_TYPE_FM_STOP_REC
//pMsg:
typedef struct
{
	int lChannel;
}MSG_FM_STOP_REC;


#define HALF_CIF_WIDTH (352)
#define HALF_CIF_HIGHT (144)

/*END VIDEO STREAM SET*/
#define _MSG(x)						(0xff000000|x)

#define G_NET_MSG_TYPE_MASK				0xffffff
#define G_MSG_GET_STREAMCFG				_MSG(IE_TYPE_GET_STREAMCFG)
#define G_MSG_SET_STREAMCFG				_MSG(IE_TYPE_SET_STREAMCFG)

#define G_MSG_GET_VIDEOMOTIONCFG		_MSG( IE_TYPE_GET_VIDEOMOTIONCFG)
#define G_MSG_SET_VIDEOMOTIONCFG		_MSG( IE_TYPE_SET_VIDEOMOTIONCFG)

#define G_MSG_GET_VIDEOSHELTERCFG		_MSG( IE_TYPE_GET_VIDEOSHELTERCFG)
#define G_MSG_SET_VIDEOSHELTERCFG		_MSG( IE_TYPE_SET_VIDEOSHELTERCFG)

#define G_MSG_GET_VIDEOMASKCFG			_MSG( IE_TYPE_GET_VIDEOMASKCFG)
#define G_MSG_SET_VIDEOMASKCFG			_MSG( IE_TYPE_SET_VIDEOMASKCFG)

#define G_MSG_GET_VIDEOLOSTCFG			_MSG( IE_TYPE_GET_VIDEOLOSTCFG)
#define G_MSG_SET_VIDEOLOSTCFG    		_MSG( IE_TYPE_SET_VIDEOLOSTCFG)

#define G_MSG_GET_VIDEOSIGNALCFG     	_MSG( IE_TYPE_GET_VIDEOSIGNALCFG)
#define G_MSG_SET_VIDEOSIGNALCFG      	_MSG( IE_TYPE_SET_VIDEOSIGNALCFG)

#define G_MSG_GET_ENCODECFG   			_MSG( IE_TYPE_GET_ENCODECFG)
#define G_MSG_SET_ENCODECFG    			_MSG( IE_TYPE_SET_ENCODECFG)

#define G_MSG_GET_VIDEOOVERLAYCFG		_MSG( IE_TYPE_GET_VIDEOOVERLAYCFG)
#define G_MSG_SET_VIDEOOVERLAYCFG 		_MSG( IE_TYPE_SET_VIDEOOVERLAYCFG)


#define G_MSG_GET_ALARMINCFG			_MSG( IE_TYPE_GET_ALARMINCFG)
#define G_MSG_SET_ALARMINCFG			_MSG( IE_TYPE_SET_ALARMINCFG)
#define G_MSG_GET_OUTCTRLCFG			_MSG( IE_TYPE_GET_OUTCTRLCTRL)
#define G_MSG_SET_OUTCTRLCFG			_MSG( IE_TYPE_SET_OUTCTRLCTRL)

#define G_MSG_SET_SHOOTIMAGE			_MSG( IE_TYPE_SET_SHOOTIMAGE)

#define G_MSG_DEVTOC_ALARMSTATUS		_MSG( IE_TYPE_DEVTOC_ALARMSTATUS)
#define G_MSG_DEVTOC_PARAMCHANGED		_MSG( IE_TYPE_DEVTOC_PARAMCHANGED)

#define G_MSG_GET_ALARMLINKAGECFG    	_MSG( IE_TYPE_GET_ALARMLINKAGECFG)
#define G_MSG_SET_ALARMLINKAGECFG     	_MSG( IE_TYPE_SET_ALARMLINKAGECFG)
#define G_MSG_GET_ALARMSTATUS         	_MSG( IE_TYPE_GET_ALARMSTATUS)
#define G_MSG_SET_ALARMSTATUS   		_MSG( IE_TYPE_SET_ALARMSTATUS)
#define G_MSG_GET_ALARMDETAILSTATUS 	_MSG( IE_TYPE_GET_ALARMDETAILSTATUS)

#define G_MSG_ASK_REALPLAY				_MSG( MSG_TYPE_ASK_REALPLAY)	/* ����ʵʱ����*/
#define G_MSG_ACK_REALPLAY				_MSG( MSG_TYPE_ACK_REALPLAY)	/* ��Ӧʵʱ����*/


#define G_MSGE_ASK_TALK 				_MSG( MSG_TYPE_ASK_TALK)	/* ���������Ի�*/
#define G_MSG_ACK_TALK 					_MSG( MSG_TYPE_ACK_TALK)	/* Ӧ�������Ի�*/

#define G_MSG_ASK_BROADCAST				_MSG( MSG_TYPE_ASK_BROADCAST)	/* ����㲥*/
#define G_MSG_ACK_BROADCAST				_MSG( MSG_TYPE_ACK_BROADCAST)	/* Ӧ��㲥*/

#define G_MSG_ASK_AUTOSEARCH 			_MSG( MSG_TYPE_ASK_AUTOSEARCH)	/* �����Զ������豸*/
#define G_MSG_ACK_AUTOSEARCH 			_MSG( MSG_TYPE_ACK_AUTOSEARCH)	/* Ӧ���Զ������豸*/

#define G_MSG_GET_REALPLAYINFO 			_MSG( IE_TYPE_GET_REALPLAYINFO)
#define G_MSG_OPEN_FILE                 _MSG( IE_TYPE_FILE_OPEN)

#define G_MSG_GET_MJPEGCFG              _MSG(IE_TYPE_GET_MJPEGCFG)
#define G_MSG_SET_MJPEGCFG              _MSG(IE_TYPE_SET_MJPEGCFG)
#define G_MSG_SET_264FEATURE            _MSG(IE_TYPE_SET_H264FEATURECFG)

#define G_MSG_SET_SUB_WINDOWS            _MSG(ISIL_SET_SUB_WIN)
#define G_MSG_BIND_FILE_WINDOWS          _MSG(ISIL_BIND_FILE_WINDOW)

#define G_MSG_STOP_FILE_PLAY            _MSG(ISIL_STOP_FILE_PLAY)
#define G_MSG_SET_PLAY_MOD              _MSG(ISIL_SET_FILE_PLAYMODE)
#define G_MSG_SET_AV_SYNC             _MSG(ISIL_SET_FILE_AVSYNC)
#define G_MSG_DIAPLAY_PORT_MODE_CFG   _MSG(ISIL_DIAPLAY_PORT_MODE_CFG)
#define G_MSG_VIDEO_STANDARD_CFG   _MSG(ISIL_SET_VIDEO_STDANDARD)
#define G_MSG_NET_CLOSE                 _MSG(IE_TYPE_NET_CLOSE)

#define MSG_TYPE_FM_REMOTE_CLOSE   _MSG(5000)

#define MSG_TYPE_FM_REMOTE_PLAY    _MSG(5001)

#define MSG_TYPE_FM_REMOTE_PAUSE    _MSG(5002)

#define MSG_TYPE_FM_REMOTE_STOP    _MSG(5003)

#define MSG_TYPE_FM_REMOTE_GET_FRAME    _MSG(5004)

#define PB_MSG_REQ_FRAMES    _MSG(5005)

#define NETLINK_REQ_MSG    _MSG(5006)

//#define LOCAL_GUI_ON_BOARD

#ifdef __LITTLE_ENDIAN_BITFIELD


#define _swab32(x) (x)

#define _swab16(x) (x)

#else

#ifdef LOCAL_GUI_ON_BOARD

	#define _swab32(x) (x)

	#define _swab16(x) (x)

#else
#define _swab16(x) \
({ \
        uint16_t __x = (x); \
        ((uint16_t)( \
                (((uint16_t)(__x) & (uint16_t)0x00ffU) << 8) | \
                (((uint16_t)(__x) & (uint16_t)0xff00U) >> 8) )); \
})

#define _swab32(x) \
({ \
        uint32_t __x = (x); \
        ((uint32_t)( \
                (((uint32_t)(__x) & (uint32_t)0x000000ffUL) << 24) | \
                (((uint32_t)(__x) & (uint32_t)0x0000ff00UL) <<  8) | \
                (((uint32_t)(__x) & (uint32_t)0x00ff0000UL) >>  8) | \
                (((uint32_t)(__x) & (uint32_t)0xff000000UL) >> 24) )); \
})

#endif


#endif

/* �û�Ȩ�� */
enum
{
	RIGHT_DEVICECFG				= 0,	/*	�豸����			*/
	RIGHT_DEVICEBASECFG			= 1,	/*	�豸��������		*/
	RIGHT_NETCFG				= 2,	/*	�������			*/
	RIGHT_USERCFG				= 3,	/*	�û�����			*/
	RIGHT_USERGROUPCFG			= 4,	/*	�û������			*/
	RIGHT_PTZPROTOCOL			= 5,	/*	�豸������̨Э��	*/
	RIGHT_DEVICEPOWER			= 6,	/*	�豸֧�ֹ���		*/

	RIGHT_STREAMCFG				= 20,	/*	ͨ�������в���		*/
	RIGHT_VIDEOMOTIONCFG		= 21,	/*	��Ƶͨ���ƶ�������*/
	RIGHT_VIDEOSHELTERCFG		= 22,	/*	��Ƶͨ���ڵ�������*/
	RIGHT_VIDEOMASKCFG			= 23,	/*	��Ƶͨ��ͼ�����β���*/
	RIGHT_VIDEOLOSTCFG			= 24,	/*	��Ƶͨ����Ƶ��ʧ����*/
	RIGHT_VIDEOSIGNALCFG		= 25,	/*	��Ƶͨ����Ƶ�źŲ���*/
	RIGHT_ENCODECFG				= 26,	/*	ͨ���������		*/
	RIGHT_VIDEOOVERLAYCFG		= 27,	/*	��ͼ����Ӳ���		*/

	RIGHT_ALARMINCFG			= 40,	/*	�����������		*/
	RIGHT_OUTCTRLCFG			= 41,	/*	������Ʋ���		*/
	RIGHT_ALARMINCFG_ALL		= 42,	/*	���������������	*/
	RIGHT_OUTCTRLCFG_ALL		= 43,	/*	������Ʋ���		*/

	RIGHT_PTZCTRL				= 50,	/*	��̨				*/
	RIGHT_COMMCFG				= 51,	/*	��������			*/
	RIGHT_COMM_SENDDATA			= 52,	/*	͸�����ݴ���		*/
	RIGHT_COMM_CAPDATA			= 53,	/*	�ɼ�͸������		*/
	RIGHT_PTZCFG				= 55,	/*	������̨��Ϣ		*/
	RIGHT_PTZPRESETCFG			= 56,	/*	������̨Ԥ��λ��Ϣ	*/
	RIGHT_SHOOTIMAGE			= 57,	/*	ץ��ͼƬ			*/
	RIGHT_MANUALSTARTRECORD		= 58,	/*	�ֶ���������¼��	*/
	RIGHT_MANUALSTOPRECORD		= 59,	/*	�ֶ�����ֹͣ¼��	*/

	RIGHT_UPDATE				= 70,	/*	�豸����			*/

	/*----------------------------------------------------------------------*/

	/* ʵʱ���Ȩ�� */

	CHAN_1_MONITOR					= 256,
	CHAN_2_MONITOR					= 257,
	CHAN_3_MONITOR					= 258,
	CHAN_4_MONITOR					= 259,
	CHAN_5_MONITOR					= 260,
	CHAN_6_MONITOR					= 261,
	CHAN_7_MONITOR					= 262,
	CHAN_8_MONITOR					= 263,
	CHAN_9_MONITOR					= 264,
	CHAN_10_MONITOR					= 265,
	CHAN_11_MONITOR					= 266,
	CHAN_12_MONITOR					= 267,
	CHAN_13_MONITOR					= 268,
	CHAN_14_MONITOR					= 269,
	CHAN_15_MONITOR					= 270,
	CHAN_16_MONITOR					= 271,
	CHAN_17_MONITOR					= 272,
	CHAN_18_MONITOR					= 273,
	CHAN_19_MONITOR					= 274,
	CHAN_20_MONITOR					= 275,
	CHAN_21_MONITOR					= 276,
	CHAN_22_MONITOR					= 277,
	CHAN_23_MONITOR					= 278,
	CHAN_24_MONITOR					= 279,
	CHAN_25_MONITOR					= 280,
	CHAN_26_MONITOR					= 281,
	CHAN_27_MONITOR					= 282,
	CHAN_28_MONITOR					= 283,
	CHAN_29_MONITOR					= 284,
	CHAN_30_MONITOR					= 285,
	CHAN_31_MONITOR					= 286,
	CHAN_32_MONITOR					= 287,
	CHAN_33_MONITOR					= 288,
	CHAN_34_MONITOR					= 289,
	CHAN_35_MONITOR					= 290,
	CHAN_36_MONITOR					= 291,
	CHAN_37_MONITOR					= 292,
	CHAN_38_MONITOR					= 293,
	CHAN_39_MONITOR					= 294,
	CHAN_40_MONITOR					= 295,
	CHAN_41_MONITOR					= 296,
	CHAN_42_MONITOR					= 297,
	CHAN_43_MONITOR					= 298,
	CHAN_44_MONITOR					= 299,
	CHAN_45_MONITOR					= 300,
	CHAN_46_MONITOR					= 301,
	CHAN_47_MONITOR					= 302,
	CHAN_48_MONITOR					= 303,
	CHAN_49_MONITOR					= 304,
	CHAN_50_MONITOR					= 305,
	CHAN_51_MONITOR					= 306,
	CHAN_52_MONITOR					= 307,
	CHAN_53_MONITOR					= 308,
	CHAN_54_MONITOR					= 309,
	CHAN_55_MONITOR					= 310,
	CHAN_56_MONITOR					= 311,
	CHAN_57_MONITOR					= 312,
	CHAN_58_MONITOR					= 313,
	CHAN_59_MONITOR					= 314,
	CHAN_60_MONITOR					= 315,
	CHAN_61_MONITOR					= 316,
	CHAN_62_MONITOR					= 317,
	CHAN_63_MONITOR					= 318,
	CHAN_64_MONITOR					= 319,

	/*----------------------------------------------------------------------*/

	/* ͨ���ط� */

	PLAY_BACK_CHAN_1				= 512,
	PLAY_BACK_CHAN_2				= 513,
	PLAY_BACK_CHAN_3				= 514,
	PLAY_BACK_CHAN_4				= 515,
	PLAY_BACK_CHAN_5				= 516,
	PLAY_BACK_CHAN_6				= 517,
	PLAY_BACK_CHAN_7				= 518,
	PLAY_BACK_CHAN_8				= 519,
	PLAY_BACK_CHAN_9				= 520,
	PLAY_BACK_CHAN_10				= 521,
	PLAY_BACK_CHAN_11				= 522,
	PLAY_BACK_CHAN_12				= 523,
	PLAY_BACK_CHAN_13				= 524,
	PLAY_BACK_CHAN_14				= 525,
	PLAY_BACK_CHAN_15				= 526,
	PLAY_BACK_CHAN_16				= 527,
	PLAY_BACK_CHAN_17				= 528,
	PLAY_BACK_CHAN_18				= 529,
	PLAY_BACK_CHAN_19				= 530,
	PLAY_BACK_CHAN_20				= 531,
	PLAY_BACK_CHAN_21				= 532,
	PLAY_BACK_CHAN_22				= 533,
	PLAY_BACK_CHAN_23				= 534,
	PLAY_BACK_CHAN_24				= 535,
	PLAY_BACK_CHAN_25				= 536,
	PLAY_BACK_CHAN_26				= 537,
	PLAY_BACK_CHAN_27				= 538,
	PLAY_BACK_CHAN_28				= 539,
	PLAY_BACK_CHAN_29				= 540,
	PLAY_BACK_CHAN_30				= 541,
	PLAY_BACK_CHAN_31				= 542,
	PLAY_BACK_CHAN_32				= 543,
	PLAY_BACK_CHAN_33				= 544,
	PLAY_BACK_CHAN_34				= 545,
	PLAY_BACK_CHAN_35				= 546,
	PLAY_BACK_CHAN_36				= 547,
	PLAY_BACK_CHAN_37				= 548,
	PLAY_BACK_CHAN_38				= 549,
	PLAY_BACK_CHAN_39				= 550,
	PLAY_BACK_CHAN_40				= 551,
	PLAY_BACK_CHAN_41				= 552,
	PLAY_BACK_CHAN_42				= 553,
	PLAY_BACK_CHAN_43				= 554,
	PLAY_BACK_CHAN_44				= 555,
	PLAY_BACK_CHAN_45				= 556,
	PLAY_BACK_CHAN_46				= 557,
	PLAY_BACK_CHAN_47				= 558,
	PLAY_BACK_CHAN_48				= 559,
	PLAY_BACK_CHAN_49				= 560,
	PLAY_BACK_CHAN_50				= 561,
	PLAY_BACK_CHAN_51				= 562,
	PLAY_BACK_CHAN_52				= 563,
	PLAY_BACK_CHAN_53				= 564,
	PLAY_BACK_CHAN_54				= 565,
	PLAY_BACK_CHAN_55				= 566,
	PLAY_BACK_CHAN_56				= 567,
	PLAY_BACK_CHAN_57				= 568,
	PLAY_BACK_CHAN_58				= 569,
	PLAY_BACK_CHAN_59				= 570,
	PLAY_BACK_CHAN_60				= 571,
	PLAY_BACK_CHAN_61				= 572,
	PLAY_BACK_CHAN_62				= 573,
	PLAY_BACK_CHAN_63				= 574,
	PLAY_BACK_CHAN_64				= 575,

	/*----------------------------------------------------------------------*/

	/* ͨ��ʵʱԤ�� */

	REALPLAY_CHAN_1					= 768,
	REALPLAY_CHAN_2					= 769,
	REALPLAY_CHAN_3					= 770,
	REALPLAY_CHAN_4					= 771,
	REALPLAY_CHAN_5					= 772,
	REALPLAY_CHAN_6					= 773,
	REALPLAY_CHAN_7					= 774,
	REALPLAY_CHAN_8					= 775,
	REALPLAY_CHAN_9					= 776,
	REALPLAY_CHAN_10				= 777,
	REALPLAY_CHAN_11				= 778,
	REALPLAY_CHAN_12				= 779,
	REALPLAY_CHAN_13				= 780,
	REALPLAY_CHAN_14				= 781,
	REALPLAY_CHAN_15				= 782,
	REALPLAY_CHAN_16				= 783,
	REALPLAY_CHAN_17				= 784,
	REALPLAY_CHAN_18				= 785,
	REALPLAY_CHAN_19				= 786,
	REALPLAY_CHAN_20				= 787,
	REALPLAY_CHAN_21				= 788,
	REALPLAY_CHAN_22				= 789,
	REALPLAY_CHAN_23				= 790,
	REALPLAY_CHAN_24				= 791,
	REALPLAY_CHAN_25				= 792,
	REALPLAY_CHAN_26				= 793,
	REALPLAY_CHAN_27				= 794,
	REALPLAY_CHAN_28				= 795,
	REALPLAY_CHAN_29				= 796,
	REALPLAY_CHAN_30				= 797,
	REALPLAY_CHAN_31				= 798,
	REALPLAY_CHAN_32				= 799,
	REALPLAY_CHAN_33				= 800,
	REALPLAY_CHAN_34				= 801,
	REALPLAY_CHAN_35				= 802,
	REALPLAY_CHAN_36				= 803,
	REALPLAY_CHAN_37				= 804,
	REALPLAY_CHAN_38				= 805,
	REALPLAY_CHAN_39				= 806,
	REALPLAY_CHAN_40				= 807,
	REALPLAY_CHAN_41				= 808,
	REALPLAY_CHAN_42				= 809,
	REALPLAY_CHAN_43				= 810,
	REALPLAY_CHAN_44				= 811,
	REALPLAY_CHAN_45				= 812,
	REALPLAY_CHAN_46				= 813,
	REALPLAY_CHAN_47				= 814,
	REALPLAY_CHAN_48				= 815,
	REALPLAY_CHAN_49				= 816,
	REALPLAY_CHAN_50				= 817,
	REALPLAY_CHAN_51				= 818,
	REALPLAY_CHAN_52				= 819,
	REALPLAY_CHAN_53				= 820,
	REALPLAY_CHAN_54				= 821,
	REALPLAY_CHAN_55				= 822,
	REALPLAY_CHAN_56				= 823,
	REALPLAY_CHAN_57				= 824,
	REALPLAY_CHAN_58				= 825,
	REALPLAY_CHAN_59				= 826,
	REALPLAY_CHAN_60				= 827,
	REALPLAY_CHAN_61				= 828,
	REALPLAY_CHAN_62				= 829,
	REALPLAY_CHAN_63				= 830,
	REALPLAY_CHAN_64				= 831,
};

#ifdef __cplusplus
}
#endif

#endif

