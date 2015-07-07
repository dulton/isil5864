#ifndef __ISIL_LOCAL_NET_MSG_H__
#define __ISIL_LOCAL_NET_MSG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "isil_messagestruct.h"
//#include "isil_parsemessage.h"

#define WORD	unsigned short
#define DWORD	unsigned long
#define LPDWORD	DWORD*
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define LONG	long
#define UINT	unsigned int
#define HDC		void*
#define HWND	void*
#define LPVOID	void*
//#define NULL	0
/****************************************BEGIN***************************************************/



//////////////////////////////////////////////////////////////////////////
//	��ѯ����
typedef enum
{
	ABILITY_WATERMARK_CFG = 17,			//ˮӡ��������
	ABILITY_WIRELESS_CFG = 18,			//wireless��������
	ABILITY_DEVALL_INFO = 26,			//�豸�������б�
	ABILITY_CARD_QUERY = 0x0100,		//���Ų�ѯ����
	ABILITY_MULTIPLAY = 0x0101,			//�໭��Ԥ������
	ABILITY_QUICK_QUERY_CFG = 0x0102,	//���ٲ�ѯ��������
	ABILITY_INFRARED = 0x0121,			//���߱�������
	ABILITY_TRIGGER_MODE = 0x0131,		//�������������ʽ����
	ABILITY_DISK_SUBAREA = 0x0141,		//����Ӳ�̷�������
	ABILITY_DSP_CFG = 0x0151,		//��ѯdsp����
} DH_SYS_ABILITY;

//////////////////////////////////////////////////////////////////////////
//	�豸֧�ֹ����б�
enum
{
	EN_FTP = 0,							//FTP ��λ��1������¼���ļ� 2������ץͼ�ļ�
	EN_SMTP,							//SMTP ��λ��1�����������ı��ʼ� 2����������ͼƬ
	EN_NTP,								//NTP	��λ��1������ϵͳʱ��
	EN_AUTO_MAINTAIN,					//�Զ�ά�� ��λ��1������ 2���ر� 3:ɾ���ļ�
	EN_VIDEO_COVER,						//�����ڵ� ��λ��1���������ڵ�
	EN_AUTO_REGISTER,					//����ע��	��λ��1��ע���sdk������½
	EN_DHCP,							//DHCP	��λ��1��DHCP
	EN_UPNP,							//UPNP	��λ��1��UPNP
	EN_COMM_SNIFFER,					//����ץ�� ��λ��1:CommATM
	EN_NET_SNIFFER,						//����ץ�� ��λ�� 1��NetSniffer
	EN_BURN,							//��¼���� ��λ��1����ѯ��¼״̬
	EN_VIDEO_MATRIX,					//��Ƶ���� ��λ��1���Ƿ�֧����Ƶ����
	EN_AUDIO_DETECT,					//��Ƶ��� ��λ��1���Ƿ�֧����Ƶ���
	EN_STORAGE_STATION,					//�洢λ�� ��λ��1��Ftp������(Ips) 2��SBM 3��NFS 16��DISK 17��U��
	EN_IPSSEARCH,						//IPS�洢��ѯ ��λ��1��IPS�洢��ѯ
	EN_SNAP,							//ץͼ  ��λ��1���ֱ���2��֡��3��ץͼ��ʽ4��ץͼ�ļ���ʽ5��ͼ������
	EN_DEFAULTNIC,						//֧��Ĭ��������ѯ ��λ 1��֧��
	EN_SHOWQUALITY,						//CBRģʽ����ʾ���������� ��λ 1:֧��
	EN_CONFIG_IMEXPORT,					//���õ��뵼���������� ��λ 1:֧��
	EN_LOG,								//�Ƿ�֧�ַ�ҳ��ʽ����־��ѯ ��λ 1��֧��
	EN_SCHEDULE,						//¼�����õ�һЩ���� ��λ 1:���� 2:Ԥ¼ 3:¼��ʱ���
	EN_NETWORK_TYPE,					//�������Ͱ�λ��ʾ 1:��̬�� 2:���߾��� 3:CDMA/GPRS
	EN_MARK_IMPORTANTRECORD,			//��ʶ��Ҫ¼�� ��λ:1��������Ҫ¼���ʶ
	EN_ACFCONTROL,						//�֡�ʿ��� ��λ��1��֧�ֻ֡�ʿ���
	EN_MULTIASSIOPTION,					//��·������ ��λ��1��֧����·������
	EN_DAVINCIMODULE,					//�����ģ�� ��λ��1��ʱ���ֿ����� 2:��׼I֡�������
	EN_GPS,                             //GPS���� ��λ��1��Gps��λ����
};

typedef struct
{
	DWORD IsFucEnable[512];				//�����б�������,�±��Ӧ������ö��ֵ,��λ��ʾ�ӹ���
} DH_DEV_ENABLE_INFO;

//////////////////////////////////////////////////////////////////////////
//	���Ų�ѯ�����ṹ��
typedef struct
{
	char		IsCardQueryEnable;
	char		iRev[3];
} DH_CARD_QUERY_EN;

//////////////////////////////////////////////////////////////////////////
//	wireless�����ṹ��
typedef struct
{
	char		IsWirelessEnable;
	char		iRev[3];
} DH_WIRELESS_EN;

//////////////////////////////////////////////////////////////////////////
//	ͼ��ˮӡ�����ṹ��
typedef struct
{
	char		isSupportWM;	//1 ֧�֣�0 ��֧��
	char		supportWhat;	//0������ˮӡ��1��ͼƬˮӡ��2��ͬʱ֧������ˮӡ��ͼƬˮӡ
	char		reserved[2];
} DH_WATERMAKE_EN;

//////////////////////////////////////////////////////////////////////////
//	�໭��Ԥ�������ṹ��
typedef struct
{
	int			nEnable;			//1 ֧�֣�0 ��֧��
	DWORD		dwMultiPlayMask;	//�໭��Ԥ������
	char		reserved[4];		//����
} DH_MULTIPLAY_EN;

//////////////////////////////////////////////////////////////////////////
//	���߱��������ṹ��
typedef struct
{
	BOOL		bSupport;//�Ƿ�֧��
	int			nAlarmInCount;//�������
	int			nAlarmOutCount;//�������
	int			nRemoteAddrCount;//ң��������
	BYTE		reserved[32];
} DH_WIRELESS_ALARM_INFO;

//////////////////////////////////////////////////////////////////////////
// ����Ӳ�̷��������ṹ��
typedef struct
{
	BOOL		bSupported;//�Ƿ�֧������Ӳ�̷���
	int			nSupportNum;//֧�ַ�������Ŀ
	BYTE		bReserved[32];//�����ֽ�
} DH_DISK_SUBAREA_EN;

// DSP������ѯ����DSP�����㷨��ʶΪ2ʱʹ�á�
typedef struct
{
	BYTE bMainFrame[32];		//�Էֱ���ö��ֵ(CAPTURE_SIZE)Ϊ����,�������ֱ��ʶ�Ӧ֧�ֵ����֡��,�����֧�ִ˷ֱ���,��ֵΪ0.
	BYTE bExtraFrame_1[32];		//������1,ʹ��ͬbMainFrame
	BYTE bReserved[128];		//Ԥ����������2��3.
}DH_DSP_CFG_ITEM;

typedef struct
{
	int nItemNum;						//DH_DSP_CFG_ITEM����Ч����,����ͨ����
	DH_DSP_CFG_ITEM	stuDspCfgItem[32];	//����������Ϣ
	BYTE bReserved[128];				//����
}DH_DSP_CFG;

//////////////////////////////////////////////////////////////////////////
//	���ٲ�ѯ���������ṹ��
typedef struct
{
	char		IsQuickQueryEnable;    //1���豸֧������������ٷ��أ�����������ʱ���㹻���Ա�֤խ�������õ�������ȡ����������60S
	char		iRev[3];
} DH_QUICK_QUERY_CFG_EN;

/****************************************END***************************************************/

#define ISIL_SERIALNO_LEN 			48			// �豸���к��ַ�����
#define ISIL_MAX_DISKNUM 			256			// ���Ӳ�̸���
#define ISIL_MAX_SDCARDNUM			32			// ���SD������
#define ISIL_MAX_BURNING_DEV_NUM		32			// ����¼�豸����
#define ISIL_BURNING_DEV_NAMELEN		32			// ��¼�豸������󳤶�
#define ISIL_MAX_LINK 				6
#define ISIL_MAX_CHANNUM 			16			// ���ͨ������
#define ISIL_MAX_ALARMIN 			128			// ��󱨾��������
#define ISIL_MAX_ALARMOUT 			64			// ��󱨾��������
#define ISIL_MAX_RIGHT_NUM			100			// �û�Ȩ�޸�������
#define ISIL_MAX_GROUP_NUM			20			// �û����������
#define ISIL_MAX_USER_NUM			200			// �û���������
#define ISIL_RIGHT_NAME_LENGTH		32			// Ȩ��������
#define ISIL_USER_NAME_LENGTH		8			// �û�������
#define ISIL_USER_PSW_LENGTH			8			// �û����볤��
#define ISIL_MEMO_LENGTH				32			// ��ע����
#define ISIL_MAX_STRING_LEN			128
#define ISIL_DVR_SERIAL_RETURN		1			// �豸�������кŻص�
#define ISIL_DVR_DISCONNECT			-1			// ��֤�ڼ��豸���߻ص�
#define MAX_STRING_LINE_LEN			6			// �������
#define MAX_PER_STRING_LEN			20			// ÿ����󳤶�
#define ISIL_MAX_MAIL_NAME_LEN		64			// �µ��ʼ��ṹ��֧�ֵ��û�������
#define ISIL_MAX_MAIL_PSW_LEN		64			// �µ��ʼ��ṹ��֧�ֵ����볤��

// Զ�����ýṹ����س���
#define ISIL_MAX_MAIL_ADDR_LEN		128			// �ʼ���(��)��ַ��󳤶�
#define ISIL_MAX_MAIL_SUBJECT_LEN	64			// �ʼ�������󳤶�
#define ISIL_MAX_IPADDR_LEN			16			// IP��ַ�ַ�������

#ifndef ISIL_MACADDR_LEN
	#define ISIL_MACADDR_LEN				40			// MAC��ַ�ַ�������
#endif
													
#define ISIL_MAX_URL_LEN				128			// URL�ַ�������
#define ISIL_MAX_DEV_ID_LEN			48			// ���������󳤶�
#define	ISIL_MAX_HOST_NAMELEN		64			// ���������ȣ�
#define ISIL_MAX_HOST_PSWLEN			32			// ���볤��
#define ISIL_MAX_NAME_LEN			16			// ͨ�������ַ�������
#define ISIL_MAX_ETHERNET_NUM		2			// ��̫����������
#define	ISIL_DEV_SERIALNO_LEN		48			// ���к��ַ�������
#define ISIL_DEV_TYPE_LEN			32			// �豸�����ַ�������
#define ISIL_N_WEEKS					7			// һ�ܵ�����
#define ISIL_N_TSECT					6			// ͨ��ʱ��θ���
#define ISIL_N_REC_TSECT				6			// ¼��ʱ��θ���
#define ISIL_N_COL_TSECT				2			// ��ɫʱ��θ���
#define ISIL_CHAN_NAME_LEN			32			// ͨ�������ȣ�DVR DSP�������ƣ����32�ֽ�
#define ISIL_N_ENCODE_AUX			3			// ��չ��������
#define ISIL_N_TALK					1			// ���Խ�ͨ������
#define ISIL_N_COVERS				1			// �ڵ��������
#define ISIL_N_CHANNEL				16			// ���ͨ������
#define ISIL_N_ALARM_TSECT			2			// ������ʾʱ��θ���
#define ISIL_MAX_ALARMOUT_NUM		16			// ��������ڸ�������
#define ISIL_MAX_AUDIO_IN_NUM		16			// ��Ƶ����ڸ�������
#define ISIL_MAX_VIDEO_IN_NUM		16			// ��Ƶ����ڸ�������
#define ISIL_MAX_ALARM_IN_NUM		16			// ��������ڸ�������
#define ISIL_MAX_DISK_NUM			16			// Ӳ�̸������ޣ��ݶ�Ϊ16
#define ISIL_MAX_DECODER_NUM			16			// ������(485)��������
#define ISIL_MAX_232FUNCS			10			// 232���ڹ��ܸ�������
#define ISIL_MAX_232_NUM				2			// 232���ڸ�������
#define ISIL_MAX_DECPRO_LIST_SIZE	100			// ������Э���б��������
#define ISIL_FTP_MAXDIRLEN			240			// FTP�ļ�Ŀ¼��󳤶�
#define ISIL_MATRIX_MAXOUT			16			// ���������������
#define ISIL_TOUR_GROUP_NUM			6			// ���������������
#define ISIL_MAX_DDNS_NUM			10			// �豸֧�ֵ�ddns������������
#define ISIL_MAX_SERVER_TYPE_LEN		32			// ddns���������ͣ�����ַ�������
#define ISIL_MAX_DOMAIN_NAME_LEN		256			// ddns����������ַ�������
#define ISIL_MAX_DDNS_ALIAS_LEN		32			// ddns����������������ַ�������
#define ISIL_MOTION_ROW				32			// ��̬������������
#define ISIL_MOTION_COL				32			// ��̬������������
#define	ISIL_FTP_USERNAME_LEN			64			// FTP���ã��û�����󳤶�
#define	ISIL_FTP_PASSWORD_LEN			64			// FTP���ã�������󳤶�
#define	ISIL_TIME_SECTION				2			// FTP���ã�ÿ��ʱ��θ���
#define ISIL_FTP_MAX_PATH				240			// FTP���ã��ļ�·������󳤶�
#define ISIL_INTERVIDEO_UCOM_CHANID	32			// ƽ̨�������ã�U��ͨͨ��ID
#define ISIL_INTERVIDEO_UCOM_DEVID	32			// ƽ̨�������ã�U��ͨ�豸ID
#define ISIL_INTERVIDEO_UCOM_REGPSW	16			// ƽ̨�������ã�U��ͨע������
#define ISIL_INTERVIDEO_UCOM_USERNAME	32			// ƽ̨�������ã�U��ͨ�û���
#define ISIL_INTERVIDEO_UCOM_USERPSW	32			// ƽ̨�������ã�U��ͨ����
#define ISIL_INTERVIDEO_NSS_IP		32			// ƽ̨�������ã�������άIP
#define ISIL_INTERVIDEO_NSS_SERIAL	32			// ƽ̨�������ã�������άserial
#define ISIL_INTERVIDEO_NSS_USER		32			// ƽ̨�������ã�������άuser
#define ISIL_INTERVIDEO_NSS_PWD		50			// ƽ̨�������ã�������άpassword
#define ISIL_MAX_VIDEO_COVER_NUM		16			// �ڵ�����������
#define ISIL_MAX_WATERMAKE_DATA		4096		// ˮӡͼƬ������󳤶�
#define ISIL_MAX_WATERMAKE_LETTER		128			// ˮӡ������󳤶�
#define ISIL_MAX_WLANDEVICE_NUM		10			// ����������������豸����
#define ISIL_MAX_ALARM_NAME			64			// ��ַ����
#define ISIL_MAX_REGISTER_SERVER_NUM	10			// ����ע�����������
#define ISIL_SNIFFER_FRAMEID_NUM		6			// 6��FRAME ID ѡ��
#define ISIL_SNIFFER_CONTENT_NUM		4			// ÿ��FRAME��Ӧ��4��ץ������
#define ISIL_SNIFFER_CONTENT_NUM_EX	8			// ÿ��FRAME��Ӧ��8��ץ������
#define ISIL_SNIFFER_PROTOCOL_SIZE	20			// Э�����ֳ���
#define ISIL_MAX_PROTOCOL_NAME_LENGTH 20
#define ISIL_SNIFFER_GROUP_NUM		4			// 4��ץ������
#define MAX_PATH_STOR				240			// Զ��Ŀ¼�ĳ���
#define ISIL_ALARM_OCCUR_TIME_LEN		40			// �µı����ϴ�ʱ��ĳ���
#define ISIL_VIDEO_OSD_NAME_NUM		64			// ���ӵ����Ƴ��ȣ�Ŀǰ֧��32��Ӣ�ģ�16������
#define ISIL_VIDEO_CUSTOM_OSD_NUM		8			// ֧�ֵ��Զ�����ӵ���Ŀ��������ʱ���ͨ��
#define ISIL_CONTROL_AUTO_REGISTER_NUM 100        // ֧�ֶ�������ע��������ĸ���
#define ISIL_MMS_RECEIVER_NUM          100        // ֧�ֶ��Ž����ߵĸ���
#define ISIL_MMS_SMSACTIVATION_NUM     100        // ֧�ֶ��ŷ����ߵĸ���
#define ISIL_MMS_DIALINACTIVATION_NUM  100        // ֧�ֲ��ŷ����ߵĸ���
#define ISIL_MAX_ALARMOUT_NUM_EX		 32			// ��������ڸ���������չ
#define ISIL_MAX_VIDEO_IN_NUM_EX		 32			// ��Ƶ����ڸ���������չ
#define ISIL_MAX_ALARM_IN_NUM_EX		 32			// ��������ڸ�������

// ��ѯ���ͣ���ӦISIL_CLIENT_QueryDevState�ӿ�
#define ISIL_DEVSTATE_COMM_ALARM		0x0001		// ��ѯ��ͨ����״̬(�����ⲿ��������Ƶ��ʧ����̬���)
#define ISIL_DEVSTATE_SHELTER_ALARM	0x0002		// ��ѯ�ڵ�����״̬
#define ISIL_DEVSTATE_RECORDING		0x0003		// ��ѯ¼��״̬
#define ISIL_DEVSTATE_DISK			0x0004		// ��ѯӲ����Ϣ
#define ISIL_DEVSTATE_RESOURCE		0x0005		// ��ѯϵͳ��Դ״̬
#define ISIL_DEVSTATE_BITRATE			0x0006		// ��ѯͨ������
#define ISIL_DEVSTATE_CONN			0x0007		// ��ѯ�豸����״̬
#define ISIL_DEVSTATE_PROTOCAL_VER	0x0008		// ��ѯ����Э��汾�ţ�pBuf = int*
#define ISIL_DEVSTATE_TALK_ERROR_CTYPE		0x0009		// ��ѯ�豸֧�ֵ������Խ���ʽ�б����ṹ��ISIL_DEV_TALKFORMAT_LIST
#define ISIL_DEVSTATE_SD_CARD			0x000A		// ��ѯSD����Ϣ(IPC���Ʒ)
#define ISIL_DEVSTATE_BURNING_DEV		0x000B		// ��ѯ��¼����Ϣ
#define ISIL_DEVSTATE_BURNING_PROGRESS 0x000C		// ��ѯ��¼����
#define ISIL_DEVSTATE_PLATFORM		0x000D		// ��ѯ�豸֧�ֵĽ���ƽ̨
#define ISIL_DEVSTATE_CAMERA			0x000E		// ��ѯ����ͷ������Ϣ(IPC���Ʒ)��pBuf = ISIL_DEV_CAMERA_INFO *�������ж���ṹ��
#define ISIL_DEVSTATE_SOFTWARE		0x000F		// ��ѯ�豸����汾��Ϣ
#define ISIL_DEVSTATE_LANGUAGE        0x0010		// ��ѯ�豸֧�ֵ���������
#define ISIL_DEVSTATE_DSP				0x0011		// ��ѯDSP��������
#define	ISIL_DEVSTATE_OEM				0x0012		// ��ѯOEM��Ϣ
#define	ISIL_DEVSTATE_NET				0x0013		// ��ѯ��������״̬��Ϣ
#define ISIL_DEVSTATE_TYPE			0x0014		// ��ѯ�豸����
#define ISIL_DEVSTATE_SNAP			0x0015		// ��ѯץͼ��������(IPC���Ʒ)
#define ISIL_DEVSTATE_RECORD_TIME		0x0016		// ��ѯ����¼��ʱ������¼��ʱ��
#define ISIL_DEVSTATE_NET_RSSI        0x0017      // ��ѯ���������ź�ǿ�ȣ����ṹ��ISIL_DEV_WIRELESS_RSS_INFO
#define ISIL_DEVSTATE_BURNING_ATTACH	0x0018		// ��ѯ������¼ѡ��

// �������ͣ���ӦISIL_CLIENT_GetDevConfig��ISIL_CLIENT_SetDevConfig�ӿ�
#define ISIL_DEV_DEVICECFG			0x0001		// �豸��������
#define ISIL_DEV_NETCFG				0x0002		// ��������
#define ISIL_DEV_CHANNELCFG			0x0003		// ͼ��ͨ������
#define ISIL_DEV_PREVIEWCFG 			0x0004		// Ԥ����������
#define ISIL_DEV_RECORDCFG			0x0005		// ¼������
#define ISIL_DEV_COMMCFG				0x0006		// ������������
#define ISIL_DEV_ALARMCFG 			0x0007		// ������������
#define ISIL_DEV_TIMECFG 				0x0008		// DVRʱ������
#define ISIL_DEV_TALKCFG				0x0009		// �Խ���������
#define ISIL_DEV_AUTOMTCFG			0x000A		// �Զ�ά������
#define	ISIL_DEV_VEDIO_MARTIX			0x000B		// ����������Ʋ�������
#define ISIL_DEV_MULTI_DDNS			0x000C		// ��ddns����������
#define ISIL_DEV_SNAP_CFG_INFO				0x000D		// ץͼ�������
#define ISIL_DEV_WEB_URL_CFG			0x000E		// HTTP·������
#define ISIL_DEV_FTP_PROTO_CFG_INFO		0x000F		// FTP�ϴ�����
#define ISIL_DEV_INTERVIDEO_CFG		0x0010		// ƽ̨�������ã���ʱchannel��������ƽ̨���ͣ�
												// channel=4���������������أ�channel=10������������ά��channel=11������U��ͨ
#define ISIL_DEV_VIDEO_COVER			0x0011		// �����ڵ�����
#define ISIL_DEV_TRANS_STRATEGY		0x0012		// ����������ã���������\����������
#define ISIL_DEV_DOWNLOAD_STRATEGY	0x0013		// ¼�����ز������ã���������\��ͨ����
#define ISIL_DEV_WATERMAKE_CFG_INFO		0x0014		// ͼ��ˮӡ����
#define ISIL_DEV_WLAN_CFG				0x0015		// ������������
#define ISIL_DEV_WLAN_DEVICE_CFG		0x0016		// ���������豸����
#define ISIL_DEV_REGISTER_CFG			0x0017		// ����ע���������
#define ISIL_DEV_CAMERA_CFG_INFO			0x0018		// ����ͷ��������
#define ISIL_DEV_INFRARED_CFG 		0x0019		// ���ⱨ������
#define ISIL_DEV_SNIFFER_CFG_INFO			0x001A		// Snifferץ������
#define ISIL_DEV_MAIL_CFG_INFO				0x001B		// �ʼ�����
#define ISIL_DEV_DNS_CFG_INFO				0x001C		// DNS����������
#define ISIL_DEV_NTP_CFG_INFO				0x001D		// NTP����
#define ISIL_DEV_AUDIO_DETECT_CFG		0x001E		// ��Ƶ�������
#define ISIL_DEV_STORAGE_STATION_CFG  0x001F      // �洢λ������
#define ISIL_DEV_PTZ_OPT_CFG			0x0020		// ��̨��������(�Ѿ��ϳ�����ʹ��ISIL_CLIENT_GetPtzOptAttr��ȡ��̨��������)
#define ISIL_DEV_DST_CFG_INFO		0x0021      // ����ʱ����
#define ISIL_DEV_ALARM_CENTER_CFG		0x0022		// ������������
#define ISIL_DEV_VIDEO_OSD_CFG        0x0023		// ��ƵOSD��������
#define ISIL_DEV_CDMAGPRS_CFG_INFO         0x0024		// CDMA\GPRS��������
#define ISIL_DEV_IPFILTER_CFG         0x0025		// IP��������
#define ISIL_DEV_TALK_ENCODE_CFG_INFO      0x0026      // �����Խ���������
#define ISIL_DEV_RECORD_PACKET_CFG_INFO    0X0027      // ¼������������
#define ISIL_DEV_MMS_CFG_INFO              0X0028		// ����MMS����
#define ISIL_DEV_SMSACTIVATION_CFG_INFO	0X0029		// ���ż���������������
#define ISIL_DEV_DIALINACTIVATION_CFG_INFO	0X002A		// ���ż���������������
#define ISIL_DEV_FILETRANS_STOP		0x002B		// ֹͣ�ļ��ϴ�
#define ISIL_DEV_FILETRANS_BURN		0x002C		// ��¼�ļ��ϴ�
#define ISIL_DEV_SNIFFER_CFG_EX		0x0030		// ����ץ������
#define ISIL_DEV_DOWNLOAD_RATE_CFG	0x0031		// �����ٶ�����
#define ISIL_DEV_PANORAMA_SWITCH_CFG	0x0032		// ȫ���л���������
#define ISIL_DEV_LOST_FOCUS_CFG		0x0033		// ʧȥ���㱨������
#define ISIL_DEV_ALARM_DECODE_CFG		0x0034		// ��������������
#define ISIL_DEV_VIDEOOUT_CFG         0x0035      // ��Ƶ�����������
#define ISIL_DEV_POINT_CFG_INFO			0x0036		// Ԥ�Ƶ�ʹ������
#define ISIL_DEV_IP_COLLISION_CFG     0x0037      // Ip��ͻ��ⱨ������
#define ISIL_DEV_OSD_ENABLE_CFG_INFO		0x0038		// OSD����ʹ������
#define ISIL_DEV_LOCALALARM_CFG 		0x0039		// ���ر�������(�ṹ��ISIL_ALARMIN_CFG_EX)
#define ISIL_DEV_NETALARM_CFG 		0x003A		// ���籨������(�ṹ��ISIL_ALARMIN_CFG_EX)
#define ISIL_DEV_MOTIONALARM_CFG 		0x003B		// ���챨������(�ṹ��ISIL_MOTION_DETECT_CFG_EX)
#define ISIL_DEV_VIDEOLOSTALARM_CFG 	0x003C		// ��Ƶ��ʧ��������(�ṹ��ISIL_VIDEO_LOST_CFG_EX)
#define ISIL_DEV_BLINDALARM_CFG 		0x003D		// ��Ƶ�ڵ���������(�ṹ��ISIL_BLIND_CFG_EX)
#define ISIL_DEV_DISKALARM_CFG 		0x003E		// Ӳ�̱�������(�ṹ��ISIL_DISK_ALARM_CFG_EX)
#define ISIL_DEV_NETBROKENALARM_CFG 	0x003F		// �����жϱ�������(�ṹ��ISIL_NETBROKEN_ALARM_CFG_EX)
#define ISIL_DEV_ENCODER_CFG          0x0040      // ����ͨ����ǰ�˱�������Ϣ�����DVRʹ�ã��ṹ��DEV_ENCODER_CFG��

//#define ISIL_LOCAL_SEARCH_FILE       0x07f8


// �������ͣ���ӦISIL_CLIENT_StartListen�ӿ�
#define ISIL_COMM_ALARM				0x1100		// ���汨��(�����ⲿ��������Ƶ��ʧ����̬���)
#define ISIL_SHELTER_ALARM			0x1101		// ��Ƶ�ڵ�����
#define ISIL_DISK_FULL_ALARM			0x1102		// Ӳ��������
#define ISIL_DISK_ERROR_ALARM			0x1103		// Ӳ�̹��ϱ���
#define ISIL_SOUND_DETECT_ALARM		0x1104		// ��Ƶ��ⱨ��
#define ISIL_ALARM_DECODER_ALARM		0x1105		// ��������������

// ��չ�������ͣ���ӦISIL_CLIENT_StartListenEx�ӿ�
#define ISIL_ALARM_ALARM_EX			0x2101		// �ⲿ����
#define ISIL_MOTION_ALARM_EX			0x2102		// ��̬��ⱨ��
#define ISIL_VIDEOLOST_ALARM_EX		0x2103		// ��Ƶ��ʧ����
#define ISIL_SHELTER_ALARM_EX			0x2104		// ��Ƶ�ڵ�����
#define ISIL_SOUND_DETECT_ALARM_EX	0x2105		// ��Ƶ��ⱨ��
#define ISIL_DISKFULL_ALARM_EX		0x2106		// Ӳ��������
#define ISIL_DISKERROR_ALARM_EX		0x2107		// ��Ӳ�̱���
#define ISIL_ENCODER_ALARM_EX			0x210A		// ����������
#define ISIL_URGENCY_ALARM_EX			0x210B		// ��������
#define ISIL_WIRELESS_ALARM_EX		0x210C		// ���߱���
#define ISIL_NEW_SOUND_DETECT_ALARM_EX 0x210D		// ����Ƶ��ⱨ����������Ϣ�Ľṹ���ISIL_NEW_SOUND_ALARM_STATE��
#define ISIL_ALARM_DECODER_ALARM_EX	0x210E		// ��������������
#define ISIL_DECODER_DECODE_ABILITY	0x210F		// ��������������������
#define ISIL_FDDI_DECODER_ABILITY		0x2110		// ���˱�����״̬����
#define ISIL_PANORAMA_SWITCH_ALARM_EX	0x2111		// �л���������
#define ISIL_LOSTFOCUS_ALARM_EX		0x2112		// ʧȥ���㱨��
#define ISIL_OEMSTATE_EX				0x2113		// oem��ͣ״̬
#define ISIL_DSP_ALARM_EX				0x2114		// DSP����
#define ISIL_ATMPOS_BROKEN_EX			0x2115		// atm��pos���Ͽ������� 0�����ӶϿ� 1����������

// �¼�����
#define ISIL_CONFIG_RESULT_EVENT_EX	0x3000		// �޸����õķ����룻���ؽṹ��DEV_SET_RESULT
#define ISIL_REBOOT_EVENT_EX			0x3001		// �豸�����¼������δ�������������ǰ�޸ĵ����ò���������Ч
#define ISIL_AUTO_TALK_START_EX		0x3002		// �豸�������뿪ʼ�����Խ�
#define ISIL_AUTO_TALK_STOP_EX		0x3003		// �豸����ֹͣ�����Խ�
#define ISIL_CONFIG_CHANGE_EX			0x3004		// �豸���÷����ı�

// �����ϴ����ܵı������ͣ���ӦISIL_CLIENT_StartService�ӿڡ�NEW_ALARM_UPLOAD�ṹ��.
#define ISIL_UPLOAD_ALARM				0x4000		// �ⲿ����
#define ISIL_UPLOAD_MOTION_ALARM		0x4001		// ��̬��ⱨ��
#define ISIL_UPLOAD_VIDEOLOST_ALARM	0x4002		// ��Ƶ��ʧ����
#define ISIL_UPLOAD_SHELTER_ALARM		0x4003		// ��Ƶ�ڵ�����
#define ISIL_UPLOAD_SOUND_DETECT_ALARM 0x4004		// ��Ƶ��ⱨ��
#define ISIL_UPLOAD_DISKFULL_ALARM	0x4005		// Ӳ��������
#define ISIL_UPLOAD_DISKERROR_ALARM	0x4006		// ��Ӳ�̱���
#define ISIL_UPLOAD_ENCODER_ALARM		0x4007		// ����������
#define ISIL_UPLOAD_DECODER_ALARM		0x400B		// ��������������
#define ISIL_UPLOAD_EVENT				0x400C		// ��ʱ�ϴ���

/*��ץͼ�Լ�����API֮��*/
#define MSG_SNAP_PICTURE            0x5000


// �첽�ӿڻص�����
#define RESPONSE_DECODER_CTRL_TV	0x00000001	// ��ӦISIL_CLIENT_CtrlDecTVScreen�ӿ�
#define RESPONSE_DECODER_SWITCH_TV	0x00000002	// ��ӦISIL_CLIENT_SwitchDecTVEncoder�ӿ�
#define RESPONSE_DECODER_PLAYBACK	0x00000003	// ��ӦISIL_CLIENT_DecTVPlayback�ӿ�

// �ֱ����б�������ֱ�����������롢�����
#define	ISIL_CAPTURE_SIZE_D1			0x00000001
#define ISIL_CAPTURE_SIZE_HD1			0x00000002
#define ISIL_CAPTURE_SIZE_BCIF		0x00000004
#define ISIL_CAPTURE_SIZE_CIF			0x00000008
#define ISIL_CAPTURE_SIZE_QCIF		0x00000010
#define ISIL_CAPTURE_SIZE_VGA			0x00000020
#define ISIL_CAPTURE_SIZE_QVGA		0x00000040
#define ISIL_CAPTURE_SIZE_SVCD		0x00000080
#define ISIL_CAPTURE_SIZE_QQVGA		0x00000100
#define ISIL_CAPTURE_SIZE_SVGA		0x00000200
#define ISIL_CAPTURE_SIZE_XVGA		0x00000400
#define ISIL_CAPTURE_SIZE_WXGA		0x00000800
#define ISIL_CAPTURE_SIZE_SXGA		0x00001000
#define ISIL_CAPTURE_SIZE_WSXGA		0x00002000
#define ISIL_CAPTURE_SIZE_UXGA		0x00004000
#define ISIL_CAPTURE_SIZE_WUXGA       0x00008000
#define ISIL_CAPTURE_SIZE_LFT         0x00010000
#define ISIL_CAPTURE_SIZE_720		    0x00020000
#define ISIL_CAPTURE_SIZE_1080		0x00040000
#define ISIL_CAPTURE_SIZE_1_3M		0x00080000

// ����ģʽ�б����������ģʽ��������롢�����
#define ISIL_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define ISIL_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define ISIL_CAPTURE_COMP_MPEG2		0x00000004
#define ISIL_CAPTURE_COMP_MPEG1		0x00000008
#define ISIL_CAPTURE_COMP_H263		0x00000010
#define ISIL_CAPTURE_COMP_MJPG		0x00000020
#define ISIL_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define ISIL_CAPTURE_COMP_H264		0x00000080

// �������������������뱨������������������롢�����
#define ISIL_ALARM_UPLOAD				0x00000001
#define ISIL_ALARM_RECORD				0x00000002
#define ISIL_ALARM_PTZ				0x00000004
#define ISIL_ALARM_MAIL				0x00000008
#define ISIL_ALARM_TOUR				0x00000010
#define ISIL_ALARM_TIP				0x00000020
#define ISIL_ALARM_OUT				0x00000040
#define ISIL_ALARM_FTP_UL				0x00000080
#define ISIL_ALARM_BEEP				0x00000100
#define ISIL_ALARM_VOICE				0x00000200
#define ISIL_ALARM_SNAP				0x00000400

// "�ָ�Ĭ������"���룬�ɽ����롢�����
#define ISIL_RESTORE_COMMON			0x00000001	// ��ͨ����
#define ISIL_RESTORE_CODING			0x00000002	// ��������
#define ISIL_RESTORE_VIDEO			0x00000004	// ¼������
#define ISIL_RESTORE_COMM				0x00000008	// ��������
#define ISIL_RESTORE_NETWORK			0x00000010	// ��������
#define ISIL_RESTORE_ALARM			0x00000020	// ��������
#define ISIL_RESTORE_VIDEODETECT		0x00000040	// ��Ƶ���
#define ISIL_RESTORE_PTZ				0x00000080	// ��̨����
#define ISIL_RESTORE_OUTPUTMODE		0x00000100	// ���ģʽ
#define ISIL_RESTORE_CHANNELNAME		0x00000200	// ͨ������
#define ISIL_RESTORE_ALL				0x80000000	// ȫ������

// ��̨�����б�
// ���ĸ��ֽ�����
#define PTZ_DIRECTION				0x00000001	// ����
#define PTZ_ZOOM					0x00000002	// �䱶
#define PTZ_FOCUS					0x00000004	// �۽�
#define PTZ_IRIS					0x00000008	// ��Ȧ
#define PTZ_ALARM					0x00000010	// ��������
#define PTZ_LIGHT					0x00000020	// �ƹ�
#define PTZ_SETPRESET				0x00000040	// ����Ԥ�õ�
#define PTZ_CLEARPRESET				0x00000080	// ���Ԥ�õ�
#define PTZ_GOTOPRESET				0x00000100	// ת��Ԥ�õ�
#define PTZ_AUTOPANON				0x00000200	// ˮƽ��ʼ
#define PTZ_AUTOPANOFF				0x00000400	// ˮƽ����
#define PTZ_SETLIMIT				0x00000800	// ���ñ߽�
#define PTZ_AUTOSCANON				0x00001000	// �Զ�ɨ�迪ʼ
#define PTZ_AUTOSCANOFF				0x00002000	// �Զ�ɨ�迪ֹͣ
#define PTZ_ADDTOUR					0x00004000	// ����Ѳ����
#define PTZ_DELETETOUR				0x00008000	// ɾ��Ѳ����
#define PTZ_STARTTOUR				0x00010000	// ��ʼѲ��
#define PTZ_STOPTOUR				0x00020000	// ����Ѳ��
#define PTZ_CLEARTOUR				0x00040000	// ɾ��Ѳ��
#define PTZ_SETPATTERN				0x00080000	// ����ģʽ
#define PTZ_STARTPATTERN			0x00100000	// ��ʼģʽ
#define PTZ_STOPPATTERN				0x00200000	// ֹͣģʽ
#define PTZ_CLEARPATTERN			0x00400000	// ���ģʽ
#define PTZ_POSITION				0x00800000	// ���ٶ�λ
#define PTZ_AUX						0x01000000	// ��������
#define PTZ_MENU					0x02000000	// ����˵�
#define PTZ_EXIT					0x04000000	// �˳�����˵�
#define PTZ_ENTER					0x08000000	// ȷ��
#define PTZ_ESC						0x10000000	// ȡ��
#define PTZ_MENUUPDOWN				0x20000000	// �˵����²���
#define PTZ_MENULEFTRIGHT			0x40000000	// �˵����Ҳ���
#define PTZ_OPT_NUM					0x80000000	// �����ĸ���
// ���ĸ��ֽ�����
#define PTZ_DEV						0x00000001	// ��̨����
#define PTZ_MATRIX					0x00000002	// �������

// ץͼ��Ƶ��������
#define CODETYPE_MPEG4				0
#define CODETYPE_H264				1
#define CODETYPE_JPG				2

// ���������б�
#define ISIL_CAPTURE_BRC_CBR			0
#define ISIL_CAPTURE_BRC_VBR			1
//#define ISIL_CAPTURE_BRC_MBR		2

// �������ʹ��ţ���ӦISIL_CLIENT_GetLastError�ӿڵķ���ֵ
#define _ERROR_C(x)						(0x80000000|x)
#define NET_NOERROR 				0			// û�д���
#define NET_ERROR					-1			// δ֪����
#define NET_SYSTEM_ERROR			_ERROR_C(1)		// Windowsϵͳ����
#define NET_NETWORK_ERROR			_ERROR_C(2)		// ������󣬿�������Ϊ���糬ʱ
#define NET_DEV_VER_NOMATCH			_ERROR_C(3)		// �豸Э�鲻ƥ��
#define NET_INVALID_HANDLE			_ERROR_C(4)		// �����Ч
#define NET_OPEN_CHANNEL_ERROR		_ERROR_C(5)		// ��ͨ��ʧ��
#define NET_CLOSE_CHANNEL_ERROR		_ERROR_C(6)		// �ر�ͨ��ʧ��
#define NET_ILLEGAL_PARAM			_ERROR_C(7)		// �û��������Ϸ�
#define NET_SDK_INIT_ERROR			_ERROR_C(8)		// SDK��ʼ������
#define NET_SDK_UNINIT_ERROR		_ERROR_C(9)		// SDK�������
#define NET_RENDER_OPEN_ERROR		_ERROR_C(10)		// ����render��Դ����
#define NET_DEC_OPEN_ERROR			_ERROR_C(11)		// �򿪽�������
#define NET_DEC_CLOSE_ERROR			_ERROR_C(12)		// �رս�������
#define NET_MULTIPLAY_NOCHANNEL		_ERROR_C(13)		// �໭��Ԥ���м�⵽ͨ����Ϊ0
#define NET_TALK_INIT_ERROR			_ERROR_C(14)		// ¼�����ʼ��ʧ��
#define NET_TALK_NOT_INIT			_ERROR_C(15)		// ¼����δ����ʼ��
#define	NET_TALK_SENDDATA_ERROR		_ERROR_C(16)		// ������Ƶ���ݳ���
#define NET_REAL_ALREADY_SAVING		_ERROR_C(17)		// ʵʱ�����Ѿ����ڱ���״̬
#define NET_NOT_SAVING				_ERROR_C(18)		// δ����ʵʱ����
#define NET_OPEN_FILE_ERROR			_ERROR_C(19)		// ���ļ�����
#define NET_PTZ_SET_TIMER_ERROR		_ERROR_C(20)		// ������̨���ƶ�ʱ��ʧ��
#define NET_RETURN_DATA_ERROR		_ERROR_C(21)		// �Է������ݵ�У�����
#define NET_INSUFFICIENT_BUFFER		_ERROR_C(22)		// û���㹻�Ļ���
#define NET_NOT_SUPPORTED			_ERROR_C(23)		// ��ǰSDKδ֧�ָù���
#define NET_NO_RECORD_FOUND			_ERROR_C(24)		// ��ѯ����¼��
#define NET_NOT_AUTHORIZED			_ERROR_C(25)		// �޲���Ȩ��
#define NET_NOT_NOW					_ERROR_C(26)		// ��ʱ�޷�ִ��
#define NET_NO_TALK_CHANNEL			_ERROR_C(27)		// δ���ֶԽ�ͨ��
#define NET_NO_AUDIO				_ERROR_C(28)		// δ������Ƶ
#define NET_NO_INIT					_ERROR_C(29)		// ����SDKδ����ʼ��
#define NET_DOWNLOAD_END			_ERROR_C(30)		// �����ѽ���
#define NET_EMPTY_LIST				_ERROR_C(31)		// ��ѯ���Ϊ��
#define NET_ERROR_GETCFG_SYSATTR	_ERROR_C(32)		// ��ȡϵͳ��������ʧ��
#define NET_ERROR_GETCFG_SERIAL		_ERROR_C(33)		// ��ȡ���к�ʧ��
#define NET_ERROR_GETCFG_GENERAL	_ERROR_C(34)		// ��ȡ��������ʧ��
#define NET_ERROR_GETCFG_DSPCAP		_ERROR_C(35)		// ��ȡDSP��������ʧ��
#define NET_ERROR_GETCFG_NETCFG		_ERROR_C(36)		// ��ȡ��������ʧ��
#define NET_ERROR_GETCFG_CHANNAME	_ERROR_C(37)		// ��ȡͨ������ʧ��
#define NET_ERROR_GETCFG_VIDEO		_ERROR_C(38)		// ��ȡ��Ƶ����ʧ��
#define NET_ERROR_GETCFG_RECORD		_ERROR_C(39)		// ��ȡ¼������ʧ��
#define NET_ERROR_GETCFG_PRONAME	_ERROR_C(40)		// ��ȡ������Э������ʧ��
#define NET_ERROR_GETCFG_FUNCNAME	_ERROR_C(41)		// ��ȡ232���ڹ�������ʧ��
#define NET_ERROR_GETCFG_485DECODER	_ERROR_C(42)		// ��ȡ����������ʧ��
#define NET_ERROR_GETCFG_232COM		_ERROR_C(43)		// ��ȡ232��������ʧ��
#define NET_ERROR_GETCFG_ALARMIN	_ERROR_C(44)		// ��ȡ�ⲿ������������ʧ��
#define NET_ERROR_GETCFG_ALARMDET	_ERROR_C(45)		// ��ȡ��̬��ⱨ��ʧ��
#define NET_ERROR_GETCFG_SYSTIME	_ERROR_C(46)		// ��ȡ�豸ʱ��ʧ��
#define NET_ERROR_GETCFG_PREVIEW	_ERROR_C(47)		// ��ȡԤ������ʧ��
#define NET_ERROR_GETCFG_AUTOMT		_ERROR_C(48)		// ��ȡ�Զ�ά������ʧ��
#define NET_ERROR_GETCFG_VIDEOMTRX	_ERROR_C(49)		// ��ȡ��Ƶ��������ʧ��
#define NET_ERROR_GETCFG_COVER		_ERROR_C(50)		// ��ȡ�����ڵ�����ʧ��
#define NET_ERROR_GETCFG_WATERMAKE	_ERROR_C(51)		// ��ȡͼ��ˮӡ����ʧ��
#define NET_ERROR_SETCFG_GENERAL	_ERROR_C(55)		// �޸ĳ�������ʧ��
#define NET_ERROR_SETCFG_NETCFG		_ERROR_C(56)		// �޸���������ʧ��
#define NET_ERROR_SETCFG_CHANNAME	_ERROR_C(57)		// �޸�ͨ������ʧ��
#define NET_ERROR_SETCFG_VIDEO		_ERROR_C(58)		// �޸���Ƶ����ʧ��
#define NET_ERROR_SETCFG_RECORD		_ERROR_C(59)		// �޸�¼������ʧ��
#define NET_ERROR_SETCFG_485DECODER	_ERROR_C(60)		// �޸Ľ���������ʧ��
#define NET_ERROR_SETCFG_232COM		_ERROR_C(61)		// �޸�232��������ʧ��
#define NET_ERROR_SETCFG_ALARMIN	_ERROR_C(62)		// �޸��ⲿ���뱨������ʧ��
#define NET_ERROR_SETCFG_ALARMDET	_ERROR_C(63)		// �޸Ķ�̬��ⱨ������ʧ��
#define NET_ERROR_SETCFG_SYSTIME	_ERROR_C(64)		// �޸��豸ʱ��ʧ��
#define NET_ERROR_SETCFG_PREVIEW	_ERROR_C(65)		// �޸�Ԥ������ʧ��
#define NET_ERROR_SETCFG_AUTOMT		_ERROR_C(66)		// �޸��Զ�ά������ʧ��
#define NET_ERROR_SETCFG_VIDEOMTRX	_ERROR_C(67)		// �޸���Ƶ��������ʧ��
#define NET_ERROR_SETCFG_COVER		_ERROR_C(68)		// �޸������ڵ�����ʧ��
#define NET_ERROR_SETCFG_WATERMAKE	_ERROR_C(69)		// �޸�ͼ��ˮӡ����ʧ��
#define NET_ERROR_SETCFG_WLAN		_ERROR_C(70)		// �޸�����������Ϣʧ��
#define NET_ERROR_SETCFG_WLANDEV	_ERROR_C(71)		// ѡ�����������豸ʧ��
#define NET_ERROR_SETCFG_REGISTER	_ERROR_C(72)		// �޸�����ע���������ʧ��
#define NET_ERROR_SETCFG_CAMERA		_ERROR_C(73)		// �޸�����ͷ��������ʧ��
#define NET_ERROR_SETCFG_INFRARED	_ERROR_C(74)		// �޸ĺ��ⱨ������ʧ��
#define NET_ERROR_SETCFG_SOUNDALARM	_ERROR_C(75)		// �޸���Ƶ��������ʧ��
#define NET_ERROR_SETCFG_STORAGE    _ERROR_C(76)		// �޸Ĵ洢λ������ʧ��
#define NET_AUDIOENCODE_NOTINIT		_ERROR_C(77)		// ��Ƶ����ӿ�û�гɹ���ʼ��
#define NET_DATA_TOOLONGH			_ERROR_C(78)		// ���ݹ���
#define NET_UNSUPPORTED				_ERROR_C(79)		// �豸��֧�ָò���
#define NET_DEVICE_BUSY				_ERROR_C(80)		// �豸��Դ����
#define NET_SERVER_STARTED			_ERROR_C(81)		// �������Ѿ�����
#define NET_SERVER_STOPPED			_ERROR_C(82)		// ��������δ�ɹ�����
#define NET_LISTER_INCORRECT_SERIAL	_ERROR_C(83)		// �������к�����
#define NET_QUERY_DISKINFO_FAILED	_ERROR_C(84)		// ��ȡӲ����Ϣʧ��
#define NET_ERROR_GETCFG_SESSION	_ERROR_C(85)		// ��ȡ����Session��Ϣ
#define NET_LOGIN_ERROR_PASSWORD	_ERROR_C(100)	// ���벻��ȷ
#define NET_LOGIN_ERROR_USER		_ERROR_C(101)	// �ʻ�������
#define NET_LOGIN_ERROR_TIMEOUT		_ERROR_C(102)	// �ȴ���¼���س�ʱ
#define NET_LOGIN_ERROR_RELOGGIN	_ERROR_C(103)	// �ʺ��ѵ�¼
#define NET_LOGIN_ERROR_LOCKED		_ERROR_C(104)	// �ʺ��ѱ�����
#define NET_LOGIN_ERROR_BLACKLIST	_ERROR_C(105)	// �ʺ��ѱ���Ϊ������
#define NET_LOGIN_ERROR_BUSY		_ERROR_C(106)	// ��Դ���㣬ϵͳæ
#define NET_LOGIN_ERROR_CONNECT		_ERROR_C(107)	// ��¼�豸��ʱ���������粢����
#define NET_LOGIN_ERROR_NETWORK		_ERROR_C(108)	// ��������ʧ��
#define NET_LOGIN_ERROR_SUBCONNECT	_ERROR_C(109)	// ��¼�豸�ɹ������޷�������Ƶͨ������������״��
#define NET_RENDER_SOUND_ON_ERROR	_ERROR_C(120)	// Render�����Ƶ����
#define NET_RENDER_SOUND_OFF_ERROR	_ERROR_C(121)	// Render��ر���Ƶ����
#define NET_RENDER_SET_VOLUME_ERROR	_ERROR_C(122)	// Render�������������
#define NET_RENDER_ADJUST_ERROR		_ERROR_C(123)	// Render�����û����������
#define NET_RENDER_PAUSE_ERROR		_ERROR_C(124)	// Render����ͣ���ų���
#define NET_RENDER_SNAP_ERROR		_ERROR_C(125)	// Render��ץͼ����
#define NET_RENDER_STEP_ERROR		_ERROR_C(126)	// Render�ⲽ������
#define NET_RENDER_FRAMERATE_ERROR	_ERROR_C(127)	// Render������֡�ʳ���
#define NET_GROUP_EXIST				_ERROR_C(140)	// �����Ѵ���
#define	NET_GROUP_NOEXIST			_ERROR_C(141)	// ����������
#define NET_GROUP_RIGHTOVER			_ERROR_C(142)	// ���Ȩ�޳���Ȩ���б�Χ
#define NET_GROUP_HAVEUSER			_ERROR_C(143)	// �������û�������ɾ��
#define NET_GROUP_RIGHTUSE			_ERROR_C(144)	// ���ĳ��Ȩ�ޱ��û�ʹ�ã����ܳ���
#define NET_GROUP_SAMENAME			_ERROR_C(145)	// ������ͬ���������ظ�
#define	NET_USER_EXIST				_ERROR_C(146)	// �û��Ѵ���
#define NET_USER_NOEXIST			_ERROR_C(147)	// �û�������
#define NET_USER_RIGHTOVER			_ERROR_C(148)	// �û�Ȩ�޳�����Ȩ��
#define NET_USER_PWD				_ERROR_C(149)	// �����ʺţ��������޸�����
#define NET_USER_FLASEPWD			_ERROR_C(150)	// ���벻��ȷ
#define NET_USER_NOMATCHING			_ERROR_C(151)	// ���벻ƥ��
#define NET_ERROR_GETCFG_ETHERNET	_ERROR_C(300)	// ��ȡ��������ʧ��
#define NET_ERROR_GETCFG_WLAN		_ERROR_C(301)	// ��ȡ����������Ϣʧ��
#define NET_ERROR_GETCFG_WLANDEV	_ERROR_C(302)	// ��ȡ���������豸ʧ��
#define NET_ERROR_GETCFG_REGISTER	_ERROR_C(303)	// ��ȡ����ע�����ʧ��
#define NET_ERROR_GETCFG_CAMERA		_ERROR_C(304)	// ��ȡ����ͷ����ʧ��
#define NET_ERROR_GETCFG_INFRARED	_ERROR_C(305)	// ��ȡ���ⱨ������ʧ��
#define NET_ERROR_GETCFG_SOUNDALARM	_ERROR_C(306)	// ��ȡ��Ƶ��������ʧ��
#define NET_ERROR_GETCFG_STORAGE    _ERROR_C(307)	// ��ȡ�洢λ������ʧ��
#define NET_ERROR_GETCFG_MAIL		_ERROR_C(308)	// ��ȡ�ʼ�����ʧ��
#define NET_CONFIG_DEVBUSY			_ERROR_C(309)	// ��ʱ�޷�����
#define NET_CONFIG_DATAILLEGAL		_ERROR_C(310)	// �������ݲ��Ϸ�
#define NET_ERROR_GETCFG_DST        _ERROR_C(311)    // ��ȡ����ʱ����ʧ��
#define NET_ERROR_SETCFG_DST        _ERROR_C(312)    // ��������ʱ����ʧ��
#define NET_ERROR_GETCFG_VIDEO_OSD  _ERROR_C(313)    // ��ȡ��ƵOSD��������ʧ��
#define NET_ERROR_SETCFG_VIDEO_OSD  _ERROR_C(314)    // ������ƵOSD��������ʧ��
#define NET_ERROR_GETCFG_GPRSCDMA   _ERROR_C(315)    // ��ȡCDMA\GPRS��������ʧ��
#define NET_ERROR_SETCFG_GPRSCDMA   _ERROR_C(316)    // ����CDMA\GPRS��������ʧ��
#define NET_ERROR_GETCFG_IPFILTER   _ERROR_C(317)    // ��ȡIP��������ʧ��
#define NET_ERROR_SETCFG_IPFILTER   _ERROR_C(318)    // ����IP��������ʧ��
#define NET_ERROR_GETCFG_TALKENCODE _ERROR_C(319)    // ��ȡ�����Խ���������ʧ��
#define NET_ERROR_SETCFG_TALKENCODE _ERROR_C(320)    // ���������Խ���������ʧ��
#define NET_ERROR_GETCFG_RECORDLEN  _ERROR_C(321)    // ��ȡ¼������������ʧ��
#define NET_ERROR_SETCFG_RECORDLEN  _ERROR_C(322)    // ����¼������������ʧ��
#define	NET_DONT_SUPPORT_SUBAREA	_ERROR_C(323)	// ��֧������Ӳ�̷���
#define	NET_ERROR_GET_AUTOREGSERVER	_ERROR_C(324)	// ��ȡ�豸������ע���������Ϣʧ��
#define	NET_ERROR_CONTROL_AUTOREGISTER		_ERROR_C(325)	// ����ע���ض���ע�����
#define	NET_ERROR_DISCONNECT_AUTOREGISTER	_ERROR_C(326)	// �Ͽ�����ע�����������
#define NET_ERROR_GETCFG_MMS				_ERROR_C(327)	// ��ȡmms����ʧ��
#define NET_ERROR_SETCFG_MMS				_ERROR_C(328)	// ����mms����ʧ��
#define NET_ERROR_GETCFG_SMSACTIVATION      _ERROR_C(329)	// ��ȡ���ż���������������ʧ��
#define NET_ERROR_SETCFG_SMSACTIVATION      _ERROR_C(330)	// ���ö��ż���������������ʧ��
#define NET_ERROR_GETCFG_DIALINACTIVATION	_ERROR_C(331)	// ��ȡ���ż���������������ʧ��
#define NET_ERROR_SETCFG_DIALINACTIVATION	_ERROR_C(332)	// ���ò��ż���������������ʧ��
#define NET_ERROR_GETCFG_VIDEOOUT           _ERROR_C(333)    // ��ѯ��Ƶ�����������ʧ��
#define NET_ERROR_SETCFG_VIDEOOUT			_ERROR_C(334)	// ������Ƶ�����������ʧ��
#define NET_ERROR_GETCFG_OSDENABLE			_ERROR_C(335)	// ��ȡosd����ʹ������ʧ��
#define NET_ERROR_SETCFG_OSDENABLE			_ERROR_C(336)	// ����osd����ʹ������ʧ��
#define NET_ERROR_SETCFG_ENCODERINFO        _ERROR_C(337)    // ��������ͨ��ǰ�˱����������ʧ��

#define NET_ERROR_CONNECT_FAILED			_ERROR_C(340)	// ����������ʧ��
#define NET_ERROR_SETCFG_BURNFILE			_ERROR_C(341)	// �����¼�ļ��ϴ�ʧ��
#define NET_ERROR_SNIFFER_GETCFG			_ERROR_C(342)	// ��ȡץ��������Ϣʧ��
#define NET_ERROR_SNIFFER_SETCFG			_ERROR_C(343)	// ����ץ��������Ϣʧ��
#define NET_ERROR_DOWNLOADRATE_GETCFG		_ERROR_C(344)	// ��ѯ����������Ϣʧ��
#define NET_ERROR_DOWNLOADRATE_SETCFG		_ERROR_C(345)	// ��������������Ϣʧ��
#define NET_ERROR_SEARCH_TRANSCOM			_ERROR_C(346)	// ��ѯ���ڲ���ʧ��
#define NET_ERROR_GETCFG_POINT				_ERROR_C(347)	// ��ȡԤ�Ƶ���Ϣ����
#define NET_ERROR_SETCFG_POINT				_ERROR_C(348)	// ����Ԥ�Ƶ���Ϣ����
#define NET_SDK_LOGOUT_ERROR				_ERROR_C(349)    // SDKû�������ǳ��豸


/************************************************************************
 ** ö�ٶ���
 ***********************************************************************/
// �豸����
enum NET_DEVICE_TYPE
{
	NET_PRODUCT_NONE = 0,
	NET_DVR_NONREALTIME_MACE,					// ��ʵʱMACE
	NET_DVR_NONREALTIME,						// ��ʵʱ
	NET_NVS_MPEG1,								// ������Ƶ������
	NET_DVR_MPEG1_2,							// MPEG1��·¼���
	NET_DVR_MPEG1_8,							// MPEG1��·¼���
	NET_DVR_MPEG4_8,							// MPEG4��·¼���
	NET_DVR_MPEG4_16,							// MPEG4ʮ��·¼���
	NET_DVR_MPEG4_SX2,							// LBϵ��¼���
	NET_DVR_MEPG4_ST2,							// GBϵ��¼���
	NET_DVR_MEPG4_SH2,							// HBϵ��¼���
	NET_DVR_MPEG4_GBE,							// GBEϵ��¼���
	NET_DVR_MPEG4_NVSII,						// II��������Ƶ������
	NET_DVR_STD_NEW,							// �±�׼����Э��
	NET_DVR_DDNS,								// DDNS������
	NET_DVR_ATM,								// ATM��
	NET_NB_SERIAL,								// ������ʵʱNBϵ�л���
	NET_LN_SERIAL,								// LNϵ�в�Ʒ
	NET_BAV_SERIAL,								// BAVϵ�в�Ʒ
	NET_SDIP_SERIAL,							// SDIPϵ�в�Ʒ
	NET_IPC_SERIAL,								// IPCϵ�в�Ʒ
	NET_NVS_B,									// NVS Bϵ��
	NET_NVS_C,									// NVS Hϵ��
	NET_NVS_S,									// NVS Sϵ��
	NET_NVS_E,									// NVS Eϵ��
	NET_DVR_NEW_PROTOCOL,						// ��QueryDevState�в�ѯ�豸����,���ַ�����ʽ
	NET_NVD_SERIAL,								// ������
	NET_DVR_N5,									// N5
	NET_DVR_MIX_DVR,							// ���DVR
	NET_SVR_SERIAL,								// SVRϵ��
	NET_SVR_BS,									// SVR-BS
};

// ��������
typedef enum __LANGUAGE_TYPE
{
	ISIL_LANGUAGE_ENGLISH,						// Ӣ��
	ISIL_LANGUAGE_CHINESE_SIMPLIFIED,				// ��������
	ISIL_LANGUAGE_CHINESE_TRADITIONAL,			// ��������
	ISIL_LANGUAGE_ITALIAN,						// �������
	ISIL_LANGUAGE_SPANISH,						// ��������
	ISIL_LANGUAGE_JAPANESE,						// ���İ�
	ISIL_LANGUAGE_RUSSIAN,						// ���İ�
	ISIL_LANGUAGE_FRENCH,							// ���İ�
	ISIL_LANGUAGE_GERMAN, 						// ���İ�
	ISIL_LANGUAGE_PORTUGUESE,						// ��������
	ISIL_LANGUAGE_TURKEY,							// ��������
	ISIL_LANGUAGE_POLISH,							// ������
	ISIL_LANGUAGE_ROMANIAN,						// ��������
	ISIL_LANGUAGE_HUNGARIAN,						// ��������
	ISIL_LANGUAGE_FINNISH,						// ������
	ISIL_LANGUAGE_ESTONIAN,						// ��ɳ������
	ISIL_LANGUAGE_KOREAN,							// ����
	ISIL_LANGUAGE_FARSI,							// ��˹��
	ISIL_LANGUAGE_DANSK,							// ������
	ISIL_LANGUAGE_CZECHISH,						// �ݿ���
	ISIL_LANGUAGE_BULGARIA,						// ����������
	ISIL_LANGUAGE_SLOVAKIAN,						// ˹�工����
	ISIL_LANGUAGE_SLOVENIA,						// ˹����������
	ISIL_LANGUAGE_CROATIAN,						// ���޵�����
	ISIL_LANGUAGE_DUTCH,							// ������
	ISIL_LANGUAGE_GREEK,							// ϣ����
	ISIL_LANGUAGE_UKRAINIAN,						// �ڿ�����
	ISIL_LANGUAGE_SWEDISH,						// �����
	ISIL_LANGUAGE_SERBIAN,						// ����ά����
	ISIL_LANGUAGE_VIETNAMESE,						// Խ����
	ISIL_LANGUAGE_LITHUANIAN,						// ��������
	ISIL_LANGUAGE_FILIPINO,						// ���ɱ���
	ISIL_LANGUAGE_ARABIC,							// ��������
	ISIL_LANGUAGE_CATALAN,						// ��̩��������
	ISIL_LANGUAGE_LATVIAN,						// ����ά����
	ISIL_LANGUAGE_THAI,							// ̩��
} ISIL_LANGUAGE_TYPE;

// ��������
typedef enum __EM_UPGRADE_TYPE
{
	ISIL_UPGRADE_BIOS_TYPE = 1,					// BIOS����
	ISIL_UPGRADE_WEB_TYPE,						// WEB����
	ISIL_UPGRADE_BOOT_YPE,						// BOOT����
	ISIL_UPGRADE_CHARACTER_TYPE,					// ���ֿ�
	ISIL_UPGRADE_LOGO_TYPE,						// LOGO
	ISIL_UPGRADE_EXE_TYPE,						// EXE�����粥������
} EM_UPGRADE_TYPE;

// ¼������(��ʱ����̬��⡢����)
typedef enum __REC_TYPE
{
	ISIL_REC_TYPE_TIM = 0,
	ISIL_REC_TYPE_MTD,
	ISIL_REC_TYPE_ALM,
	ISIL_REC_TYPE_NUM,
} REC_TYPE;


// ��������
typedef enum __GPRSCDMA_NETWORK_TYPE
{
	ISIL_TYPE_AUTOSEL = 0,						// �Զ�ѡ��
	ISIL_TYPE_TD_SCDMA,							// TD-SCDMA����
	ISIL_TYPE_WCDMA,								// WCDMA����
	ISIL_TYPE_CDMA_1x,							// CDMA 1.x����
	ISIL_TYPE_EDGE,								// GPRS����
	ISIL_TYPE_EVDO,								// EVDO����
	ISIL_TYPE_WIFI,								// ����
} EM_GPRSCDMA_NETWORK_TYPE;

// �ӿ����ͣ���ӦISIL_CLIENT_SetSubconnCallBack�ӿ�
typedef enum __EM_INTERFACE_TYPE
{
	ISIL_INTERFACE_OTHER = 0x00000000,			// δ֪�ӿ�
	ISIL_INTERFACE_REALPLAY,						// ʵʱ���ӽӿ�
	ISIL_INTERFACE_PREVIEW,						// �໭��Ԥ���ӿ�
	ISIL_INTERFACE_PLAYBACK,						// �طŽӿ�
	ISIL_INTERFACE_DOWNLOAD,						// ���ؽӿ�
} EM_INTERFACE_TYPE;


/////////////////////////////////�������/////////////////////////////////

// Ԥ�����ͣ���ӦISIL_CLIENT_RealPlayEx�ӿ�
typedef enum _RealPlayType
{
	ISIL_RType_Realplay = 0,						// ʵʱԤ��
	ISIL_RType_Multiplay,							// �໭��Ԥ��

	ISIL_RType_Realplay_0,						// ʵʱ����-����������ͬ��ISIL_RType_Realplay
	ISIL_RType_Realplay_1,						// ʵʱ����-������1
	ISIL_RType_Realplay_2,						// ʵʱ����-������2
	ISIL_RType_Realplay_3,						// ʵʱ����-������3

	ISIL_RType_Multiplay_1,						// �໭��Ԥ����1����
	ISIL_RType_Multiplay_4,						// �໭��Ԥ����4����
	ISIL_RType_Multiplay_8,						// �໭��Ԥ����8����
	ISIL_RType_Multiplay_9,						// �໭��Ԥ����9����
	ISIL_RType_Multiplay_16,						// �໭��Ԥ����16����
	ISIL_RType_Multiplay_6,						// �໭��Ԥ����6����
	ISIL_RType_Multiplay_12,						// �໭��Ԥ����12����
} ISIL_RealPlayType;

/////////////////////////////////��̨���/////////////////////////////////

// ͨ����̨��������
typedef enum _PTZ_ControlType
{
	ISIL_PTZ_UP_CONTROL = 0,						// ��
	ISIL_PTZ_DOWN_CONTROL,						// ��
	ISIL_PTZ_LEFT_CONTROL,						// ��
	ISIL_PTZ_RIGHT_CONTROL,						// ��
	ISIL_PTZ_ZOOM_ADD_CONTROL,					// �䱶+
	ISIL_PTZ_ZOOM_DEC_CONTROL,					// �䱶-
	ISIL_PTZ_FOCUS_ADD_CONTROL,					// ����+
	ISIL_PTZ_FOCUS_DEC_CONTROL,					// ����-
	ISIL_PTZ_APERTURE_ADD_CONTROL,				// ��Ȧ+
	ISIL_PTZ_APERTURE_DEC_CONTROL,				// ��Ȧ-
    ISIL_PTZ_POINT_MOVE_CONTROL,					// ת��Ԥ�õ�
    ISIL_PTZ_POINT_SET_CONTROL,					// ����
    ISIL_PTZ_POINT_DEL_CONTROL,					// ɾ��
    ISIL_PTZ_POINT_LOOP_CONTROL,					// ���Ѳ��
    ISIL_PTZ_LAMP_CONTROL							// �ƹ���ˢ
} ISIL_PTZ_ControlType;

// ��̨������չ����
typedef enum _EXTPTZ_ControlType
{
	ISIL_EXTPTZ_LEFTTOP = 0x20,					// ����
	ISIL_EXTPTZ_RIGHTTOP,							// ����
	ISIL_EXTPTZ_LEFTDOWN,							// ����
	ISIL_EXTPTZ_RIGHTDOWN,						// ����
	ISIL_EXTPTZ_ADDTOLOOP,						// ����Ԥ�õ㵽Ѳ�� Ѳ����· Ԥ�õ�ֵ
	ISIL_EXTPTZ_DELFROMLOOP,						// ɾ��Ѳ����Ԥ�õ� Ѳ����· Ԥ�õ�ֵ
    ISIL_EXTPTZ_CLOSELOOP,						// ���Ѳ�� Ѳ����·
	ISIL_EXTPTZ_STARTPANCRUISE,					// ��ʼˮƽ��ת
	ISIL_EXTPTZ_STOPPANCRUISE,					// ֹͣˮƽ��ת
	ISIL_EXTPTZ_SETLEFTBORDER,					// ������߽�
	ISIL_EXTPTZ_SETRIGHTBORDER,					// �����ұ߽�
	ISIL_EXTPTZ_STARTLINESCAN,					// ��ʼ��ɨ
    ISIL_EXTPTZ_CLOSELINESCAN,					// ֹͣ��ɨ
    ISIL_EXTPTZ_SETMODESTART,						// ����ģʽ��ʼ	ģʽ��·
    ISIL_EXTPTZ_SETMODESTOP,						// ����ģʽ����	ģʽ��·
	ISIL_EXTPTZ_RUNMODE,							// ����ģʽ	ģʽ��·
	ISIL_EXTPTZ_STOPMODE,							// ֹͣģʽ	ģʽ��·
	ISIL_EXTPTZ_DELETEMODE,						// ���ģʽ	ģʽ��·
	ISIL_EXTPTZ_REVERSECOMM,						// ��ת����
	ISIL_EXTPTZ_FASTGOTO,							// ���ٶ�λ ˮƽ����(8192) ��ֱ����(8192) �䱶(4)
	ISIL_EXTPTZ_AUXIOPEN,							// �������ؿ� ������
	ISIL_EXTPTZ_AUXICLOSE,						// �������ع� ������
	ISIL_EXTPTZ_OPENMENU = 0x36,					// ������˵�
	ISIL_EXTPTZ_CLOSEMENU,						// �رղ˵�
	ISIL_EXTPTZ_MENUOK,							// �˵�ȷ��
	ISIL_EXTPTZ_MENUCANCEL,						// �˵�ȡ��
	ISIL_EXTPTZ_MENUUP,							// �˵���
	ISIL_EXTPTZ_MENUDOWN,							// �˵���
	ISIL_EXTPTZ_MENULEFT,							// �˵���
	ISIL_EXTPTZ_MENURIGHT,						// �˵���
	ISIL_EXTPTZ_ALARMHANDLE = 0x40,				// ����������̨ parm1����������ͨ����parm2��������������1-Ԥ�õ�2-��ɨ3-Ѳ����parm3������ֵ����Ԥ�õ��
	ISIL_EXTPTZ_MATRIXSWITCH = 0x41,				// �����л� parm1����������(��Ƶ�����)��parm2����Ƶ����ţ�parm3�������
	ISIL_EXTPTZ_LIGHTCONTROL,						// �ƹ������
	ISIL_EXTPTZ_UP_TELE = 0x70,					// �� + TELE param1=�ٶ�(1-8)����ͬ
	ISIL_EXTPTZ_DOWN_TELE,						// �� + TELE
	ISIL_EXTPTZ_LEFT_TELE,						// �� + TELE
	ISIL_EXTPTZ_RIGHT_TELE,						// �� + TELE
	ISIL_EXTPTZ_LEFTUP_TELE,						// ���� + TELE
	ISIL_EXTPTZ_LEFTDOWN_TELE,					// ���� + TELE
	ISIL_EXTPTZ_TIGHTUP_TELE,						// ���� + TELE
	ISIL_EXTPTZ_RIGHTDOWN_TELE,					// ���� + TELE
	ISIL_EXTPTZ_UP_WIDE,							// �� + WIDE param1=�ٶ�(1-8)����ͬ
	ISIL_EXTPTZ_DOWN_WIDE,						// �� + WIDE
	ISIL_EXTPTZ_LEFT_WIDE,						// �� + WIDE
	ISIL_EXTPTZ_RIGHT_WIDE,						// �� + WIDE
	ISIL_EXTPTZ_LEFTUP_WIDE,						// ���� + WIDE
	ISIL_EXTPTZ_LEFTDOWN_WIDE,					// ���� + WIDE
	ISIL_EXTPTZ_TIGHTUP_WIDE,						// ���� + WIDE
	ISIL_EXTPTZ_RIGHTDOWN_WIDE,					// ���� + WIDE
	ISIL_EXTPTZ_TOTAL,							// �������ֵ
} ISIL_EXTPTZ_ControlType;

/////////////////////////////////��־���/////////////////////////////////

// ��־��ѯ����
typedef enum _ISIL_LOG_QUERY_TYPE
{
	ISIL_LOG_ALL = 0,								// ������־
	ISIL_LOG_SYSTEM,								// ϵͳ��־
	ISIL_LOG_CONFIG,								// ������־
	ISIL_LOG_STORAGE,								// �洢���
	ISIL_LOG_ALARM,								// ������־
	ISIL_LOG_RECORD,								// ¼�����
	ISIL_LOG_ACCOUNT,								// �ʺ����
	ISIL_LOG_QCLEAR,								// �����־
	ISIL_LOG_QPLAYBACK								// �ط����
} ISIL_LOG_QUERY_TYPE;

// ��־����
typedef enum _ISIL_LOG_TYPE
{
	ISIL_LOG_REBOOT = 0x0000,						// �豸����
	ISIL_LOG_SHUT,								// �豸�ػ�
	ISIL_LOG_CONFSAVE = 0x0100,					// ��������
	ISIL_LOG_CONFLOAD,							// ��ȡ����
	ISIL_LOG_FSERROR = 0x0200,					// �ļ�ϵͳ����
	ISIL_LOG_HDD_WERR,							// Ӳ��д����
	ISIL_LOG_HDD_RERR,							// Ӳ�̶�����
	ISIL_LOG_HDD_TYPE,							// ����Ӳ������
	ISIL_LOG_HDD_FORMAT,							// ��ʽ��Ӳ��
	ISIL_LOG_HDD_NOSPACE,							// ��ǰ�����̿ռ䲻��
	ISIL_LOG_HDD_TYPE_RW,							// ����Ӳ������Ϊ��д��
	ISIL_LOG_HDD_TYPE_RO,							// ����Ӳ������Ϊֻ����
	ISIL_LOG_HDD_TYPE_RE,							// ����Ӳ������Ϊ������
	ISIL_LOG_HDD_TYPE_SS,							// ����Ӳ������Ϊ������
	ISIL_LOG_HDD_NONE,							// ��Ӳ�̼�¼��־
	ISIL_LOG_ALM_IN = 0x0300,						// �ⲿ���뱨����ʼ
	ISIL_LOG_NETALM_IN,							// ���籨������
	ISIL_LOG_ALM_END = 0x0302,					// �ⲿ���뱨��ֹͣ
	ISIL_LOG_LOSS_IN,								// ��Ƶ��ʧ������ʼ
	ISIL_LOG_LOSS_END,							// ��Ƶ��ʧ��������
	ISIL_LOG_MOTION_IN,							// ��̬��ⱨ����ʼ
	ISIL_LOG_MOTION_END,							// ��̬��ⱨ������
	ISIL_LOG_ALM_BOSHI,							// ��������������
	ISIL_LOG_NET_ABORT = 0x0308,					// ����Ͽ�
	ISIL_LOG_NET_ABORT_RESUME,					// ����ָ�
	ISIL_LOG_CODER_BREAKDOWN,						// ����������
	ISIL_LOG_CODER_BREAKDOWN_RESUME,				// ���������ϻָ�
	ISIL_LOG_BLIND_IN,							// ��Ƶ�ڵ�
	ISIL_LOG_BLIND_END,							// ��Ƶ�ڵ��ָ�
	ISIL_LOG_ALM_TEMP_HIGH,						// �¶ȹ���
	ISIL_LOG_ALM_VOLTAGE_LOW,						// ��ѹ����
	ISIL_LOG_ALM_BATTERY_LOW,						// �����������
	ISIL_LOG_ALM_ACC_BREAK,						// ACC�ϵ�
	ISIL_LOG_INFRAREDALM_IN = 0x03a0,				// ���߱�����ʼ
	ISIL_LOG_INFRAREDALM_END,						// ���߱�������
	ISIL_LOG_IPCONFLICT,							// IP��ͻ
	ISIL_LOG_IPCONFLICT_RESUME,					// IP�ָ�
	ISIL_LOG_SDPLUG_IN,							// SD������
	ISIL_LOG_SDPLUG_OUT,							// SD���γ�
	ISIL_LOG_NET_PORT_BIND_FAILED,				// ����˿ڰ�ʧ��
	ISIL_LOG_AUTOMATIC_RECORD = 0x0400,			// �Զ�¼��
	ISIL_LOG_MANUAL_RECORD = 0x0401,				// �ֶ�¼��
	ISIL_LOG_CLOSED_RECORD,						// ֹͣ¼��
	ISIL_LOG_LOGIN = 0x0500,						// ��¼
	ISIL_LOG_LOGOUT,								// ע��
	ISIL_LOG_ADD_USER,							// ����û�
	ISIL_LOG_DELETE_USER,							// ɾ���û�
	ISIL_LOG_MODIFY_USER,							// �޸��û�
	ISIL_LOG_ADD_GROUP,							// ����û���
	ISIL_LOG_DELETE_GROUP,						// ɾ���û���
	ISIL_LOG_MODIFY_GROUP,						// �޸��û���
	ISIL_LOG_CLEAR = 0x0600,						// �����־
	ISIL_LOG_SEARCHLOG,							// ��ѯ��־
	ISIL_LOG_SEARCH = 0x0700,						// ¼���ѯ
	ISIL_LOG_DOWNLOAD,							// ¼������
	ISIL_LOG_PLAYBACK,							// ¼��ط�
	ISIL_LOG_BACKUP,								// ����¼���ļ�
	ISIL_LOG_BACKUPERROR,							// ����¼���ļ�ʧ��

	ISIL_LOG_TYPE_NR = 7,
} ISIL_LOG_TYPE;

// ��չ��־���ͣ���ӦISIL_CLIENT_QueryLogEx�ӿڣ�����(int nType = 1������reserved = &nType)
typedef enum _ISIL_NEWLOG_TYPE
{
	ISIL_NEWLOG_REBOOT = 0x0000,					// �豸����
	ISIL_NEWLOG_SHUT,								// �豸�ػ�
	ISIL_NEWLOG_CONFSAVE = 0x0100,				// ��������
	ISIL_NEWLOG_CONFLOAD,							// ��ȡ����
	ISIL_NEWLOG_FSERROR = 0x0200,					// �ļ�ϵͳ����
	ISIL_NEWLOG_HDD_WERR,							// Ӳ��д����
	ISIL_NEWLOG_HDD_RERR,							// Ӳ�̶�����
	ISIL_NEWLOG_HDD_TYPE,							// ����Ӳ������
	ISIL_NEWLOG_HDD_FORMAT,						// ��ʽ��Ӳ��
	ISIL_NEWLOG_HDD_NOSPACE,						// ��ǰ�����̿ռ䲻��
	ISIL_NEWLOG_HDD_TYPE_RW,						// ����Ӳ������Ϊ��д��
	ISIL_NEWLOG_HDD_TYPE_RO,						// ����Ӳ������Ϊֻ����
	ISIL_NEWLOG_HDD_TYPE_RE,						// ����Ӳ������Ϊ������
	ISIL_NEWLOG_HDD_TYPE_SS,						// ����Ӳ������Ϊ������
	ISIL_NEWLOG_HDD_NONE,							// ��Ӳ�̼�¼��־
	ISIL_NEWLOG_ALM_IN = 0x0300,					// �ⲿ���뱨����ʼ
	ISIL_NEWLOG_NETALM_IN,						// ���籨��
	ISIL_NEWLOG_ALM_END,							// �ⲿ���뱨��ֹͣ
	ISIL_NEWLOG_LOSS_IN,							// ��Ƶ��ʧ������ʼ
	ISIL_NEWLOG_LOSS_END,							// ��Ƶ��ʧ��������
	ISIL_NEWLOG_MOTION_IN,						// ��̬��ⱨ����ʼ
	ISIL_NEWLOG_MOTION_END,						// ��̬��ⱨ������
	ISIL_NEWLOG_ALM_BOSHI,						// ��������������
	ISIL_NEWLOG_NET_ABORT = 0x0308,				// ����Ͽ�
	ISIL_NEWLOG_NET_ABORT_RESUME,					// ����ָ�
	ISIL_NEWLOG_CODER_BREAKDOWN,					// ����������
	ISIL_NEWLOG_CODER_BREAKDOWN_RESUME,			// ���������ϻָ�
	ISIL_NEWLOG_BLIND_IN,							// ��Ƶ�ڵ�
	ISIL_NEWLOG_BLIND_END,						// ��Ƶ�ڵ��ָ�
	ISIL_NEWLOG_ALM_TEMP_HIGH,					// �¶ȹ���
	ISIL_NEWLOG_ALM_VOLTAGE_LOW,					// ��ѹ����
	ISIL_NEWLOG_ALM_BATTERY_LOW,					// �����������
	ISIL_NEWLOG_ALM_ACC_BREAK,					// ACC�ϵ�
	ISIL_NEWLOG_INFRAREDALM_IN = 0x03a0,			// ���߱�����ʼ
	ISIL_NEWLOG_INFRAREDALM_END,					// ���߱�������
	ISIL_NEWLOG_IPCONFLICT,						// IP��ͻ
	ISIL_NEWLOG_IPCONFLICT_RESUME,				// IP�ָ�
	ISIL_NEWLOG_SDPLUG_IN,						// SD������
	ISIL_NEWLOG_SDPLUG_OUT,						// SD���γ�
	ISIL_NEWLOG_NET_PORT_BIND_FAILED,				// ����˿ڰ�ʧ��
	ISIL_NEWLOG_AUTOMATIC_RECORD = 0x0400,		// �Զ�¼��
	ISIL_NEWLOG_MANUAL_RECORD,					// �ֶ�¼��
	ISIL_NEWLOG_CLOSED_RECORD,					// ֹͣ¼��
	ISIL_NEWLOG_LOGIN = 0x0500,					// ��¼
	ISIL_NEWLOG_LOGOUT,							// ע��
	ISIL_NEWLOG_ADD_USER,							// ����û�
	ISIL_NEWLOG_DELETE_USER,						// ɾ���û�
	ISIL_NEWLOG_MODIFY_USER,						// �޸��û�
	ISIL_NEWLOG_ADD_GROUP,						// ����û���
	ISIL_NEWLOG_DELETE_GROUP,						// ɾ���û���
	ISIL_NEWLOG_MODIFY_GROUP,						// �޸��û���
	ISIL_NEWLOG_CLEAR = 0x0600,					// �����־
	ISIL_NEWLOG_SEARCHLOG,						// ��ѯ��־
	ISIL_NEWLOG_SEARCH = 0x0700,					// ¼���ѯ
	ISIL_NEWLOG_DOWNLOAD,							// ¼������
	ISIL_NEWLOG_PLAYBACK,							// ¼��ط�
	ISIL_NEWLOG_BACKUP,							// ����¼���ļ�
	ISIL_NEWLOG_BACKUPERROR,						// ����¼���ļ�ʧ��

	ISIL_NEWLOG_TYPE_NR = 8,
} ISIL_NEWLOG_TYPE;

///////////////////////////////�����Խ����///////////////////////////////

// ������������
typedef enum __TALK_CODING_TYPE
{
	ISIL_TALK_DEFAULT = 0,						// ��ͷPCM
	ISIL_TALK_PCM = 1,							// ��ͷPCM
	ISIL_TALK_G711a,								// G711a
	ISIL_TALK_AMR,								// AMR
	ISIL_TALK_G711u,								// G711u
	ISIL_TALK_G726,								// G726
} ISIL_TALK_CODING_TYPE;

// �Խ���ʽ
typedef enum __EM_USEDEV_MODE
{
	ISIL_TALK_ISIL_CLIENT_MODE,						// ���ÿͻ��˷�ʽ���������Խ�
	ISIL_TALK_SERVER_MODE,						// ���÷�������ʽ���������Խ�
	ISIL_TALK_ENCODE_TYPE,						// ���������Խ������ʽ
	ISIL_ALARM_LISTEN_MODE,						// ���ñ������ķ�ʽ
	ISIL_CONFIG_AUTHORITY_MODE,					// ����ͨ��Ȩ�޽������ù���
} EM_USEDEV_MODE;

// AMR��������
typedef enum __EM_ARM_ENCODE_MODE
{
	ISIL_TALK_AMR_AMR475 = 1,						// AMR475����
	ISIL_TALK_AMR_AMR515,							// AMR515����
	ISIL_TALK_AMR_AMR59,							// AMR59����
	ISIL_TALK_AMR_AMR67,							// AMR67����
	ISIL_TALK_AMR_AMR74,							// AMR74����
	ISIL_TALK_AMR_AMR795,							// AMR795����
	ISIL_TALK_AMR_AMR102,							// AMR102����
	ISIL_TALK_AMR_AMR122,							// AMR122����
} EM_ARM_ENCODE_MODE;

/////////////////////////////////�������/////////////////////////////////

// �������ͣ���ӦISIL_CLIENT_ControlDevice�ӿ�
typedef enum _CtrlType
{
	ISIL_CTRL_REBOOT = 0,							// �����豸
	ISIL_CTRL_SHUTDOWN,							// �ر��豸
	ISIL_CTRL_DISK,								// Ӳ�̹���
	ISIL_KEYBOARD_POWER = 3,						// �������
	ISIL_KEYBOARD_ENTER,
	ISIL_KEYBOARD_ESC,
	ISIL_KEYBOARD_UP,
	ISIL_KEYBOARD_DOWN,
	ISIL_KEYBOARD_LEFT,
	ISIL_KEYBOARD_RIGHT,
	ISIL_KEYBOARD_BTN0,
	ISIL_KEYBOARD_BTN1,
	ISIL_KEYBOARD_BTN2,
	ISIL_KEYBOARD_BTN3,
	ISIL_KEYBOARD_BTN4,
	ISIL_KEYBOARD_BTN5,
	ISIL_KEYBOARD_BTN6,
	ISIL_KEYBOARD_BTN7,
	ISIL_KEYBOARD_BTN8,
	ISIL_KEYBOARD_BTN9,
	ISIL_KEYBOARD_BTN10,
	ISIL_KEYBOARD_BTN11,
	ISIL_KEYBOARD_BTN12,
	ISIL_KEYBOARD_BTN13,
	ISIL_KEYBOARD_BTN14,
	ISIL_KEYBOARD_BTN15,
	ISIL_KEYBOARD_BTN16,
	ISIL_KEYBOARD_SPLIT,
	ISIL_KEYBOARD_ONE,
	ISIL_KEYBOARD_NINE,
	ISIL_KEYBOARD_ADDR,
	ISIL_KEYBOARD_INFO,
	ISIL_KEYBOARD_REC,
	ISIL_KEYBOARD_FN1,
	ISIL_KEYBOARD_FN2,
	ISIL_KEYBOARD_PLAY,
	ISIL_KEYBOARD_STOP,
	ISIL_KEYBOARD_SLOW,
	ISIL_KEYBOARD_FAST,
	ISIL_KEYBOARD_PREW,
	ISIL_KEYBOARD_NEXT,
	ISIL_KEYBOARD_JMPDOWN,
	ISIL_KEYBOARD_JMPUP,
	ISIL_TRIGGER_ALARM_IN = 100,					// ������������
	ISIL_TRIGGER_ALARM_OUT,						// �����������
	ISIL_CTRL_MATRIX,								// �������
	ISIL_CTRL_SDCARD,								// SD������(IPC��Ʒ)����ͬӲ�̿���
	ISIL_BURNING_START,							// ��¼�����ƣ���ʼ��¼
	ISIL_BURNING_STOP,							// ��¼�����ƣ�������¼
	ISIL_BURNING_ADDPWD,							// ��¼�����ƣ���������(��'\0'Ϊ��β���ַ�������󳤶�8λ)
	ISIL_BURNING_ADDHEAD,							// ��¼�����ƣ�����Ƭͷ(��'\0'Ϊ��β���ַ�������󳤶�1024�ֽڣ�֧�ַ��У��зָ���'\n')
	ISIL_BURNING_ADDSIGN,							// ��¼�����ƣ����Ӵ�㵽��¼��Ϣ(������)
	ISIL_BURNING_ADDCURSTOMINFO,					// ��¼�����ƣ��Զ������(��'\0'Ϊ��β���ַ�������󳤶�1024�ֽڣ�֧�ַ��У��зָ���'\n')
	ISIL_CTRL_RESTOREDEFAULT,						// �ָ��豸��Ĭ������
	ISIL_CTRL_CAPTURE_START,						// �����豸ץͼ
	ISIL_CTRL_CLEARLOG,							// �����־
	ISIL_TRIGGER_ALARM_WIRELESS = 200,			// �������߱���(IPC��Ʒ)
	ISIL_MARK_IMPORTANT_RECORD,					// ��ʶ��Ҫ¼���ļ�
	ISIL_CTRL_DISK_SUBAREA, 						// ����Ӳ�̷���
	ISIL_BURNING_ATTACH,							// ��¼�����ƣ�������¼.
	ISIL_BURNING_PAUSE,							// ��¼��ͣ
	ISIL_BURNING_CONTINUE,						// ��¼����
	ISIL_BURNING_POSTPONE,						// ��¼˳��
	ISIL_CTRL_OEMCTRL,							// ��ͣ����
} CtrlType;

// IO���������ӦISIL_CLIENT_QueryIOControlState�ӿ�
typedef enum _IOTYPE
{
	ISIL_ALARMINPUT = 1,							// ���Ʊ�������
	ISIL_ALARMOUTPUT = 2,							// ���Ʊ������
	ISIL_DECODER_ALARMOUT = 3,					// ���Ʊ������������
	ISIL_WIRELESS_ALARMOUT = 5,					// �������߱������
	ISIL_ALARM_TRIGGER_MODE = 7,					// ����������ʽ���ֶ�,�Զ�,�رգ���ʹ��TRIGGER_MODE_CONTROL�ṹ��
} ISIL_IOTYPE;

/////////////////////////////////�������/////////////////////////////////

// �ֱ���ö�٣���ISIL_DSP_ENCODECAPʹ��
typedef enum _CAPTURE_SIZE
{
	CAPTURE_SIZE_D1,							// 720*576(PAL)  720*480(NTSC)
	CAPTURE_SIZE_HD1,							// 352*576(PAL)  352*480(NTSC)
	CAPTURE_SIZE_BCIF,							// 720*288(PAL)  720*240(NTSC)
	CAPTURE_SIZE_CIF,							// 352*288(PAL)  352*240(NTSC)
	CAPTURE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	CAPTURE_SIZE_VGA,							// 640*480
	CAPTURE_SIZE_QVGA,							// 320*240
	CAPTURE_SIZE_SVCD,							// 480*480
	CAPTURE_SIZE_QQVGA,							// 160*128
	CAPTURE_SIZE_SVGA,							// 800*592
	CAPTURE_SIZE_XVGA,							// 1024*768
	CAPTURE_SIZE_WXGA,							// 1280*800
	CAPTURE_SIZE_SXGA,							// 1280*1024
	CAPTURE_SIZE_WSXGA,							// 1600*1024
	CAPTURE_SIZE_UXGA,							// 1600*1200
	CAPTURE_SIZE_WUXGA,							// 1920*1200
	CAPTURE_SIZE_LTF,							// 240*192(PAL)
	CAPTURE_SIZE_720,							// 1280*720
	CAPTURE_SIZE_1080,							// 1920*1080
	CAPTURE_SIZE_1_3M,							// 1280*960
	CAPTURE_SIZE_NR
} CAPTURE_SIZE;

// �����ļ����ͣ���ISIL_CLIENT_ExportConfigFile�ӿ�ʹ��
typedef enum __ISIL_CONFIG_FILE_TYPE
{
	ISIL_CONFIGFILE_ALL = 0,						// ȫ�������ļ�
	ISIL_CONFIGFILE_LOCAL,						// ���������ļ�
	ISIL_CONFIGFILE_NETWORK,						// ���������ļ�
	ISIL_CONFIGFILE_USER,							// �û������ļ�
} ISIL_CONFIG_FILE_TYPE;

// NTP
typedef enum __ISIL_TIME_ZONE_TYPE
{
	ISIL_TIME_ZONE_0,								// {0, 0*3600,"GMT+00:00"}
	ISIL_TIME_ZONE_1,								// {1, 1*3600,"GMT+01:00"}
	ISIL_TIME_ZONE_2,								// {2, 2*3600,"GMT+02:00"}
	ISIL_TIME_ZONE_3,								// {3, 3*3600,"GMT+03:00"}
	ISIL_TIME_ZONE_4,								// {4, 3*3600+1800,"GMT+03:30"}
	ISIL_TIME_ZONE_5,								// {5, 4*3600,"GMT+04:00"}
	ISIL_TIME_ZONE_6,								// {6, 4*3600+1800,"GMT+04:30"}
	ISIL_TIME_ZONE_7,								// {7, 5*3600,"GMT+05:00"}
	ISIL_TIME_ZONE_8,								// {8, 5*3600+1800,"GMT+05:30"}
	ISIL_TIME_ZONE_9,								// {9, 5*3600+1800+900,"GMT+05:45"}
	ISIL_TIME_ZONE_10,							// {10, 6*3600,"GMT+06:00"}
	ISIL_TIME_ZONE_11,							// {11, 6*3600+1800,"GMT+06:30"}
	ISIL_TIME_ZONE_12,							// {12, 7*3600,"GMT+07:00"}
	ISIL_TIME_ZONE_13,							// {13, 8*3600,"GMT+08:00"}
	ISIL_TIME_ZONE_14,							// {14, 9*3600,"GMT+09:00"}
	ISIL_TIME_ZONE_15,							// {15, 9*3600+1800,"GMT+09:30"}
	ISIL_TIME_ZONE_16,							// {16, 10*3600,"GMT+10:00"}
	ISIL_TIME_ZONE_17,							// {17, 11*3600,"GMT+11:00"}
	ISIL_TIME_ZONE_18,							// {18, 12*3600,"GMT+12:00"}
	ISIL_TIME_ZONE_19,							// {19, 13*3600,"GMT+13:00"}
	ISIL_TIME_ZONE_20,							// {20, -1*3600,"GMT-01:00"}
	ISIL_TIME_ZONE_21,							// {21, -2*3600,"GMT-02:00"}
	ISIL_TIME_ZONE_22,							// {22, -3*3600,"GMT-03:00"}
	ISIL_TIME_ZONE_23,							// {23, -3*3600-1800,"GMT-03:30"}
	ISIL_TIME_ZONE_24,							// {24, -4*3600,"GMT-04:00"}
	ISIL_TIME_ZONE_25,							// {25, -5*3600,"GMT-05:00"}
	ISIL_TIME_ZONE_26,							// {26, -6*3600,"GMT-06:00"}
	ISIL_TIME_ZONE_27,							// {27, -7*3600,"GMT-07:00"}
	ISIL_TIME_ZONE_28,							// {28, -8*3600,"GMT-08:00"}
	ISIL_TIME_ZONE_29,							// {29, -9*3600,"GMT-09:00"}
	ISIL_TIME_ZONE_30,							// {30, -10*3600,"GMT-10:00"}
	ISIL_TIME_ZONE_31,							// {31, -11*3600,"GMT-11:00"}
	ISIL_TIME_ZONE_32,							// {32, -12*3600,"GMT-12:00"}
} ISIL_TIME_ZONE_TYPE;

typedef enum _SNAP_TYPE
{
	SNAP_TYP_TIMING = 0,
	SNAP_TYP_ALARM,
	SNAP_TYP_NUM,
} SNAP_TYPE;



/************************************************************************
 ** �ṹ�嶨��
 ***********************************************************************/
/*����λ��*/
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;
// ʱ��
typedef struct
{
	DWORD				dwYear;					// ��
	DWORD				dwMonth;				// ��
	DWORD				dwDay;					// ��
	DWORD				dwHour;					// ʱ
	DWORD				dwMinute;				// ��
	DWORD				dwSecond;				// ��
} NET_TIME,*LPNET_TIME;

// ��־��Ϣ���ʱ�䶨��
typedef struct _ISILDEVTIME
{
	DWORD				second		:6;			// ��	1-60
	DWORD				minute		:6;			// ��	1-60
	DWORD				hour		:5;			// ʱ	1-24
	DWORD				day			:5;			// ��	1-31
	DWORD				month		:4;			// ��	1-12
	DWORD				year		:6;			// ��	2000-2063
} ISIL_DEV_TIME, *LPISILDEVTIME;

// �ص�����(�첽�ӿ�)
typedef struct __NET_CALLBACK_DATA
{
	int					nResultCode;			// �����룻0���ɹ�
	char				*pBuf;					// �������ݣ����������û����ٵģ��ӽӿ��βδ���
	int					nRetLen;				// ���ճ���
	LONG				lOperateHandle;			// �������
	void*				userdata;				// ������Ӧ�û�����
	char				reserved[16];
} NET_CALLBACK_DATA, *LPNET_CALLBACK_DATA;

///////////////////////////////������ض���///////////////////////////////

// �ص���Ƶ����֡��֡�����ṹ��
typedef struct _tagVideoFrameParam
{
	BYTE				encode;					// ��������
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15, LFT - 16, 720 - 17, 1080 - 18
	DWORD				fourcc;					// �����H264��������Ϊ0��MPEG4����������дFOURCC('X','V','I','D');
	DWORD				reserved;				// ����
	NET_TIME			struTime;				// ʱ����Ϣ
} tagVideoFrameParam;

// �ص���Ƶ����֡��֡�����ṹ��
typedef struct _tagCBPCMDataParam
{
	BYTE				channels;				// ������
	BYTE				samples;				// ���� 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// ������� ȡֵ8����16�ȡ�ֱ�ӱ�ʾ
	BYTE				param1;					// 0 - ָʾ�޷��ţ�1-ָʾ�з���
	DWORD				reserved;				// ����
} tagCBPCMDataParam;

// ͨ��������Ļ���ӵ����ݽṹ
typedef struct _ISIL_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// ʹ��
	DWORD				dwPosition[MAX_STRING_LINE_LEN];	//�����ַ���λ�á���1-9������ʾ����С����λ�ö�Ӧ
												//		7����	8��		9����
												//		4��		5��		6��
												//		1����	2��		3����
	char				szStrings[MAX_STRING_LINE_LEN][MAX_PER_STRING_LEN];	// ��������ַ���ÿ�����20���ֽ�
} ISIL_CHANNEL_OSDSTRING;

///////////////////////////////�ط���ض���///////////////////////////////

// ¼���ļ���Ϣ
typedef struct
{
    unsigned int		ch;						// ͨ����
    char				filename[128];			// �ļ���
    unsigned int		size;					// �ļ�����
    NET_TIME			starttime;				// ��ʼʱ��
    NET_TIME			endtime;				// ����ʱ��
    unsigned int		driveno;				// ���̺�(��������¼��ͱ���¼������ͣ�0��127��ʾ����¼��128��ʾ����¼��)
    unsigned int		startcluster;			// ��ʼ�غ�
	BYTE				nRecordFileType;		// ¼���ļ�����  0����ͨ¼��1������¼��2���ƶ���⣻3������¼��4��ͼƬ
	BYTE                bImportantRecID;		// 0:��ͨ¼�� 1:��Ҫ¼��
	BYTE                bHint;					// �ļ���λ����
	BYTE                bReserved;				// ����
} NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;

// ����¼��ʱ��
typedef struct
{
	int					nChnCount;				// ͨ����Ŀ
	NET_TIME			stuFurthestTime[16];	// ����¼��ʱ��,��ЧֵΪǰ��0 �� (nChnCount-1)��.���ĳͨ��û��¼��Ļ�������¼��ʱ��ȫΪ0
	BYTE				bReserved[384];			// �����ֶ�
} NET_FURTHEST_RECORD_TIME;

///////////////////////////////������ض���///////////////////////////////

// ��ͨ������Ϣ
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// �ⲿ����
	unsigned char		motiondection[16];		// ��̬���
	unsigned char		videolost[16];			// ��Ƶ��ʧ
} ISIL_CLIENT_NET__STATE;

// ����IO����
typedef struct
{
	unsigned short		index;					// �˿����
	unsigned short		state;					// �˿�״̬
} ALARM_CONTROL;

//������ʽ
typedef struct
{
	unsigned short		index;					//�˿����
	unsigned short		mode;					//������ʽ(0�ر�1�ֶ�2�Զ�);�����õ�ͨ����sdkĬ�Ͻ�����ԭ�������á�
	BYTE				bReserved[28];
} TRIGGER_MODE_CONTROL;

// ��������������
typedef struct
{
	int					decoderNo;				// �����������ţ���0��ʼ
	unsigned short		alarmChn;				// ��������ڣ���0��ʼ
	unsigned short		alarmState;				// �������״̬��1���򿪣�0���ر�
} DECODER_ALARM_CONTROL;

// �����ϴ����ܵı�����Ϣ
typedef struct
{
	DWORD				dwAlarmType;			// �������ͣ�dwAlarmType = ISIL_UPLOAD_EVENTʱ��dwAlarmMask��bAlarmDecoderIndex����Ч��
	DWORD				dwAlarmMask;			// ������Ϣ���룬��λ��ʾ������ͨ��״̬
	char				szGlobalIP[ISIL_MAX_IPADDR_LEN];	// �ͻ���IP��ַ
	char				szDomainName[ISIL_MAX_DOMAIN_NAME_LEN];	// �ͻ�������
	int					nPort;					// �����ϴ�ʱ�ͻ������ӵĶ˿�
	char				szAlarmOccurTime[ISIL_ALARM_OCCUR_TIME_LEN];	// ����������ʱ��
	BYTE				bAlarmDecoderIndex;		// ��ʾ�ڼ���������������dwAlarmType = ISIL_UPLOAD_DECODER_ALARM ����Ч.
	BYTE				bReservedSpace[15];
}NEW_ALARM_UPLOAD;

/////////////////////////////�����Խ���ض���/////////////////////////////

// ��Ƶ��ʽ��Ϣ
typedef struct
{
	BYTE				byFormatTag;			// �������ͣ���0��PCM
	WORD				nChannels;				// ������
	WORD				wBitsPerSample;			// �������
	DWORD				nSamplesPerSec;			// ������
} ISIL_AUDIO_FORMAT, *LPISIL_AUDIO_FORMAT;

/////////////////////////////�û�������ض���/////////////////////////////

// ֧���û�����󳤶�Ϊ8λ���豸����ӦISIL_CLIENT_QueryUserInfo��ISIL_CLIENT_OperateUserInfo�ӿ�
// Ȩ����Ϣ
typedef struct _OPR_RIGHT
{
	DWORD				dwID;
	char				name[ISIL_RIGHT_NAME_LENGTH];
	char				memo[ISIL_MEMO_LENGTH];
} OPR_RIGHT;

// �û���Ϣ
typedef struct _USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ISIL_USER_NAME_LENGTH];
	char				passWord[ISIL_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
	DWORD				dwReusable;				// �Ƿ��ã�1�����ã�0��������
} USER_INFO;

// �û�����Ϣ
typedef struct _USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[ISIL_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
} USER_GROUP_INFO;

// �û���Ϣ��
typedef struct _USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// Ȩ����Ϣ
	OPR_RIGHT			rightList[ISIL_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// �û�����Ϣ
	USER_GROUP_INFO		groupList[ISIL_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// �û���Ϣ
	USER_INFO			userList[ISIL_MAX_USER_NUM];
	DWORD				dwSpecial;				// �û�����������1��֧���û����ã�0����֧���û�����
} USER_MANAGE_INFO;

// ֧���û�����󳤶�Ϊ8λ��16λ���豸����Ӧ��չ�ӿ�ISIL_CLIENT_QueryUserInfoEx��ISIL_CLIENT_OperateUserInfoEx
#define ISIL_USER_NAME_LENGTH_EX		16			// �û�������
#define ISIL_USER_PSW_LENGTH_EX		16			// ����

// Ȩ����Ϣ
typedef struct _OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[ISIL_RIGHT_NAME_LENGTH];
	char				memo[ISIL_MEMO_LENGTH];
} OPR_RIGHT_EX;

// �û���Ϣ
typedef struct _USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ISIL_USER_NAME_LENGTH_EX];
	char				passWord[ISIL_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// ���룬0x00000001 - ֧���û�����
	BYTE				byReserve[32];
} USER_INFO_EX;

// �û�����Ϣ
typedef struct _USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[ISIL_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
} USER_GROUP_INFO_EX;

// �û���Ϣ��
typedef struct _USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// Ȩ����Ϣ
	OPR_RIGHT_EX		rightList[ISIL_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// �û�����Ϣ
	USER_GROUP_INFO_EX  groupList[ISIL_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// �û���Ϣ
	USER_INFO_EX		userList[ISIL_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// ���룻0x00000001 - ֧���û����ã�0x00000002 - �����޸���ҪУ��
	BYTE				byNameMaxLength;		// ֧�ֵ��û�����󳤶�
	BYTE				byPSWMaxLength;			// ֧�ֵ�������󳤶�
	BYTE				byReserve[254];
} USER_MANAGE_INFO_EX;

///////////////////////////////��ѯ��ض���///////////////////////////////

// �豸֧����������
typedef struct _ISIL_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// ֧�����Ը���
	BYTE				byLanguageType[252];	// ö��ֵ�����ISIL_LANGUAGE_TYPE
} ISIL_DEV_LANGUAGE_INFO, *LPISIL_DEV_LANGUAGE_INFO;

// Ӳ����Ϣ
typedef struct
{
	DWORD				dwVolume;				// Ӳ�̵�����
	DWORD				dwFreeSpace;			// Ӳ�̵�ʣ��ռ�
	BYTE				dwStatus;				// Ӳ�̵�״̬,0-����,1-�,2-���ϵȣ���DWORD����ĸ�BYTE
	BYTE				bDiskNum;				// Ӳ�̺�
	BYTE				bSubareaNum;			// ������
	BYTE				bSignal;				// ��ʶ��0Ϊ���� 1ΪԶ��
} ISIL_DEV_DISKSTATE,*LPISIL_DEV_DISKSTATE;

// �豸Ӳ����Ϣ
typedef struct _ISIL_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// ����
	ISIL_DEV_DISKSTATE	stDisks[ISIL_MAX_DISKNUM];// Ӳ�̻������Ϣ
} ISIL_HARDDISK_STATE, *LPISIL_HARDDISK_STATE;

typedef ISIL_HARDDISK_STATE	ISIL_SDCARD_STATE;	// SD�������ݽṹͬӲ����Ϣ

// ����������Ϣ
typedef struct
{
	ISIL_TALK_CODING_TYPE	encodeType;				// ��������
	int					nAudioBit;				// λ������8��16
	DWORD				dwSampleRate;			// �����ʣ���8000��16000
	char				reserved[64];
} ISIL_DEV_TALKDECODE_INFO;

// �豸֧�ֵ������Խ�����
typedef struct
{
	int					nSupportNum;			// ����
	ISIL_DEV_TALKDECODE_INFO type[64];				// ��������
	char				reserved[64];
} ISIL_DEV_TALKFORMAT_LIST;

// ��̨������Ϣ
#define  NAME_MAX_LEN 16
typedef struct
{
	DWORD				dwHighMask;				// �����������λ
	DWORD				dwLowMask;				// �����������λ
	char				szName[NAME_MAX_LEN];	// ������Э����
	WORD				wCamAddrMin;			// ͨ����ַ����Сֵ
	WORD				wCamAddrMax;			// ͨ����ַ�����ֵ
	WORD				wMonAddrMin;			// ���ӵ�ַ����Сֵ
	WORD				wMonAddrMax;			// ���ӵ�ַ�����ֵ
	BYTE				bPresetMin;				// Ԥ�õ����Сֵ
	BYTE				bPresetMax;				// Ԥ�õ�����ֵ
	BYTE				bTourMin;				// �Զ�Ѳ����·����Сֵ
	BYTE				bTourMax;				// �Զ�Ѳ����·�����ֵ
	BYTE				bPatternMin;			// �켣��·����Сֵ
	BYTE				bPatternMax;			// �켣��·�����ֵ
	BYTE				bTileSpeedMin;			// ��ֱ�ٶȵ���Сֵ
	BYTE				bTileSpeedMax;			// ��ֱ�ٶȵ����ֵ
	BYTE				bPanSpeedMin;			// ˮƽ�ٶȵ���Сֵ
	BYTE				bPanSpeedMax;			// ˮƽ�ٶȵ����ֵ
	BYTE				bAuxMin;				// �������ܵ���Сֵ
	BYTE				bAuxMax;				// �������ܵ����ֵ
	int					nInternal;				// ���������ʱ����
	char				cType;					// Э�������
	char				Reserved[7];
} PTZ_OPT_ATTR;

// ��¼����Ϣ
typedef struct _ISIL_DEV_BURNING
{
	DWORD				dwDriverType;			// ��¼���������ͣ�0��DHFS��1��DISK��2��CDRW
	DWORD				dwBusType;				// �������ͣ�0��USB��1��1394��2��IDE
	DWORD				dwTotalSpace;			// ������(KB)
	DWORD				dwRemainSpace;			// ʣ������(KB)
	BYTE				dwDriverName[ISIL_BURNING_DEV_NAMELEN];	// ��¼����������
} ISIL_DEV_BURNING, *LPISIL_DEV_BURNING;

// �豸��¼����Ϣ
typedef struct _ISIL_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// ��¼�豸����
	ISIL_DEV_BURNING		stDevs[ISIL_MAX_BURNING_DEV_NUM];	// ����¼�豸��Ϣ
} ISIL_BURNING_DEVINFO, *LPISIL_BURNING_DEVINFO;

// ��¼����
typedef struct _ISIL_BURNING_PROGRESS
{
	BYTE				bBurning;				// ��¼��״̬��0�����Կ�¼��1����¼�����Ͳ��ԣ���һ���ǹ����豸��
												// 2��δ�ҵ���¼����3�������������ڿ�¼��4����¼�����ڷǿ���״̬�����ڱ��ݡ���¼��ط���
	BYTE				bRomType;				// ��Ƭ���ͣ�0�����ļ�ϵͳ��1���ƶ�Ӳ�̻�U�̣�2������
	BYTE				bOperateType;			// �������ͣ�0�����У�1�����ڱ����У�2�����ڿ�¼�У�3�����ڽ��й��̻ط�
	BYTE				bType;					// ���ݻ��¼����״̬��0��ֹͣ�������1����ʼ��2������3������4�����ڳ�ʼ��
	NET_TIME			stTimeStart;			// ��ʼʱ�䡡
	DWORD				dwTimeElapse;			// �ѿ�¼ʱ��(��)
	DWORD				dwTotalSpace;			// ����������
	DWORD				dwRemainSpace;			// ����ʣ������
	DWORD				dwBurned;				// �ѿ�¼����
	WORD				dwStatus;				// ����
	WORD				wChannelMask;			// ���ڿ�¼��ͨ������
} ISIL_BURNING_PROGRESS, *LPISIL_BURNING_PROGRESS;

// ��־��Ϣ����Ӧ�ӿ�ISIL_CLIENT_QueryLog�ӿ�
typedef struct _ISIL_LOG_ITEM
{
    ISIL_DEV_TIME			time;					// ����
    unsigned short		type;					// ����
    unsigned char		reserved;				// ����
    unsigned char		data;					// ����
    unsigned char		context[8];				// ����
} ISIL_LOG_ITEM, *LPISIL_LOG_ITEM;

// ��־��Ϣ����Ӧ��չ�ӿ�ISIL_CLIENT_QueryLogEx������reserved(int nType=1;reserved=&nType;)
typedef struct _ISIL_NEWLOG_ITEM
{
	ISIL_DEV_TIME			time;					// ����
	WORD				type;					// ����
	WORD				data;					// ����
	char				szOperator[8]; 			// �û���
	BYTE				context[16];		    // ����
} ISIL_NEWLOG_ITEM, *LPISIL_NEWLOG_ITEM;

// ��־��Ϣ����Ӧ�ӿ�ISIL_CLIENT_QueryDeviceLog�ӿ�
typedef struct _ISIL_DEVICE_LOG_ITEM
{
	int					nLogType;				// ��־����
	ISIL_DEV_TIME			stuOperateTime;			// ����
	char				szOperator[16]; 		// ������
	BYTE				bReserved[3];
	BYTE				bUnionType;				//  union�ṹ����,0:szLogContext��1:stuOldLog��
	union
	{
		char			szLogContext[64];		// ��־����
		struct
		{
			ISIL_LOG_ITEM		stuLog;				// �ɵ���־�ṹ��
			BYTE			bReserved[48];		// ����
		}stuOldLog;
	};
	char				reserved[16];
} ISIL_DEVICE_LOG_ITEM, *LPISIL_DEVICE_LOG_ITEM;

// ¼����־��Ϣ����Ӧ��־�ṹ�����context
typedef struct _LOG_ITEM_RECORD
{
	ISIL_DEV_TIME			time;					// ʱ��
	BYTE				channel;				// ͨ��
	BYTE				type;					// ¼������
	BYTE				reserved[2];
} LOG_ITEM_RECORD, *LPLOG_ITEM_RECORD;

typedef struct _QUERY_DEVICE_LOG_PARAM
{
	ISIL_LOG_QUERY_TYPE	emLogType;				// ��ѯ��־����
	NET_TIME			stuStartTime;			// ��ѯ��־�Ŀ�ʼʱ��
	NET_TIME			stuEndTime;				// ��ѯ��־�Ľ���ʱ��
	int					nStartNum;				// ��ʱ����дӵڼ�����־��ʼ��ѯ����ʼ��һ�β�ѯ����Ϊ0
	int					nEndNum;				// һ�β�ѯ�е��ڼ�����־������
	BYTE				bReserved[48];
} QUERY_DEVICE_LOG_PARAM;

// �豸Ӳ�����¼����Ϣ
typedef struct __ISIL_DEV_DISK_RECORD_INFO
{
	NET_TIME			stuBeginTime;			// ����¼��ʱ��
	NET_TIME			stuEndTime;				// ���¼��ʱ��
	char				reserved[128];
} ISIL_DEV_DISK_RECORD_INFO;

///////////////////////////////������ض���///////////////////////////////

// Ӳ�̲���
typedef struct _DISKCTRL_PARAM
{
	DWORD				dwSize;					// �ṹ���С���汾������
	int					nIndex;					// ΪӲ����Ϣ�ṹ��ISIL_HARDDISK_STATE�������stDisks�±꣬��0��ʼ
	int					ctrlType;				// �������ͣ�
												// 0 - �������, 1 - ��Ϊ��д��, 2 - ��Ϊֻ����
												// 3 - ��Ϊ������, 4 - �ָ�����, 5 - ��Ϊ������
} DISKCTRL_PARAM;

typedef struct
{
	BYTE				bSubareaNum;			// Ԥ�����ĸ���
	BYTE				bIndex;					// ΪӲ����Ϣ�ṹ��ISIL_HARDDISK_STATE�������stDisks�±꣬��0��ʼ
	BYTE				bSubareaSize[32];		// ������С���ٷֱȣ�
	BYTE				bReserved[30];			// ����
} DISKCTRL_SUBAREA;

// ����״̬
typedef struct _ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// ����ͨ���ţ���0��ʼ
	int					nAction;				// 1������������0��ֹͣ����
} ALARMCTRL_PARAM;

// �������
typedef struct _MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// ��Ƶ����ţ���0��ʼ
	int					nMatrixNo;				// ��������ţ���0��ʼ
} MATRIXCTRL_PARAM;

// ��¼����
typedef struct _BURNING_PARM
{
	int					channelMask;			// ͨ�����룬��λ��ʾҪ��¼��ͨ��
	int					devMask;				// ��¼�����룬���ݲ�ѯ���Ŀ�¼���б���λ��ʾ
} BURNNG_PARM;

// ������¼
typedef struct _BURNING_PARM_ATTACH
{
	BOOL				bAttachBurn;			// �Ƿ�Ϊ������¼��0:����; 1:��
	BYTE				bReserved[12];			// �����ֶ�
} BURNING_PARM_ATTACH;

///////////////////////////////������ض���///////////////////////////////

//-------------------------------�豸����---------------------------------
// �豸��Ϣ
typedef struct
{
	BYTE				sSerialNumber[ISIL_SERIALNO_LEN];	// ���к�
	BYTE				byAlarmInPortNum;		// DVR�����������
	BYTE				byAlarmOutPortNum;		// DVR�����������
	BYTE				byDiskNum;				// DVRӲ�̸���
	BYTE				byDVRType;				// DVR����, ��ö��ISIL_DEV_DEVICE_TYPE
	BYTE				byChanNum;				// DVRͨ������
	BYTE                reserved[3];
} NET_DEVICEINFO, *LPNET_DEVICEINFO;

// �豸����汾��Ϣ����16λ��ʾ���汾�ţ���16λ��ʾ�ΰ汾��
typedef struct
{
	DWORD				dwSoftwareVersion;
	DWORD				dwSoftwareBuildDate;
	DWORD				dwDspSoftwareVersion;
	DWORD				dwDspSoftwareBuildDate;
	DWORD				dwPanelVersion;
	DWORD				dwPanelSoftwareBuildDate;
	DWORD				dwHardwareVersion;
	DWORD				dwHardwareDate;
	DWORD				dwWebVersion;
	DWORD				dwWebBuildDate;
} ISIL_VERSION_INFO, *LPISIL_VERSION_INFO;

// �豸����汾��Ϣ����ӦISIL_CLIENT_QueryDevState�ӿ�
typedef struct
{
	char				szDevSerialNo[ISIL_DEV_SERIALNO_LEN];	// ���к�
	char				byDevType;				// �豸���ͣ���ö��ISIL_DEV_DEVICE_TYPE
	char				szDevType[ISIL_DEV_TYPE_LEN];	// �豸��ϸ�ͺţ��ַ�����ʽ������Ϊ��
	int					nProtocalVer;			// Э��汾��
	char				szSoftWareVersion[ISIL_MAX_URL_LEN];
	DWORD				dwSoftwareBuildDate;
	char				szDspSoftwareVersion[ISIL_MAX_URL_LEN];
	DWORD				dwDspSoftwareBuildDate;
	char				szPanelVersion[ISIL_MAX_URL_LEN];
	DWORD				dwPanelSoftwareBuildDate;
	char				szHardwareVersion[ISIL_MAX_URL_LEN];
	DWORD				dwHardwareDate;
	char				szWebVersion[ISIL_MAX_URL_LEN];
	DWORD				dwWebBuildDate;
	char				reserved[256];
} ISIL_DEV_VERSION_INFO;

// DSP������������ӦISIL_CLIENT_GetDevConfig�ӿ�
typedef struct
{
	DWORD				dwVideoStandardMask;	// ��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ
	DWORD				dwImageSizeMask;		// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ�������
	DWORD				dwEncodeModeMask;		// ����ģʽ���룬��λ��ʾ�豸�ܹ�֧�ֵı���ģʽ����
	DWORD				dwStreamCap;			// ��λ��ʾ�豸֧�ֵĶ�ý�幦�ܣ�
												// ��һλ��ʾ֧��������
												// �ڶ�λ��ʾ֧�ָ�����1
												// ����λ��ʾ֧�ָ�����2
												// ����λ��ʾ֧��jpgץͼ
	DWORD				dwImageSizeMask_Assi[8];// ��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ������롣
	DWORD				dwMaxEncodePower;		// DSP֧�ֵ���߱�������
	WORD				wMaxSupportChannel;		// ÿ��DSP֧�����������Ƶͨ����
	WORD				wChannelMaxSetSync;		// DSPÿͨ���������������Ƿ�ͬ����0����ͬ����1��ͬ��
} ISIL_DSP_ENCODECAP, *LPISIL_DSP_ENCODECAP;

// DSP������������չ���ͣ���ӦISIL_CLIENT_QueryDevState�ӿ�
typedef struct
{
	DWORD				dwVideoStandardMask;	// ��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ
	DWORD				dwImageSizeMask;		// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ���
	DWORD				dwEncodeModeMask;		// ����ģʽ���룬��λ��ʾ�豸�ܹ�֧�ֵı���ģʽ
	DWORD				dwStreamCap;			// ��λ��ʾ�豸֧�ֵĶ�ý�幦�ܣ�
												// ��һλ��ʾ֧��������
												// �ڶ�λ��ʾ֧�ָ�����1
												// ����λ��ʾ֧�ָ�����2
												// ����λ��ʾ֧��jpgץͼ
	DWORD				dwImageSizeMask_Assi[32];// ��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ������롣
	DWORD				dwMaxEncodePower;		// DSP֧�ֵ���߱�������
	WORD				wMaxSupportChannel;		// ÿ��DSP֧�����������Ƶͨ����
	WORD				wChannelMaxSetSync;		// DSPÿͨ���������������Ƿ�ͬ����0����ͬ����1��ͬ��
	BYTE				bMaxFrameOfImageSize[32];// ��ͬ�ֱ����µ����ɼ�֡�ʣ���dwVideoStandardMask��λ��Ӧ
	BYTE				bEncodeCap;				// ��־������ʱҪ����������������������ò�����Ч��
												// 0���������ı�������+�������ı������� <= �豸�ı���������
												// 1���������ı�������+�������ı������� <= �豸�ı���������
												// �������ı������� <= �������ı���������
												// �������ķֱ��� <= �������ķֱ��ʣ�
												// �������͸�������֡�� <= ǰ����Ƶ�ɼ�֡��
												// 2��N5�ļ��㷽��
												// �������ķֱ��� <= �������ķֱ���
												// ��ѯ֧�ֵķֱ��ʺ���Ӧ���֡��
	char				reserved[95];
} ISIL_DEV_DSP_ENCODECAP, *LPISIL_DEV_DSP_ENCODECAP;

// ϵͳ��Ϣ
typedef struct
{
	DWORD				dwSize;
	/* �������豸��ֻ������ */
	ISIL_VERSION_INFO		stVersion;
	ISIL_DSP_ENCODECAP	stDspEncodeCap;			// DSP��������
	BYTE				szDevSerialNo[ISIL_DEV_SERIALNO_LEN];	// ���к�
	BYTE				byDevType;				// �豸���ͣ���ö��ISIL_DEV_DEVICE_TYPE
	BYTE				szDevType[ISIL_DEV_TYPE_LEN];	// �豸��ϸ�ͺţ��ַ�����ʽ������Ϊ��
	BYTE				byVideoCaptureNum;		// ��Ƶ������
	BYTE				byAudioCaptureNum;		// ��Ƶ������
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// �����������
	BYTE				byAlarmOutNum;			// �����������
	BYTE				byNetIONum;				// �������
	BYTE				byUsbIONum;				// USB������
	BYTE				byIdeIONum;				// IDE����
	BYTE				byComIONum;				// ��������
	BYTE				byLPTIONum;				// ��������
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP����չ����
	BYTE				byMatrixOutNum;			// ��Ƶ�����������
	/* �������豸�Ŀ�д���� */
	BYTE				byOverWrite;			// Ӳ��������ʽ(���ǡ�ֹͣ)
	BYTE				byRecordLen;			// ¼��������
	BYTE				byDSTEnable;			// �Ƿ�ʵ������ʱ 1-ʵ�� 0-��ʵ��
	WORD				wDevNo;					// �豸��ţ�����ң��
	BYTE				byVideoStandard;		// ��Ƶ��ʽ:0-PAL,1-NTSC
	BYTE				byDateFormat;			// ���ڸ�ʽ
	BYTE				byDateSprtr;			// ���ڷָ��(0��"."��1��"-"��2��"/")
	BYTE				byTimeFmt;				// ʱ���ʽ (0-24Сʱ��1��12Сʱ)
	BYTE				byLanguage;				// ö��ֵ���ISIL_LANGUAGE_TYPE
} ISIL_DEV_SYSTEM_ATTR_CFG, *LPISIL_DEV_SYSTEM_ATTR_CFG;

// �޸��豸���÷�����Ϣ
typedef struct
{
	DWORD				dwType;					// ����(��GetDevConfig��SetDevConfig������)
	WORD				wResultCode;			// �����룻0���ɹ���1��ʧ�ܣ�2�����ݲ��Ϸ���3����ʱ�޷����ã�4��û��Ȩ��
	WORD   				wRebootSign;			// ������־��0������Ҫ������1����Ҫ��������Ч
	DWORD				dwReserved[2];			// ����
} DEV_SET_RESULT;

//DST(����ʱ)����
typedef struct
{
	int					nYear;					// ��[200 - 2037]
	int					nMonth;					// ��[1 - 12]
	int					nHour;					// Сʱ [0 - 23]
	int					nMinute;				// ���� [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:��ʾʹ�ð����ڼ���ķ���
												// 1: ���ܼ���: ��һ��,2: �ڶ���,3: ������,4: ������,-1: ���һ��
	union
	{
		int				iWeekDay;				// ��[0 - 6](nWeekOrDay�����ܼ���ʱ)0:������, 1:����һ, 2:���ڶ�,3:������,4:������,5:������,6:������
		int				iDay;					// ����[1 - 31] (nWeekOrDay�������ڼ���)
	};

	DWORD				dwReserved[8];			// ����
}ISIL_DST_POINT;



typedef struct
{
DWORD				dwSize;
int					nDSTType;				// ����ʱ��λ��ʽ 0:�����ڶ�λ��ʽ, 1:���ܶ�λ��ʽ
ISIL_DST_POINT        stDSTStart;             // ��ʼ����ʱ
ISIL_DST_POINT        stDSTEnd;				// ��������ʱ
DWORD				dwReserved[16];			// ����
}ISIL_DEV_DST_CFG;


//�Զ�ά������
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// �Զ�������0���Ӳ�, 1��ÿ�죬2��ÿ�����գ�3��ÿ����һ��......
	BYTE				byAutoRebootTime;		// 0��0:00��1��1:00��......23��23:00
	BYTE				byAutoDeleteFilesTime;	// �Զ�ɾ���ļ���0���Ӳ���1��24H��2��48H��3��72H��4��96H��5��ONE WEEK��6��ONE MONTH
	BYTE				reserved[13];			// ����λ
} ISIL_DEV_AUTOMT_CFG;

//-----------------------------ͼ��ͨ������-------------------------------

// ʱ��νṹ
typedef struct
{
	BOOL				bEnable;				// ����ʾ¼��ʱ���ʱ����λ��ʾ����ʹ�ܣ��ӵ�λ����λ�ֱ��ʾ����¼�󡢱���¼����ͨ¼��
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} ISIL_TSECT, *LPISIL_TSECT;

// ���򣻸��߾ఴ����8192�ı���
typedef struct {
   long					left;
   long					top;
   long					right;
   long					bottom;
} ISIL_RECT, *LPISIL_RECT;

// OSD���Խṹ
typedef struct  tagENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// �����ǰ�������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	DWORD				rgbaBackground;			// ����ı��������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	ISIL_RECT				rcRect;					// λ��
	BYTE				bShow;					// ��ʾʹ��
	BYTE				byReserved[3];
} ISIL_ENCODE_WIDGET, *LPISIL_ENCODE_WIDGET;

// ͨ������Ƶ����
typedef struct
{
	// ��Ƶ����
	BYTE				byVideoEnable;			// ��Ƶʹ�ܣ�1���򿪣�0���ر�
	BYTE				byBitRateControl;		// �������ƣ����ճ���"��������"����
	BYTE				byFramesPerSec;			// ֡��
	BYTE				byEncodeMode;			// ����ģʽ�����ճ���"����ģʽ"����
	BYTE				byImageSize;			// �ֱ��ʣ����ճ���"�ֱ���"����
	BYTE				byImageQlty;			// ����1-6
	WORD				wLimitStream;			// ����������
	// ��Ƶ����
	BYTE				byAudioEnable;			// ��Ƶʹ�ܣ�1���򿪣�0���ر�
	BYTE				wFormatTag;				// ��Ƶ��������
	WORD				nChannels;				// ������
	WORD				wBitsPerSample;			// �������
	BYTE				bAudioOverlay;			// ��Ƶ����ʹ��
	BYTE				bReserved_2;
	DWORD				nSamplesPerSec;			// ������
	BYTE				bIFrameInterval;		// I֡���֡��������������I֮֡���P֡������0-149
	BYTE				bScanMode;				// NSP
	BYTE				bReserved_3;
	BYTE				bReserved_4;
} ISIL_VIDEOENC_OPT, *LPISIL_VIDEOENC_OPT;

// ������ɫ����
typedef struct
{
	ISIL_TSECT			stSect;
	BYTE				byBrightness;			// ���ȣ�0-100
	BYTE				byContrast;				// �Աȶȣ�0-100
	BYTE				bySaturation;			// ���Ͷȣ�0-100
	BYTE				byHue;					// ɫ�ȣ�0-100
	BYTE				byGainEn;				// ����ʹ��
	BYTE				byGain;					// ���棻0-100
	BYTE				byReserved[2];
} ISIL_COLOR_CFG, *LPISIL_COLOR_CFG;

// ͼ��ͨ�����Խṹ��
typedef struct
{
	//DWORD				dwSize;
	WORD				dwSize;
	BYTE				bNoise;
	BYTE				bReserved;
	char				szChannelName[ISIL_CHAN_NAME_LEN];
	ISIL_VIDEOENC_OPT		stMainVideoEncOpt[ISIL_REC_TYPE_NUM];
	ISIL_VIDEOENC_OPT		stAssiVideoEncOpt[ISIL_N_ENCODE_AUX];
	ISIL_COLOR_CFG		stColorCfg[ISIL_N_COL_TSECT];
	ISIL_ENCODE_WIDGET	stTimeOSD;
	ISIL_ENCODE_WIDGET	stChannelOSD;
	ISIL_ENCODE_WIDGET	stBlindCover[ISIL_N_COVERS];	// �������ڵ�
	BYTE				byBlindEnable;			// �����ڸǿ��أ�0x00����ʹ���ڸǣ�0x01�����ڸ��豸����Ԥ����0x10�����ڸ�¼������Ԥ����0x11�����ڸ�
	BYTE				byBlindMask;			// �����ڸ����룻��һλ���豸����Ԥ�����ڶ�λ��¼��(������Ԥ��) */
	BYTE				bVolume;				// ������ֵ(0~100�ɵ�)
	BYTE				bVolumeEnable;			// ������ֵʹ��
} ISIL_DEV_CHANNEL_CFG, *LPISIL_DEV_CHANNEL_CFG;

// Ԥ��ͼ�����
typedef struct
{
	DWORD				dwSize;
	ISIL_VIDEOENC_OPT		stPreView;
	ISIL_COLOR_CFG		stColorCfg[ISIL_N_COL_TSECT];
}ISIL_DEV_PREVIEW_CFG;

//-------------------------------��������---------------------------------

// ���ڻ�������
typedef struct
{
	BYTE				byDataBit;				// ����λ��0��5��1��6��2��7��3��8
	BYTE				byStopBit;				// ֹͣλ��0��1λ��1��1.5λ��2��2λ
	BYTE				byParity;				// У��λ��0����У�飬1����У�飻2��żУ��
	BYTE				byBaudRate;				// �����ʣ�0��300��1��600��2��1200��3��2400��4��4800��
												// 5��9600��6��19200��7��38400��8��57600��9��115200
} ISIL_COMM_PROP;

// 485����������
typedef struct
{
	ISIL_COMM_PROP		struComm;
	BYTE				wProtocol;				// Э�����ͣ���Ӧ"Э�����б�"�±�
	BYTE				byReserved;				// ����
	BYTE				wDecoderAddress;		// ��������ַ��0 - 255
	BYTE 				byMartixID;				// �����
} ISIL_485_CFG;

// 232��������
typedef struct
{
	ISIL_COMM_PROP		struComm;
	BYTE				byFunction;				// ���ڹ��ܣ���Ӧ"�������б�"�±�
	BYTE				byReserved[3];
} ISIL_RS232_CFG;

// �������ýṹ��
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;				// ������Э�����
	char				DecProName[ISIL_MAX_DECPRO_LIST_SIZE][ISIL_MAX_NAME_LEN]; // Э�����б�
	ISIL_485_CFG			stDecoder[ISIL_MAX_DECODER_NUM];	// ����������ǰ����

	DWORD				dw232FuncNameNum;		// 232���ܸ���
	char				s232FuncName[ISIL_MAX_232FUNCS][ISIL_MAX_NAME_LEN];	// �������б�
	ISIL_RS232_CFG		st232[ISIL_MAX_232_NUM];	// ��232���ڵ�ǰ����
} ISIL_DEV_COMM_CFG;

// ����״̬
typedef struct
{
	unsigned int		uBeOpened;
	unsigned int		uBaudRate;
	unsigned int		uDataBites;
	unsigned int		uStopBits;
	unsigned int		uParity;
	BYTE				bReserved[32];
}ISIL_COMM_STATE;

//-------------------------------¼������---------------------------------

// ��ʱ¼��
typedef struct
{
	DWORD				dwSize;
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	BYTE				byPreRecordLen;			// Ԥ¼ʱ�䣬��λ��s��0��ʾ��Ԥ¼
	BYTE				byRedundancyEn;			// ¼�����࿪��
	BYTE                byRecordType;           // ¼���������ͣ�0-������ 1-������1 2-������2 3-������3
	BYTE				byReserved;
}ISIL_DEV_RECORD_CFG, *LPISIL_RECORD_CFG;

// NTP����
typedef struct
{
	BOOL				bEnable;				//	�Ƿ�����
	int					nHostPort;				//	NTP������Ĭ�϶˿�Ϊ123
	char				szHostIp[32];			//	����IP
	char				szDomainName[128];		//	����
	int					nType;					//	�������ã�0����ʾIP��1����ʾ������2����ʾIP������
	int					nUpdateInterval;		//	����ʱ��(����)
	int					nTimeZone;				//	��ISIL_TIME_ZONE_TYPE
	char				reserved[128];
}ISIL_DEV_NTP_CFG;

// FTP�ϴ�����
typedef struct
{
	struct
	{
		ISIL_TSECT		struSect;				// ��ʱ����ڵġ�ʹ�ܡ���Ч���ɺ���
		BOOL			bMdEn;					// �ϴ���̬���¼��
		BOOL			bAlarmEn;				// �ϴ��ⲿ����¼��
		BOOL			bTimerEn;				// �ϴ���ͨ��ʱ¼��
		DWORD			dwRev[4];
	} struPeriod[ISIL_TIME_SECTION];
} ISIL_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// �Ƿ�����
	char				szHostIp[ISIL_MAX_IPADDR_LEN];		// ����IP
	WORD				wHostPort;							// �����˿�
	char				szDirName[ISIL_FTP_MAX_PATH];			// FTPĿ¼·��
	char				szUserName[ISIL_FTP_USERNAME_LEN];	// �û���
	char				szPassword[ISIL_FTP_PASSWORD_LEN];	// ����
	int					iFileLen;							// �ļ�����
	int					iInterval;							// �����ļ�ʱ����
	ISIL_FTP_UPLOAD_CFG	struUploadCfg[ISIL_MAX_CHANNUM][ISIL_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB
	char				NASVer;								// ����洢�������汾0=�ϵ�FTP(��������ʾʱ���)��1=NAS�洢(����������ʱ���)
	DWORD				dwFunctionMask;						// �����������룬��λ��ʾ����16λ(����洢)���α�ʾFTP��SMB��NFS����16λ(���ش洢)����ΪDISK��U
	BYTE 				reserved[124];
} ISIL_DEV_FTP_PROTO_CFG;

//-------------------------------��������---------------------------------

// ��̫������
typedef struct
{
	char				sDevIPAddr[ISIL_MAX_IPADDR_LEN];	// DVR IP ��ַ
	char				sDevIPMask[ISIL_MAX_IPADDR_LEN];	// DVR IP ��ַ����
	char				sGatewayIP[ISIL_MAX_IPADDR_LEN];	// ���ص�ַ

	/* 10M/100M  ����Ӧ,����
	 * 1-10MBase - T
	 * 2-10MBase-T ȫ˫��
	 * 3-100MBase - TX
	 * 4-100M ȫ˫��
	 * 5-10M/100M  ����Ӧ
	 */
	// Ϊ����չ��DWORD����ĸ�
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0�����ߣ�1������
	BYTE				bValid;					// ��λ��ʾ����һλ��1����Ч 0����Ч���ڶ�λ��0��DHCP�ر� 1��DHCPʹ�ܣ�����λ��0����֧��DHCP 1��֧��DHCP
	BYTE				bDefaultEth;			// �Ƿ���ΪĬ�ϵ����� 1��Ĭ�� 0����Ĭ��
	char				byMACAddr[ISIL_MACADDR_LEN];	// MAC��ַ��ֻ��
} ISIL_ETHERNET;

// Զ����������
typedef struct
{
	BYTE				byEnable;				// ����ʹ��
	BYTE				byAssistant;            // Ŀǰֻ����PPPoE���������ã�0���������������ţ�1�������������ϲ���
	WORD				wHostPort;				// Զ������ �˿�
	char				sHostIPAddr[ISIL_MAX_IPADDR_LEN];		// Զ������ IP ��ַ
	char				sHostUser[ISIL_MAX_HOST_NAMELEN];		// Զ������ �û���
	char				sHostPassword[ISIL_MAX_HOST_PSWLEN];	// Զ������ ����
} ISIL_REMOTE_HOST;

// �ʼ�����
typedef struct
{
	char				sMailIPAddr[ISIL_MAX_IPADDR_LEN];	// �ʼ�������IP��ַ
	WORD				wMailPort;				// �ʼ��������˿�
	WORD				wReserved;				// ����
	char				sSenderAddr[ISIL_MAX_MAIL_ADDR_LEN];	// ���͵�ַ
	char				sUserName[ISIL_MAX_NAME_LEN];			// �û���
	char				sUserPsw[ISIL_MAX_NAME_LEN];			// �û�����
	char				sDestAddr[ISIL_MAX_MAIL_ADDR_LEN];	// Ŀ�ĵ�ַ
	char				sCcAddr[ISIL_MAX_MAIL_ADDR_LEN];		// ���͵�ַ
	char				sBccAddr[ISIL_MAX_MAIL_ADDR_LEN];		// ������ַ
	char				sSubject[ISIL_MAX_MAIL_SUBJECT_LEN];	// ����
} ISIL_MAIL_CFG;

// �������ýṹ��
typedef struct
{
	DWORD				dwSize;

	char				sDevName[ISIL_MAX_NAME_LEN];	// �豸������

	WORD				wTcpMaxConnectNum;		// TCP���������
	WORD				wTcpPort;				// TCP֡���˿�
	WORD				wUdpPort;				// UDP�����˿�
	WORD				wHttpPort;				// HTTP�˿ں�
	WORD				wHttpsPort;				// HTTPS�˿ں�
	WORD				wSslPort;				// SSL�˿ں�
	ISIL_ETHERNET			stEtherNet[ISIL_MAX_ETHERNET_NUM];	// ��̫����

	ISIL_REMOTE_HOST		struAlarmHost;			// ����������
	ISIL_REMOTE_HOST		struLogHost;			// ��־������
	ISIL_REMOTE_HOST		struSmtpHost;			// SMTP������
	ISIL_REMOTE_HOST		struMultiCast;			// �ಥ��
	ISIL_REMOTE_HOST		struNfs;				// NFS������
	ISIL_REMOTE_HOST		struPppoe;				// PPPoE������
	char				sPppoeIP[ISIL_MAX_IPADDR_LEN]; // PPPoEע�᷵�ص�IP
	ISIL_REMOTE_HOST		struDdns;				// DDNS������
	char				sDdnsHostName[ISIL_MAX_HOST_NAMELEN];	// DDNS������
	ISIL_REMOTE_HOST		struDns;				// DNS������
	ISIL_MAIL_CFG			struMail;				// �ʼ�����
} ISIL_DEV_NET_CFG;

// ��ddns���ýṹ��
typedef struct
{
	DWORD				dwId;					// ddns������id��
	BOOL				bEnable;				// ʹ�ܣ�ͬһʱ��ֻ����һ��ddns����������ʹ��״̬
	char				szServerType[ISIL_MAX_SERVER_TYPE_LEN];	// ���������ͣ�ϣ��..
	char				szServerIp[ISIL_MAX_DOMAIN_NAME_LEN];		// ������ip��������
	DWORD				dwServerPort;			// �������˿�
	char				szDomainName[ISIL_MAX_DOMAIN_NAME_LEN];	// dvr��������jeckean.3322.org
	char				szUserName[ISIL_MAX_HOST_NAMELEN];		// �û���
	char				szUserPsw[ISIL_MAX_HOST_PSWLEN];			// ����
	char				szAlias[ISIL_MAX_DDNS_ALIAS_LEN];			// ��������������"dahua inter ddns"
	DWORD				dwAlivePeriod;							// DDNS ����ʱ��
	char				reserved[256];
} ISIL_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;
	ISIL_DDNS_SERVER_CFG	struDdnsServer[ISIL_MAX_DDNS_NUM];
} ISIL_DEV_MULTI_DDNS_CFG;

// �ʼ����ýṹ��
typedef struct
{
	char				sMailIPAddr[ISIL_MAX_DOMAIN_NAME_LEN];	// �ʼ���������ַ(IP��������)
	char				sSubMailIPAddr[ISIL_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// �ʼ��������˿�
	WORD				wSubMailPort;
	WORD				wReserved;								// ����
	char				sSenderAddr[ISIL_MAX_MAIL_ADDR_LEN];		// ���͵�ַ
	char				sUserName[ISIL_MAX_MAIL_NAME_LEN];		// �û���
	char				sUserPsw[ISIL_MAX_MAIL_NAME_LEN];			// �û�����
	char				sDestAddr[ISIL_MAX_MAIL_ADDR_LEN];		// Ŀ�ĵ�ַ
	char				sCcAddr[ISIL_MAX_MAIL_ADDR_LEN];			// ���͵�ַ
	char				sBccAddr[ISIL_MAX_MAIL_ADDR_LEN];			// ������ַ
	char				sSubject[ISIL_MAX_MAIL_SUBJECT_LEN];		// ����
	BYTE				bEnable;								// ʹ��0:false,	1:true
	BYTE				bSSLEnable;								// SSLʹ��
	WORD				wSendInterval;							// ����ʱ����,[0,3600]��
	char				reserved[156];
} ISIL_DEV_MAIL_CFG;

// DNS����������
typedef struct
{
	char				szPrimaryIp[ISIL_MAX_IPADDR_LEN];
	char				szSecondaryIp[ISIL_MAX_IPADDR_LEN];
	char				reserved[256];
} ISIL_DEV_DNS_CFG;

// ¼�����ز�������
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE���������أ�FALSE����ͨ����
}ISIL_DEV_DOWNLOAD_STRATEGY_CFG;

// ���紫���������
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0���������ȣ�1�����������ȣ�2���Զ�
}ISIL_DEV_TRANSFER_STRATEGY_CFG;

// ���õ���ʱ����ز���
typedef struct
{
	int					nWaittime;				// �ȴ���ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��5000ms
	int					nConnectTime;			// ���ӳ�ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��1500ms
	int					nConnectTryNum;			// ���ӳ��Դ�����Ϊ0Ĭ��1��
	int					nSubConnectSpaceTime;	// ������֮��ĵȴ�ʱ��(����Ϊ��λ)��Ϊ0Ĭ��10ms
	int					nGetDevInfoTime;		// ��ȡ�豸��Ϣ��ʱʱ�䣬Ϊ0Ĭ��1000ms
	int					nConnectBufSize;		// ÿ�����ӽ������ݻ����С(�ֽ�Ϊ��λ)��Ϊ0Ĭ��250*1024
	int					nGetConnInfoTime;		// ��ȡ��������Ϣ��ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��1000ms
	BYTE				bReserved[20];			// �����ֶ�
} NET_PARAM;

// ��ӦISIL_CLIENT_SearchDevices�ӿ�
typedef struct
{
	char				szIP[ISIL_MAX_IPADDR_LEN];		// IP
	int					nPort;							// �˿�
	char				szSubmask[ISIL_MAX_IPADDR_LEN];	// ��������
	char				szGateway[ISIL_MAX_IPADDR_LEN];	// ����
	char				szMac[ISIL_MACADDR_LEN];			// MAC��ַ
	char				szDeviceType[ISIL_DEV_TYPE_LEN];	// �豸����
	BYTE				bReserved[32];					// �����ֽ�
} DEVICE_NET_INFO;

//-------------------------------��������---------------------------------

// ��̨����
typedef struct
{
	int					iType;
	int					iValue;
} ISIL_PTZ_LINK, *LPISIL_PTZ_LINK;

// ���������ṹ��
typedef struct
{
	/* ��Ϣ����ʽ������ͬʱ���ִ���ʽ������
	 * 0x00000001 - �����ϴ�
	 * 0x00000002 - ����¼��
	 * 0x00000004 - ��̨����
	 * 0x00000008 - �����ʼ�
	 * 0x00000010 - ������Ѳ
	 * 0x00000020 - ������ʾ
	 * 0x00000040 - �������
	 * 0x00000080 - Ftp�ϴ�
	 * 0x00000100 - ����
	 * 0x00000200 - ������ʾ
	 * 0x00000400 - ץͼ
	*/

	/* ��ǰ������֧�ֵĴ���ʽ����λ�����ʾ */
	DWORD				dwActionMask;

	/* ������������λ�����ʾ�����嶯������Ҫ�Ĳ����ڸ��Ե����������� */
	DWORD				dwActionFlag;

	/* �������������ͨ�������������������Ϊ1��ʾ��������� */
	BYTE				byRelAlarmOut[ISIL_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/* ��������ʱ�� */

	/* ����¼�� */
	BYTE				byRecordChannel[ISIL_MAX_VIDEO_IN_NUM]; /* ����������¼��ͨ����Ϊ1��ʾ������ͨ�� */
	DWORD				dwRecLatch;				/* ¼�����ʱ�� */

	/* ץͼͨ�� */
	BYTE				bySnap[ISIL_MAX_VIDEO_IN_NUM];
	/* ��Ѳͨ�� */
	BYTE				byTour[ISIL_MAX_VIDEO_IN_NUM];

	/* ��̨���� */
	ISIL_PTZ_LINK			struPtzLink[ISIL_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* ������ʼ��ʱʱ�䣬sΪ��λ����Χ��0~15��Ĭ��ֵ��0 */
	/* �����������������ͨ�������������������Ϊ1��ʾ��������� */
	BYTE				byRelWIAlarmOut[ISIL_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*���ű���ʹ��*/
	BYTE                bySnapshotTimes;       /*���ŷ���ץͼ���� */
	BYTE				bMatrixEn;				/*!< ����ʹ�� */
	DWORD				dwMatrix;				/*!< �������� */
	BYTE				bLog;					/*!< ��־ʹ�ܣ�Ŀǰֻ����WTN��̬�����ʹ�� */
	BYTE				byReserved[103];
} ISIL_MSG_HANDLE;

// �ⲿ����
typedef struct
{
	BYTE				byAlarmType;			// ���������ͣ�0�����գ�1������
	BYTE				byAlarmEn;				// ����ʹ��
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struHandle;				// ����ʽ
} ISIL_ALARMIN_CFG, *LPISIL_DEV_ALARMIN_CFG;

// ��̬��ⱨ��
typedef struct
{
	BYTE				byMotionEn;				// ��̬��ⱨ��ʹ��
	BYTE				byReserved;
	WORD				wSenseLevel;			// ������
	WORD				wMotionRow;				// ��̬������������
	WORD				wMotionCol;				// ��̬������������
	BYTE				byDetected[ISIL_MOTION_ROW][ISIL_MOTION_COL]; // ����������32*32������
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				//����ʽ
} ISIL_MOTION_DETECT_CFG;

// ��Ƶ��ʧ����
typedef struct
{
	BYTE				byAlarmEn;				// ��Ƶ��ʧ����ʹ��
	BYTE				byReserved[3];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				// ����ʽ
} ISIL_VIDEO_LOST_CFG;

// ͼ���ڵ�����
typedef struct
{
	BYTE				byBlindEnable;			// ʹ��
	BYTE				byBlindLevel;			// ������1-6
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				// ����ʽ
} ISIL_BLIND_CFG;

// Ӳ����Ϣ(�ڲ�����)
typedef struct
{
	BYTE				byNoDiskEn;				// ��Ӳ��ʱ����
	BYTE				byReserved_1[3];
	ISIL_TSECT			stNDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struNDHandle;			// ����ʽ

	BYTE				byLowCapEn;				// Ӳ�̵�����ʱ����
	BYTE				byLowerLimit;			// ������ֵ��0-99
	BYTE				byReserved_2[2];
	ISIL_TSECT			stLCSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struLCHandle;			// ����ʽ

	BYTE				byDiskErrEn;			// Ӳ�̹��ϱ���
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ISIL_TSECT			stEDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struEDHandle;			// ����ʽ
} ISIL_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ISIL_MSG_HANDLE		struHandle;
} ISIL_NETBROKEN_ALARM_CFG;

// ��������
typedef struct
{
	DWORD dwSize;
	ISIL_ALARMIN_CFG 		struLocalAlmIn[ISIL_MAX_ALARM_IN_NUM];
	ISIL_ALARMIN_CFG		struNetAlmIn[ISIL_MAX_ALARM_IN_NUM];
	ISIL_MOTION_DETECT_CFG struMotion[ISIL_MAX_VIDEO_IN_NUM];
	ISIL_VIDEO_LOST_CFG	struVideoLost[ISIL_MAX_VIDEO_IN_NUM];
	ISIL_BLIND_CFG		struBlind[ISIL_MAX_VIDEO_IN_NUM];
	ISIL_DISK_ALARM_CFG	struDiskAlarm;
	ISIL_NETBROKEN_ALARM_CFG	struNetBrokenAlarm;
} ISIL_DEV_ALARM_SCHEDULE;

#define DECODER_OUT_SLOTS_MAX_NUM 		16
#define DECODER_IN_SLOTS_MAX_NUM 		16

// ��������������
typedef struct
{
	DWORD				dwAddr;									// ������������ַ
	BOOL				bEnable;								// ����������ʹ��
	DWORD				dwOutSlots[DECODER_OUT_SLOTS_MAX_NUM];	// ����ֻ֧��8��.
	int					nOutSlotNum;							// dwOutSlots������ЧԪ�ظ���.
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle[DECODER_IN_SLOTS_MAX_NUM];	// ����ֻ֧��8��.
	int					nMsgHandleNum;							// stuHandle������ЧԪ�ظ���.
	BYTE				bReserved[120];
} ISIL_ALARMDEC_CFG;

// �����ϴ�������
typedef struct
{
	BYTE				byEnable;				// �ϴ�ʹ��
	BYTE				bReserverd;				//  ����
	WORD				wHostPort;				// �������������˿�
	char				sHostIPAddr[ISIL_MAX_IPADDR_LEN];		// ��������IP

	int					nByTimeEn;				// ��ʱ�ϴ�ʹ�ܣ����������������ϴ�IP��������
	int					nUploadDay;				/* �����ϴ�����
													"Never = 0", "Everyday = 1", "Sunday = 2",
													"Monday = 3", Tuesday = 4", "Wednesday = 5",
													"Thursday = 6", "Friday = 7", "Saturday = 8"*/
	int					nUploadHour;			// �����ϴ�ʱ�� ,[0~23]��

	DWORD				dwReserved[300]; 		// ��������չ��
} ALARMCENTER_UP_CFG;

// ȫ���л���������
typedef struct __ISIL_PANORAMA_SWITCH_CFG
{
	BOOL				bEnable;				// ʹ��
	int					nReserved[5];			// ����
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// ��������
} ISIL_PANORAMA_SWITCH_CFG;

typedef struct __ALARM_PANORAMA_SWITCH_CFG
{
	int					nAlarmChnNum;			// ����ͨ������
	ISIL_PANORAMA_SWITCH_CFG stuPanoramaSwitch[ISIL_MAX_VIDEO_IN_NUM];
} ALARM_PANORAMA_SWITCH_CFG;

// ʧȥ���㱨������
typedef struct __ISIL_LOST_FOCUS_CFG
{
	BOOL				bEnable;				// ʹ��
	int					nReserved[5];			// ����
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// ��������
} ISIL_LOST_FOCUS_CFG;

typedef struct __ALARM_LOST_FOCUS_CFG
{
	int					nAlarmChnNum;			// ����ͨ������
	ISIL_LOST_FOCUS_CFG stuLostFocus[ISIL_MAX_VIDEO_IN_NUM];
} ALARM_LOST_FOCUS_CFG;

// IP��ͻ��ⱨ������
typedef struct __ALARM_IP_COLLISION_CFG
{
	BOOL				bEnable;				// ʹ��
	ISIL_MSG_HANDLE		struHandle;				// ��������
	int                 nReserved[300];			// ����
}ALARM_IP_COLLISION_CFG;

//------------------------------�������ڵ�--------------------------------

// �ڵ���Ϣ
typedef struct __VIDEO_COVER_ATTR
{
	ISIL_RECT				rcBlock;				// ���ǵ���������
	int					nColor;					// ���ǵ���ɫ
	BYTE				bBlockType;				// ���Ƿ�ʽ��0���ڿ飬1��������
	BYTE				bEncode;				// ���뼶�ڵ���1����Ч��0������Ч
	BYTE				bPriview;				// Ԥ���ڵ��� 1����Ч��0������Ч
	char				reserved[29];			// ����
} VIDEO_COVER_ATTR;

// �������ڵ�����
typedef struct __ISIL_DEV_VIDEOCOVER_CFG
{
	DWORD				dwSize;
	char				szChannelName[ISIL_CHAN_NAME_LEN]; // ֻ��
	BYTE				bTotalBlocks;			// ֧�ֵ��ڵ�����
	BYTE				bCoverCount;			// �����õ��ڵ�����
	VIDEO_COVER_ATTR	CoverBlock[ISIL_MAX_VIDEO_COVER_NUM]; // ���ǵ�����
	char				reserved[30];			// ����
}ISIL_DEV_VIDEOCOVER_CFG;

////////////////////////////////IPC��Ʒ֧��////////////////////////////////

// ��������������Ϣ
typedef struct
{
	int					nEnable;				// ����ʹ��
	char				szSSID[36];				// SSID
	int					nLinkMode;				// ����ģʽ��0��auto��1��adhoc��2��Infrastructure
	int					nEncryption;			// ���ܣ�0��off��2��WEP64bit��3��WEP128bit
	int					nKeyType;				// 0��Hex��1��ASCII
    int					nKeyID;					// ���
	char				szKeys[4][32];			// ��������
	int					nKeyFlag;
	char				reserved[12];
} ISIL_DEV_WLAN_INFO;

// ѡ��ʹ��ĳ�������豸
typedef struct
{
	char				szSSID[36];
	int					nLinkMode;				// ����ģʽ��0��adhoc��1��Infrastructure
	int 				nEncryption;			// ���ܣ�0��off��2��WEP64bit��3��WEP128bit
	char				reserved[48];
} ISIL_DEV_WLAN_DEVICE;

// �������������豸�б�
typedef struct
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// �������������豸����
	ISIL_DEV_WLAN_DEVICE	lstWlanDev[ISIL_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} ISIL_DEV_WLAN_DEVICE_LIST;

// ����ע���������
typedef struct
{
	char				szServerIp[32];			// ע�������IP
	int					nServerPort;			// �˿ں�
	char				reserved[64];
} ISIL_DEV_SERVER_INFO;

typedef struct
{
	DWORD				dwSize;
	BYTE				bServerNum;				// ֧�ֵ����ip��
	ISIL_DEV_SERVER_INFO	lstServer[ISIL_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// ʹ��
	char				szDeviceID[32];			// �豸id
	char				reserved[94];
} ISIL_DEV_REGISTER_SERVER;

// ����ͷ����
typedef struct __ISIL_DEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// ���ȿɵ���1���ɣ�0������
	BYTE				bContrastEn;			// �Աȶȿɵ�
	BYTE				bColorEn;				// ɫ�ȿɵ�
	BYTE				bGainEn;				// ����ɵ�
	BYTE				bSaturationEn;			// ���Ͷȿɵ�
	BYTE				bBacklightEn;			// ���ⲹ�� 0��ʾ��֧�ֱ��ⲹ��,1��ʾ֧��һ����������,�أ���2��ʾ֧��������������,��,�ͣ���3��ʾ֧��������������,��,��,�ͣ�
	BYTE				bExposureEn;			// �ع�ѡ�� 0��ʾ��֧���ع���ƣ�1��ʾֻ֧���Զ��ع⣬������ʾ֧�ֵ��ع��ٶȵȼ��������ֶ����Ƶĵȼ���+1
	BYTE				bColorConvEn;			// �Զ��ʺ�ת���ɵ�
	BYTE				bAttrEn;				// ����ѡ�1���ɣ�0������
	BYTE				bMirrorEn;				// ����1��֧�֣�0����֧��
    BYTE				bFlipEn;				// ��ת��1��֧�֣�0����֧��
	BYTE				iWhiteBalance;			// ��ƽ�� 2 ֧���龰ģʽ�� 1 ֧�ְ�ƽ�� ��0 ��֧��
	BYTE				iSignalFormatMask;		// �źŸ�ʽ���룬��λ�ӵ͵���λ�ֱ�Ϊ��0-Inside(�ڲ�����) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRev[123];				// ����
} ISIL_DEV_CAMERA_INFO;

// ����ͷ��������
typedef struct __ISIL_DEV_CAMERA_CFG
{
	DWORD				dwSize;
	BYTE				bExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-����ع�ȼ���
	BYTE				bBacklight;				// ���ⲹ�������ⲹ���ȼ�ȡֵ��Χȡ�����豸��������0-�رգ�1-���ⲹ��ǿ��1��2-���ⲹ��ǿ��2��n-��󱳹ⲹ���ȼ���
	BYTE				bAutoColor2BW;			// ��/ҹģʽ��2����(�ڰ�)��1���Զ���0����(��ɫ)
	BYTE				bMirror;				// ����1������0����
	BYTE				bFlip;					// ��ת��1������0����
	BYTE				bLensEn;				// �Զ���Ȧ��������: 1��֧�֣�0 ����֧��
	BYTE				bLensFunction;			// �Զ���Ȧ����: 1:�����Զ���Ȧ��0: �ر��Զ���Ȧ
	BYTE				bWhiteBalance;			// ��ƽ�� 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night
	BYTE				bSignalFormat;			// �źŸ�ʽ0-Inside(�ڲ�����) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	char				bRev[119];				// ����
} ISIL_DEV_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (����)���ⱨ������
typedef struct
{
	BOOL				bEnable;				// ��������ʹ��
	char				szAlarmName[ISIL_MAX_ALARM_NAME];	// ������������
	int					nAlarmInPattern;		// ���������벨��
	int					nAlarmOutPattern;		// �����������
	char				szAlarmInAddress[ISIL_MAX_ALARM_NAME];// ���������ַ
	int					nSensorType;			// �ⲿ�豸���������ͳ��� or ����
	int					nDefendEfectTime;		// ��������ʱʱ�䣬�ڴ�ʱ���ñ���������Ч
	int					nDefendAreaType;		// ��������
	int					nAlarmSmoothTime;		// ����ƽ��ʱ�䣬���ڴ�ʱ�������ֻ��һ��������������������������Ե�����һ��
	char				reserved[128];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// ����ʽ
} ISIL_INFRARED_INFO;

// ����ң��������
typedef struct
{
	BYTE				address[ALARM_MAX_NAME];// ң������ַ
	BYTE				name[ALARM_MAX_NAME];	// ң��������
	BYTE				reserved[32];			// �����ֶ�
} ISIL_WI_CONFIG_ROBOT;

// ���߱����������
typedef struct
{
	BYTE				address[ALARM_MAX_NAME];// ���������ַ
	BYTE				name[ALARM_MAX_NAME];	// �����������
	BYTE				reserved[32];			// �����ֶ�
} ISIL_WI_CONFIG_ALARM_OUT;

typedef struct
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// ���߱���������
	BYTE				bAlarmOutNum;			// ���߱��������
	ISIL_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// ���������ַ
	BYTE				bRobotNum;				// ң��������
	ISIL_WI_CONFIG_ROBOT RobotAddr[16];			// ң������ַ
	ISIL_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} ISIL_INFRARED_CFG;

// ����Ƶ��ⱨ����Ϣ
typedef struct
{
	int					channel;				// ����ͨ����
	int					alarmType;				// �������ͣ�0����Ƶֵ���ͣ�1����Ƶֵ����
	unsigned int		volume;					// ����ֵ
	char				reserved[256];
} NET_NEW_SOUND_ALARM_STATE;

typedef struct
{
	int					channelcount;			// ������ͨ������
	NET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[ISIL_MAX_ALARM_IN_NUM];
} ISIL_NEW_SOUND_ALARM_STATE;

// ץͼ�������Խṹ��
typedef struct
{
	int					nChannelNum;			// ͨ����
	DWORD				dwVideoStandardMask;	// �ֱ���(��λ)������鿴ö��CAPTURE_SIZE
	int					nFramesCount;			// Frequence[128]�������Ч����
	char				Frames[128];			// ֡��(����ֵ)
												// -25��25��1֡��-24��24��1֡��-23��23��1֡��-22��22��1֡
												// ����
												// 0����Ч��1��1��1֡��2��1��2֡��3��1��3֡
												// 4��1��4֡��5��1��5֡��17��1��17֡��18��1��18֡
												// 19��1��19֡��20��1��20֡
												// ����
												// 25: 1��25֡
	int					nSnapModeCount;			// SnapMode[16]�������Ч����
	char				SnapMode[16];			// (����ֵ)0����ʱ����ץͼ��1���ֶ�����ץͼ
	int					nPicFormatCount;		// Format[16]�������Ч����
	char 				PictureFormat[16];		// (����ֵ)0��BMP��ʽ��1��JPG��ʽ
	int					nPicQualityCount;		// Quality[32]�������Ч����
	char 				PictureQuality[32];		// ����ֵ
												// 100��ͼ������100%��80:ͼ������80%��60:ͼ������60%
												// 50:ͼ������50%��30:ͼ������30%��10:ͼ������10%
	char 				nReserved[128];			// ����
} ISIL_QUERY_SNAP_INFO;

typedef struct
{
	int					nChannelCount;			// ͨ������
	ISIL_QUERY_SNAP_INFO  stuSnap[ISIL_MAX_CHANNUM];
} ISIL_SNAP_ATTR_EN;


/* IP���˹������� */
#define ISIL_IPIFILTER_NUM			200			// IP

// IP��Ϣ
typedef struct
{
	DWORD				dwIPNum;				// IP����
	char				SZIP[ISIL_IPIFILTER_NUM][ISIL_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// ����
} IPIFILTER_INFO;

// IP�������ýṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwType;					// ��ǰ�������ͣ�0�������� 1�����������豸ֻ��ʹһ��������Ч�������ǰ����������Ǻ�������
	IPIFILTER_INFO		BannedIP;				// ������
	IPIFILTER_INFO		TrustIP;				// ������
	char				byReserve[256];			// ����
} ISIL_DEV_IPIFILTER_CFG;

/*�����Խ���������*/
typedef struct
{
	DWORD				dwSize;
	int					nCompression;			// ѹ����ʽ��ö��ֵ�����ISIL_TALK_CODING_TYPE��������豸֧�ֵ������Խ���������ѹ����ʽ��
	int					nMode;					// ����ģʽ��ö��ֵ��Ϊ0ʱ��ʾ��ѹ����ʽ��֧�ֱ���ģʽ��
												// ����ѹ����ʽ�������ö�Ӧ�ı����ʽ����
												// AMR���EM_ARM_ENCODE_MODE
	char				byReserve[256];			// ����
} ISIL_DEV_TALK_ENCODE_CFG;

// ������mobile�������
// (�¼�������ý�����/���ŷ���)MMS���ýṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwReceiverNum;			// ���Ž����߸���
	char				SZReceiver[ISIL_MMS_RECEIVER_NUM][32];	// ���Ž����ߣ�һ��Ϊ�ֻ�����
    BYTE                byType;					// ������Ϣ���� 0:MMS��1:SMS
	char                SZTitle[32];			// ������Ϣ����
	char				byReserve[223];			// ����
} ISIL_DEV_MMS_CFG;

// (���ż���������������)
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwSenderNum;			// ���ŷ����߸���
	char				SZSender[ISIL_MMS_SMSACTIVATION_NUM][32];	// ���ŷ����ߣ�һ��Ϊ�ֻ�����
 	char				byReserve[256];			// ����
}ISIL_DEV_SMSACTIVATION_CFG;

// (���ż���������������)
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwCallerNum;			// �����߸���
	char				SZCaller[ISIL_MMS_DIALINACTIVATION_NUM][32];	// ������, һ��Ϊ�ֻ�����
 	char				byReserve[256];			// ����
}ISIL_DEV_DIALINACTIVATION_CFG;
// ������mobile�������


// ���������ź�ǿ�Ƚṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwTDSCDMA;				// TD-SCDMAǿ�ȣ���Χ��0��100
	DWORD				dwWCDMA;				// WCDMAǿ�ȣ���Χ��0��100
	DWORD				dwCDMA1x;				// CDMA1xǿ�ȣ���Χ��0��100
	DWORD				dwEDGE;					// EDGEǿ�ȣ���Χ��0��100
	DWORD				dwEVDO;					// EVDOǿ�ȣ���Χ��0��100
	int					nCurrentType;			// ��ǰ����
												// 0	�豸��֧����һ��
												// 1    TD_SCDMA
												// 2	WCDMA
												// 3	CDMA_1x
												// 4	EDGE
												// 5	EVDO
	char				byReserve[252];			// ����
} ISIL_DEV_WIRELESS_RSS_INFO;

/***************************** ��̨Ԥ�Ƶ����� ***********************************/
typedef struct _POINTEANBLE
{
	BYTE				bPoint;	//Ԥ�Ƶ����Ч��Χ������[1,80]����Ч����Ϊ0��
	BYTE				bEnable;	//�Ƿ���Ч,0��Ч��1��Ч
	BYTE				bReserved[2];
} POINTEANBLE;

typedef struct _POINTCFG
{
	char				szIP[ISIL_MAX_IPADDR_LEN];// ip
	int					nPort;					// �˿�
	POINTEANBLE			stuPointEnable[80];		// Ԥ�Ƶ�ʹ��
	BYTE				bReserved[256];
}POINTCFG;

typedef struct _ISIL_DEV_POINT_CFG
{
	int					nSupportNum;			// ֻ�����������õ�ʱ����Ҫ���ظ�sdk����ʾ֧�ֵ�Ԥ�Ƶ���
	POINTCFG			stuPointCfg[16];	// ��ά�±��ʾͨ���š�Ҫ���õĵ���ֵ����ǰnSupportNum���±����档
	BYTE				bReserved[256];			// ����
}ISIL_DEV_POINT_CFG;
////////////////////////////////����DVR֧��////////////////////////////////

// GPS��Ϣ(�����豸)
typedef struct _GPS_Info
{
    NET_TIME			revTime;				// ��λʱ��
	char				DvrSerial[50];			// �豸���к�
    double				longitude;				// ����
    double				latidude;				// γ��
    double				height;					// �߶�(��)
    double				angle;					// �����(��������Ϊԭ�㣬˳ʱ��Ϊ��)
    double				speed;					// �ٶ�(����/Сʱ)
    WORD				starCount;				// ��λ����
    BOOL				antennaState;			// ����״̬(true �ã�false ��)
    BOOL				orientationState;		// ��λ״̬(true ��λ��false ����λ)
} GPS_Info,*LPGPS_Info;

// ץͼ�����ṹ��
typedef struct _snap_param
{
	unsigned int		Channel;				// ץͼ��ͨ��
	unsigned int		Quality;				// ���ʣ�1~6
	unsigned int		ImageSize;				// �����С��0��QCIF��1��CIF��2��D1
	unsigned int		mode;					// ץͼģʽ��0����ʾ����һ֡��1����ʾ��ʱ��������2����ʾ��������
	unsigned int		InterSnap;				// ʱ�䵥λ�룻��mode=1��ʾ��ʱ��������ʱ����ʱ����Ч
	unsigned int		CmdSerial;				// �������к�
	unsigned int		Reserved[4];
} SNAP_PARAMS, *LPSNAP_PARAMS;

// ץͼ��������
typedef struct
{
	DWORD				dwSize;
	BYTE				bTimingEnable;				// ��ʱץͼ����(����ץͼ�����ڸ�������������������)
	BYTE                bReserved;
	short	            PicTimeInterval;			// ��ʱץͼʱ��������λΪ��,Ŀǰ�豸֧������ץͼʱ����Ϊ30����
	ISIL_VIDEOENC_OPT		struSnapEnc[SNAP_TYP_NUM]; // ץͼ�������ã���֧�����еķֱ��ʡ����ʡ�֡�����ã�֡���������Ǹ�������ʾһ��ץͼ�Ĵ�����
} ISIL_DEV_SNAP_CFG;

//////////////////////////////////ATM֧��//////////////////////////////////

typedef struct
{
	int					Offset;					// ��־λ��λƫ��
	int					Length;					// ��־λ�ĳ���
	char				Key[16];				// ��־λ��ֵ
} ISIL_SNIFFER_FRAMEID;

typedef struct
{
	int					Offset;					// ��־λ��λƫ��
	int					Offset2;				// Ŀǰû��Ӧ��
	int					Length;					// ��־λ�ĳ���
	int					Length2;				// Ŀǰû��Ӧ��
	char				KeyTitle[24];			// �����ֵ
} ISIL_SNIFFER_CONTENT;

// ����ץ������
typedef struct
{
	ISIL_SNIFFER_FRAMEID	snifferFrameId;			// ÿ��FRAME ID ѡ��
	ISIL_SNIFFER_CONTENT	snifferContent[ISIL_SNIFFER_CONTENT_NUM];	// ÿ��FRAME��Ӧ��4��ץ������
} ISIL_SNIFFER_FRAME;

// ÿ��ץ����Ӧ�����ýṹ
typedef struct
{
	char				SnifferSrcIP[ISIL_MAX_IPADDR_LEN];	// ץ��Դ��ַ
	int					SnifferSrcPort;			// ץ��Դ�˿�
	char				SnifferDestIP[ISIL_MAX_IPADDR_LEN];	// ץ��Ŀ���ַ
	int					SnifferDestPort;		// ץ��Ŀ��˿�
	char				reserved[28];			// �����ֶ�
	ISIL_SNIFFER_FRAME	snifferFrame[ISIL_SNIFFER_FRAMEID_NUM];	// 6��FRAME ѡ��
	int					displayPosition;		// ��ʾλ��
	int					recdChannelMask;		// ͨ������
} ISIL_ATM_SNIFFER_CFG;

typedef struct
{
	DWORD				dwSize;
	ISIL_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];			// �����ֶ�
} ISIL_DEV_SNIFFER_CFG;

typedef ISIL_SNIFFER_FRAMEID ISIL_SNIFFER_FRAMEID_EX;
typedef ISIL_SNIFFER_CONTENT ISIL_SNIFFER_CONTENT_EX;

// ����ץ������
typedef struct
{
	ISIL_SNIFFER_FRAMEID	snifferFrameId;								// ÿ��FRAME ID ѡ��
	ISIL_SNIFFER_CONTENT	snifferContent[ISIL_SNIFFER_CONTENT_NUM_EX];	// ÿ��FRAME��Ӧ��8��ץ������
} ISIL_SNIFFER_FRAME_EX;

// ÿ��ץ����Ӧ�����ýṹ
typedef struct
{
	char				SnifferSrcIP[ISIL_MAX_IPADDR_LEN];					// ץ��Դ��ַ
	int					SnifferSrcPort;										// ץ��Դ�˿�
	char				SnifferDestIP[ISIL_MAX_IPADDR_LEN];					// ץ��Ŀ���ַ
	int					SnifferDestPort;									// ץ��Ŀ��˿�
	ISIL_SNIFFER_FRAME_EX	snifferFrame[ISIL_SNIFFER_FRAMEID_NUM];				// 6��FRAME ѡ��
	int					displayPosition;									// ��ʾλ��
	int					recdChannelMask;									// ͨ������
	BOOL				bDateScopeEnable;									// ������Դʹ��
	BOOL				bProtocolEnable;									// Э��ʹ��
	char				szProtocolName[ISIL_SNIFFER_PROTOCOL_SIZE];			// Э������
	int					nSnifferMode;										// ץ����ʽ��0:net,1:232.
	char				reserved[256];
} ISIL_ATM_SNIFFER_CFG_EX;

/////////////////////////////////������֧��/////////////////////////////////

// ��������Ϣ
typedef struct __DEV_DECODER_INFO
{
	char			szDecType[64];			// ����
	int				nMonitorNum;			// TV����
	int				nEncoderNum;			// ����ͨ������
	BYTE			szSplitMode[16];		// ֧�ֵ�TV����ָ�������������ʽ��ʾ��0Ϊ��β
	BYTE            bMonitorEnable[16];		// ��TVʹ��
	char			reserved[64];
} DEV_DECODER_INFO, *LPDEV_DECODER_INFO;

// ���ӵı�������Ϣ
typedef struct __DEV_ENCODER_INFO
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// ����
	int				nDevChannel;						// ͨ����
	int				nStreamType;						// �������ͣ�0����������1��������
	BYTE			byConnType;							// 0��TCP��1��UDP��2���鲥
	BYTE			byWorkMode;							// 0��ֱ����1��ת��
	WORD			wListenPort;						// ָʾ��������Ķ˿ڣ�ת��ʱ��Ч
	DWORD			dwProtoType;						// Э������,
														// 0:������ǰ
	char			szDevName[64];						// ǰ���豸����
	char			reserved[116];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

// TV������Ϣ
typedef struct __DEV_DECODER_TV
{
	int				nID;								// TV��
	BOOL			bEnable;							// ʹ�ܣ�������ر�
	int				nSplitType;							// ����ָ���
	DEV_ENCODER_INFO stuDevInfo[16];					// �������������Ϣ
	char			reserved[16];
} DEV_DECODER_TV, *LPDEV_DECODER_TV;

// ���������������Ϣ
typedef struct __DEC_COMBIN_INFO
{
	int				nCombinID;							// ���ID
	int             nSplitType;							// ����ָ���
	BYTE            bDisChn[16];						// ��ʾͨ��
	char			reserved[16];
} DEC_COMBIN_INFO, *LPDEC_COMBIN_INFO;

// ��������Ѳ��Ϣ
#define DEC_COMBIN_NUM 			32						// ��Ѳ��ϸ���
typedef struct __DEC_TOUR_COMBIN
{
	int				nTourTime;							// ��Ѳ���(��)
	int				nCombinNum;							// ��ϸ���
	BYTE			bCombinID[DEC_COMBIN_NUM];			// ��ϱ�
	char			reserved1[32];
	BYTE			bCombinState[DEC_COMBIN_NUM];		// ������ʹ��״̬��0���أ�1����
	char			reserved2[32];
} DEC_TOUR_COMBIN, *LPDEC_TOUR_COMBIN;

// �������ط�����
typedef enum __DEC_PLAYBACK_MODE
{
	Dec_By_Device_File = 0,								// ǰ���豸�����ļ���ʽ
	Dec_By_Device_Time,									// ǰ���豸����ʱ�䷽ʽ
} DEC_PLAYBACK_MODE;

// �������طſ�������
typedef enum __DEC_CTRL_PLAYBACK_TYPE
{
	Dec_Playback_Seek = 0,								// �϶�
	Dec_Playback_Play,									// ����
	Dec_Playback_Pause,									// ��ͣ
	Dec_Playback_Stop,									// ֹͣ
} DEC_CTRL_PLAYBACK_TYPE;

// ���ļ��ط�ǰ���豸����
typedef struct __DEC_PLAYBACK_FILE_PARAM
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// ����
	NET_RECORDFILE_INFO stuRecordInfo;					// ¼���ļ���Ϣ
	char			reserved[12];
} DEC_PLAYBACK_FILE_PARAM, *LPDEC_PLAYBACK_FILE_PARAM;

// ��ʱ��ط�ǰ���豸����
typedef struct __DEC_PLAYBACK_TIME_PARAM
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// ����
	int				nChannelID;
	NET_TIME		startTime;
	NET_TIME		endTime;
	char			reserved[12];
} DEC_PLAYBACK_TIME_PARAM, *LPDEC_PLAYBACK_TIME_PARAM;

// ��ǰ����ͨ��״̬��Ϣ(����ͨ��״̬����������Ϣ��)
typedef struct __DEV_DECCHANNEL_STATE
{
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	BYTE            byChnState;                         // ��ǰ����ͨ�����ڲ���״̬:0�����У�1��ʵʱ���ӣ�2���ط�
	BYTE			byFrame;                            // ��ǰ����֡��
	BYTE            byReserved;                         // ����
	int				nChannelFLux;						// ����ͨ����������
	int             nDecodeFlux;						// ����������
	char            szResolution[16];                   // ��ǰ���ݷֱ���
	char			reserved[256];
} DEV_DECCHANNEL_STATE, *LPDEV_DECCHANNEL_STATE;

// �豸TV���������Ϣ
typedef struct __DEV_VIDEOOUT_INFO
{
	DWORD				dwVideoStandardMask;			// NSP,��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ(�ݲ�֧��)
	int					nVideoStandard;                 // NSP,��ǰ����ʽ(�ݲ�֧�֣���ʹ��ISIL_DEV_SYSTEM_ATTR_CFG��byVideoStandard����ʽ��ȡ������)
	DWORD				dwImageSizeMask;				// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ���
	int                 nImageSize;                     // ��ǰ�ķֱ���
	char				reserved[256];
}DEV_VIDEOOUT_INFO, *LPDEV_VIDEOOUT_INFO;

/////////////////////////////////����汾/////////////////////////////////

// �����豸ץͼ�����ӿ�����Ϣ
typedef struct __NET_SNAP_COMMANDINFO
{
	char				szCardInfo[16];			// ������Ϣ
	char				reserved[64];			// ����
} NET_SNAP_COMMANDINFO, LPNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// ͨ����
	char				szUseType[32];			// ͨ����;
	DWORD				dwStreamSize;			// ������С(��λ��kb/s)
	char				reserved[32];			// ����
} ISIL_DEV_USE_CHANNEL_STATE;

typedef struct
{
	char				szUserName[32];			// �û���
	char				szUserGroup[32];		// �û���
	NET_TIME			time;					// ����ʱ��
	int					nOpenedChannelNum;		// ������ͨ������
	ISIL_DEV_USE_CHANNEL_STATE	channelInfo[ISIL_MAX_CHANNUM];
	char				reserved[64];
} ISIL_DEV_USER_NET_INFO;

// ��������״̬��Ϣ
typedef	struct
{
	int					nUserCount;				// �û�����
	ISIL_DEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}ISIL_DEV_TOTAL_NET_STATE;

// ͼ��ˮӡ����
typedef struct __ISIL_DEV_WATERMAKE_CFG
{
	DWORD				dwSize;
	int					nEnable;				// ʹ��
	int					nStream;				// ����(1��n)0-��������
	int					nKey;					// ��������(1-���֣�2-ͼƬ)
	char				szLetterData[ISIL_MAX_WATERMAKE_LETTER];	//	����
	char				szData[ISIL_MAX_WATERMAKE_DATA]; // ͼƬ����
	BYTE				bReserved[512];			// ����
} ISIL_DEV_WATERMAKE_CFG;

// �洢λ�����ýṹ�壬ÿͨ����������,ÿͨ������ѡ����ִ洢����, Ŀǰ��������, ���ƶ�, Զ�̴洢.
typedef struct
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// ���ش洢���룻��λ��ʾ��
												// ��һλ��ϵͳԤ¼���ڶ�λ����ʱ¼�񣬵���λ������¼��
												// ����λ������¼�񣬵���λ������¼�񣬵���λ���ֶ�¼��
	DWORD				dwMobileMask;			// ���ƶ��洢���� �洢�����籾�ش洢����
	int					RemoteType;				// Զ�̴洢���� 0: Ftp  1: Smb
	DWORD				dwRemoteMask;			// Զ�̴洢���� �洢�����籾�ش洢����
	DWORD				dwRemoteSecondSelLocal;	// Զ���쳣ʱ���ش洢����
	DWORD				dwRemoteSecondSelMobile;// Զ���쳣ʱ���ƶ��洢����
	char				SubRemotePath[MAX_PATH_STOR]; // Զ��Ŀ¼, ���г���Ϊ240
	DWORD				dwFunctionMask;			//��������λ����λ��ʾ��bit0 = 1:����ץͼ�¼������洢λ�ù���

	char				reserved[124];
} ISIL_STORAGE_STATION_CFG;

#define MAX_ALARM_DECODER_NUM 16
typedef struct
{
	DWORD				dwAlarmDecoder;			// �������֧��8����������ڣ���8λ���Ժ���չ
	BYTE				bDecoderIndex;			// ��ʾ�ڼ�������������
	BYTE				bReserved[3];
} ALARM_DECODER;

// ��������������
typedef struct
{
	int					nAlarmDecoderNum;
	ALARM_DECODER		stuAlarmDecoder[MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ALARM_DECODER_ALARM;

//DSP����
typedef struct
{
	BOOL				bError;			//0,DSP���� 1,DSP�쳣
	DWORD				dwErrorMask;	//��λ��ʾ����0��ʾ�д˴���0��ʾû�С�(Ŀǰÿ�α���ֻ��һλ��Ч)
										//bit		DSP����
										//1			DSP����ʧ��
										//2			DSP����
										//3			��ʽ����
										//4			�ֱ��ʲ�֧��
										//5			���ݸ�ʽ��֧��
										//6			�Ҳ���I֡
	DWORD               dwDecChnnelMask;//��λ��ʾ�������Ľ���ͨ���ţ�dwErrorMaskΪDSP������ʽ���ԣ��ֱ��ʲ�֧�֣����ݸ�ʽ��֧��ʱ������Ч

	BYTE				bReserved[28];
}DSP_ALARM;

// ���˱�����������
typedef struct
{
	int		nFDDINum;
	BYTE	bAlarm[256];
} ALARM_FDDI_ALARM;

// ����Ƶ��ⱨ������
typedef struct
{
	BOOL				bEnable;				// ��������ʹ��
	int					Volume_min;				// ��������Сֵ
	int					Volume_max;				// ���������ֵ
	char				reserved[128];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// ����ʽ
} ISIL_AUDIO_DETECT_INFO;

typedef struct
{
	DWORD				dwSize;
	int					AlarmNum;
	ISIL_AUDIO_DETECT_INFO AudioDetectAlarm[ISIL_MAX_AUDIO_IN_NUM];
	char				reserved[256];
} ISIL_AUDIO_DETECT_CFG;

typedef struct
{
	BOOL				bTourEnable;			// ��Ѳʹ��
	int					nTourPeriod;			// ��Ѳ�������λ��, 5-300
	DWORD				dwChannelMask;			// ��Ѳ��ͨ����������ʽ��ʾ
	char				reserved[64];
}ISIL_VIDEOGROUP_CFG;

// ����������Ʋ�������
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// �������(ע���������޸�)
	ISIL_VIDEOGROUP_CFG	struVideoGroup[ISIL_MATRIX_MAXOUT];
	char				reserved[32];
} ISIL_DEV_VIDEO_MATRIX_CFG;

// WEB·������
typedef struct
{
	DWORD				dwSize;
	BOOL				bSnapEnable;			// �Ƿ�ץͼ
	int					iSnapInterval;			// ץͼ����
	char				szHostIp[ISIL_MAX_IPADDR_LEN]; // HTTP����IP
	WORD				wHostPort;
	int					iMsgInterval;			// ״̬��Ϣ���ͼ��
	char				szUrlState[ISIL_MAX_URL_LEN];	// ״̬��Ϣ�ϴ�URL
	char				szUrlImage[ISIL_MAX_URL_LEN];	// ͼƬ�ϴ�Url
	char				szDevId[ISIL_MAX_DEV_ID_LEN];	// ������web���
	BYTE				byReserved[2];
} ISIL_DEV_URL_CFG;

// OEM��ѯ
typedef struct
{
	char				szVendor[ISIL_MAX_STRING_LEN];
	char				szType[ISIL_MAX_STRING_LEN];
	char				reserved[128];
} ISIL_DEV_OEM_INFO;


//��ƵOSD��������
typedef struct
{
	DWORD	rgbaFrontground;		// �����ǰ�������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	DWORD	rgbaBackground;			// ����ı��������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	RECT	rcRelativePos;			// λ��,����߾��������ı���*8191
	BOOL	bPreviewBlend;			// Ԥ������ʹ��
	BOOL	bEncodeBlend;			// �������ʹ��
	BYTE    bReserved[4];           // ����
} ISIL_DVR_VIDEO_WIDGET;

typedef struct
{
	ISIL_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD���ӵ�λ�úͱ���ɫ
	char 				SzOSD_Name[ISIL_VIDEO_OSD_NAME_NUM]; 		// OSD���ӵ�����
}ISIL_DVR_VIDEOITEM;

// ÿ��ͨ����OSD��Ϣ
typedef struct
{
	DWORD 				dwSize;
	ISIL_DVR_VIDEOITEM 	StOSDTitleOpt [ISIL_VIDEO_CUSTOM_OSD_NUM]; 	// ÿ��ͨ����OSD��Ϣ
	BYTE    			bReserved[16];                  		  // ����
} ISIL_DVR_VIDEOOSD_CFG;

// ����CDMA/GPRS������Ϣ
// ʱ��νṹ
typedef struct
{
	BYTE				bEnable;				  // ʱ���ʹ�ܣ�1��ʾ��ʱ�����Ч��0��ʾ��ʱ�����Ч��
	BYTE				bBeginHour;
	BYTE				bBeginMin;
	BYTE				bBeginSec;
	BYTE				bEndHour;
	BYTE				bEndMin;
	BYTE				bEndSec;
	BYTE    			bReserved;                //����
} ISIL_3G_TIMESECT, *LPISIL_3G_TIMESECT;

typedef struct
{
	DWORD 				dwSize;
	BOOL				bEnable;					// ����ģ��ʹ�ܱ�־
	DWORD               dwTypeMask;                 // �豸֧��������������;��λ��ʾ,��һλ;�Զ�ѡ��;�ڶ�λ��TD-SCDMA���磻
													// ����λ��WCDMA����;����λ��CDMA 1.x����;����λ��CDMA2000����;����λ��GPRS����;
													// ����λ��EVDO����;�ڰ�λ��WIFI
	DWORD               dwNetType;                  // ��ǰ�������������ͣ�ΪEM_GPRSCDMA_NETWORK_TYPEֵ
	char				szAPN[128];					// ���������
	char				szDialNum[128];				// ���ź���
	char				szUserName[128];			// �����û���
	char				szPWD[128];					// ��������

	/* �������豸��ֻ������ */
	BOOL				iAccessStat;				// ��������ע��״̬
    char				szDevIP[16];				// ǰ���豸����IP���ַ���, ����'\0'��������16byte
	char				szSubNetMask [16];			// ǰ���豸�����������룬�ַ���, ����'\0'��������16byte
	char				szGateWay[16];				// ǰ���豸�������أ��ַ���, ����'\0'��������16byte
	/* �������豸��ֻ������ */
	int                 iKeepLive;					// ����ʱ��
	ISIL_3G_TIMESECT		stSect[ISIL_N_WEEKS][ISIL_N_TSECT];// 3G����ʱ��Σ���Чʱ���֮�ڣ��������ţ���Чʱ���֮�⣬�رղ��š�
	BYTE                byActivate;                  //�Ƿ���Ҫ����������ż���
	char				Reserved[171];				// �����ֽڣ�������չ
} ISIL_DEV_CDMAGPRS_CFG;

// ¼������������
typedef struct
{
	DWORD 				dwSize;
	int					nType;						// 0:��ʱ�䣬1������С
	int					nValue;						// nType = 0ʱ:��λ���ӣ�nType = 1ʱ:��λKB
	char				Reserved[128];				// �����ֽڣ�������չ
} ISIL_DEV_RECORD_PACKET_CFG;

// (����)����ע���������Ϣ
typedef struct __DEV_AUTOREGISTER_INFO
{
	LONG			lConnectionID;						// ����ID
	char			szServerIp[ISIL_MAX_IPADDR_LEN];		// ����ע���������IP
	int				nPort;								// ����ע��������˿�0- 65535
	int             nState;                             // ��������״̬��0��ע��ʧ�ܣ�1-ע��ɹ�; 2-����ʧ��
	char			reserved[16];
} DEV_AUTOREGISTER_INFO;

typedef struct __DEV_SERVER_AUTOREGISTER
{
	DWORD					dwSize;
	int						nRegisterSeverCount;											// ����ע�����������
	DEV_AUTOREGISTER_INFO	stuDevRegisterSeverInfo[ISIL_CONTROL_AUTO_REGISTER_NUM];			// ������ע���������Ϣ
	char					reserved[256];
} DEV_SERVER_AUTOREGISTER, *LPDEV_SERVER_AUTOREGISTER;

// ������¼�����ϴ�
typedef struct
{
	DWORD				dwSize;
	char				szSourFile[MAX_PATH_STOR];	// Դ�ļ�·��
	int					nFileSize;					// Դ�ļ���С�����С�ڵ���0��sdk���м����ļ���С.
	char				szBurnFile[MAX_PATH_STOR];	// ��¼����ļ���
	BYTE				bReserved[64];
} ISIL_DEV_BURNFILE_TRANS_CFG;

// ֣������ķEC_U��Ƶ���ݵ���ʹ������
typedef struct
{
	BOOL				bEnable;					// ʹ��
	int					nPort;						// �˿�
	BYTE				bReserved[64];
}ISIL_DEV_OSD_ENABLE_CFG;

/////////////////////////////////ƽ̨����/////////////////////////////////

// ƽ̨�������� �� U��ͨ
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[ISIL_INTERVIDEO_UCOM_CHANID];
} ISIL_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// ���빦��ʹ��
	BOOL				bAliveEnable;			// ����ʹ��
	DWORD				dwAlivePeriod;			// �������ڣ���λ�룬0-3600
	char				szServerIp[ISIL_MAX_IPADDR_LEN]; // CMS��IP
	WORD				wServerPort;			// CMS��Port
    char				szRegPwd[ISIL_INTERVIDEO_UCOM_REGPSW]; // ע������
	char				szDeviceId[ISIL_INTERVIDEO_UCOM_DEVID];// �豸id
	char				szUserName[ISIL_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[ISIL_INTERVIDEO_UCOM_USERPSW];
    ISIL_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[ISIL_MAX_CHANNUM]; // ͨ��id,en
} ISIL_DEV_INTERVIDEO_UCOM_CFG;

// ƽ̨�������� �� ��������
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// ��˾ID����ֵ����ͬ�ĵ���������˾������4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szDeviceNO[32];			// ǰ���豸���кţ��ַ���������'\0'��������32byte
    char				szVSName[32];			// ǰ���豸���ƣ��ַ���������'\0'��������16byte
    char				szVapPath[32];			// VAP·��
    unsigned short		usTcpPort;				// TCP�˿ڣ���ֵ����ֵ 1~65535
    unsigned short		usUdpPort;				// UDP�˿ڣ���ֵ����ֵ 1~65535
    char				bCsEnable[4];			// ���ķ�����ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szCsIP[16];				// ���ķ�����IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usCsPort[2];			// ���ķ������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    char				bHsEnable[4];			// ����������ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szHsIP[16];				// ����������IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usHsPort[2];			// �����������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    int					iHsIntervalTime;		// ����������������ڣ���ֵ(��λ:��)
    char				bRsEnable[4];			// ע�������ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szRsIP[16];				// ע�������IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usRsPort[2];			// ע��������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    int					iRsAgedTime;			// ע���������Чʱ�䣬��ֵ(��λ:Сʱ)
    char				szAuthorizeServerIp[16];// ��Ȩ������IP
    unsigned short		usAuthorizePort[2];		// ��Ȩ�������˿ڣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szAuthorizeUsername[32];// ��Ȩ�������ʺ�
    char				szAuthorizePassword[36];// ��Ȩ����������

    char				szIpACS[16];			// ACS(�Զ�ע�������) IP
    unsigned short		usPortACS[2];			// ACS Port������4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szUsernameACS[32];		// ACS�û���
    char				szPasswordACS[36];		// ACS����
    char				bVideoMonitorEnabled[4];// DVS�Ƿ����ϱ�ǰ����Ƶ�źż����Ϣ����ֵ��trueʹ�ܣ�false��ʹ��
    int					iVideoMonitorInterval;	// �ϱ�����(����)

    char				szCoordinateGPS[64];	// GPS����
    char				szPosition[32];			// �豸λ��
    char				szConnPass[36];			// �豸������
} ISIL_DEV_INTERVIDEO_BELL_CFG;

// ƽ̨�������� �� ������ά
typedef struct
{
	DWORD				dwSize;
	unsigned short		nSevPort;				// �������˿ڣ���ֵ����ֵ1~65535
    char				szSevIp[ISIL_INTERVIDEO_NSS_IP]; // ������IP��ַ���ַ���������'\0'��������32byte
    char				szDevSerial[ISIL_INTERVIDEO_NSS_SERIAL]; // ǰ���豸���кţ��ַ���������'\0'��������32byte
    char				szUserName[ISIL_INTERVIDEO_NSS_USER];
    char				szPwd[ISIL_INTERVIDEO_NSS_PWD];
} ISIL_DEV_INTERVIDEO_NSS_CFG;


////////////////////////////////HDVRר��//////////////////////////////////
// ����������չ�ṹ��
typedef struct
{
	/* ��Ϣ����ʽ������ͬʱ���ִ���ʽ������
	 * 0x00000001 - �����ϴ�
	 * 0x00000002 - ����¼��
	 * 0x00000004 - ��̨����
	 * 0x00000008 - �����ʼ�
	 * 0x00000010 - ������Ѳ
	 * 0x00000020 - ������ʾ
	 * 0x00000040 - �������
	 * 0x00000080 - Ftp�ϴ�
	 * 0x00000100 - ����
	 * 0x00000200 - ������ʾ
	 * 0x00000400 - ץͼ
	*/

	/* ��ǰ������֧�ֵĴ���ʽ����λ�����ʾ */
	DWORD				dwActionMask;

	/* ������������λ�����ʾ�����嶯������Ҫ�Ĳ����ڸ��Ե����������� */
	DWORD				dwActionFlag;

	/* �������������ͨ�������������������Ϊ1��ʾ��������� */
	BYTE				byRelAlarmOut[ISIL_MAX_ALARMOUT_NUM_EX];
	DWORD				dwDuration;				/* ��������ʱ�� */

	/* ����¼�� */
	BYTE				byRecordChannel[ISIL_MAX_VIDEO_IN_NUM_EX]; /* ����������¼��ͨ����Ϊ1��ʾ������ͨ�� */
	DWORD				dwRecLatch;				/* ¼�����ʱ�� */

	/* ץͼͨ�� */
	BYTE				bySnap[ISIL_MAX_VIDEO_IN_NUM_EX];
	/* ��Ѳͨ�� */
	BYTE				byTour[ISIL_MAX_VIDEO_IN_NUM_EX];

	/* ��̨���� */
	ISIL_PTZ_LINK			struPtzLink[ISIL_MAX_VIDEO_IN_NUM_EX];
	DWORD				dwEventLatch;			/* ������ʼ��ʱʱ�䣬sΪ��λ����Χ��0~15��Ĭ��ֵ��0 */
	/* �����������������ͨ�������������������Ϊ1��ʾ��������� */
	BYTE				byRelWIAlarmOut[ISIL_MAX_ALARMOUT_NUM_EX];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*���ű���ʹ��*/
	BYTE                bySnapshotTimes;       /*���ŷ���ץͼ���� */
	BYTE				bMatrixEn;				/*!< ����ʹ�� */
	DWORD				dwMatrix;				/*!< �������� */
	BYTE				bLog;					/*!< ��־ʹ�ܣ�Ŀǰֻ����WTN��̬�����ʹ�� */
	BYTE				byReserved[511];
} ISIL_MSG_HANDLE_EX;

// �ⲿ������չ
typedef struct
{
	BYTE				byAlarmType;			// ���������ͣ�0�����գ�1������
	BYTE				byAlarmEn;				// ����ʹ��
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ISIL_ALARMIN_CFG_EX, *LPISIL_DEV_ALARMIN_CFG_EX;

// ��̬��ⱨ��
typedef struct
{
	BYTE				byMotionEn;				// ��̬��ⱨ��ʹ��
	BYTE				byReserved;
	WORD				wSenseLevel;			// ������
	WORD				wMotionRow;				// ��̬������������
	WORD				wMotionCol;				// ��̬������������
	BYTE				byDetected[ISIL_MOTION_ROW][ISIL_MOTION_COL]; // ����������32*32������
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX		struHandle;				//����ʽ
} ISIL_MOTION_DETECT_CFG_EX;

// ��Ƶ��ʧ����
typedef struct
{
	BYTE				byAlarmEn;				// ��Ƶ��ʧ����ʹ��
	BYTE				byReserved[3];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ISIL_VIDEO_LOST_CFG_EX;

// ͼ���ڵ�����
typedef struct
{
	BYTE				byBlindEnable;			// ʹ��
	BYTE				byBlindLevel;			// ������1-6
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ISIL_BLIND_CFG_EX;

// Ӳ����Ϣ(�ڲ�����)
typedef struct
{
	BYTE				byNoDiskEn;				// ��Ӳ��ʱ����
	BYTE				byReserved_1[3];
	ISIL_TSECT			stNDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struNDHandle;			// ����ʽ

	BYTE				byLowCapEn;				// Ӳ�̵�����ʱ����
	BYTE				byLowerLimit;			// ������ֵ��0-99
	BYTE				byReserved_2[2];
	ISIL_TSECT			stLCSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struLCHandle;			// ����ʽ

	BYTE				byDiskErrEn;			// Ӳ�̹��ϱ���
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ISIL_TSECT			stEDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struEDHandle;			// ����ʽ
} ISIL_DISK_ALARM_CFG_EX;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ISIL_MSG_HANDLE_EX	struHandle;
} ISIL_NETBROKEN_ALARM_CFG_EX;

// ǰ�˽������ò�����Ϣ
typedef struct __DEV_ENCODER_CFG
{
	int				nChannels;							// ����ͨ������
	DEV_ENCODER_INFO stuDevInfo[32];					// ������ͨ����ǰ�˱�������Ϣ
	char			reserved[16];
} DEV_ENCODER_CFG, *LPDEV_ENCODER_CFG;


// Э����Ϣ
typedef struct
{
	char				protocolname[12];		// Э����
	unsigned int		baudbase;				// ������
	unsigned char		databits;				// ����λ
	unsigned char		stopbits;				// ֹͣλ
	unsigned char		parity;					// У��λ
	unsigned char		reserve;
} PROTOCOL_INFO, *LPPROTOCOL_INFO;

// �����Խ���������
typedef struct
{
	// ��Ƶ�������
	BYTE				byInFormatTag;			// �������ͣ���PCM
	BYTE				byInChannels;			// ������
	WORD				wInBitsPerSample;		// �������
	DWORD				dwInSamplesPerSec;		// ������

	// ��Ƶ�������
	BYTE				byOutFormatTag;			// �������ͣ���PCM
	BYTE				byOutChannels;			// ������
	WORD				wOutBitsPerSample;		// �������
	DWORD				dwOutSamplesPerSec;		// ������
} ISIL_DEV_TALK_CFG, *LPISIL_DEV_TALK_CFG;


extern S32  ISIL_ParseLocalNetMsg(U32 uiMsgType, S08 *data, S32 iLen, S32 iConnectfd);

#ifdef __cplusplus
}
#endif
#endif

