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
//	查询类型
typedef enum
{
	ABILITY_WATERMARK_CFG = 17,			//水印配置能力
	ABILITY_WIRELESS_CFG = 18,			//wireless配置能力
	ABILITY_DEVALL_INFO = 26,			//设备的能力列表
	ABILITY_CARD_QUERY = 0x0100,		//卡号查询能力
	ABILITY_MULTIPLAY = 0x0101,			//多画面预览能力
	ABILITY_QUICK_QUERY_CFG = 0x0102,	//快速查询配置能力
	ABILITY_INFRARED = 0x0121,			//无线报警能力
	ABILITY_TRIGGER_MODE = 0x0131,		//报警输出触发方式能力
	ABILITY_DISK_SUBAREA = 0x0141,		//网络硬盘分区能力
	ABILITY_DSP_CFG = 0x0151,		//查询dsp能力
} DH_SYS_ABILITY;

//////////////////////////////////////////////////////////////////////////
//	设备支持功能列表
enum
{
	EN_FTP = 0,							//FTP 按位，1：传送录像文件 2：传送抓图文件
	EN_SMTP,							//SMTP 按位，1：报警传送文本邮件 2：报警传送图片
	EN_NTP,								//NTP	按位：1：调整系统时间
	EN_AUTO_MAINTAIN,					//自动维护 按位：1：重启 2：关闭 3:删除文件
	EN_VIDEO_COVER,						//区域遮挡 按位：1：多区域遮挡
	EN_AUTO_REGISTER,					//主动注册	按位：1：注册后sdk主动登陆
	EN_DHCP,							//DHCP	按位：1：DHCP
	EN_UPNP,							//UPNP	按位：1：UPNP
	EN_COMM_SNIFFER,					//串口抓包 按位：1:CommATM
	EN_NET_SNIFFER,						//网络抓包 按位： 1：NetSniffer
	EN_BURN,							//刻录功能 按位：1：查询刻录状态
	EN_VIDEO_MATRIX,					//视频矩阵 按位：1：是否支持视频矩阵
	EN_AUDIO_DETECT,					//音频检测 按位：1：是否支持音频检测
	EN_STORAGE_STATION,					//存储位置 按位：1：Ftp服务器(Ips) 2：SBM 3：NFS 16：DISK 17：U盘
	EN_IPSSEARCH,						//IPS存储查询 按位：1：IPS存储查询
	EN_SNAP,							//抓图  按位：1：分辨率2：帧率3：抓图方式4：抓图文件格式5：图画质量
	EN_DEFAULTNIC,						//支持默认网卡查询 按位 1：支持
	EN_SHOWQUALITY,						//CBR模式下显示画质配置项 按位 1:支持
	EN_CONFIG_IMEXPORT,					//配置导入导出功能能力 按位 1:支持
	EN_LOG,								//是否支持分页方式的日志查询 按位 1：支持
	EN_SCHEDULE,						//录像设置的一些能力 按位 1:冗余 2:预录 3:录像时间段
	EN_NETWORK_TYPE,					//网络类型按位表示 1:以态网 2:无线局域 3:CDMA/GPRS
	EN_MARK_IMPORTANTRECORD,			//标识重要录像 按位:1：设置重要录像标识
	EN_ACFCONTROL,						//活动帧率控制 按位：1：支持活动帧率控制
	EN_MULTIASSIOPTION,					//多路辅码流 按位：1：支持三路辅码流
	EN_DAVINCIMODULE,					//组件化模块 按位：1，时间表分开处理 2:标准I帧间隔设置
	EN_GPS,                             //GPS功能 按位：1：Gps定位功能
};

typedef struct
{
	DWORD IsFucEnable[512];				//功能列表能力集,下标对应上述的枚举值,按位表示子功能
} DH_DEV_ENABLE_INFO;

//////////////////////////////////////////////////////////////////////////
//	卡号查询能力结构体
typedef struct
{
	char		IsCardQueryEnable;
	char		iRev[3];
} DH_CARD_QUERY_EN;

//////////////////////////////////////////////////////////////////////////
//	wireless能力结构体
typedef struct
{
	char		IsWirelessEnable;
	char		iRev[3];
} DH_WIRELESS_EN;

//////////////////////////////////////////////////////////////////////////
//	图象水印能力结构体
typedef struct
{
	char		isSupportWM;	//1 支持；0 不支持
	char		supportWhat;	//0：文字水印；1：图片水印；2：同时支持文字水印和图片水印
	char		reserved[2];
} DH_WATERMAKE_EN;

//////////////////////////////////////////////////////////////////////////
//	多画面预览能力结构体
typedef struct
{
	int			nEnable;			//1 支持；0 不支持
	DWORD		dwMultiPlayMask;	//多画面预览掩码
	char		reserved[4];		//保留
} DH_MULTIPLAY_EN;

//////////////////////////////////////////////////////////////////////////
//	无线报警能力结构体
typedef struct
{
	BOOL		bSupport;//是否支持
	int			nAlarmInCount;//输入个数
	int			nAlarmOutCount;//输出个数
	int			nRemoteAddrCount;//遥控器个数
	BYTE		reserved[32];
} DH_WIRELESS_ALARM_INFO;

//////////////////////////////////////////////////////////////////////////
// 网络硬盘分区能力结构体
typedef struct
{
	BOOL		bSupported;//是否支持网络硬盘分区
	int			nSupportNum;//支持分区的数目
	BYTE		bReserved[32];//保留字节
} DH_DISK_SUBAREA_EN;

// DSP能力查询，当DSP能力算法标识为2时使用。
typedef struct
{
	BYTE bMainFrame[32];		//以分辨率枚举值(CAPTURE_SIZE)为索引,主码流分辨率对应支持的最大帧率,如果不支持此分辨率,则值为0.
	BYTE bExtraFrame_1[32];		//辅码流1,使用同bMainFrame
	BYTE bReserved[128];		//预留给辅码流2和3.
}DH_DSP_CFG_ITEM;

typedef struct
{
	int nItemNum;						//DH_DSP_CFG_ITEM的有效个数,等于通道数
	DH_DSP_CFG_ITEM	stuDspCfgItem[32];	//主码流的信息
	BYTE bReserved[128];				//保留
}DH_DSP_CFG;

//////////////////////////////////////////////////////////////////////////
//	快速查询配置能力结构体
typedef struct
{
	char		IsQuickQueryEnable;    //1是设备支持配置命令快速返回，请设置配置时间足够长以保证窄带下配置的正常读取。建议设置60S
	char		iRev[3];
} DH_QUICK_QUERY_CFG_EN;

/****************************************END***************************************************/

#define ISIL_SERIALNO_LEN 			48			// 设备序列号字符长度
#define ISIL_MAX_DISKNUM 			256			// 最大硬盘个数
#define ISIL_MAX_SDCARDNUM			32			// 最大SD卡个数
#define ISIL_MAX_BURNING_DEV_NUM		32			// 最大刻录设备个数
#define ISIL_BURNING_DEV_NAMELEN		32			// 刻录设备名字最大长度
#define ISIL_MAX_LINK 				6
#define ISIL_MAX_CHANNUM 			16			// 最大通道个数
#define ISIL_MAX_ALARMIN 			128			// 最大报警输入个数
#define ISIL_MAX_ALARMOUT 			64			// 最大报警输出个数
#define ISIL_MAX_RIGHT_NUM			100			// 用户权限个数上限
#define ISIL_MAX_GROUP_NUM			20			// 用户组个数上限
#define ISIL_MAX_USER_NUM			200			// 用户个数上限
#define ISIL_RIGHT_NAME_LENGTH		32			// 权限名长度
#define ISIL_USER_NAME_LENGTH		8			// 用户名长度
#define ISIL_USER_PSW_LENGTH			8			// 用户密码长度
#define ISIL_MEMO_LENGTH				32			// 备注长度
#define ISIL_MAX_STRING_LEN			128
#define ISIL_DVR_SERIAL_RETURN		1			// 设备发送序列号回调
#define ISIL_DVR_DISCONNECT			-1			// 验证期间设备断线回调
#define MAX_STRING_LINE_LEN			6			// 最多六行
#define MAX_PER_STRING_LEN			20			// 每行最大长度
#define ISIL_MAX_MAIL_NAME_LEN		64			// 新的邮件结构体支持的用户名长度
#define ISIL_MAX_MAIL_PSW_LEN		64			// 新的邮件结构体支持的密码长度

// 远程配置结构体相关常量
#define ISIL_MAX_MAIL_ADDR_LEN		128			// 邮件发(收)地址最大长度
#define ISIL_MAX_MAIL_SUBJECT_LEN	64			// 邮件主题最大长度
#define ISIL_MAX_IPADDR_LEN			16			// IP地址字符串长度

#ifndef ISIL_MACADDR_LEN
	#define ISIL_MACADDR_LEN				40			// MAC地址字符串长度
#endif
													
#define ISIL_MAX_URL_LEN				128			// URL字符串长度
#define ISIL_MAX_DEV_ID_LEN			48			// 机器编号最大长度
#define	ISIL_MAX_HOST_NAMELEN		64			// 主机名长度，
#define ISIL_MAX_HOST_PSWLEN			32			// 密码长度
#define ISIL_MAX_NAME_LEN			16			// 通用名字字符串长度
#define ISIL_MAX_ETHERNET_NUM		2			// 以太网口最大个数
#define	ISIL_DEV_SERIALNO_LEN		48			// 序列号字符串长度
#define ISIL_DEV_TYPE_LEN			32			// 设备类型字符串长度
#define ISIL_N_WEEKS					7			// 一周的天数
#define ISIL_N_TSECT					6			// 通用时间段个数
#define ISIL_N_REC_TSECT				6			// 录像时间段个数
#define ISIL_N_COL_TSECT				2			// 颜色时间段个数
#define ISIL_CHAN_NAME_LEN			32			// 通道名长度，DVR DSP能力限制，最多32字节
#define ISIL_N_ENCODE_AUX			3			// 扩展码流个数
#define ISIL_N_TALK					1			// 最多对讲通道个数
#define ISIL_N_COVERS				1			// 遮挡区域个数
#define ISIL_N_CHANNEL				16			// 最大通道个数
#define ISIL_N_ALARM_TSECT			2			// 报警提示时间段个数
#define ISIL_MAX_ALARMOUT_NUM		16			// 报警输出口个数上限
#define ISIL_MAX_AUDIO_IN_NUM		16			// 音频输入口个数上限
#define ISIL_MAX_VIDEO_IN_NUM		16			// 视频输入口个数上限
#define ISIL_MAX_ALARM_IN_NUM		16			// 报警输入口个数上限
#define ISIL_MAX_DISK_NUM			16			// 硬盘个数上限，暂定为16
#define ISIL_MAX_DECODER_NUM			16			// 解码器(485)个数上限
#define ISIL_MAX_232FUNCS			10			// 232串口功能个数上限
#define ISIL_MAX_232_NUM				2			// 232串口个数上限
#define ISIL_MAX_DECPRO_LIST_SIZE	100			// 解码器协议列表个数上限
#define ISIL_FTP_MAXDIRLEN			240			// FTP文件目录最大长度
#define ISIL_MATRIX_MAXOUT			16			// 矩阵输出口最大个数
#define ISIL_TOUR_GROUP_NUM			6			// 矩阵输出组最大个数
#define ISIL_MAX_DDNS_NUM			10			// 设备支持的ddns服务器最大个数
#define ISIL_MAX_SERVER_TYPE_LEN		32			// ddns服务器类型，最大字符串长度
#define ISIL_MAX_DOMAIN_NAME_LEN		256			// ddns域名，最大字符串长度
#define ISIL_MAX_DDNS_ALIAS_LEN		32			// ddns服务器别名，最大字符串长度
#define ISIL_MOTION_ROW				32			// 动态检测区域的行数
#define ISIL_MOTION_COL				32			// 动态检测区域的列数
#define	ISIL_FTP_USERNAME_LEN			64			// FTP配置，用户名最大长度
#define	ISIL_FTP_PASSWORD_LEN			64			// FTP配置，密码最大长度
#define	ISIL_TIME_SECTION				2			// FTP配置，每天时间段个数
#define ISIL_FTP_MAX_PATH				240			// FTP配置，文件路径名最大长度
#define ISIL_INTERVIDEO_UCOM_CHANID	32			// 平台接入配置，U网通通道ID
#define ISIL_INTERVIDEO_UCOM_DEVID	32			// 平台接入配置，U网通设备ID
#define ISIL_INTERVIDEO_UCOM_REGPSW	16			// 平台接入配置，U网通注册密码
#define ISIL_INTERVIDEO_UCOM_USERNAME	32			// 平台接入配置，U网通用户名
#define ISIL_INTERVIDEO_UCOM_USERPSW	32			// 平台接入配置，U网通密码
#define ISIL_INTERVIDEO_NSS_IP		32			// 平台接入配置，中兴力维IP
#define ISIL_INTERVIDEO_NSS_SERIAL	32			// 平台接入配置，中兴力维serial
#define ISIL_INTERVIDEO_NSS_USER		32			// 平台接入配置，中兴力维user
#define ISIL_INTERVIDEO_NSS_PWD		50			// 平台接入配置，中兴力维password
#define ISIL_MAX_VIDEO_COVER_NUM		16			// 遮挡区域最大个数
#define ISIL_MAX_WATERMAKE_DATA		4096		// 水印图片数据最大长度
#define ISIL_MAX_WATERMAKE_LETTER		128			// 水印文字最大长度
#define ISIL_MAX_WLANDEVICE_NUM		10			// 最多搜索出的无线设备个数
#define ISIL_MAX_ALARM_NAME			64			// 地址长度
#define ISIL_MAX_REGISTER_SERVER_NUM	10			// 主动注册服务器个数
#define ISIL_SNIFFER_FRAMEID_NUM		6			// 6个FRAME ID 选项
#define ISIL_SNIFFER_CONTENT_NUM		4			// 每个FRAME对应的4个抓包内容
#define ISIL_SNIFFER_CONTENT_NUM_EX	8			// 每个FRAME对应的8个抓包内容
#define ISIL_SNIFFER_PROTOCOL_SIZE	20			// 协议名字长度
#define ISIL_MAX_PROTOCOL_NAME_LENGTH 20
#define ISIL_SNIFFER_GROUP_NUM		4			// 4组抓包设置
#define MAX_PATH_STOR				240			// 远程目录的长度
#define ISIL_ALARM_OCCUR_TIME_LEN		40			// 新的报警上传时间的长度
#define ISIL_VIDEO_OSD_NAME_NUM		64			// 叠加的名称长度，目前支持32个英文，16个中文
#define ISIL_VIDEO_CUSTOM_OSD_NUM		8			// 支持的自定义叠加的数目，不包含时间和通道
#define ISIL_CONTROL_AUTO_REGISTER_NUM 100        // 支持定向主动注册服务器的个数
#define ISIL_MMS_RECEIVER_NUM          100        // 支持短信接收者的个数
#define ISIL_MMS_SMSACTIVATION_NUM     100        // 支持短信发送者的个数
#define ISIL_MMS_DIALINACTIVATION_NUM  100        // 支持拨号发送者的个数
#define ISIL_MAX_ALARMOUT_NUM_EX		 32			// 报警输出口个数上限扩展
#define ISIL_MAX_VIDEO_IN_NUM_EX		 32			// 视频输入口个数上限扩展
#define ISIL_MAX_ALARM_IN_NUM_EX		 32			// 报警输入口个数上限

// 查询类型，对应ISIL_CLIENT_QueryDevState接口
#define ISIL_DEVSTATE_COMM_ALARM		0x0001		// 查询普通报警状态(包括外部报警，视频丢失，动态检测)
#define ISIL_DEVSTATE_SHELTER_ALARM	0x0002		// 查询遮挡报警状态
#define ISIL_DEVSTATE_RECORDING		0x0003		// 查询录象状态
#define ISIL_DEVSTATE_DISK			0x0004		// 查询硬盘信息
#define ISIL_DEVSTATE_RESOURCE		0x0005		// 查询系统资源状态
#define ISIL_DEVSTATE_BITRATE			0x0006		// 查询通道码流
#define ISIL_DEVSTATE_CONN			0x0007		// 查询设备连接状态
#define ISIL_DEVSTATE_PROTOCAL_VER	0x0008		// 查询网络协议版本号，pBuf = int*
#define ISIL_DEVSTATE_TALK_ERROR_CTYPE		0x0009		// 查询设备支持的语音对讲格式列表，见结构体ISIL_DEV_TALKFORMAT_LIST
#define ISIL_DEVSTATE_SD_CARD			0x000A		// 查询SD卡信息(IPC类产品)
#define ISIL_DEVSTATE_BURNING_DEV		0x000B		// 查询刻录机信息
#define ISIL_DEVSTATE_BURNING_PROGRESS 0x000C		// 查询刻录进度
#define ISIL_DEVSTATE_PLATFORM		0x000D		// 查询设备支持的接入平台
#define ISIL_DEVSTATE_CAMERA			0x000E		// 查询摄像头属性信息(IPC类产品)，pBuf = ISIL_DEV_CAMERA_INFO *，可以有多个结构体
#define ISIL_DEVSTATE_SOFTWARE		0x000F		// 查询设备软件版本信息
#define ISIL_DEVSTATE_LANGUAGE        0x0010		// 查询设备支持的语音种类
#define ISIL_DEVSTATE_DSP				0x0011		// 查询DSP能力描述
#define	ISIL_DEVSTATE_OEM				0x0012		// 查询OEM信息
#define	ISIL_DEVSTATE_NET				0x0013		// 查询网络运行状态信息
#define ISIL_DEVSTATE_TYPE			0x0014		// 查询设备类型
#define ISIL_DEVSTATE_SNAP			0x0015		// 查询抓图功能属性(IPC类产品)
#define ISIL_DEVSTATE_RECORD_TIME		0x0016		// 查询最早录像时间和最近录像时间
#define ISIL_DEVSTATE_NET_RSSI        0x0017      // 查询无线网络信号强度，见结构体ISIL_DEV_WIRELESS_RSS_INFO
#define ISIL_DEVSTATE_BURNING_ATTACH	0x0018		// 查询附件刻录选项

// 配置类型，对应ISIL_CLIENT_GetDevConfig和ISIL_CLIENT_SetDevConfig接口
#define ISIL_DEV_DEVICECFG			0x0001		// 设备属性配置
#define ISIL_DEV_NETCFG				0x0002		// 网络配置
#define ISIL_DEV_CHANNELCFG			0x0003		// 图象通道配置
#define ISIL_DEV_PREVIEWCFG 			0x0004		// 预览参数配置
#define ISIL_DEV_RECORDCFG			0x0005		// 录像配置
#define ISIL_DEV_COMMCFG				0x0006		// 串口属性配置
#define ISIL_DEV_ALARMCFG 			0x0007		// 报警属性配置
#define ISIL_DEV_TIMECFG 				0x0008		// DVR时间配置
#define ISIL_DEV_TALKCFG				0x0009		// 对讲参数配置
#define ISIL_DEV_AUTOMTCFG			0x000A		// 自动维护配置
#define	ISIL_DEV_VEDIO_MARTIX			0x000B		// 本机矩阵控制策略配置
#define ISIL_DEV_MULTI_DDNS			0x000C		// 多ddns服务器配置
#define ISIL_DEV_SNAP_CFG_INFO				0x000D		// 抓图相关配置
#define ISIL_DEV_WEB_URL_CFG			0x000E		// HTTP路径配置
#define ISIL_DEV_FTP_PROTO_CFG_INFO		0x000F		// FTP上传配置
#define ISIL_DEV_INTERVIDEO_CFG		0x0010		// 平台接入配置，此时channel参数代表平台类型，
												// channel=4：代表贝尔阿尔卡特；channel=10：代表中兴力维；channel=11：代表U网通
#define ISIL_DEV_VIDEO_COVER			0x0011		// 区域遮挡配置
#define ISIL_DEV_TRANS_STRATEGY		0x0012		// 传输策略配置，画质优先\流畅性优先
#define ISIL_DEV_DOWNLOAD_STRATEGY	0x0013		// 录象下载策略配置，高速下载\普通下载
#define ISIL_DEV_WATERMAKE_CFG_INFO		0x0014		// 图象水印配置
#define ISIL_DEV_WLAN_CFG				0x0015		// 无线网络配置
#define ISIL_DEV_WLAN_DEVICE_CFG		0x0016		// 搜索无线设备配置
#define ISIL_DEV_REGISTER_CFG			0x0017		// 主动注册参数配置
#define ISIL_DEV_CAMERA_CFG_INFO			0x0018		// 摄像头属性配置
#define ISIL_DEV_INFRARED_CFG 		0x0019		// 红外报警配置
#define ISIL_DEV_SNIFFER_CFG_INFO			0x001A		// Sniffer抓包配置
#define ISIL_DEV_MAIL_CFG_INFO				0x001B		// 邮件配置
#define ISIL_DEV_DNS_CFG_INFO				0x001C		// DNS服务器配置
#define ISIL_DEV_NTP_CFG_INFO				0x001D		// NTP配置
#define ISIL_DEV_AUDIO_DETECT_CFG		0x001E		// 音频检测配置
#define ISIL_DEV_STORAGE_STATION_CFG  0x001F      // 存储位置配置
#define ISIL_DEV_PTZ_OPT_CFG			0x0020		// 云台操作属性(已经废除，请使用ISIL_CLIENT_GetPtzOptAttr获取云台操作属性)
#define ISIL_DEV_DST_CFG_INFO		0x0021      // 夏令时配置
#define ISIL_DEV_ALARM_CENTER_CFG		0x0022		// 报警中心配置
#define ISIL_DEV_VIDEO_OSD_CFG        0x0023		// 视频OSD叠加配置
#define ISIL_DEV_CDMAGPRS_CFG_INFO         0x0024		// CDMA\GPRS网络配置
#define ISIL_DEV_IPFILTER_CFG         0x0025		// IP过滤配置
#define ISIL_DEV_TALK_ENCODE_CFG_INFO      0x0026      // 语音对讲编码配置
#define ISIL_DEV_RECORD_PACKET_CFG_INFO    0X0027      // 录像打包长度配置
#define ISIL_DEV_MMS_CFG_INFO              0X0028		// 短信MMS配置
#define ISIL_DEV_SMSACTIVATION_CFG_INFO	0X0029		// 短信激活无线连接配置
#define ISIL_DEV_DIALINACTIVATION_CFG_INFO	0X002A		// 拨号激活无线连接配置
#define ISIL_DEV_FILETRANS_STOP		0x002B		// 停止文件上传
#define ISIL_DEV_FILETRANS_BURN		0x002C		// 刻录文件上传
#define ISIL_DEV_SNIFFER_CFG_EX		0x0030		// 网络抓包配置
#define ISIL_DEV_DOWNLOAD_RATE_CFG	0x0031		// 下载速度限制
#define ISIL_DEV_PANORAMA_SWITCH_CFG	0x0032		// 全景切换报警配置
#define ISIL_DEV_LOST_FOCUS_CFG		0x0033		// 失去焦点报警配置
#define ISIL_DEV_ALARM_DECODE_CFG		0x0034		// 报警解码器配置
#define ISIL_DEV_VIDEOOUT_CFG         0x0035      // 视频输出参数配置
#define ISIL_DEV_POINT_CFG_INFO			0x0036		// 预制点使能配置
#define ISIL_DEV_IP_COLLISION_CFG     0x0037      // Ip冲突检测报警配置
#define ISIL_DEV_OSD_ENABLE_CFG_INFO		0x0038		// OSD叠加使能配置
#define ISIL_DEV_LOCALALARM_CFG 		0x0039		// 本地报警配置(结构体ISIL_ALARMIN_CFG_EX)
#define ISIL_DEV_NETALARM_CFG 		0x003A		// 网络报警配置(结构体ISIL_ALARMIN_CFG_EX)
#define ISIL_DEV_MOTIONALARM_CFG 		0x003B		// 动检报警配置(结构体ISIL_MOTION_DETECT_CFG_EX)
#define ISIL_DEV_VIDEOLOSTALARM_CFG 	0x003C		// 视频丢失报警配置(结构体ISIL_VIDEO_LOST_CFG_EX)
#define ISIL_DEV_BLINDALARM_CFG 		0x003D		// 视频遮挡报警配置(结构体ISIL_BLIND_CFG_EX)
#define ISIL_DEV_DISKALARM_CFG 		0x003E		// 硬盘报警配置(结构体ISIL_DISK_ALARM_CFG_EX)
#define ISIL_DEV_NETBROKENALARM_CFG 	0x003F		// 网络中断报警配置(结构体ISIL_NETBROKEN_ALARM_CFG_EX)
#define ISIL_DEV_ENCODER_CFG          0x0040      // 数字通道的前端编码器信息（混合DVR使用，结构体DEV_ENCODER_CFG）

//#define ISIL_LOCAL_SEARCH_FILE       0x07f8


// 报警类型，对应ISIL_CLIENT_StartListen接口
#define ISIL_COMM_ALARM				0x1100		// 常规报警(包括外部报警，视频丢失，动态检测)
#define ISIL_SHELTER_ALARM			0x1101		// 视频遮挡报警
#define ISIL_DISK_FULL_ALARM			0x1102		// 硬盘满报警
#define ISIL_DISK_ERROR_ALARM			0x1103		// 硬盘故障报警
#define ISIL_SOUND_DETECT_ALARM		0x1104		// 音频检测报警
#define ISIL_ALARM_DECODER_ALARM		0x1105		// 报警解码器报警

// 扩展报警类型，对应ISIL_CLIENT_StartListenEx接口
#define ISIL_ALARM_ALARM_EX			0x2101		// 外部报警
#define ISIL_MOTION_ALARM_EX			0x2102		// 动态检测报警
#define ISIL_VIDEOLOST_ALARM_EX		0x2103		// 视频丢失报警
#define ISIL_SHELTER_ALARM_EX			0x2104		// 视频遮挡报警
#define ISIL_SOUND_DETECT_ALARM_EX	0x2105		// 音频检测报警
#define ISIL_DISKFULL_ALARM_EX		0x2106		// 硬盘满报警
#define ISIL_DISKERROR_ALARM_EX		0x2107		// 坏硬盘报警
#define ISIL_ENCODER_ALARM_EX			0x210A		// 编码器报警
#define ISIL_URGENCY_ALARM_EX			0x210B		// 紧急报警
#define ISIL_WIRELESS_ALARM_EX		0x210C		// 无线报警
#define ISIL_NEW_SOUND_DETECT_ALARM_EX 0x210D		// 新音频检测报警，报警信息的结构体见ISIL_NEW_SOUND_ALARM_STATE；
#define ISIL_ALARM_DECODER_ALARM_EX	0x210E		// 报警解码器报警
#define ISIL_DECODER_DECODE_ABILITY	0x210F		// 解码器：解码能力报警
#define ISIL_FDDI_DECODER_ABILITY		0x2110		// 光纤编码器状态报警
#define ISIL_PANORAMA_SWITCH_ALARM_EX	0x2111		// 切换场景报警
#define ISIL_LOSTFOCUS_ALARM_EX		0x2112		// 失去焦点报警
#define ISIL_OEMSTATE_EX				0x2113		// oem报停状态
#define ISIL_DSP_ALARM_EX				0x2114		// DSP报警
#define ISIL_ATMPOS_BROKEN_EX			0x2115		// atm和pos机断开报警， 0：连接断开 1：连接正常

// 事件类型
#define ISIL_CONFIG_RESULT_EVENT_EX	0x3000		// 修改配置的返回码；返回结构见DEV_SET_RESULT
#define ISIL_REBOOT_EVENT_EX			0x3001		// 设备重启事件；如果未发送重启命令，当前修改的配置不会立即生效
#define ISIL_AUTO_TALK_START_EX		0x3002		// 设备主动邀请开始语音对讲
#define ISIL_AUTO_TALK_STOP_EX		0x3003		// 设备主动停止语音对讲
#define ISIL_CONFIG_CHANGE_EX			0x3004		// 设备配置发生改变

// 报警上传功能的报警类型，对应ISIL_CLIENT_StartService接口、NEW_ALARM_UPLOAD结构体.
#define ISIL_UPLOAD_ALARM				0x4000		// 外部报警
#define ISIL_UPLOAD_MOTION_ALARM		0x4001		// 动态检测报警
#define ISIL_UPLOAD_VIDEOLOST_ALARM	0x4002		// 视频丢失报警
#define ISIL_UPLOAD_SHELTER_ALARM		0x4003		// 视频遮挡报警
#define ISIL_UPLOAD_SOUND_DETECT_ALARM 0x4004		// 音频检测报警
#define ISIL_UPLOAD_DISKFULL_ALARM	0x4005		// 硬盘满报警
#define ISIL_UPLOAD_DISKERROR_ALARM	0x4006		// 坏硬盘报警
#define ISIL_UPLOAD_ENCODER_ALARM		0x4007		// 编码器报警
#define ISIL_UPLOAD_DECODER_ALARM		0x400B		// 报警解码器报警
#define ISIL_UPLOAD_EVENT				0x400C		// 定时上传的

/*供抓图以及其他API之用*/
#define MSG_SNAP_PICTURE            0x5000


// 异步接口回调类型
#define RESPONSE_DECODER_CTRL_TV	0x00000001	// 对应ISIL_CLIENT_CtrlDecTVScreen接口
#define RESPONSE_DECODER_SWITCH_TV	0x00000002	// 对应ISIL_CLIENT_SwitchDecTVEncoder接口
#define RESPONSE_DECODER_PLAYBACK	0x00000003	// 对应ISIL_CLIENT_DecTVPlayback接口

// 分辨率列表，用于与分辨率掩码进行与、或操作
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

// 编码模式列表，用于与编码模式掩码进行与、或操作
#define ISIL_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define ISIL_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define ISIL_CAPTURE_COMP_MPEG2		0x00000004
#define ISIL_CAPTURE_COMP_MPEG1		0x00000008
#define ISIL_CAPTURE_COMP_H263		0x00000010
#define ISIL_CAPTURE_COMP_MJPG		0x00000020
#define ISIL_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define ISIL_CAPTURE_COMP_H264		0x00000080

// 报警联动动作，用于与报警联动动作掩码进行与、或操作
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

// "恢复默认配置"掩码，可进行与、或操作
#define ISIL_RESTORE_COMMON			0x00000001	// 普通设置
#define ISIL_RESTORE_CODING			0x00000002	// 编码设置
#define ISIL_RESTORE_VIDEO			0x00000004	// 录像设置
#define ISIL_RESTORE_COMM				0x00000008	// 串口设置
#define ISIL_RESTORE_NETWORK			0x00000010	// 网络设置
#define ISIL_RESTORE_ALARM			0x00000020	// 报警设置
#define ISIL_RESTORE_VIDEODETECT		0x00000040	// 视频检测
#define ISIL_RESTORE_PTZ				0x00000080	// 云台控制
#define ISIL_RESTORE_OUTPUTMODE		0x00000100	// 输出模式
#define ISIL_RESTORE_CHANNELNAME		0x00000200	// 通道名称
#define ISIL_RESTORE_ALL				0x80000000	// 全部重置

// 云台属性列表
// 低四个字节掩码
#define PTZ_DIRECTION				0x00000001	// 方向
#define PTZ_ZOOM					0x00000002	// 变倍
#define PTZ_FOCUS					0x00000004	// 聚焦
#define PTZ_IRIS					0x00000008	// 光圈
#define PTZ_ALARM					0x00000010	// 报警功能
#define PTZ_LIGHT					0x00000020	// 灯光
#define PTZ_SETPRESET				0x00000040	// 设置预置点
#define PTZ_CLEARPRESET				0x00000080	// 清除预置点
#define PTZ_GOTOPRESET				0x00000100	// 转至预置点
#define PTZ_AUTOPANON				0x00000200	// 水平开始
#define PTZ_AUTOPANOFF				0x00000400	// 水平结束
#define PTZ_SETLIMIT				0x00000800	// 设置边界
#define PTZ_AUTOSCANON				0x00001000	// 自动扫描开始
#define PTZ_AUTOSCANOFF				0x00002000	// 自动扫描开停止
#define PTZ_ADDTOUR					0x00004000	// 增加巡航点
#define PTZ_DELETETOUR				0x00008000	// 删除巡航点
#define PTZ_STARTTOUR				0x00010000	// 开始巡航
#define PTZ_STOPTOUR				0x00020000	// 结束巡航
#define PTZ_CLEARTOUR				0x00040000	// 删除巡航
#define PTZ_SETPATTERN				0x00080000	// 设置模式
#define PTZ_STARTPATTERN			0x00100000	// 开始模式
#define PTZ_STOPPATTERN				0x00200000	// 停止模式
#define PTZ_CLEARPATTERN			0x00400000	// 清除模式
#define PTZ_POSITION				0x00800000	// 快速定位
#define PTZ_AUX						0x01000000	// 辅助开关
#define PTZ_MENU					0x02000000	// 球机菜单
#define PTZ_EXIT					0x04000000	// 退出球机菜单
#define PTZ_ENTER					0x08000000	// 确认
#define PTZ_ESC						0x10000000	// 取消
#define PTZ_MENUUPDOWN				0x20000000	// 菜单上下操作
#define PTZ_MENULEFTRIGHT			0x40000000	// 菜单左右操作
#define PTZ_OPT_NUM					0x80000000	// 操作的个数
// 高四个字节掩码
#define PTZ_DEV						0x00000001	// 云台控制
#define PTZ_MATRIX					0x00000002	// 矩阵控制

// 抓图视频编码类型
#define CODETYPE_MPEG4				0
#define CODETYPE_H264				1
#define CODETYPE_JPG				2

// 码流控制列表
#define ISIL_CAPTURE_BRC_CBR			0
#define ISIL_CAPTURE_BRC_VBR			1
//#define ISIL_CAPTURE_BRC_MBR		2

// 错误类型代号，对应ISIL_CLIENT_GetLastError接口的返回值
#define _ERROR_C(x)						(0x80000000|x)
#define NET_NOERROR 				0			// 没有错误
#define NET_ERROR					-1			// 未知错误
#define NET_SYSTEM_ERROR			_ERROR_C(1)		// Windows系统出错
#define NET_NETWORK_ERROR			_ERROR_C(2)		// 网络错误，可能是因为网络超时
#define NET_DEV_VER_NOMATCH			_ERROR_C(3)		// 设备协议不匹配
#define NET_INVALID_HANDLE			_ERROR_C(4)		// 句柄无效
#define NET_OPEN_CHANNEL_ERROR		_ERROR_C(5)		// 打开通道失败
#define NET_CLOSE_CHANNEL_ERROR		_ERROR_C(6)		// 关闭通道失败
#define NET_ILLEGAL_PARAM			_ERROR_C(7)		// 用户参数不合法
#define NET_SDK_INIT_ERROR			_ERROR_C(8)		// SDK初始化出错
#define NET_SDK_UNINIT_ERROR		_ERROR_C(9)		// SDK清理出错
#define NET_RENDER_OPEN_ERROR		_ERROR_C(10)		// 申请render资源出错
#define NET_DEC_OPEN_ERROR			_ERROR_C(11)		// 打开解码库出错
#define NET_DEC_CLOSE_ERROR			_ERROR_C(12)		// 关闭解码库出错
#define NET_MULTIPLAY_NOCHANNEL		_ERROR_C(13)		// 多画面预览中检测到通道数为0
#define NET_TALK_INIT_ERROR			_ERROR_C(14)		// 录音库初始化失败
#define NET_TALK_NOT_INIT			_ERROR_C(15)		// 录音库未经初始化
#define	NET_TALK_SENDDATA_ERROR		_ERROR_C(16)		// 发送音频数据出错
#define NET_REAL_ALREADY_SAVING		_ERROR_C(17)		// 实时数据已经处于保存状态
#define NET_NOT_SAVING				_ERROR_C(18)		// 未保存实时数据
#define NET_OPEN_FILE_ERROR			_ERROR_C(19)		// 打开文件出错
#define NET_PTZ_SET_TIMER_ERROR		_ERROR_C(20)		// 启动云台控制定时器失败
#define NET_RETURN_DATA_ERROR		_ERROR_C(21)		// 对返回数据的校验出错
#define NET_INSUFFICIENT_BUFFER		_ERROR_C(22)		// 没有足够的缓存
#define NET_NOT_SUPPORTED			_ERROR_C(23)		// 当前SDK未支持该功能
#define NET_NO_RECORD_FOUND			_ERROR_C(24)		// 查询不到录象
#define NET_NOT_AUTHORIZED			_ERROR_C(25)		// 无操作权限
#define NET_NOT_NOW					_ERROR_C(26)		// 暂时无法执行
#define NET_NO_TALK_CHANNEL			_ERROR_C(27)		// 未发现对讲通道
#define NET_NO_AUDIO				_ERROR_C(28)		// 未发现音频
#define NET_NO_INIT					_ERROR_C(29)		// 网络SDK未经初始化
#define NET_DOWNLOAD_END			_ERROR_C(30)		// 下载已结束
#define NET_EMPTY_LIST				_ERROR_C(31)		// 查询结果为空
#define NET_ERROR_GETCFG_SYSATTR	_ERROR_C(32)		// 获取系统属性配置失败
#define NET_ERROR_GETCFG_SERIAL		_ERROR_C(33)		// 获取序列号失败
#define NET_ERROR_GETCFG_GENERAL	_ERROR_C(34)		// 获取常规属性失败
#define NET_ERROR_GETCFG_DSPCAP		_ERROR_C(35)		// 获取DSP能力描述失败
#define NET_ERROR_GETCFG_NETCFG		_ERROR_C(36)		// 获取网络配置失败
#define NET_ERROR_GETCFG_CHANNAME	_ERROR_C(37)		// 获取通道名称失败
#define NET_ERROR_GETCFG_VIDEO		_ERROR_C(38)		// 获取视频属性失败
#define NET_ERROR_GETCFG_RECORD		_ERROR_C(39)		// 获取录象配置失败
#define NET_ERROR_GETCFG_PRONAME	_ERROR_C(40)		// 获取解码器协议名称失败
#define NET_ERROR_GETCFG_FUNCNAME	_ERROR_C(41)		// 获取232串口功能名称失败
#define NET_ERROR_GETCFG_485DECODER	_ERROR_C(42)		// 获取解码器属性失败
#define NET_ERROR_GETCFG_232COM		_ERROR_C(43)		// 获取232串口配置失败
#define NET_ERROR_GETCFG_ALARMIN	_ERROR_C(44)		// 获取外部报警输入配置失败
#define NET_ERROR_GETCFG_ALARMDET	_ERROR_C(45)		// 获取动态检测报警失败
#define NET_ERROR_GETCFG_SYSTIME	_ERROR_C(46)		// 获取设备时间失败
#define NET_ERROR_GETCFG_PREVIEW	_ERROR_C(47)		// 获取预览参数失败
#define NET_ERROR_GETCFG_AUTOMT		_ERROR_C(48)		// 获取自动维护配置失败
#define NET_ERROR_GETCFG_VIDEOMTRX	_ERROR_C(49)		// 获取视频矩阵配置失败
#define NET_ERROR_GETCFG_COVER		_ERROR_C(50)		// 获取区域遮挡配置失败
#define NET_ERROR_GETCFG_WATERMAKE	_ERROR_C(51)		// 获取图象水印配置失败
#define NET_ERROR_SETCFG_GENERAL	_ERROR_C(55)		// 修改常规属性失败
#define NET_ERROR_SETCFG_NETCFG		_ERROR_C(56)		// 修改网络配置失败
#define NET_ERROR_SETCFG_CHANNAME	_ERROR_C(57)		// 修改通道名称失败
#define NET_ERROR_SETCFG_VIDEO		_ERROR_C(58)		// 修改视频属性失败
#define NET_ERROR_SETCFG_RECORD		_ERROR_C(59)		// 修改录象配置失败
#define NET_ERROR_SETCFG_485DECODER	_ERROR_C(60)		// 修改解码器属性失败
#define NET_ERROR_SETCFG_232COM		_ERROR_C(61)		// 修改232串口配置失败
#define NET_ERROR_SETCFG_ALARMIN	_ERROR_C(62)		// 修改外部输入报警配置失败
#define NET_ERROR_SETCFG_ALARMDET	_ERROR_C(63)		// 修改动态检测报警配置失败
#define NET_ERROR_SETCFG_SYSTIME	_ERROR_C(64)		// 修改设备时间失败
#define NET_ERROR_SETCFG_PREVIEW	_ERROR_C(65)		// 修改预览参数失败
#define NET_ERROR_SETCFG_AUTOMT		_ERROR_C(66)		// 修改自动维护配置失败
#define NET_ERROR_SETCFG_VIDEOMTRX	_ERROR_C(67)		// 修改视频矩阵配置失败
#define NET_ERROR_SETCFG_COVER		_ERROR_C(68)		// 修改区域遮挡配置失败
#define NET_ERROR_SETCFG_WATERMAKE	_ERROR_C(69)		// 修改图象水印配置失败
#define NET_ERROR_SETCFG_WLAN		_ERROR_C(70)		// 修改无线网络信息失败
#define NET_ERROR_SETCFG_WLANDEV	_ERROR_C(71)		// 选择无线网络设备失败
#define NET_ERROR_SETCFG_REGISTER	_ERROR_C(72)		// 修改主动注册参数配置失败
#define NET_ERROR_SETCFG_CAMERA		_ERROR_C(73)		// 修改摄像头属性配置失败
#define NET_ERROR_SETCFG_INFRARED	_ERROR_C(74)		// 修改红外报警配置失败
#define NET_ERROR_SETCFG_SOUNDALARM	_ERROR_C(75)		// 修改音频报警配置失败
#define NET_ERROR_SETCFG_STORAGE    _ERROR_C(76)		// 修改存储位置配置失败
#define NET_AUDIOENCODE_NOTINIT		_ERROR_C(77)		// 音频编码接口没有成功初始化
#define NET_DATA_TOOLONGH			_ERROR_C(78)		// 数据过长
#define NET_UNSUPPORTED				_ERROR_C(79)		// 设备不支持该操作
#define NET_DEVICE_BUSY				_ERROR_C(80)		// 设备资源不足
#define NET_SERVER_STARTED			_ERROR_C(81)		// 服务器已经启动
#define NET_SERVER_STOPPED			_ERROR_C(82)		// 服务器尚未成功启动
#define NET_LISTER_INCORRECT_SERIAL	_ERROR_C(83)		// 输入序列号有误
#define NET_QUERY_DISKINFO_FAILED	_ERROR_C(84)		// 获取硬盘信息失败
#define NET_ERROR_GETCFG_SESSION	_ERROR_C(85)		// 获取连接Session信息
#define NET_LOGIN_ERROR_PASSWORD	_ERROR_C(100)	// 密码不正确
#define NET_LOGIN_ERROR_USER		_ERROR_C(101)	// 帐户不存在
#define NET_LOGIN_ERROR_TIMEOUT		_ERROR_C(102)	// 等待登录返回超时
#define NET_LOGIN_ERROR_RELOGGIN	_ERROR_C(103)	// 帐号已登录
#define NET_LOGIN_ERROR_LOCKED		_ERROR_C(104)	// 帐号已被锁定
#define NET_LOGIN_ERROR_BLACKLIST	_ERROR_C(105)	// 帐号已被列为黑名单
#define NET_LOGIN_ERROR_BUSY		_ERROR_C(106)	// 资源不足，系统忙
#define NET_LOGIN_ERROR_CONNECT		_ERROR_C(107)	// 登录设备超时，请检查网络并重试
#define NET_LOGIN_ERROR_NETWORK		_ERROR_C(108)	// 网络连接失败
#define NET_LOGIN_ERROR_SUBCONNECT	_ERROR_C(109)	// 登录设备成功，但无法创建视频通道，请检查网络状况
#define NET_RENDER_SOUND_ON_ERROR	_ERROR_C(120)	// Render库打开音频出错
#define NET_RENDER_SOUND_OFF_ERROR	_ERROR_C(121)	// Render库关闭音频出错
#define NET_RENDER_SET_VOLUME_ERROR	_ERROR_C(122)	// Render库控制音量出错
#define NET_RENDER_ADJUST_ERROR		_ERROR_C(123)	// Render库设置画面参数出错
#define NET_RENDER_PAUSE_ERROR		_ERROR_C(124)	// Render库暂停播放出错
#define NET_RENDER_SNAP_ERROR		_ERROR_C(125)	// Render库抓图出错
#define NET_RENDER_STEP_ERROR		_ERROR_C(126)	// Render库步进出错
#define NET_RENDER_FRAMERATE_ERROR	_ERROR_C(127)	// Render库设置帧率出错
#define NET_GROUP_EXIST				_ERROR_C(140)	// 组名已存在
#define	NET_GROUP_NOEXIST			_ERROR_C(141)	// 组名不存在
#define NET_GROUP_RIGHTOVER			_ERROR_C(142)	// 组的权限超出权限列表范围
#define NET_GROUP_HAVEUSER			_ERROR_C(143)	// 组下有用户，不能删除
#define NET_GROUP_RIGHTUSE			_ERROR_C(144)	// 组的某个权限被用户使用，不能出除
#define NET_GROUP_SAMENAME			_ERROR_C(145)	// 新组名同已有组名重复
#define	NET_USER_EXIST				_ERROR_C(146)	// 用户已存在
#define NET_USER_NOEXIST			_ERROR_C(147)	// 用户不存在
#define NET_USER_RIGHTOVER			_ERROR_C(148)	// 用户权限超出组权限
#define NET_USER_PWD				_ERROR_C(149)	// 保留帐号，不容许修改密码
#define NET_USER_FLASEPWD			_ERROR_C(150)	// 密码不正确
#define NET_USER_NOMATCHING			_ERROR_C(151)	// 密码不匹配
#define NET_ERROR_GETCFG_ETHERNET	_ERROR_C(300)	// 获取网卡配置失败
#define NET_ERROR_GETCFG_WLAN		_ERROR_C(301)	// 获取无线网络信息失败
#define NET_ERROR_GETCFG_WLANDEV	_ERROR_C(302)	// 获取无线网络设备失败
#define NET_ERROR_GETCFG_REGISTER	_ERROR_C(303)	// 获取主动注册参数失败
#define NET_ERROR_GETCFG_CAMERA		_ERROR_C(304)	// 获取摄像头属性失败
#define NET_ERROR_GETCFG_INFRARED	_ERROR_C(305)	// 获取红外报警配置失败
#define NET_ERROR_GETCFG_SOUNDALARM	_ERROR_C(306)	// 获取音频报警配置失败
#define NET_ERROR_GETCFG_STORAGE    _ERROR_C(307)	// 获取存储位置配置失败
#define NET_ERROR_GETCFG_MAIL		_ERROR_C(308)	// 获取邮件配置失败
#define NET_CONFIG_DEVBUSY			_ERROR_C(309)	// 暂时无法设置
#define NET_CONFIG_DATAILLEGAL		_ERROR_C(310)	// 配置数据不合法
#define NET_ERROR_GETCFG_DST        _ERROR_C(311)    // 获取夏令时配置失败
#define NET_ERROR_SETCFG_DST        _ERROR_C(312)    // 设置夏令时配置失败
#define NET_ERROR_GETCFG_VIDEO_OSD  _ERROR_C(313)    // 获取视频OSD叠加配置失败
#define NET_ERROR_SETCFG_VIDEO_OSD  _ERROR_C(314)    // 设置视频OSD叠加配置失败
#define NET_ERROR_GETCFG_GPRSCDMA   _ERROR_C(315)    // 获取CDMA\GPRS网络配置失败
#define NET_ERROR_SETCFG_GPRSCDMA   _ERROR_C(316)    // 设置CDMA\GPRS网络配置失败
#define NET_ERROR_GETCFG_IPFILTER   _ERROR_C(317)    // 获取IP过滤配置失败
#define NET_ERROR_SETCFG_IPFILTER   _ERROR_C(318)    // 设置IP过滤配置失败
#define NET_ERROR_GETCFG_TALKENCODE _ERROR_C(319)    // 获取语音对讲编码配置失败
#define NET_ERROR_SETCFG_TALKENCODE _ERROR_C(320)    // 设置语音对讲编码配置失败
#define NET_ERROR_GETCFG_RECORDLEN  _ERROR_C(321)    // 获取录像打包长度配置失败
#define NET_ERROR_SETCFG_RECORDLEN  _ERROR_C(322)    // 设置录像打包长度配置失败
#define	NET_DONT_SUPPORT_SUBAREA	_ERROR_C(323)	// 不支持网络硬盘分区
#define	NET_ERROR_GET_AUTOREGSERVER	_ERROR_C(324)	// 获取设备上主动注册服务器信息失败
#define	NET_ERROR_CONTROL_AUTOREGISTER		_ERROR_C(325)	// 主动注册重定向注册错误
#define	NET_ERROR_DISCONNECT_AUTOREGISTER	_ERROR_C(326)	// 断开主动注册服务器错误
#define NET_ERROR_GETCFG_MMS				_ERROR_C(327)	// 获取mms配置失败
#define NET_ERROR_SETCFG_MMS				_ERROR_C(328)	// 设置mms配置失败
#define NET_ERROR_GETCFG_SMSACTIVATION      _ERROR_C(329)	// 获取短信激活无线连接配置失败
#define NET_ERROR_SETCFG_SMSACTIVATION      _ERROR_C(330)	// 设置短信激活无线连接配置失败
#define NET_ERROR_GETCFG_DIALINACTIVATION	_ERROR_C(331)	// 获取拨号激活无线连接配置失败
#define NET_ERROR_SETCFG_DIALINACTIVATION	_ERROR_C(332)	// 设置拨号激活无线连接配置失败
#define NET_ERROR_GETCFG_VIDEOOUT           _ERROR_C(333)    // 查询视频输出参数配置失败
#define NET_ERROR_SETCFG_VIDEOOUT			_ERROR_C(334)	// 设置视频输出参数配置失败
#define NET_ERROR_GETCFG_OSDENABLE			_ERROR_C(335)	// 获取osd叠加使能配置失败
#define NET_ERROR_SETCFG_OSDENABLE			_ERROR_C(336)	// 设置osd叠加使能配置失败
#define NET_ERROR_SETCFG_ENCODERINFO        _ERROR_C(337)    // 设置数字通道前端编码接入配置失败

#define NET_ERROR_CONNECT_FAILED			_ERROR_C(340)	// 请求建立连接失败
#define NET_ERROR_SETCFG_BURNFILE			_ERROR_C(341)	// 请求刻录文件上传失败
#define NET_ERROR_SNIFFER_GETCFG			_ERROR_C(342)	// 获取抓包配置信息失败
#define NET_ERROR_SNIFFER_SETCFG			_ERROR_C(343)	// 设置抓包配置信息失败
#define NET_ERROR_DOWNLOADRATE_GETCFG		_ERROR_C(344)	// 查询下载限制信息失败
#define NET_ERROR_DOWNLOADRATE_SETCFG		_ERROR_C(345)	// 设置下载限制信息失败
#define NET_ERROR_SEARCH_TRANSCOM			_ERROR_C(346)	// 查询串口参数失败
#define NET_ERROR_GETCFG_POINT				_ERROR_C(347)	// 获取预制点信息错误
#define NET_ERROR_SETCFG_POINT				_ERROR_C(348)	// 设置预制点信息错误
#define NET_SDK_LOGOUT_ERROR				_ERROR_C(349)    // SDK没有正常登出设备


/************************************************************************
 ** 枚举定义
 ***********************************************************************/
// 设备类型
enum NET_DEVICE_TYPE
{
	NET_PRODUCT_NONE = 0,
	NET_DVR_NONREALTIME_MACE,					// 非实时MACE
	NET_DVR_NONREALTIME,						// 非实时
	NET_NVS_MPEG1,								// 网络视频服务器
	NET_DVR_MPEG1_2,							// MPEG1二路录像机
	NET_DVR_MPEG1_8,							// MPEG1八路录像机
	NET_DVR_MPEG4_8,							// MPEG4八路录像机
	NET_DVR_MPEG4_16,							// MPEG4十六路录像机
	NET_DVR_MPEG4_SX2,							// LB系列录像机
	NET_DVR_MEPG4_ST2,							// GB系列录像机
	NET_DVR_MEPG4_SH2,							// HB系列录像机
	NET_DVR_MPEG4_GBE,							// GBE系列录像机
	NET_DVR_MPEG4_NVSII,						// II代网络视频服务器
	NET_DVR_STD_NEW,							// 新标准配置协议
	NET_DVR_DDNS,								// DDNS服务器
	NET_DVR_ATM,								// ATM机
	NET_NB_SERIAL,								// 二代非实时NB系列机器
	NET_LN_SERIAL,								// LN系列产品
	NET_BAV_SERIAL,								// BAV系列产品
	NET_SDIP_SERIAL,							// SDIP系列产品
	NET_IPC_SERIAL,								// IPC系列产品
	NET_NVS_B,									// NVS B系列
	NET_NVS_C,									// NVS H系列
	NET_NVS_S,									// NVS S系列
	NET_NVS_E,									// NVS E系列
	NET_DVR_NEW_PROTOCOL,						// 从QueryDevState中查询设备类型,以字符串格式
	NET_NVD_SERIAL,								// 解码器
	NET_DVR_N5,									// N5
	NET_DVR_MIX_DVR,							// 混合DVR
	NET_SVR_SERIAL,								// SVR系列
	NET_SVR_BS,									// SVR-BS
};

// 语言种类
typedef enum __LANGUAGE_TYPE
{
	ISIL_LANGUAGE_ENGLISH,						// 英文
	ISIL_LANGUAGE_CHINESE_SIMPLIFIED,				// 简体中文
	ISIL_LANGUAGE_CHINESE_TRADITIONAL,			// 繁体中文
	ISIL_LANGUAGE_ITALIAN,						// 意大利文
	ISIL_LANGUAGE_SPANISH,						// 西班牙文
	ISIL_LANGUAGE_JAPANESE,						// 日文版
	ISIL_LANGUAGE_RUSSIAN,						// 俄文版
	ISIL_LANGUAGE_FRENCH,							// 法文版
	ISIL_LANGUAGE_GERMAN, 						// 德文版
	ISIL_LANGUAGE_PORTUGUESE,						// 葡萄牙语
	ISIL_LANGUAGE_TURKEY,							// 土尔其语
	ISIL_LANGUAGE_POLISH,							// 波兰语
	ISIL_LANGUAGE_ROMANIAN,						// 罗马尼亚
	ISIL_LANGUAGE_HUNGARIAN,						// 匈牙利语
	ISIL_LANGUAGE_FINNISH,						// 芬兰语
	ISIL_LANGUAGE_ESTONIAN,						// 爱沙尼亚语
	ISIL_LANGUAGE_KOREAN,							// 韩语
	ISIL_LANGUAGE_FARSI,							// 波斯语
	ISIL_LANGUAGE_DANSK,							// 丹麦语
	ISIL_LANGUAGE_CZECHISH,						// 捷克文
	ISIL_LANGUAGE_BULGARIA,						// 保加利亚文
	ISIL_LANGUAGE_SLOVAKIAN,						// 斯洛伐克语
	ISIL_LANGUAGE_SLOVENIA,						// 斯洛文尼亚文
	ISIL_LANGUAGE_CROATIAN,						// 克罗地亚语
	ISIL_LANGUAGE_DUTCH,							// 荷兰语
	ISIL_LANGUAGE_GREEK,							// 希腊语
	ISIL_LANGUAGE_UKRAINIAN,						// 乌克兰语
	ISIL_LANGUAGE_SWEDISH,						// 瑞典语
	ISIL_LANGUAGE_SERBIAN,						// 塞尔维亚语
	ISIL_LANGUAGE_VIETNAMESE,						// 越南语
	ISIL_LANGUAGE_LITHUANIAN,						// 立陶宛语
	ISIL_LANGUAGE_FILIPINO,						// 菲律宾语
	ISIL_LANGUAGE_ARABIC,							// 阿拉伯语
	ISIL_LANGUAGE_CATALAN,						// 加泰罗尼亚语
	ISIL_LANGUAGE_LATVIAN,						// 拉脱维亚语
	ISIL_LANGUAGE_THAI,							// 泰语
} ISIL_LANGUAGE_TYPE;

// 升级类型
typedef enum __EM_UPGRADE_TYPE
{
	ISIL_UPGRADE_BIOS_TYPE = 1,					// BIOS升级
	ISIL_UPGRADE_WEB_TYPE,						// WEB升级
	ISIL_UPGRADE_BOOT_YPE,						// BOOT升级
	ISIL_UPGRADE_CHARACTER_TYPE,					// 汉字库
	ISIL_UPGRADE_LOGO_TYPE,						// LOGO
	ISIL_UPGRADE_EXE_TYPE,						// EXE，例如播放器等
} EM_UPGRADE_TYPE;

// 录象类型(定时、动态检测、报警)
typedef enum __REC_TYPE
{
	ISIL_REC_TYPE_TIM = 0,
	ISIL_REC_TYPE_MTD,
	ISIL_REC_TYPE_ALM,
	ISIL_REC_TYPE_NUM,
} REC_TYPE;


// 网络类型
typedef enum __GPRSCDMA_NETWORK_TYPE
{
	ISIL_TYPE_AUTOSEL = 0,						// 自动选择
	ISIL_TYPE_TD_SCDMA,							// TD-SCDMA网络
	ISIL_TYPE_WCDMA,								// WCDMA网络
	ISIL_TYPE_CDMA_1x,							// CDMA 1.x网络
	ISIL_TYPE_EDGE,								// GPRS网络
	ISIL_TYPE_EVDO,								// EVDO网络
	ISIL_TYPE_WIFI,								// 无线
} EM_GPRSCDMA_NETWORK_TYPE;

// 接口类型，对应ISIL_CLIENT_SetSubconnCallBack接口
typedef enum __EM_INTERFACE_TYPE
{
	ISIL_INTERFACE_OTHER = 0x00000000,			// 未知接口
	ISIL_INTERFACE_REALPLAY,						// 实时监视接口
	ISIL_INTERFACE_PREVIEW,						// 多画面预览接口
	ISIL_INTERFACE_PLAYBACK,						// 回放接口
	ISIL_INTERFACE_DOWNLOAD,						// 下载接口
} EM_INTERFACE_TYPE;


/////////////////////////////////监视相关/////////////////////////////////

// 预览类型，对应ISIL_CLIENT_RealPlayEx接口
typedef enum _RealPlayType
{
	ISIL_RType_Realplay = 0,						// 实时预览
	ISIL_RType_Multiplay,							// 多画面预览

	ISIL_RType_Realplay_0,						// 实时监视-主码流，等同于ISIL_RType_Realplay
	ISIL_RType_Realplay_1,						// 实时监视-从码流1
	ISIL_RType_Realplay_2,						// 实时监视-从码流2
	ISIL_RType_Realplay_3,						// 实时监视-从码流3

	ISIL_RType_Multiplay_1,						// 多画面预览－1画面
	ISIL_RType_Multiplay_4,						// 多画面预览－4画面
	ISIL_RType_Multiplay_8,						// 多画面预览－8画面
	ISIL_RType_Multiplay_9,						// 多画面预览－9画面
	ISIL_RType_Multiplay_16,						// 多画面预览－16画面
	ISIL_RType_Multiplay_6,						// 多画面预览－6画面
	ISIL_RType_Multiplay_12,						// 多画面预览－12画面
} ISIL_RealPlayType;

/////////////////////////////////云台相关/////////////////////////////////

// 通用云台控制命令
typedef enum _PTZ_ControlType
{
	ISIL_PTZ_UP_CONTROL = 0,						// 上
	ISIL_PTZ_DOWN_CONTROL,						// 下
	ISIL_PTZ_LEFT_CONTROL,						// 左
	ISIL_PTZ_RIGHT_CONTROL,						// 右
	ISIL_PTZ_ZOOM_ADD_CONTROL,					// 变倍+
	ISIL_PTZ_ZOOM_DEC_CONTROL,					// 变倍-
	ISIL_PTZ_FOCUS_ADD_CONTROL,					// 调焦+
	ISIL_PTZ_FOCUS_DEC_CONTROL,					// 调焦-
	ISIL_PTZ_APERTURE_ADD_CONTROL,				// 光圈+
	ISIL_PTZ_APERTURE_DEC_CONTROL,				// 光圈-
    ISIL_PTZ_POINT_MOVE_CONTROL,					// 转至预置点
    ISIL_PTZ_POINT_SET_CONTROL,					// 设置
    ISIL_PTZ_POINT_DEL_CONTROL,					// 删除
    ISIL_PTZ_POINT_LOOP_CONTROL,					// 点间巡航
    ISIL_PTZ_LAMP_CONTROL							// 灯光雨刷
} ISIL_PTZ_ControlType;

// 云台控制扩展命令
typedef enum _EXTPTZ_ControlType
{
	ISIL_EXTPTZ_LEFTTOP = 0x20,					// 左上
	ISIL_EXTPTZ_RIGHTTOP,							// 右上
	ISIL_EXTPTZ_LEFTDOWN,							// 左下
	ISIL_EXTPTZ_RIGHTDOWN,						// 右下
	ISIL_EXTPTZ_ADDTOLOOP,						// 加入预置点到巡航 巡航线路 预置点值
	ISIL_EXTPTZ_DELFROMLOOP,						// 删除巡航中预置点 巡航线路 预置点值
    ISIL_EXTPTZ_CLOSELOOP,						// 清除巡航 巡航线路
	ISIL_EXTPTZ_STARTPANCRUISE,					// 开始水平旋转
	ISIL_EXTPTZ_STOPPANCRUISE,					// 停止水平旋转
	ISIL_EXTPTZ_SETLEFTBORDER,					// 设置左边界
	ISIL_EXTPTZ_SETRIGHTBORDER,					// 设置右边界
	ISIL_EXTPTZ_STARTLINESCAN,					// 开始线扫
    ISIL_EXTPTZ_CLOSELINESCAN,					// 停止线扫
    ISIL_EXTPTZ_SETMODESTART,						// 设置模式开始	模式线路
    ISIL_EXTPTZ_SETMODESTOP,						// 设置模式结束	模式线路
	ISIL_EXTPTZ_RUNMODE,							// 运行模式	模式线路
	ISIL_EXTPTZ_STOPMODE,							// 停止模式	模式线路
	ISIL_EXTPTZ_DELETEMODE,						// 清除模式	模式线路
	ISIL_EXTPTZ_REVERSECOMM,						// 翻转命令
	ISIL_EXTPTZ_FASTGOTO,							// 快速定位 水平坐标(8192) 垂直坐标(8192) 变倍(4)
	ISIL_EXTPTZ_AUXIOPEN,							// 辅助开关开 辅助点
	ISIL_EXTPTZ_AUXICLOSE,						// 辅助开关关 辅助点
	ISIL_EXTPTZ_OPENMENU = 0x36,					// 打开球机菜单
	ISIL_EXTPTZ_CLOSEMENU,						// 关闭菜单
	ISIL_EXTPTZ_MENUOK,							// 菜单确定
	ISIL_EXTPTZ_MENUCANCEL,						// 菜单取消
	ISIL_EXTPTZ_MENUUP,							// 菜单上
	ISIL_EXTPTZ_MENUDOWN,							// 菜单下
	ISIL_EXTPTZ_MENULEFT,							// 菜单左
	ISIL_EXTPTZ_MENURIGHT,						// 菜单右
	ISIL_EXTPTZ_ALARMHANDLE = 0x40,				// 报警联动云台 parm1：报警输入通道；parm2：报警联动类型1-预置点2-线扫3-巡航；parm3：联动值，如预置点号
	ISIL_EXTPTZ_MATRIXSWITCH = 0x41,				// 矩阵切换 parm1：监视器号(视频输出号)；parm2：视频输入号；parm3：矩阵号
	ISIL_EXTPTZ_LIGHTCONTROL,						// 灯光控制器
	ISIL_EXTPTZ_UP_TELE = 0x70,					// 上 + TELE param1=速度(1-8)，下同
	ISIL_EXTPTZ_DOWN_TELE,						// 下 + TELE
	ISIL_EXTPTZ_LEFT_TELE,						// 左 + TELE
	ISIL_EXTPTZ_RIGHT_TELE,						// 右 + TELE
	ISIL_EXTPTZ_LEFTUP_TELE,						// 左上 + TELE
	ISIL_EXTPTZ_LEFTDOWN_TELE,					// 左下 + TELE
	ISIL_EXTPTZ_TIGHTUP_TELE,						// 右上 + TELE
	ISIL_EXTPTZ_RIGHTDOWN_TELE,					// 右下 + TELE
	ISIL_EXTPTZ_UP_WIDE,							// 上 + WIDE param1=速度(1-8)，下同
	ISIL_EXTPTZ_DOWN_WIDE,						// 下 + WIDE
	ISIL_EXTPTZ_LEFT_WIDE,						// 左 + WIDE
	ISIL_EXTPTZ_RIGHT_WIDE,						// 右 + WIDE
	ISIL_EXTPTZ_LEFTUP_WIDE,						// 左上 + WIDE
	ISIL_EXTPTZ_LEFTDOWN_WIDE,					// 左下 + WIDE
	ISIL_EXTPTZ_TIGHTUP_WIDE,						// 右上 + WIDE
	ISIL_EXTPTZ_RIGHTDOWN_WIDE,					// 右下 + WIDE
	ISIL_EXTPTZ_TOTAL,							// 最大命令值
} ISIL_EXTPTZ_ControlType;

/////////////////////////////////日志相关/////////////////////////////////

// 日志查询类型
typedef enum _ISIL_LOG_QUERY_TYPE
{
	ISIL_LOG_ALL = 0,								// 所有日志
	ISIL_LOG_SYSTEM,								// 系统日志
	ISIL_LOG_CONFIG,								// 配置日志
	ISIL_LOG_STORAGE,								// 存储相关
	ISIL_LOG_ALARM,								// 报警日志
	ISIL_LOG_RECORD,								// 录象相关
	ISIL_LOG_ACCOUNT,								// 帐号相关
	ISIL_LOG_QCLEAR,								// 清除日志
	ISIL_LOG_QPLAYBACK								// 回放相关
} ISIL_LOG_QUERY_TYPE;

// 日志类型
typedef enum _ISIL_LOG_TYPE
{
	ISIL_LOG_REBOOT = 0x0000,						// 设备重启
	ISIL_LOG_SHUT,								// 设备关机
	ISIL_LOG_CONFSAVE = 0x0100,					// 保存配置
	ISIL_LOG_CONFLOAD,							// 读取配置
	ISIL_LOG_FSERROR = 0x0200,					// 文件系统错误
	ISIL_LOG_HDD_WERR,							// 硬盘写错误
	ISIL_LOG_HDD_RERR,							// 硬盘读错误
	ISIL_LOG_HDD_TYPE,							// 设置硬盘类型
	ISIL_LOG_HDD_FORMAT,							// 格式化硬盘
	ISIL_LOG_HDD_NOSPACE,							// 当前工作盘空间不足
	ISIL_LOG_HDD_TYPE_RW,							// 设置硬盘类型为读写盘
	ISIL_LOG_HDD_TYPE_RO,							// 设置硬盘类型为只读盘
	ISIL_LOG_HDD_TYPE_RE,							// 设置硬盘类型为冗余盘
	ISIL_LOG_HDD_TYPE_SS,							// 设置硬盘类型为快照盘
	ISIL_LOG_HDD_NONE,							// 无硬盘记录日志
	ISIL_LOG_ALM_IN = 0x0300,						// 外部输入报警开始
	ISIL_LOG_NETALM_IN,							// 网络报警输入
	ISIL_LOG_ALM_END = 0x0302,					// 外部输入报警停止
	ISIL_LOG_LOSS_IN,								// 视频丢失报警开始
	ISIL_LOG_LOSS_END,							// 视频丢失报警结束
	ISIL_LOG_MOTION_IN,							// 动态检测报警开始
	ISIL_LOG_MOTION_END,							// 动态检测报警结束
	ISIL_LOG_ALM_BOSHI,							// 报警器报警输入
	ISIL_LOG_NET_ABORT = 0x0308,					// 网络断开
	ISIL_LOG_NET_ABORT_RESUME,					// 网络恢复
	ISIL_LOG_CODER_BREAKDOWN,						// 编码器故障
	ISIL_LOG_CODER_BREAKDOWN_RESUME,				// 编码器故障恢复
	ISIL_LOG_BLIND_IN,							// 视频遮挡
	ISIL_LOG_BLIND_END,							// 视频遮挡恢复
	ISIL_LOG_ALM_TEMP_HIGH,						// 温度过高
	ISIL_LOG_ALM_VOLTAGE_LOW,						// 电压过低
	ISIL_LOG_ALM_BATTERY_LOW,						// 电池容量不足
	ISIL_LOG_ALM_ACC_BREAK,						// ACC断电
	ISIL_LOG_INFRAREDALM_IN = 0x03a0,				// 无线报警开始
	ISIL_LOG_INFRAREDALM_END,						// 无线报警结束
	ISIL_LOG_IPCONFLICT,							// IP冲突
	ISIL_LOG_IPCONFLICT_RESUME,					// IP恢复
	ISIL_LOG_SDPLUG_IN,							// SD卡插入
	ISIL_LOG_SDPLUG_OUT,							// SD卡拔出
	ISIL_LOG_NET_PORT_BIND_FAILED,				// 网络端口绑定失败
	ISIL_LOG_AUTOMATIC_RECORD = 0x0400,			// 自动录像
	ISIL_LOG_MANUAL_RECORD = 0x0401,				// 手动录象
	ISIL_LOG_CLOSED_RECORD,						// 停止录象
	ISIL_LOG_LOGIN = 0x0500,						// 登录
	ISIL_LOG_LOGOUT,								// 注销
	ISIL_LOG_ADD_USER,							// 添加用户
	ISIL_LOG_DELETE_USER,							// 删除用户
	ISIL_LOG_MODIFY_USER,							// 修改用户
	ISIL_LOG_ADD_GROUP,							// 添加用户组
	ISIL_LOG_DELETE_GROUP,						// 删除用户组
	ISIL_LOG_MODIFY_GROUP,						// 修改用户组
	ISIL_LOG_CLEAR = 0x0600,						// 清除日志
	ISIL_LOG_SEARCHLOG,							// 查询日志
	ISIL_LOG_SEARCH = 0x0700,						// 录像查询
	ISIL_LOG_DOWNLOAD,							// 录像下载
	ISIL_LOG_PLAYBACK,							// 录像回放
	ISIL_LOG_BACKUP,								// 备份录像文件
	ISIL_LOG_BACKUPERROR,							// 备份录像文件失败

	ISIL_LOG_TYPE_NR = 7,
} ISIL_LOG_TYPE;

// 扩展日志类型，对应ISIL_CLIENT_QueryLogEx接口，条件(int nType = 1；参数reserved = &nType)
typedef enum _ISIL_NEWLOG_TYPE
{
	ISIL_NEWLOG_REBOOT = 0x0000,					// 设备重启
	ISIL_NEWLOG_SHUT,								// 设备关机
	ISIL_NEWLOG_CONFSAVE = 0x0100,				// 保存配置
	ISIL_NEWLOG_CONFLOAD,							// 读取配置
	ISIL_NEWLOG_FSERROR = 0x0200,					// 文件系统错误
	ISIL_NEWLOG_HDD_WERR,							// 硬盘写错误
	ISIL_NEWLOG_HDD_RERR,							// 硬盘读错误
	ISIL_NEWLOG_HDD_TYPE,							// 设置硬盘类型
	ISIL_NEWLOG_HDD_FORMAT,						// 格式化硬盘
	ISIL_NEWLOG_HDD_NOSPACE,						// 当前工作盘空间不足
	ISIL_NEWLOG_HDD_TYPE_RW,						// 设置硬盘类型为读写盘
	ISIL_NEWLOG_HDD_TYPE_RO,						// 设置硬盘类型为只读盘
	ISIL_NEWLOG_HDD_TYPE_RE,						// 设置硬盘类型为冗余盘
	ISIL_NEWLOG_HDD_TYPE_SS,						// 设置硬盘类型为快照盘
	ISIL_NEWLOG_HDD_NONE,							// 无硬盘记录日志
	ISIL_NEWLOG_ALM_IN = 0x0300,					// 外部输入报警开始
	ISIL_NEWLOG_NETALM_IN,						// 网络报警
	ISIL_NEWLOG_ALM_END,							// 外部输入报警停止
	ISIL_NEWLOG_LOSS_IN,							// 视频丢失报警开始
	ISIL_NEWLOG_LOSS_END,							// 视频丢失报警结束
	ISIL_NEWLOG_MOTION_IN,						// 动态检测报警开始
	ISIL_NEWLOG_MOTION_END,						// 动态检测报警结束
	ISIL_NEWLOG_ALM_BOSHI,						// 报警器报警输入
	ISIL_NEWLOG_NET_ABORT = 0x0308,				// 网络断开
	ISIL_NEWLOG_NET_ABORT_RESUME,					// 网络恢复
	ISIL_NEWLOG_CODER_BREAKDOWN,					// 编码器故障
	ISIL_NEWLOG_CODER_BREAKDOWN_RESUME,			// 编码器故障恢复
	ISIL_NEWLOG_BLIND_IN,							// 视频遮挡
	ISIL_NEWLOG_BLIND_END,						// 视频遮挡恢复
	ISIL_NEWLOG_ALM_TEMP_HIGH,					// 温度过高
	ISIL_NEWLOG_ALM_VOLTAGE_LOW,					// 电压过低
	ISIL_NEWLOG_ALM_BATTERY_LOW,					// 电池容量不足
	ISIL_NEWLOG_ALM_ACC_BREAK,					// ACC断电
	ISIL_NEWLOG_INFRAREDALM_IN = 0x03a0,			// 无线报警开始
	ISIL_NEWLOG_INFRAREDALM_END,					// 无线报警结束
	ISIL_NEWLOG_IPCONFLICT,						// IP冲突
	ISIL_NEWLOG_IPCONFLICT_RESUME,				// IP恢复
	ISIL_NEWLOG_SDPLUG_IN,						// SD卡插入
	ISIL_NEWLOG_SDPLUG_OUT,						// SD卡拔出
	ISIL_NEWLOG_NET_PORT_BIND_FAILED,				// 网络端口绑定失败
	ISIL_NEWLOG_AUTOMATIC_RECORD = 0x0400,		// 自动录象
	ISIL_NEWLOG_MANUAL_RECORD,					// 手动录象开
	ISIL_NEWLOG_CLOSED_RECORD,					// 停止录象
	ISIL_NEWLOG_LOGIN = 0x0500,					// 登录
	ISIL_NEWLOG_LOGOUT,							// 注销
	ISIL_NEWLOG_ADD_USER,							// 添加用户
	ISIL_NEWLOG_DELETE_USER,						// 删除用户
	ISIL_NEWLOG_MODIFY_USER,						// 修改用户
	ISIL_NEWLOG_ADD_GROUP,						// 添加用户组
	ISIL_NEWLOG_DELETE_GROUP,						// 删除用户组
	ISIL_NEWLOG_MODIFY_GROUP,						// 修改用户组
	ISIL_NEWLOG_CLEAR = 0x0600,					// 清除日志
	ISIL_NEWLOG_SEARCHLOG,						// 查询日志
	ISIL_NEWLOG_SEARCH = 0x0700,					// 录像查询
	ISIL_NEWLOG_DOWNLOAD,							// 录像下载
	ISIL_NEWLOG_PLAYBACK,							// 录像回放
	ISIL_NEWLOG_BACKUP,							// 备份录像文件
	ISIL_NEWLOG_BACKUPERROR,						// 备份录像文件失败

	ISIL_NEWLOG_TYPE_NR = 8,
} ISIL_NEWLOG_TYPE;

///////////////////////////////语音对讲相关///////////////////////////////

// 语音编码类型
typedef enum __TALK_CODING_TYPE
{
	ISIL_TALK_DEFAULT = 0,						// 无头PCM
	ISIL_TALK_PCM = 1,							// 带头PCM
	ISIL_TALK_G711a,								// G711a
	ISIL_TALK_AMR,								// AMR
	ISIL_TALK_G711u,								// G711u
	ISIL_TALK_G726,								// G726
} ISIL_TALK_CODING_TYPE;

// 对讲方式
typedef enum __EM_USEDEV_MODE
{
	ISIL_TALK_ISIL_CLIENT_MODE,						// 设置客户端方式进行语音对讲
	ISIL_TALK_SERVER_MODE,						// 设置服务器方式进行语音对讲
	ISIL_TALK_ENCODE_TYPE,						// 设置语音对讲编码格式
	ISIL_ALARM_LISTEN_MODE,						// 设置报警订阅方式
	ISIL_CONFIG_AUTHORITY_MODE,					// 设置通过权限进行配置管理
} EM_USEDEV_MODE;

// AMR编码类型
typedef enum __EM_ARM_ENCODE_MODE
{
	ISIL_TALK_AMR_AMR475 = 1,						// AMR475编码
	ISIL_TALK_AMR_AMR515,							// AMR515编码
	ISIL_TALK_AMR_AMR59,							// AMR59编码
	ISIL_TALK_AMR_AMR67,							// AMR67编码
	ISIL_TALK_AMR_AMR74,							// AMR74编码
	ISIL_TALK_AMR_AMR795,							// AMR795编码
	ISIL_TALK_AMR_AMR102,							// AMR102编码
	ISIL_TALK_AMR_AMR122,							// AMR122编码
} EM_ARM_ENCODE_MODE;

/////////////////////////////////控制相关/////////////////////////////////

// 控制类型，对应ISIL_CLIENT_ControlDevice接口
typedef enum _CtrlType
{
	ISIL_CTRL_REBOOT = 0,							// 重启设备
	ISIL_CTRL_SHUTDOWN,							// 关闭设备
	ISIL_CTRL_DISK,								// 硬盘管理
	ISIL_KEYBOARD_POWER = 3,						// 网络键盘
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
	ISIL_TRIGGER_ALARM_IN = 100,					// 触发报警输入
	ISIL_TRIGGER_ALARM_OUT,						// 触发报警输出
	ISIL_CTRL_MATRIX,								// 矩阵控制
	ISIL_CTRL_SDCARD,								// SD卡控制(IPC产品)参数同硬盘控制
	ISIL_BURNING_START,							// 刻录机控制，开始刻录
	ISIL_BURNING_STOP,							// 刻录机控制，结束刻录
	ISIL_BURNING_ADDPWD,							// 刻录机控制，叠加密码(以'\0'为结尾的字符串，最大长度8位)
	ISIL_BURNING_ADDHEAD,							// 刻录机控制，叠加片头(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
	ISIL_BURNING_ADDSIGN,							// 刻录机控制，叠加打点到刻录信息(参数无)
	ISIL_BURNING_ADDCURSTOMINFO,					// 刻录机控制，自定义叠加(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
	ISIL_CTRL_RESTOREDEFAULT,						// 恢复设备的默认设置
	ISIL_CTRL_CAPTURE_START,						// 触发设备抓图
	ISIL_CTRL_CLEARLOG,							// 清除日志
	ISIL_TRIGGER_ALARM_WIRELESS = 200,			// 触发无线报警(IPC产品)
	ISIL_MARK_IMPORTANT_RECORD,					// 标识重要录像文件
	ISIL_CTRL_DISK_SUBAREA, 						// 网络硬盘分区
	ISIL_BURNING_ATTACH,							// 刻录机控制，附件刻录.
	ISIL_BURNING_PAUSE,							// 刻录暂停
	ISIL_BURNING_CONTINUE,						// 刻录继续
	ISIL_BURNING_POSTPONE,						// 刻录顺延
	ISIL_CTRL_OEMCTRL,							// 报停控制
} CtrlType;

// IO控制命令，对应ISIL_CLIENT_QueryIOControlState接口
typedef enum _IOTYPE
{
	ISIL_ALARMINPUT = 1,							// 控制报警输入
	ISIL_ALARMOUTPUT = 2,							// 控制报警输出
	ISIL_DECODER_ALARMOUT = 3,					// 控制报警解码器输出
	ISIL_WIRELESS_ALARMOUT = 5,					// 控制无线报警输出
	ISIL_ALARM_TRIGGER_MODE = 7,					// 报警触发方式（手动,自动,关闭），使用TRIGGER_MODE_CONTROL结构体
} ISIL_IOTYPE;

/////////////////////////////////配置相关/////////////////////////////////

// 分辨率枚举，供ISIL_DSP_ENCODECAP使用
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

// 配置文件类型，供ISIL_CLIENT_ExportConfigFile接口使用
typedef enum __ISIL_CONFIG_FILE_TYPE
{
	ISIL_CONFIGFILE_ALL = 0,						// 全部配置文件
	ISIL_CONFIGFILE_LOCAL,						// 本地配置文件
	ISIL_CONFIGFILE_NETWORK,						// 网络配置文件
	ISIL_CONFIGFILE_USER,							// 用户配置文件
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
 ** 结构体定义
 ***********************************************************************/
/*坐标位置*/
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;
// 时间
typedef struct
{
	DWORD				dwYear;					// 年
	DWORD				dwMonth;				// 月
	DWORD				dwDay;					// 日
	DWORD				dwHour;					// 时
	DWORD				dwMinute;				// 分
	DWORD				dwSecond;				// 秒
} NET_TIME,*LPNET_TIME;

// 日志信息里的时间定义
typedef struct _ISILDEVTIME
{
	DWORD				second		:6;			// 秒	1-60
	DWORD				minute		:6;			// 分	1-60
	DWORD				hour		:5;			// 时	1-24
	DWORD				day			:5;			// 日	1-31
	DWORD				month		:4;			// 月	1-12
	DWORD				year		:6;			// 年	2000-2063
} ISIL_DEV_TIME, *LPISILDEVTIME;

// 回调数据(异步接口)
typedef struct __NET_CALLBACK_DATA
{
	int					nResultCode;			// 返回码；0：成功
	char				*pBuf;					// 接收数据，缓冲是由用户开辟的，从接口形参传入
	int					nRetLen;				// 接收长度
	LONG				lOperateHandle;			// 操作句柄
	void*				userdata;				// 操作对应用户参数
	char				reserved[16];
} NET_CALLBACK_DATA, *LPNET_CALLBACK_DATA;

///////////////////////////////监视相关定义///////////////////////////////

// 回调视频数据帧的帧参数结构体
typedef struct _tagVideoFrameParam
{
	BYTE				encode;					// 编码类型
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15, LFT - 16, 720 - 17, 1080 - 18
	DWORD				fourcc;					// 如果是H264编码则总为0，MPEG4这里总是填写FOURCC('X','V','I','D');
	DWORD				reserved;				// 保留
	NET_TIME			struTime;				// 时间信息
} tagVideoFrameParam;

// 回调音频数据帧的帧参数结构体
typedef struct _tagCBPCMDataParam
{
	BYTE				channels;				// 声道数
	BYTE				samples;				// 采样 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// 采样深度 取值8或者16等。直接表示
	BYTE				param1;					// 0 - 指示无符号，1-指示有符号
	DWORD				reserved;				// 保留
} tagCBPCMDataParam;

// 通道画面字幕叠加的数据结构
typedef struct _ISIL_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// 使能
	DWORD				dwPosition[MAX_STRING_LINE_LEN];	//各行字符的位置　用1-9整数表示，与小键盘位置对应
												//		7左上	8上		9右上
												//		4左		5中		6右
												//		1左下	2下		3右下
	char				szStrings[MAX_STRING_LINE_LEN][MAX_PER_STRING_LEN];	// 最多六行字符，每行最多20个字节
} ISIL_CHANNEL_OSDSTRING;

///////////////////////////////回放相关定义///////////////////////////////

// 录像文件信息
typedef struct
{
    unsigned int		ch;						// 通道号
    char				filename[128];			// 文件名
    unsigned int		size;					// 文件长度
    NET_TIME			starttime;				// 开始时间
    NET_TIME			endtime;				// 结束时间
    unsigned int		driveno;				// 磁盘号(区分网络录像和本地录像的类型，0－127表示本地录像，128表示网络录像)
    unsigned int		startcluster;			// 起始簇号
	BYTE				nRecordFileType;		// 录象文件类型  0：普通录象；1：报警录象；2：移动检测；3：卡号录象；4：图片
	BYTE                bImportantRecID;		// 0:普通录像 1:重要录像
	BYTE                bHint;					// 文件定位索引
	BYTE                bReserved;				// 保留
} NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;

// 最早录像时间
typedef struct
{
	int					nChnCount;				// 通道数目
	NET_TIME			stuFurthestTime[16];	// 最早录像时间,有效值为前面0 到 (nChnCount-1)个.如果某通道没有录象的话，最早录象时间全为0
	BYTE				bReserved[384];			// 保留字段
} NET_FURTHEST_RECORD_TIME;

///////////////////////////////报警相关定义///////////////////////////////

// 普通报警信息
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// 外部报警
	unsigned char		motiondection[16];		// 动态检测
	unsigned char		videolost[16];			// 视频丢失
} ISIL_CLIENT_NET__STATE;

// 报警IO控制
typedef struct
{
	unsigned short		index;					// 端口序号
	unsigned short		state;					// 端口状态
} ALARM_CONTROL;

//触发方式
typedef struct
{
	unsigned short		index;					//端口序号
	unsigned short		mode;					//触发方式(0关闭1手动2自动);不设置的通道，sdk默认将保持原来的设置。
	BYTE				bReserved[28];
} TRIGGER_MODE_CONTROL;

// 报警解码器控制
typedef struct
{
	int					decoderNo;				// 报警解码器号，从0开始
	unsigned short		alarmChn;				// 报警输出口，从0开始
	unsigned short		alarmState;				// 报警输出状态；1：打开，0：关闭
} DECODER_ALARM_CONTROL;

// 报警上传功能的报警信息
typedef struct
{
	DWORD				dwAlarmType;			// 报警类型，dwAlarmType = ISIL_UPLOAD_EVENT时，dwAlarmMask和bAlarmDecoderIndex是无效的
	DWORD				dwAlarmMask;			// 报警信息掩码，按位表示各报警通道状态
	char				szGlobalIP[ISIL_MAX_IPADDR_LEN];	// 客户端IP地址
	char				szDomainName[ISIL_MAX_DOMAIN_NAME_LEN];	// 客户端域名
	int					nPort;					// 报警上传时客户端连接的端口
	char				szAlarmOccurTime[ISIL_ALARM_OCCUR_TIME_LEN];	// 报警发生的时间
	BYTE				bAlarmDecoderIndex;		// 表示第几个报警解码器，dwAlarmType = ISIL_UPLOAD_DECODER_ALARM 才有效.
	BYTE				bReservedSpace[15];
}NEW_ALARM_UPLOAD;

/////////////////////////////语音对讲相关定义/////////////////////////////

// 音频格式信息
typedef struct
{
	BYTE				byFormatTag;			// 编码类型，如0：PCM
	WORD				nChannels;				// 声道数
	WORD				wBitsPerSample;			// 采样深度
	DWORD				nSamplesPerSec;			// 采样率
} ISIL_AUDIO_FORMAT, *LPISIL_AUDIO_FORMAT;

/////////////////////////////用户管理相关定义/////////////////////////////

// 支持用户名最大长度为8位的设备，对应ISIL_CLIENT_QueryUserInfo和ISIL_CLIENT_OperateUserInfo接口
// 权限信息
typedef struct _OPR_RIGHT
{
	DWORD				dwID;
	char				name[ISIL_RIGHT_NAME_LENGTH];
	char				memo[ISIL_MEMO_LENGTH];
} OPR_RIGHT;

// 用户信息
typedef struct _USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ISIL_USER_NAME_LENGTH];
	char				passWord[ISIL_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
	DWORD				dwReusable;				// 是否复用；1：复用，0：不复用
} USER_INFO;

// 用户组信息
typedef struct _USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[ISIL_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
} USER_GROUP_INFO;

// 用户信息表
typedef struct _USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// 权限信息
	OPR_RIGHT			rightList[ISIL_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// 用户组信息
	USER_GROUP_INFO		groupList[ISIL_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// 用户信息
	USER_INFO			userList[ISIL_MAX_USER_NUM];
	DWORD				dwSpecial;				// 用户复用能力；1：支持用户复用，0：不支持用户复用
} USER_MANAGE_INFO;

// 支持用户名最大长度为8位或16位的设备，对应扩展接口ISIL_CLIENT_QueryUserInfoEx和ISIL_CLIENT_OperateUserInfoEx
#define ISIL_USER_NAME_LENGTH_EX		16			// 用户名长度
#define ISIL_USER_PSW_LENGTH_EX		16			// 密码

// 权限信息
typedef struct _OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[ISIL_RIGHT_NAME_LENGTH];
	char				memo[ISIL_MEMO_LENGTH];
} OPR_RIGHT_EX;

// 用户信息
typedef struct _USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ISIL_USER_NAME_LENGTH_EX];
	char				passWord[ISIL_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// 掩码，0x00000001 - 支持用户复用
	BYTE				byReserve[32];
} USER_INFO_EX;

// 用户组信息
typedef struct _USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[ISIL_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ISIL_MAX_RIGHT_NUM];
	char				memo[ISIL_MEMO_LENGTH];
} USER_GROUP_INFO_EX;

// 用户信息表
typedef struct _USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// 权限信息
	OPR_RIGHT_EX		rightList[ISIL_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// 用户组信息
	USER_GROUP_INFO_EX  groupList[ISIL_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// 用户信息
	USER_INFO_EX		userList[ISIL_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// 掩码；0x00000001 - 支持用户复用，0x00000002 - 密码修改需要校验
	BYTE				byNameMaxLength;		// 支持的用户名最大长度
	BYTE				byPSWMaxLength;			// 支持的密码最大长度
	BYTE				byReserve[254];
} USER_MANAGE_INFO_EX;

///////////////////////////////查询相关定义///////////////////////////////

// 设备支持语言种类
typedef struct _ISIL_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// 支持语言个数
	BYTE				byLanguageType[252];	// 枚举值，详见ISIL_LANGUAGE_TYPE
} ISIL_DEV_LANGUAGE_INFO, *LPISIL_DEV_LANGUAGE_INFO;

// 硬盘信息
typedef struct
{
	DWORD				dwVolume;				// 硬盘的容量
	DWORD				dwFreeSpace;			// 硬盘的剩余空间
	BYTE				dwStatus;				// 硬盘的状态,0-休眠,1-活动,2-故障等；将DWORD拆成四个BYTE
	BYTE				bDiskNum;				// 硬盘号
	BYTE				bSubareaNum;			// 分区号
	BYTE				bSignal;				// 标识，0为本地 1为远程
} ISIL_DEV_DISKSTATE,*LPISIL_DEV_DISKSTATE;

// 设备硬盘信息
typedef struct _ISIL_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// 个数
	ISIL_DEV_DISKSTATE	stDisks[ISIL_MAX_DISKNUM];// 硬盘或分区信息
} ISIL_HARDDISK_STATE, *LPISIL_HARDDISK_STATE;

typedef ISIL_HARDDISK_STATE	ISIL_SDCARD_STATE;	// SD卡，数据结构同硬盘信息

// 语音编码信息
typedef struct
{
	ISIL_TALK_CODING_TYPE	encodeType;				// 编码类型
	int					nAudioBit;				// 位数，如8或16
	DWORD				dwSampleRate;			// 采样率，如8000或16000
	char				reserved[64];
} ISIL_DEV_TALKDECODE_INFO;

// 设备支持的语音对讲类型
typedef struct
{
	int					nSupportNum;			// 个数
	ISIL_DEV_TALKDECODE_INFO type[64];				// 编码类型
	char				reserved[64];
} ISIL_DEV_TALKFORMAT_LIST;

// 云台属性信息
#define  NAME_MAX_LEN 16
typedef struct
{
	DWORD				dwHighMask;				// 操作的掩码高位
	DWORD				dwLowMask;				// 操作的掩码低位
	char				szName[NAME_MAX_LEN];	// 操作的协议名
	WORD				wCamAddrMin;			// 通道地址的最小值
	WORD				wCamAddrMax;			// 通道地址的最大值
	WORD				wMonAddrMin;			// 监视地址的最小值
	WORD				wMonAddrMax;			// 监视地址的最大值
	BYTE				bPresetMin;				// 预置点的最小值
	BYTE				bPresetMax;				// 预置点的最大值
	BYTE				bTourMin;				// 自动巡航线路的最小值
	BYTE				bTourMax;				// 自动巡航线路的最大值
	BYTE				bPatternMin;			// 轨迹线路的最小值
	BYTE				bPatternMax;			// 轨迹线路的最大值
	BYTE				bTileSpeedMin;			// 垂直速度的最小值
	BYTE				bTileSpeedMax;			// 垂直速度的最大值
	BYTE				bPanSpeedMin;			// 水平速度的最小值
	BYTE				bPanSpeedMax;			// 水平速度的最大值
	BYTE				bAuxMin;				// 辅助功能的最小值
	BYTE				bAuxMax;				// 辅助功能的最大值
	int					nInternal;				// 发送命令的时间间隔
	char				cType;					// 协议的类型
	char				Reserved[7];
} PTZ_OPT_ATTR;

// 刻录机信息
typedef struct _ISIL_DEV_BURNING
{
	DWORD				dwDriverType;			// 刻录驱动器类型；0：DHFS，1：DISK，2：CDRW
	DWORD				dwBusType;				// 总线类型；0：USB，1：1394，2：IDE
	DWORD				dwTotalSpace;			// 总容量(KB)
	DWORD				dwRemainSpace;			// 剩余容量(KB)
	BYTE				dwDriverName[ISIL_BURNING_DEV_NAMELEN];	// 刻录驱动器名称
} ISIL_DEV_BURNING, *LPISIL_DEV_BURNING;

// 设备刻录机信息
typedef struct _ISIL_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// 刻录设备个数
	ISIL_DEV_BURNING		stDevs[ISIL_MAX_BURNING_DEV_NUM];	// 各刻录设备信息
} ISIL_BURNING_DEVINFO, *LPISIL_BURNING_DEVINFO;

// 刻录进度
typedef struct _ISIL_BURNING_PROGRESS
{
	BYTE				bBurning;				// 刻录机状态；0：可以刻录，1：刻录机类型不对，是一个非光盘设备，
												// 2：未找到刻录机，3：有其它光盘在刻录，4：刻录机处于非空闲状态，即在备份、刻录或回放中
	BYTE				bRomType;				// 盘片类型；0：大华文件系统，1：移动硬盘或U盘，2：光盘
	BYTE				bOperateType;			// 操作类型；0：空闲，1：正在备份中，2：正在刻录中，3：正在进行光盘回放
	BYTE				bType;					// 备份或刻录过程状态；0：停止或结束，1：开始，2：出错，3：满，4：正在初始化
	NET_TIME			stTimeStart;			// 开始时间　
	DWORD				dwTimeElapse;			// 已刻录时间(秒)
	DWORD				dwTotalSpace;			// 光盘总容量
	DWORD				dwRemainSpace;			// 光盘剩余容量
	DWORD				dwBurned;				// 已刻录容量
	WORD				dwStatus;				// 保留
	WORD				wChannelMask;			// 正在刻录的通道掩码
} ISIL_BURNING_PROGRESS, *LPISIL_BURNING_PROGRESS;

// 日志信息，对应接口ISIL_CLIENT_QueryLog接口
typedef struct _ISIL_LOG_ITEM
{
    ISIL_DEV_TIME			time;					// 日期
    unsigned short		type;					// 类型
    unsigned char		reserved;				// 保留
    unsigned char		data;					// 数据
    unsigned char		context[8];				// 内容
} ISIL_LOG_ITEM, *LPISIL_LOG_ITEM;

// 日志信息，对应扩展接口ISIL_CLIENT_QueryLogEx，参数reserved(int nType=1;reserved=&nType;)
typedef struct _ISIL_NEWLOG_ITEM
{
	ISIL_DEV_TIME			time;					// 日期
	WORD				type;					// 类型
	WORD				data;					// 数据
	char				szOperator[8]; 			// 用户名
	BYTE				context[16];		    // 内容
} ISIL_NEWLOG_ITEM, *LPISIL_NEWLOG_ITEM;

// 日志信息，对应接口ISIL_CLIENT_QueryDeviceLog接口
typedef struct _ISIL_DEVICE_LOG_ITEM
{
	int					nLogType;				// 日志类型
	ISIL_DEV_TIME			stuOperateTime;			// 日期
	char				szOperator[16]; 		// 操作者
	BYTE				bReserved[3];
	BYTE				bUnionType;				//  union结构类型,0:szLogContext；1:stuOldLog。
	union
	{
		char			szLogContext[64];		// 日志内容
		struct
		{
			ISIL_LOG_ITEM		stuLog;				// 旧的日志结构体
			BYTE			bReserved[48];		// 保留
		}stuOldLog;
	};
	char				reserved[16];
} ISIL_DEVICE_LOG_ITEM, *LPISIL_DEVICE_LOG_ITEM;

// 录象日志信息，对应日志结构体里的context
typedef struct _LOG_ITEM_RECORD
{
	ISIL_DEV_TIME			time;					// 时间
	BYTE				channel;				// 通道
	BYTE				type;					// 录像类型
	BYTE				reserved[2];
} LOG_ITEM_RECORD, *LPLOG_ITEM_RECORD;

typedef struct _QUERY_DEVICE_LOG_PARAM
{
	ISIL_LOG_QUERY_TYPE	emLogType;				// 查询日志类型
	NET_TIME			stuStartTime;			// 查询日志的开始时间
	NET_TIME			stuEndTime;				// 查询日志的结束时间
	int					nStartNum;				// 在时间段中从第几条日志开始查询，开始第一次查询可设为0
	int					nEndNum;				// 一次查询中到第几条日志结束。
	BYTE				bReserved[48];
} QUERY_DEVICE_LOG_PARAM;

// 设备硬盘里的录象信息
typedef struct __ISIL_DEV_DISK_RECORD_INFO
{
	NET_TIME			stuBeginTime;			// 最早录象时间
	NET_TIME			stuEndTime;				// 最近录象时间
	char				reserved[128];
} ISIL_DEV_DISK_RECORD_INFO;

///////////////////////////////控制相关定义///////////////////////////////

// 硬盘操作
typedef struct _DISKCTRL_PARAM
{
	DWORD				dwSize;					// 结构体大小，版本控制用
	int					nIndex;					// 为硬盘信息结构体ISIL_HARDDISK_STATE里的数组stDisks下标，从0开始
	int					ctrlType;				// 操作类型，
												// 0 - 清除数据, 1 - 设为读写盘, 2 - 设为只读盘
												// 3 - 设为冗余盘, 4 - 恢复错误, 5 - 设为快照盘
} DISKCTRL_PARAM;

typedef struct
{
	BYTE				bSubareaNum;			// 预分区的个数
	BYTE				bIndex;					// 为硬盘信息结构体ISIL_HARDDISK_STATE里的数组stDisks下标，从0开始
	BYTE				bSubareaSize[32];		// 分区大小（百分比）
	BYTE				bReserved[30];			// 保留
} DISKCTRL_SUBAREA;

// 报警状态
typedef struct _ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// 报警通道号，从0开始
	int					nAction;				// 1：触发报警，0：停止报警
} ALARMCTRL_PARAM;

// 矩阵控制
typedef struct _MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// 视频输入号，从0开始
	int					nMatrixNo;				// 矩阵输出号，从0开始
} MATRIXCTRL_PARAM;

// 刻录控制
typedef struct _BURNING_PARM
{
	int					channelMask;			// 通道掩码，按位表示要刻录的通道
	int					devMask;				// 刻录机掩码，根据查询到的刻录机列表，按位表示
} BURNNG_PARM;

// 附件刻录
typedef struct _BURNING_PARM_ATTACH
{
	BOOL				bAttachBurn;			// 是否为附件刻录，0:不是; 1:是
	BYTE				bReserved[12];			// 保留字段
} BURNING_PARM_ATTACH;

///////////////////////////////配置相关定义///////////////////////////////

//-------------------------------设备属性---------------------------------
// 设备信息
typedef struct
{
	BYTE				sSerialNumber[ISIL_SERIALNO_LEN];	// 序列号
	BYTE				byAlarmInPortNum;		// DVR报警输入个数
	BYTE				byAlarmOutPortNum;		// DVR报警输出个数
	BYTE				byDiskNum;				// DVR硬盘个数
	BYTE				byDVRType;				// DVR类型, 见枚举ISIL_DEV_DEVICE_TYPE
	BYTE				byChanNum;				// DVR通道个数
	BYTE                reserved[3];
} NET_DEVICEINFO, *LPNET_DEVICEINFO;

// 设备软件版本信息，高16位表示主版本号，低16位表示次版本号
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

// 设备软件版本信息，对应ISIL_CLIENT_QueryDevState接口
typedef struct
{
	char				szDevSerialNo[ISIL_DEV_SERIALNO_LEN];	// 序列号
	char				byDevType;				// 设备类型，见枚举ISIL_DEV_DEVICE_TYPE
	char				szDevType[ISIL_DEV_TYPE_LEN];	// 设备详细型号，字符串格式，可能为空
	int					nProtocalVer;			// 协议版本号
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

// DSP能力描述，对应ISIL_CLIENT_GetDevConfig接口
typedef struct
{
	DWORD				dwVideoStandardMask;	// 视频制式掩码，按位表示设备能够支持的视频制式
	DWORD				dwImageSizeMask;		// 分辨率掩码，按位表示设备能够支持的分辨率设置
	DWORD				dwEncodeModeMask;		// 编码模式掩码，按位表示设备能够支持的编码模式设置
	DWORD				dwStreamCap;			// 按位表示设备支持的多媒体功能，
												// 第一位表示支持主码流
												// 第二位表示支持辅码流1
												// 第三位表示支持辅码流2
												// 第五位表示支持jpg抓图
	DWORD				dwImageSizeMask_Assi[8];// 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
	DWORD				dwMaxEncodePower;		// DSP支持的最高编码能力
	WORD				wMaxSupportChannel;		// 每块DSP支持最多输入视频通道数
	WORD				wChannelMaxSetSync;		// DSP每通道的最大编码设置是否同步；0：不同步，1：同步
} ISIL_DSP_ENCODECAP, *LPISIL_DSP_ENCODECAP;

// DSP能力描述，扩展类型，对应ISIL_CLIENT_QueryDevState接口
typedef struct
{
	DWORD				dwVideoStandardMask;	// 视频制式掩码，按位表示设备能够支持的视频制式
	DWORD				dwImageSizeMask;		// 分辨率掩码，按位表示设备能够支持的分辨率
	DWORD				dwEncodeModeMask;		// 编码模式掩码，按位表示设备能够支持的编码模式
	DWORD				dwStreamCap;			// 按位表示设备支持的多媒体功能，
												// 第一位表示支持主码流
												// 第二位表示支持辅码流1
												// 第三位表示支持辅码流2
												// 第五位表示支持jpg抓图
	DWORD				dwImageSizeMask_Assi[32];// 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
	DWORD				dwMaxEncodePower;		// DSP支持的最高编码能力
	WORD				wMaxSupportChannel;		// 每块DSP支持最多输入视频通道数
	WORD				wChannelMaxSetSync;		// DSP每通道的最大编码设置是否同步；0：不同步，1：同步
	BYTE				bMaxFrameOfImageSize[32];// 不同分辨率下的最大采集帧率，与dwVideoStandardMask按位对应
	BYTE				bEncodeCap;				// 标志，配置时要求符合下面条件，否则配置不能生效；
												// 0：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
												// 1：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
												// 辅码流的编码能力 <= 主码流的编码能力，
												// 辅码流的分辨率 <= 主码流的分辨率，
												// 主码流和辅码流的帧率 <= 前端视频采集帧率
												// 2：N5的计算方法
												// 辅码流的分辨率 <= 主码流的分辨率
												// 查询支持的分辨率和相应最大帧率
	char				reserved[95];
} ISIL_DEV_DSP_ENCODECAP, *LPISIL_DEV_DSP_ENCODECAP;

// 系统信息
typedef struct
{
	DWORD				dwSize;
	/* 下面是设备的只读部分 */
	ISIL_VERSION_INFO		stVersion;
	ISIL_DSP_ENCODECAP	stDspEncodeCap;			// DSP能力描述
	BYTE				szDevSerialNo[ISIL_DEV_SERIALNO_LEN];	// 序列号
	BYTE				byDevType;				// 设备类型，见枚举ISIL_DEV_DEVICE_TYPE
	BYTE				szDevType[ISIL_DEV_TYPE_LEN];	// 设备详细型号，字符串格式，可能为空
	BYTE				byVideoCaptureNum;		// 视频口数量
	BYTE				byAudioCaptureNum;		// 音频口数量
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// 报警输入口数
	BYTE				byAlarmOutNum;			// 报警输出口数
	BYTE				byNetIONum;				// 网络口数
	BYTE				byUsbIONum;				// USB口数量
	BYTE				byIdeIONum;				// IDE数量
	BYTE				byComIONum;				// 串口数量
	BYTE				byLPTIONum;				// 并口数量
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP，扩展描述
	BYTE				byMatrixOutNum;			// 视频矩阵输出口数
	/* 下面是设备的可写部分 */
	BYTE				byOverWrite;			// 硬盘满处理方式(覆盖、停止)
	BYTE				byRecordLen;			// 录象打包长度
	BYTE				byDSTEnable;			// 是否实行夏令时 1-实行 0-不实行
	WORD				wDevNo;					// 设备编号，用于遥控
	BYTE				byVideoStandard;		// 视频制式:0-PAL,1-NTSC
	BYTE				byDateFormat;			// 日期格式
	BYTE				byDateSprtr;			// 日期分割符(0："."，1："-"，2："/")
	BYTE				byTimeFmt;				// 时间格式 (0-24小时，1－12小时)
	BYTE				byLanguage;				// 枚举值详见ISIL_LANGUAGE_TYPE
} ISIL_DEV_SYSTEM_ATTR_CFG, *LPISIL_DEV_SYSTEM_ATTR_CFG;

// 修改设备配置返回信息
typedef struct
{
	DWORD				dwType;					// 类型(即GetDevConfig和SetDevConfig的类型)
	WORD				wResultCode;			// 返回码；0：成功，1：失败，2：数据不合法，3：暂时无法设置，4：没有权限
	WORD   				wRebootSign;			// 重启标志；0：不需要重启，1：需要重启才生效
	DWORD				dwReserved[2];			// 保留
} DEV_SET_RESULT;

//DST(夏令时)配置
typedef struct
{
	int					nYear;					// 年[200 - 2037]
	int					nMonth;					// 月[1 - 12]
	int					nHour;					// 小时 [0 - 23]
	int					nMinute;				// 分钟 [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:表示使用按日期计算的方法
												// 1: 按周计算: 第一周,2: 第二周,3: 第三周,4: 第四周,-1: 最后一周
	union
	{
		int				iWeekDay;				// 周[0 - 6](nWeekOrDay：按周计算时)0:星期日, 1:星期一, 2:星期二,3:星期三,4:星期四,5:星期五,6:星期六
		int				iDay;					// 日期[1 - 31] (nWeekOrDay：按日期计算)
	};

	DWORD				dwReserved[8];			// 保留
}ISIL_DST_POINT;



typedef struct
{
DWORD				dwSize;
int					nDSTType;				// 夏令时定位方式 0:按日期定位方式, 1:按周定位方式
ISIL_DST_POINT        stDSTStart;             // 开始夏令时
ISIL_DST_POINT        stDSTEnd;				// 结束夏令时
DWORD				dwReserved[16];			// 保留
}ISIL_DEV_DST_CFG;


//自动维护配置
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// 自动重启；0：从不, 1：每天，2：每星期日，3：每星期一，......
	BYTE				byAutoRebootTime;		// 0：0:00，1：1:00，......23：23:00
	BYTE				byAutoDeleteFilesTime;	// 自动删除文件；0：从不，1：24H，2：48H，3：72H，4：96H，5：ONE WEEK，6：ONE MONTH
	BYTE				reserved[13];			// 保留位
} ISIL_DEV_AUTOMT_CFG;

//-----------------------------图像通道属性-------------------------------

// 时间段结构
typedef struct
{
	BOOL				bEnable;				// 当表示录像时间段时，按位表示三个使能，从低位到高位分别表示动检录象、报警录象、普通录象
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} ISIL_TSECT, *LPISIL_TSECT;

// 区域；各边距按整长8192的比例
typedef struct {
   long					left;
   long					top;
   long					right;
   long					bottom;
} ISIL_RECT, *LPISIL_RECT;

// OSD属性结构
typedef struct  tagENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// 物件的前景；按字节表示，分别为红、绿、蓝和透明度
	DWORD				rgbaBackground;			// 物件的背景；按字节表示，分别为红、绿、蓝和透明度
	ISIL_RECT				rcRect;					// 位置
	BYTE				bShow;					// 显示使能
	BYTE				byReserved[3];
} ISIL_ENCODE_WIDGET, *LPISIL_ENCODE_WIDGET;

// 通道音视频属性
typedef struct
{
	// 视频参数
	BYTE				byVideoEnable;			// 视频使能；1：打开，0：关闭
	BYTE				byBitRateControl;		// 码流控制；参照常量"码流控制"定义
	BYTE				byFramesPerSec;			// 帧率
	BYTE				byEncodeMode;			// 编码模式；参照常量"编码模式"定义
	BYTE				byImageSize;			// 分辨率；参照常量"分辨率"定义
	BYTE				byImageQlty;			// 档次1-6
	WORD				wLimitStream;			// 限码流参数
	// 音频参数
	BYTE				byAudioEnable;			// 音频使能；1：打开，0：关闭
	BYTE				wFormatTag;				// 音频编码类型
	WORD				nChannels;				// 声道数
	WORD				wBitsPerSample;			// 采样深度
	BYTE				bAudioOverlay;			// 音频叠加使能
	BYTE				bReserved_2;
	DWORD				nSamplesPerSec;			// 采样率
	BYTE				bIFrameInterval;		// I帧间隔帧数量，描述两个I帧之间的P帧个数，0-149
	BYTE				bScanMode;				// NSP
	BYTE				bReserved_3;
	BYTE				bReserved_4;
} ISIL_VIDEOENC_OPT, *LPISIL_VIDEOENC_OPT;

// 画面颜色属性
typedef struct
{
	ISIL_TSECT			stSect;
	BYTE				byBrightness;			// 亮度；0-100
	BYTE				byContrast;				// 对比度；0-100
	BYTE				bySaturation;			// 饱和度；0-100
	BYTE				byHue;					// 色度；0-100
	BYTE				byGainEn;				// 增益使能
	BYTE				byGain;					// 增益；0-100
	BYTE				byReserved[2];
} ISIL_COLOR_CFG, *LPISIL_COLOR_CFG;

// 图像通道属性结构体
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
	ISIL_ENCODE_WIDGET	stBlindCover[ISIL_N_COVERS];	// 单区域遮挡
	BYTE				byBlindEnable;			// 区域遮盖开关；0x00：不使能遮盖，0x01：仅遮盖设备本地预览，0x10：仅遮盖录像及网络预览，0x11：都遮盖
	BYTE				byBlindMask;			// 区域遮盖掩码；第一位：设备本地预览；第二位：录像(及网络预览) */
	BYTE				bVolume;				// 音量阀值(0~100可调)
	BYTE				bVolumeEnable;			// 音量阀值使能
} ISIL_DEV_CHANNEL_CFG, *LPISIL_DEV_CHANNEL_CFG;

// 预览图像参数
typedef struct
{
	DWORD				dwSize;
	ISIL_VIDEOENC_OPT		stPreView;
	ISIL_COLOR_CFG		stColorCfg[ISIL_N_COL_TSECT];
}ISIL_DEV_PREVIEW_CFG;

//-------------------------------串口属性---------------------------------

// 串口基本属性
typedef struct
{
	BYTE				byDataBit;				// 数据位；0：5，1：6，2：7，3：8
	BYTE				byStopBit;				// 停止位；0：1位，1：1.5位，2：2位
	BYTE				byParity;				// 校验位；0：无校验，1：奇校验；2：偶校验
	BYTE				byBaudRate;				// 波特率；0：300，1：600，2：1200，3：2400，4：4800，
												// 5：9600，6：19200，7：38400，8：57600，9：115200
} ISIL_COMM_PROP;

// 485解码器配置
typedef struct
{
	ISIL_COMM_PROP		struComm;
	BYTE				wProtocol;				// 协议类型，对应"协议名列表"下标
	BYTE				byReserved;				// 保留
	BYTE				wDecoderAddress;		// 解码器地址；0 - 255
	BYTE 				byMartixID;				// 矩阵号
} ISIL_485_CFG;

// 232串口配置
typedef struct
{
	ISIL_COMM_PROP		struComm;
	BYTE				byFunction;				// 串口功能，对应"功能名列表"下标
	BYTE				byReserved[3];
} ISIL_RS232_CFG;

// 串口配置结构体
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;				// 解码器协议个数
	char				DecProName[ISIL_MAX_DECPRO_LIST_SIZE][ISIL_MAX_NAME_LEN]; // 协议名列表
	ISIL_485_CFG			stDecoder[ISIL_MAX_DECODER_NUM];	// 各解码器当前属性

	DWORD				dw232FuncNameNum;		// 232功能个数
	char				s232FuncName[ISIL_MAX_232FUNCS][ISIL_MAX_NAME_LEN];	// 功能名列表
	ISIL_RS232_CFG		st232[ISIL_MAX_232_NUM];	// 各232串口当前属性
} ISIL_DEV_COMM_CFG;

// 串口状态
typedef struct
{
	unsigned int		uBeOpened;
	unsigned int		uBaudRate;
	unsigned int		uDataBites;
	unsigned int		uStopBits;
	unsigned int		uParity;
	BYTE				bReserved[32];
}ISIL_COMM_STATE;

//-------------------------------录象配置---------------------------------

// 定时录象
typedef struct
{
	DWORD				dwSize;
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	BYTE				byPreRecordLen;			// 预录时间，单位是s，0表示不预录
	BYTE				byRedundancyEn;			// 录像冗余开关
	BYTE                byRecordType;           // 录像码流类型：0-主码流 1-辅码流1 2-辅码流2 3-辅码流3
	BYTE				byReserved;
}ISIL_DEV_RECORD_CFG, *LPISIL_RECORD_CFG;

// NTP配置
typedef struct
{
	BOOL				bEnable;				//	是否启用
	int					nHostPort;				//	NTP服务器默认端口为123
	char				szHostIp[32];			//	主机IP
	char				szDomainName[128];		//	域名
	int					nType;					//	不可设置，0：表示IP，1：表示域名，2：表示IP和域名
	int					nUpdateInterval;		//	更新时间(分钟)
	int					nTimeZone;				//	见ISIL_TIME_ZONE_TYPE
	char				reserved[128];
}ISIL_DEV_NTP_CFG;

// FTP上传配置
typedef struct
{
	struct
	{
		ISIL_TSECT		struSect;				// 该时间段内的“使能”无效，可忽略
		BOOL			bMdEn;					// 上传动态检测录象
		BOOL			bAlarmEn;				// 上传外部报警录象
		BOOL			bTimerEn;				// 上传普通定时录像
		DWORD			dwRev[4];
	} struPeriod[ISIL_TIME_SECTION];
} ISIL_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// 是否启用
	char				szHostIp[ISIL_MAX_IPADDR_LEN];		// 主机IP
	WORD				wHostPort;							// 主机端口
	char				szDirName[ISIL_FTP_MAX_PATH];			// FTP目录路径
	char				szUserName[ISIL_FTP_USERNAME_LEN];	// 用户名
	char				szPassword[ISIL_FTP_PASSWORD_LEN];	// 密码
	int					iFileLen;							// 文件长度
	int					iInterval;							// 相邻文件时间间隔
	ISIL_FTP_UPLOAD_CFG	struUploadCfg[ISIL_MAX_CHANNUM][ISIL_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB
	char				NASVer;								// 网络存储服务器版本0=老的FTP(界面上显示时间段)，1=NAS存储(界面上屏蔽时间段)
	DWORD				dwFunctionMask;						// 功能能力掩码，按位表示，低16位(网络存储)依次表示FTP，SMB，NFS，高16位(本地存储)依次为DISK，U
	BYTE 				reserved[124];
} ISIL_DEV_FTP_PROTO_CFG;

//-------------------------------网络配置---------------------------------

// 以太网配置
typedef struct
{
	char				sDevIPAddr[ISIL_MAX_IPADDR_LEN];	// DVR IP 地址
	char				sDevIPMask[ISIL_MAX_IPADDR_LEN];	// DVR IP 地址掩码
	char				sGatewayIP[ISIL_MAX_IPADDR_LEN];	// 网关地址

	/* 10M/100M  自适应,索引
	 * 1-10MBase - T
	 * 2-10MBase-T 全双工
	 * 3-100MBase - TX
	 * 4-100M 全双工
	 * 5-10M/100M  自适应
	 */
	// 为了扩展将DWORD拆成四个
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0：有线，1：无线
	BYTE				bValid;					// 按位表示，第一位：1：有效 0：无效；第二位：0：DHCP关闭 1：DHCP使能；第三位：0：不支持DHCP 1：支持DHCP
	BYTE				bDefaultEth;			// 是否作为默认的网卡 1：默认 0：非默认
	char				byMACAddr[ISIL_MACADDR_LEN];	// MAC地址，只读
} ISIL_ETHERNET;

// 远程主机配置
typedef struct
{
	BYTE				byEnable;				// 连接使能
	BYTE				byAssistant;            // 目前只对于PPPoE服务器有用，0：在有线网卡拨号；1：在无线网卡上拨号
	WORD				wHostPort;				// 远程主机 端口
	char				sHostIPAddr[ISIL_MAX_IPADDR_LEN];		// 远程主机 IP 地址
	char				sHostUser[ISIL_MAX_HOST_NAMELEN];		// 远程主机 用户名
	char				sHostPassword[ISIL_MAX_HOST_PSWLEN];	// 远程主机 密码
} ISIL_REMOTE_HOST;

// 邮件配置
typedef struct
{
	char				sMailIPAddr[ISIL_MAX_IPADDR_LEN];	// 邮件服务器IP地址
	WORD				wMailPort;				// 邮件服务器端口
	WORD				wReserved;				// 保留
	char				sSenderAddr[ISIL_MAX_MAIL_ADDR_LEN];	// 发送地址
	char				sUserName[ISIL_MAX_NAME_LEN];			// 用户名
	char				sUserPsw[ISIL_MAX_NAME_LEN];			// 用户密码
	char				sDestAddr[ISIL_MAX_MAIL_ADDR_LEN];	// 目的地址
	char				sCcAddr[ISIL_MAX_MAIL_ADDR_LEN];		// 抄送地址
	char				sBccAddr[ISIL_MAX_MAIL_ADDR_LEN];		// 暗抄地址
	char				sSubject[ISIL_MAX_MAIL_SUBJECT_LEN];	// 标题
} ISIL_MAIL_CFG;

// 网络配置结构体
typedef struct
{
	DWORD				dwSize;

	char				sDevName[ISIL_MAX_NAME_LEN];	// 设备主机名

	WORD				wTcpMaxConnectNum;		// TCP最大连接数
	WORD				wTcpPort;				// TCP帧听端口
	WORD				wUdpPort;				// UDP侦听端口
	WORD				wHttpPort;				// HTTP端口号
	WORD				wHttpsPort;				// HTTPS端口号
	WORD				wSslPort;				// SSL端口号
	ISIL_ETHERNET			stEtherNet[ISIL_MAX_ETHERNET_NUM];	// 以太网口

	ISIL_REMOTE_HOST		struAlarmHost;			// 报警服务器
	ISIL_REMOTE_HOST		struLogHost;			// 日志服务器
	ISIL_REMOTE_HOST		struSmtpHost;			// SMTP服务器
	ISIL_REMOTE_HOST		struMultiCast;			// 多播组
	ISIL_REMOTE_HOST		struNfs;				// NFS服务器
	ISIL_REMOTE_HOST		struPppoe;				// PPPoE服务器
	char				sPppoeIP[ISIL_MAX_IPADDR_LEN]; // PPPoE注册返回的IP
	ISIL_REMOTE_HOST		struDdns;				// DDNS服务器
	char				sDdnsHostName[ISIL_MAX_HOST_NAMELEN];	// DDNS主机名
	ISIL_REMOTE_HOST		struDns;				// DNS服务器
	ISIL_MAIL_CFG			struMail;				// 邮件配置
} ISIL_DEV_NET_CFG;

// 多ddns配置结构体
typedef struct
{
	DWORD				dwId;					// ddns服务器id号
	BOOL				bEnable;				// 使能，同一时间只能有一个ddns服务器处于使能状态
	char				szServerType[ISIL_MAX_SERVER_TYPE_LEN];	// 服务器类型，希网..
	char				szServerIp[ISIL_MAX_DOMAIN_NAME_LEN];		// 服务器ip或者域名
	DWORD				dwServerPort;			// 服务器端口
	char				szDomainName[ISIL_MAX_DOMAIN_NAME_LEN];	// dvr域名，如jeckean.3322.org
	char				szUserName[ISIL_MAX_HOST_NAMELEN];		// 用户名
	char				szUserPsw[ISIL_MAX_HOST_PSWLEN];			// 密码
	char				szAlias[ISIL_MAX_DDNS_ALIAS_LEN];			// 服务器别名，如"dahua inter ddns"
	DWORD				dwAlivePeriod;							// DDNS 保活时间
	char				reserved[256];
} ISIL_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;
	ISIL_DDNS_SERVER_CFG	struDdnsServer[ISIL_MAX_DDNS_NUM];
} ISIL_DEV_MULTI_DDNS_CFG;

// 邮件配置结构体
typedef struct
{
	char				sMailIPAddr[ISIL_MAX_DOMAIN_NAME_LEN];	// 邮件服务器地址(IP或者域名)
	char				sSubMailIPAddr[ISIL_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// 邮件服务器端口
	WORD				wSubMailPort;
	WORD				wReserved;								// 保留
	char				sSenderAddr[ISIL_MAX_MAIL_ADDR_LEN];		// 发送地址
	char				sUserName[ISIL_MAX_MAIL_NAME_LEN];		// 用户名
	char				sUserPsw[ISIL_MAX_MAIL_NAME_LEN];			// 用户密码
	char				sDestAddr[ISIL_MAX_MAIL_ADDR_LEN];		// 目的地址
	char				sCcAddr[ISIL_MAX_MAIL_ADDR_LEN];			// 抄送地址
	char				sBccAddr[ISIL_MAX_MAIL_ADDR_LEN];			// 暗抄地址
	char				sSubject[ISIL_MAX_MAIL_SUBJECT_LEN];		// 标题
	BYTE				bEnable;								// 使能0:false,	1:true
	BYTE				bSSLEnable;								// SSL使能
	WORD				wSendInterval;							// 发送时间间隔,[0,3600]秒
	char				reserved[156];
} ISIL_DEV_MAIL_CFG;

// DNS服务器配置
typedef struct
{
	char				szPrimaryIp[ISIL_MAX_IPADDR_LEN];
	char				szSecondaryIp[ISIL_MAX_IPADDR_LEN];
	char				reserved[256];
} ISIL_DEV_DNS_CFG;

// 录象下载策略配置
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE：高速下载，FALSE：普通下载
}ISIL_DEV_DOWNLOAD_STRATEGY_CFG;

// 网络传输策略配置
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0：画质优先，1：流畅性优先，2：自动
}ISIL_DEV_TRANSFER_STRATEGY_CFG;

// 设置登入时的相关参数
typedef struct
{
	int					nWaittime;				// 等待超时时间(毫秒为单位)，为0默认5000ms
	int					nConnectTime;			// 连接超时时间(毫秒为单位)，为0默认1500ms
	int					nConnectTryNum;			// 连接尝试次数，为0默认1次
	int					nSubConnectSpaceTime;	// 子连接之间的等待时间(毫秒为单位)，为0默认10ms
	int					nGetDevInfoTime;		// 获取设备信息超时时间，为0默认1000ms
	int					nConnectBufSize;		// 每个连接接收数据缓冲大小(字节为单位)，为0默认250*1024
	int					nGetConnInfoTime;		// 获取子连接信息超时时间(毫秒为单位)，为0默认1000ms
	BYTE				bReserved[20];			// 保留字段
} NET_PARAM;

// 对应ISIL_CLIENT_SearchDevices接口
typedef struct
{
	char				szIP[ISIL_MAX_IPADDR_LEN];		// IP
	int					nPort;							// 端口
	char				szSubmask[ISIL_MAX_IPADDR_LEN];	// 子网掩码
	char				szGateway[ISIL_MAX_IPADDR_LEN];	// 网关
	char				szMac[ISIL_MACADDR_LEN];			// MAC地址
	char				szDeviceType[ISIL_DEV_TYPE_LEN];	// 设备类型
	BYTE				bReserved[32];					// 保留字节
} DEVICE_NET_INFO;

//-------------------------------报警属性---------------------------------

// 云台联动
typedef struct
{
	int					iType;
	int					iValue;
} ISIL_PTZ_LINK, *LPISIL_PTZ_LINK;

// 报警联动结构体
typedef struct
{
	/* 消息处理方式，可以同时多种处理方式，包括
	 * 0x00000001 - 报警上传
	 * 0x00000002 - 联动录象
	 * 0x00000004 - 云台联动
	 * 0x00000008 - 发送邮件
	 * 0x00000010 - 本地轮巡
	 * 0x00000020 - 本地提示
	 * 0x00000040 - 报警输出
	 * 0x00000080 - Ftp上传
	 * 0x00000100 - 蜂鸣
	 * 0x00000200 - 语音提示
	 * 0x00000400 - 抓图
	*/

	/* 当前报警所支持的处理方式，按位掩码表示 */
	DWORD				dwActionMask;

	/* 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 */
	DWORD				dwActionFlag;

	/* 报警触发的输出通道，报警触发的输出，为1表示触发该输出 */
	BYTE				byRelAlarmOut[ISIL_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/* 报警持续时间 */

	/* 联动录象 */
	BYTE				byRecordChannel[ISIL_MAX_VIDEO_IN_NUM]; /* 报警触发的录象通道，为1表示触发该通道 */
	DWORD				dwRecLatch;				/* 录象持续时间 */

	/* 抓图通道 */
	BYTE				bySnap[ISIL_MAX_VIDEO_IN_NUM];
	/* 轮巡通道 */
	BYTE				byTour[ISIL_MAX_VIDEO_IN_NUM];

	/* 云台联动 */
	ISIL_PTZ_LINK			struPtzLink[ISIL_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* 联动开始延时时间，s为单位，范围是0~15，默认值是0 */
	/* 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 */
	BYTE				byRelWIAlarmOut[ISIL_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*短信报警使能*/
	BYTE                bySnapshotTimes;       /*短信发送抓图张数 */
	BYTE				bMatrixEn;				/*!< 矩阵使能 */
	DWORD				dwMatrix;				/*!< 矩阵掩码 */
	BYTE				bLog;					/*!< 日志使能，目前只有在WTN动态检测中使用 */
	BYTE				byReserved[103];
} ISIL_MSG_HANDLE;

// 外部报警
typedef struct
{
	BYTE				byAlarmType;			// 报警器类型，0：常闭，1：常开
	BYTE				byAlarmEn;				// 报警使能
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struHandle;				// 处理方式
} ISIL_ALARMIN_CFG, *LPISIL_DEV_ALARMIN_CFG;

// 动态检测报警
typedef struct
{
	BYTE				byMotionEn;				// 动态检测报警使能
	BYTE				byReserved;
	WORD				wSenseLevel;			// 灵敏度
	WORD				wMotionRow;				// 动态检测区域的行数
	WORD				wMotionCol;				// 动态检测区域的列数
	BYTE				byDetected[ISIL_MOTION_ROW][ISIL_MOTION_COL]; // 检测区域，最多32*32块区域
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				//处理方式
} ISIL_MOTION_DETECT_CFG;

// 视频丢失报警
typedef struct
{
	BYTE				byAlarmEn;				// 视频丢失报警使能
	BYTE				byReserved[3];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				// 处理方式
} ISIL_VIDEO_LOST_CFG;

// 图像遮挡报警
typedef struct
{
	BYTE				byBlindEnable;			// 使能
	BYTE				byBlindLevel;			// 灵敏度1-6
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE		struHandle;				// 处理方式
} ISIL_BLIND_CFG;

// 硬盘消息(内部报警)
typedef struct
{
	BYTE				byNoDiskEn;				// 无硬盘时报警
	BYTE				byReserved_1[3];
	ISIL_TSECT			stNDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struNDHandle;			// 处理方式

	BYTE				byLowCapEn;				// 硬盘低容量时报警
	BYTE				byLowerLimit;			// 容量阀值，0-99
	BYTE				byReserved_2[2];
	ISIL_TSECT			stLCSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struLCHandle;			// 处理方式

	BYTE				byDiskErrEn;			// 硬盘故障报警
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ISIL_TSECT			stEDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE		struEDHandle;			// 处理方式
} ISIL_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ISIL_MSG_HANDLE		struHandle;
} ISIL_NETBROKEN_ALARM_CFG;

// 报警布防
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

// 报警解码器配置
typedef struct
{
	DWORD				dwAddr;									// 报警解码器地址
	BOOL				bEnable;								// 报警解码器使能
	DWORD				dwOutSlots[DECODER_OUT_SLOTS_MAX_NUM];	// 现在只支持8个.
	int					nOutSlotNum;							// dwOutSlots数组有效元素个数.
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle[DECODER_IN_SLOTS_MAX_NUM];	// 现在只支持8个.
	int					nMsgHandleNum;							// stuHandle数组有效元素个数.
	BYTE				bReserved[120];
} ISIL_ALARMDEC_CFG;

// 报警上传的配置
typedef struct
{
	BYTE				byEnable;				// 上传使能
	BYTE				bReserverd;				//  保留
	WORD				wHostPort;				// 报警中心侦听端口
	char				sHostIPAddr[ISIL_MAX_IPADDR_LEN];		// 报警中心IP

	int					nByTimeEn;				// 定时上传使能，可以用来向中心上传IP或域名等
	int					nUploadDay;				/* 设置上传日期
													"Never = 0", "Everyday = 1", "Sunday = 2",
													"Monday = 3", Tuesday = 4", "Wednesday = 5",
													"Thursday = 6", "Friday = 7", "Saturday = 8"*/
	int					nUploadHour;			// 设置上传时间 ,[0~23]点

	DWORD				dwReserved[300]; 		// 保留待扩展。
} ALARMCENTER_UP_CFG;

// 全景切换报警配置
typedef struct __ISIL_PANORAMA_SWITCH_CFG
{
	BOOL				bEnable;				// 使能
	int					nReserved[5];			// 保留
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// 报警联动
} ISIL_PANORAMA_SWITCH_CFG;

typedef struct __ALARM_PANORAMA_SWITCH_CFG
{
	int					nAlarmChnNum;			// 报警通道个数
	ISIL_PANORAMA_SWITCH_CFG stuPanoramaSwitch[ISIL_MAX_VIDEO_IN_NUM];
} ALARM_PANORAMA_SWITCH_CFG;

// 失去焦点报警配置
typedef struct __ISIL_LOST_FOCUS_CFG
{
	BOOL				bEnable;				// 使能
	int					nReserved[5];			// 保留
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// 报警联动
} ISIL_LOST_FOCUS_CFG;

typedef struct __ALARM_LOST_FOCUS_CFG
{
	int					nAlarmChnNum;			// 报警通道个数
	ISIL_LOST_FOCUS_CFG stuLostFocus[ISIL_MAX_VIDEO_IN_NUM];
} ALARM_LOST_FOCUS_CFG;

// IP冲突检测报警配置
typedef struct __ALARM_IP_COLLISION_CFG
{
	BOOL				bEnable;				// 使能
	ISIL_MSG_HANDLE		struHandle;				// 报警联动
	int                 nReserved[300];			// 保留
}ALARM_IP_COLLISION_CFG;

//------------------------------多区域遮挡--------------------------------

// 遮挡信息
typedef struct __VIDEO_COVER_ATTR
{
	ISIL_RECT				rcBlock;				// 覆盖的区域坐标
	int					nColor;					// 覆盖的颜色
	BYTE				bBlockType;				// 覆盖方式；0：黑块，1：马赛克
	BYTE				bEncode;				// 编码级遮挡；1：生效，0：不生效
	BYTE				bPriview;				// 预览遮挡； 1：生效，0：不生效
	char				reserved[29];			// 保留
} VIDEO_COVER_ATTR;

// 多区域遮挡配置
typedef struct __ISIL_DEV_VIDEOCOVER_CFG
{
	DWORD				dwSize;
	char				szChannelName[ISIL_CHAN_NAME_LEN]; // 只读
	BYTE				bTotalBlocks;			// 支持的遮挡块数
	BYTE				bCoverCount;			// 已设置的遮挡块数
	VIDEO_COVER_ATTR	CoverBlock[ISIL_MAX_VIDEO_COVER_NUM]; // 覆盖的区域
	char				reserved[30];			// 保留
}ISIL_DEV_VIDEOCOVER_CFG;

////////////////////////////////IPC产品支持////////////////////////////////

// 配置无线网络信息
typedef struct
{
	int					nEnable;				// 无线使能
	char				szSSID[36];				// SSID
	int					nLinkMode;				// 连接模式；0：auto，1：adhoc，2：Infrastructure
	int					nEncryption;			// 加密；0：off，2：WEP64bit，3：WEP128bit
	int					nKeyType;				// 0：Hex，1：ASCII
    int					nKeyID;					// 序号
	char				szKeys[4][32];			// 四组密码
	int					nKeyFlag;
	char				reserved[12];
} ISIL_DEV_WLAN_INFO;

// 选择使用某个无线设备
typedef struct
{
	char				szSSID[36];
	int					nLinkMode;				// 连接模式；0：adhoc，1：Infrastructure
	int 				nEncryption;			// 加密；0：off，2：WEP64bit，3：WEP128bit
	char				reserved[48];
} ISIL_DEV_WLAN_DEVICE;

// 搜索到的无线设备列表
typedef struct
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// 搜索到的无线设备个数
	ISIL_DEV_WLAN_DEVICE	lstWlanDev[ISIL_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} ISIL_DEV_WLAN_DEVICE_LIST;

// 主动注册参数配置
typedef struct
{
	char				szServerIp[32];			// 注册服务器IP
	int					nServerPort;			// 端口号
	char				reserved[64];
} ISIL_DEV_SERVER_INFO;

typedef struct
{
	DWORD				dwSize;
	BYTE				bServerNum;				// 支持的最大ip数
	ISIL_DEV_SERVER_INFO	lstServer[ISIL_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// 使能
	char				szDeviceID[32];			// 设备id
	char				reserved[94];
} ISIL_DEV_REGISTER_SERVER;

// 摄像头属性
typedef struct __ISIL_DEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// 亮度可调；1：可，0：不可
	BYTE				bContrastEn;			// 对比度可调
	BYTE				bColorEn;				// 色度可调
	BYTE				bGainEn;				// 增益可调
	BYTE				bSaturationEn;			// 饱和度可调
	BYTE				bBacklightEn;			// 背光补偿 0表示不支持背光补偿,1表示支持一级补偿（开,关），2表示支持两级补偿（关,高,低），3表示支持三级补偿（关,高,中,低）
	BYTE				bExposureEn;			// 曝光选择 0表示不支持曝光控制，1表示只支持自动曝光，其他表示支持的曝光速度等级数，即手动控制的等级数+1
	BYTE				bColorConvEn;			// 自动彩黑转换可调
	BYTE				bAttrEn;				// 属性选项；1：可，0：不可
	BYTE				bMirrorEn;				// 镜像；1：支持，0：不支持
    BYTE				bFlipEn;				// 翻转；1：支持，0：不支持
	BYTE				iWhiteBalance;			// 白平衡 2 支持情景模式， 1 支持白平衡 ，0 不支持
	BYTE				iSignalFormatMask;		// 信号格式掩码，按位从低到高位分别为：0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRev[123];				// 保留
} ISIL_DEV_CAMERA_INFO;

// 摄像头属性配置
typedef struct __ISIL_DEV_CAMERA_CFG
{
	DWORD				dwSize;
	BYTE				bExposure;				// 曝光模式；取值范围取决于设备能力集：0-自动曝光，1-曝光等级1，2-曝光等级2…n-最大曝光等级数
	BYTE				bBacklight;				// 背光补偿：背光补偿等级取值范围取决于设备能力集，0-关闭，1-背光补偿强度1，2-背光补偿强度2…n-最大背光补偿等级数
	BYTE				bAutoColor2BW;			// 日/夜模式；2：开(黑白)，1：自动，0：关(彩色)
	BYTE				bMirror;				// 镜像；1：开，0：关
	BYTE				bFlip;					// 翻转；1：开，0：关
	BYTE				bLensEn;				// 自动光圈功能能力: 1：支持；0 ：不支持
	BYTE				bLensFunction;			// 自动光圈功能: 1:开启自动光圈；0: 关闭自动光圈
	BYTE				bWhiteBalance;			// 白平衡 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night
	BYTE				bSignalFormat;			// 信号格式0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	char				bRev[119];				// 保留
} ISIL_DEV_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (无线)红外报警配置
typedef struct
{
	BOOL				bEnable;				// 报警输入使能
	char				szAlarmName[ISIL_MAX_ALARM_NAME];	// 报警输入名称
	int					nAlarmInPattern;		// 报警器输入波形
	int					nAlarmOutPattern;		// 报警输出波形
	char				szAlarmInAddress[ISIL_MAX_ALARM_NAME];// 报警输入地址
	int					nSensorType;			// 外部设备传感器类型常开 or 常闭
	int					nDefendEfectTime;		// 布撤防延时时间，在此时间后该报警输入有效
	int					nDefendAreaType;		// 防区类型
	int					nAlarmSmoothTime;		// 报警平滑时间，即在此时间内如果只有一个报警输入连续输入两次则忽略掉后面一次
	char				reserved[128];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// 处理方式
} ISIL_INFRARED_INFO;

// 无线遥控器配置
typedef struct
{
	BYTE				address[ALARM_MAX_NAME];// 遥控器地址
	BYTE				name[ALARM_MAX_NAME];	// 遥控器名称
	BYTE				reserved[32];			// 保留字段
} ISIL_WI_CONFIG_ROBOT;

// 无线报警输出配置
typedef struct
{
	BYTE				address[ALARM_MAX_NAME];// 报警输出地址
	BYTE				name[ALARM_MAX_NAME];	// 报警输出名称
	BYTE				reserved[32];			// 保留字段
} ISIL_WI_CONFIG_ALARM_OUT;

typedef struct
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// 无线报警输入数
	BYTE				bAlarmOutNum;			// 无线报警输出数
	ISIL_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// 报警输出地址
	BYTE				bRobotNum;				// 遥控器个数
	ISIL_WI_CONFIG_ROBOT RobotAddr[16];			// 遥控器地址
	ISIL_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} ISIL_INFRARED_CFG;

// 新音频检测报警信息
typedef struct
{
	int					channel;				// 报警通道号
	int					alarmType;				// 报警类型；0：音频值过低，1：音频值过高
	unsigned int		volume;					// 音量值
	char				reserved[256];
} NET_NEW_SOUND_ALARM_STATE;

typedef struct
{
	int					channelcount;			// 报警的通道个数
	NET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[ISIL_MAX_ALARM_IN_NUM];
} ISIL_NEW_SOUND_ALARM_STATE;

// 抓图功能属性结构体
typedef struct
{
	int					nChannelNum;			// 通道号
	DWORD				dwVideoStandardMask;	// 分辨率(按位)，具体查看枚举CAPTURE_SIZE
	int					nFramesCount;			// Frequence[128]数组的有效长度
	char				Frames[128];			// 帧率(按数值)
												// -25：25秒1帧；-24：24秒1帧；-23：23秒1帧；-22：22秒1帧
												// ……
												// 0：无效；1：1秒1帧；2：1秒2帧；3：1秒3帧
												// 4：1秒4帧；5：1秒5帧；17：1秒17帧；18：1秒18帧
												// 19：1秒19帧；20：1秒20帧
												// ……
												// 25: 1秒25帧
	int					nSnapModeCount;			// SnapMode[16]数组的有效长度
	char				SnapMode[16];			// (按数值)0：定时触发抓图，1：手动触发抓图
	int					nPicFormatCount;		// Format[16]数组的有效长度
	char 				PictureFormat[16];		// (按数值)0：BMP格式，1：JPG格式
	int					nPicQualityCount;		// Quality[32]数组的有效长度
	char 				PictureQuality[32];		// 按数值
												// 100：图象质量100%；80:图象质量80%；60:图象质量60%
												// 50:图象质量50%；30:图象质量30%；10:图象质量10%
	char 				nReserved[128];			// 保留
} ISIL_QUERY_SNAP_INFO;

typedef struct
{
	int					nChannelCount;			// 通道个数
	ISIL_QUERY_SNAP_INFO  stuSnap[ISIL_MAX_CHANNUM];
} ISIL_SNAP_ATTR_EN;


/* IP过滤功能配置 */
#define ISIL_IPIFILTER_NUM			200			// IP

// IP信息
typedef struct
{
	DWORD				dwIPNum;				// IP个数
	char				SZIP[ISIL_IPIFILTER_NUM][ISIL_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// 保留
} IPIFILTER_INFO;

// IP过滤配置结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwType;					// 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
	IPIFILTER_INFO		BannedIP;				// 黑名单
	IPIFILTER_INFO		TrustIP;				// 白名单
	char				byReserve[256];			// 保留
} ISIL_DEV_IPIFILTER_CFG;

/*语音对讲编码配置*/
typedef struct
{
	DWORD				dwSize;
	int					nCompression;			// 压缩格式，枚举值，相见ISIL_TALK_CODING_TYPE，请根据设备支持的语音对讲类型设置压缩格式。
	int					nMode;					// 编码模式，枚举值，为0时表示该压缩格式不支持编码模式。
												// 根据压缩格式可以设置对应的编码格式，如
												// AMR详见EM_ARM_ENCODE_MODE
	char				byReserve[256];			// 保留
} ISIL_DEV_TALK_ENCODE_CFG;

// 以下是mobile功能相关
// (事件触发多媒体彩信/短信发送)MMS配置结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwReceiverNum;			// 短信接收者个数
	char				SZReceiver[ISIL_MMS_RECEIVER_NUM][32];	// 短信接收者，一般为手机号码
    BYTE                byType;					// 短信信息类型 0:MMS；1:SMS
	char                SZTitle[32];			// 短信信息标题
	char				byReserve[223];			// 保留
} ISIL_DEV_MMS_CFG;

// (短信激活无线连接配置)
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwSenderNum;			// 短信发送者个数
	char				SZSender[ISIL_MMS_SMSACTIVATION_NUM][32];	// 短信发送者，一般为手机号码
 	char				byReserve[256];			// 保留
}ISIL_DEV_SMSACTIVATION_CFG;

// (拨号激活无线连接配置)
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwCallerNum;			// 发送者个数
	char				SZCaller[ISIL_MMS_DIALINACTIVATION_NUM][32];	// 发送者, 一般为手机号码
 	char				byReserve[256];			// 保留
}ISIL_DEV_DIALINACTIVATION_CFG;
// 以上是mobile功能相关


// 无线网络信号强度结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwTDSCDMA;				// TD-SCDMA强度，范围：0－100
	DWORD				dwWCDMA;				// WCDMA强度，范围：0－100
	DWORD				dwCDMA1x;				// CDMA1x强度，范围：0－100
	DWORD				dwEDGE;					// EDGE强度，范围：0－100
	DWORD				dwEVDO;					// EVDO强度，范围：0－100
	int					nCurrentType;			// 当前类型
												// 0	设备不支持这一项
												// 1    TD_SCDMA
												// 2	WCDMA
												// 3	CDMA_1x
												// 4	EDGE
												// 5	EVDO
	char				byReserve[252];			// 保留
} ISIL_DEV_WIRELESS_RSS_INFO;

/***************************** 云台预制点配置 ***********************************/
typedef struct _POINTEANBLE
{
	BYTE				bPoint;	//预制点的有效范围闭区间[1,80]，无效设置为0。
	BYTE				bEnable;	//是否有效,0无效，1有效
	BYTE				bReserved[2];
} POINTEANBLE;

typedef struct _POINTCFG
{
	char				szIP[ISIL_MAX_IPADDR_LEN];// ip
	int					nPort;					// 端口
	POINTEANBLE			stuPointEnable[80];		// 预制点使能
	BYTE				bReserved[256];
}POINTCFG;

typedef struct _ISIL_DEV_POINT_CFG
{
	int					nSupportNum;			// 只读参数，设置的时候需要返回给sdk，表示支持的预制点数
	POINTCFG			stuPointCfg[16];	// 二维下标表示通道号。要设置的点数值放在前nSupportNum个下标里面。
	BYTE				bReserved[256];			// 保留
}ISIL_DEV_POINT_CFG;
////////////////////////////////车载DVR支持////////////////////////////////

// GPS信息(车载设备)
typedef struct _GPS_Info
{
    NET_TIME			revTime;				// 定位时间
	char				DvrSerial[50];			// 设备序列号
    double				longitude;				// 经度
    double				latidude;				// 纬度
    double				height;					// 高度(米)
    double				angle;					// 方向角(正北方向为原点，顺时针为正)
    double				speed;					// 速度(公里/小时)
    WORD				starCount;				// 定位星数
    BOOL				antennaState;			// 天线状态(true 好，false 坏)
    BOOL				orientationState;		// 定位状态(true 定位，false 不定位)
} GPS_Info,*LPGPS_Info;

// 抓图参数结构体
typedef struct _snap_param
{
	unsigned int		Channel;				// 抓图的通道
	unsigned int		Quality;				// 画质；1~6
	unsigned int		ImageSize;				// 画面大小；0：QCIF，1：CIF，2：D1
	unsigned int		mode;					// 抓图模式；0：表示请求一帧，1：表示定时发送请求，2：表示连续请求
	unsigned int		InterSnap;				// 时间单位秒；若mode=1表示定时发送请求时，此时间有效
	unsigned int		CmdSerial;				// 请求序列号
	unsigned int		Reserved[4];
} SNAP_PARAMS, *LPSNAP_PARAMS;

// 抓图功能配置
typedef struct
{
	DWORD				dwSize;
	BYTE				bTimingEnable;				// 定时抓图开关(报警抓图开关在各报警联动配置中体现)
	BYTE                bReserved;
	short	            PicTimeInterval;			// 定时抓图时间间隔，单位为秒,目前设备支持最大的抓图时间间隔为30分钟
	ISIL_VIDEOENC_OPT		struSnapEnc[SNAP_TYP_NUM]; // 抓图编码配置，现支持其中的分辨率、画质、帧率设置，帧率在这里是负数，表示一秒抓图的次数。
} ISIL_DEV_SNAP_CFG;

//////////////////////////////////ATM支持//////////////////////////////////

typedef struct
{
	int					Offset;					// 标志位的位偏移
	int					Length;					// 标志位的长度
	char				Key[16];				// 标志位的值
} ISIL_SNIFFER_FRAMEID;

typedef struct
{
	int					Offset;					// 标志位的位偏移
	int					Offset2;				// 目前没有应用
	int					Length;					// 标志位的长度
	int					Length2;				// 目前没有应用
	char				KeyTitle[24];			// 标题的值
} ISIL_SNIFFER_CONTENT;

// 网络抓包配置
typedef struct
{
	ISIL_SNIFFER_FRAMEID	snifferFrameId;			// 每个FRAME ID 选项
	ISIL_SNIFFER_CONTENT	snifferContent[ISIL_SNIFFER_CONTENT_NUM];	// 每个FRAME对应的4个抓包内容
} ISIL_SNIFFER_FRAME;

// 每组抓包对应的配置结构
typedef struct
{
	char				SnifferSrcIP[ISIL_MAX_IPADDR_LEN];	// 抓包源地址
	int					SnifferSrcPort;			// 抓包源端口
	char				SnifferDestIP[ISIL_MAX_IPADDR_LEN];	// 抓包目标地址
	int					SnifferDestPort;		// 抓包目标端口
	char				reserved[28];			// 保留字段
	ISIL_SNIFFER_FRAME	snifferFrame[ISIL_SNIFFER_FRAMEID_NUM];	// 6个FRAME 选项
	int					displayPosition;		// 显示位置
	int					recdChannelMask;		// 通道掩码
} ISIL_ATM_SNIFFER_CFG;

typedef struct
{
	DWORD				dwSize;
	ISIL_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];			// 保留字段
} ISIL_DEV_SNIFFER_CFG;

typedef ISIL_SNIFFER_FRAMEID ISIL_SNIFFER_FRAMEID_EX;
typedef ISIL_SNIFFER_CONTENT ISIL_SNIFFER_CONTENT_EX;

// 网络抓包配置
typedef struct
{
	ISIL_SNIFFER_FRAMEID	snifferFrameId;								// 每个FRAME ID 选项
	ISIL_SNIFFER_CONTENT	snifferContent[ISIL_SNIFFER_CONTENT_NUM_EX];	// 每个FRAME对应的8个抓包内容
} ISIL_SNIFFER_FRAME_EX;

// 每组抓包对应的配置结构
typedef struct
{
	char				SnifferSrcIP[ISIL_MAX_IPADDR_LEN];					// 抓包源地址
	int					SnifferSrcPort;										// 抓包源端口
	char				SnifferDestIP[ISIL_MAX_IPADDR_LEN];					// 抓包目标地址
	int					SnifferDestPort;									// 抓包目标端口
	ISIL_SNIFFER_FRAME_EX	snifferFrame[ISIL_SNIFFER_FRAMEID_NUM];				// 6个FRAME 选项
	int					displayPosition;									// 显示位置
	int					recdChannelMask;									// 通道掩码
	BOOL				bDateScopeEnable;									// 数据来源使能
	BOOL				bProtocolEnable;									// 协议使能
	char				szProtocolName[ISIL_SNIFFER_PROTOCOL_SIZE];			// 协议名字
	int					nSnifferMode;										// 抓包方式，0:net,1:232.
	char				reserved[256];
} ISIL_ATM_SNIFFER_CFG_EX;

/////////////////////////////////解码器支持/////////////////////////////////

// 解码器信息
typedef struct __DEV_DECODER_INFO
{
	char			szDecType[64];			// 类型
	int				nMonitorNum;			// TV个数
	int				nEncoderNum;			// 解码通道个数
	BYTE			szSplitMode[16];		// 支持的TV画面分割数，以数组形式表示，0为结尾
	BYTE            bMonitorEnable[16];		// 各TV使能
	char			reserved[64];
} DEV_DECODER_INFO, *LPDEV_DECODER_INFO;

// 连接的编码器信息
typedef struct __DEV_ENCODER_INFO
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// 密码
	int				nDevChannel;						// 通道号
	int				nStreamType;						// 码流类型，0：主码流；1：子码流
	BYTE			byConnType;							// 0：TCP；1：UDP；2：组播
	BYTE			byWorkMode;							// 0：直连；1：转发
	WORD			wListenPort;						// 指示侦听服务的端口，转发时有效
	DWORD			dwProtoType;						// 协议类型,
														// 0:兼容以前
	char			szDevName[64];						// 前端设备名称
	char			reserved[116];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

// TV参数信息
typedef struct __DEV_DECODER_TV
{
	int				nID;								// TV号
	BOOL			bEnable;							// 使能，开启或关闭
	int				nSplitType;							// 画面分割数
	DEV_ENCODER_INFO stuDevInfo[16];					// 各画面编码器信息
	char			reserved[16];
} DEV_DECODER_TV, *LPDEV_DECODER_TV;

// 解码器画面组合信息
typedef struct __DEC_COMBIN_INFO
{
	int				nCombinID;							// 组合ID
	int             nSplitType;							// 画面分割数
	BYTE            bDisChn[16];						// 显示通道
	char			reserved[16];
} DEC_COMBIN_INFO, *LPDEC_COMBIN_INFO;

// 解码器轮巡信息
#define DEC_COMBIN_NUM 			32						// 轮巡组合个数
typedef struct __DEC_TOUR_COMBIN
{
	int				nTourTime;							// 轮巡间隔(秒)
	int				nCombinNum;							// 组合个数
	BYTE			bCombinID[DEC_COMBIN_NUM];			// 组合表
	char			reserved1[32];
	BYTE			bCombinState[DEC_COMBIN_NUM];		// 组合项的使能状态，0：关；1：开
	char			reserved2[32];
} DEC_TOUR_COMBIN, *LPDEC_TOUR_COMBIN;

// 解码器回放类型
typedef enum __DEC_PLAYBACK_MODE
{
	Dec_By_Device_File = 0,								// 前端设备－按文件方式
	Dec_By_Device_Time,									// 前端设备－按时间方式
} DEC_PLAYBACK_MODE;

// 解码器回放控制类型
typedef enum __DEC_CTRL_PLAYBACK_TYPE
{
	Dec_Playback_Seek = 0,								// 拖动
	Dec_Playback_Play,									// 播放
	Dec_Playback_Pause,									// 暂停
	Dec_Playback_Stop,									// 停止
} DEC_CTRL_PLAYBACK_TYPE;

// 按文件回放前端设备条件
typedef struct __DEC_PLAYBACK_FILE_PARAM
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// 密码
	NET_RECORDFILE_INFO stuRecordInfo;					// 录像文件信息
	char			reserved[12];
} DEC_PLAYBACK_FILE_PARAM, *LPDEC_PLAYBACK_FILE_PARAM;

// 按时间回放前端设备条件
typedef struct __DEC_PLAYBACK_TIME_PARAM
{
	char			szDevIp[ISIL_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ISIL_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ISIL_USER_PSW_LENGTH_EX];	// 密码
	int				nChannelID;
	NET_TIME		startTime;
	NET_TIME		endTime;
	char			reserved[12];
} DEC_PLAYBACK_TIME_PARAM, *LPDEC_PLAYBACK_TIME_PARAM;

// 当前解码通道状态信息(包括通道状态，解码流信息等)
typedef struct __DEV_DECCHANNEL_STATE
{
	BYTE			byEncoderID;						// 对应解码通道号
	BYTE            byChnState;                         // 当前解码通道正在操作状态:0－空闲，1－实时监视，2－回放
	BYTE			byFrame;                            // 当前数据帧率
	BYTE            byReserved;                         // 保留
	int				nChannelFLux;						// 解码通道数据总量
	int             nDecodeFlux;						// 解码数据量
	char            szResolution[16];                   // 当前数据分辨率
	char			reserved[256];
} DEV_DECCHANNEL_STATE, *LPDEV_DECCHANNEL_STATE;

// 设备TV输出参数信息
typedef struct __DEV_VIDEOOUT_INFO
{
	DWORD				dwVideoStandardMask;			// NSP,视频制式掩码，按位表示设备能够支持的视频制式(暂不支持)
	int					nVideoStandard;                 // NSP,当前的制式(暂不支持，请使用ISIL_DEV_SYSTEM_ATTR_CFG的byVideoStandard对制式读取和配置)
	DWORD				dwImageSizeMask;				// 分辨率掩码，按位表示设备能够支持的分辨率
	int                 nImageSize;                     // 当前的分辨率
	char				reserved[256];
}DEV_VIDEOOUT_INFO, *LPDEV_VIDEOOUT_INFO;

/////////////////////////////////特殊版本/////////////////////////////////

// 触发设备抓图，叠加卡号信息
typedef struct __NET_SNAP_COMMANDINFO
{
	char				szCardInfo[16];			// 卡号信息
	char				reserved[64];			// 保留
} NET_SNAP_COMMANDINFO, LPNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// 通道号
	char				szUseType[32];			// 通道用途
	DWORD				dwStreamSize;			// 流量大小(单位：kb/s)
	char				reserved[32];			// 保留
} ISIL_DEV_USE_CHANNEL_STATE;

typedef struct
{
	char				szUserName[32];			// 用户名
	char				szUserGroup[32];		// 用户组
	NET_TIME			time;					// 登入时间
	int					nOpenedChannelNum;		// 开启的通道个数
	ISIL_DEV_USE_CHANNEL_STATE	channelInfo[ISIL_MAX_CHANNUM];
	char				reserved[64];
} ISIL_DEV_USER_NET_INFO;

// 网络运行状态信息
typedef	struct
{
	int					nUserCount;				// 用户数量
	ISIL_DEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}ISIL_DEV_TOTAL_NET_STATE;

// 图象水印配置
typedef struct __ISIL_DEV_WATERMAKE_CFG
{
	DWORD				dwSize;
	int					nEnable;				// 使能
	int					nStream;				// 码流(1～n)0-所有码流
	int					nKey;					// 数据类型(1-文字，2-图片)
	char				szLetterData[ISIL_MAX_WATERMAKE_LETTER];	//	文字
	char				szData[ISIL_MAX_WATERMAKE_DATA]; // 图片数据
	BYTE				bReserved[512];			// 保留
} ISIL_DEV_WATERMAKE_CFG;

// 存储位置设置结构体，每通道独立设置,每通道可以选择各种存储类型, 目前包括本地, 可移动, 远程存储.
typedef struct
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// 本地存储掩码；按位表示：
												// 第一位：系统预录，第二位：定时录像，第三位：动检录像，
												// 第四位：报警录像，第五位：卡号录像，第六位：手动录像
	DWORD				dwMobileMask;			// 可移动存储掩码 存储掩码如本地存储掩码
	int					RemoteType;				// 远程存储类型 0: Ftp  1: Smb
	DWORD				dwRemoteMask;			// 远程存储掩码 存储掩码如本地存储掩码
	DWORD				dwRemoteSecondSelLocal;	// 远程异常时本地存储掩码
	DWORD				dwRemoteSecondSelMobile;// 远程异常时可移动存储掩码
	char				SubRemotePath[MAX_PATH_STOR]; // 远程目录, 其中长度为240
	DWORD				dwFunctionMask;			//功能屏蔽位，按位表示，bit0 = 1:屏蔽抓图事件触发存储位置功能

	char				reserved[124];
} ISIL_STORAGE_STATION_CFG;

#define MAX_ALARM_DECODER_NUM 16
typedef struct
{
	DWORD				dwAlarmDecoder;			// 现在最多支持8个报警输入口，留8位待以后扩展
	BYTE				bDecoderIndex;			// 表示第几个报警解码器
	BYTE				bReserved[3];
} ALARM_DECODER;

// 报警解码器报警
typedef struct
{
	int					nAlarmDecoderNum;
	ALARM_DECODER		stuAlarmDecoder[MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ALARM_DECODER_ALARM;

//DSP报警
typedef struct
{
	BOOL				bError;			//0,DSP正常 1,DSP异常
	DWORD				dwErrorMask;	//按位表示，非0表示有此错误，0表示没有。(目前每次报警只有一位有效)
										//bit		DSP报警
										//1			DSP加载失败
										//2			DSP错误
										//3			制式不对
										//4			分辨率不支持
										//5			数据格式不支持
										//6			找不到I帧
	DWORD               dwDecChnnelMask;//按位表示，报警的解码通道号，dwErrorMask为DSP错误，制式不对，分辨率不支持，数据格式不支持时此项有效

	BYTE				bReserved[28];
}DSP_ALARM;

// 光纤编码能力报警
typedef struct
{
	int		nFDDINum;
	BYTE	bAlarm[256];
} ALARM_FDDI_ALARM;

// 新音频检测报警配置
typedef struct
{
	BOOL				bEnable;				// 报警输入使能
	int					Volume_min;				// 音量的最小值
	int					Volume_max;				// 音量的最大值
	char				reserved[128];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];
	ISIL_MSG_HANDLE		struHandle;				// 处理方式
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
	BOOL				bTourEnable;			// 轮巡使能
	int					nTourPeriod;			// 轮巡间隔，单位秒, 5-300
	DWORD				dwChannelMask;			// 轮巡的通道，掩码形式表示
	char				reserved[64];
}ISIL_VIDEOGROUP_CFG;

// 本机矩阵控制策略配置
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// 矩阵个数(注：不允许修改)
	ISIL_VIDEOGROUP_CFG	struVideoGroup[ISIL_MATRIX_MAXOUT];
	char				reserved[32];
} ISIL_DEV_VIDEO_MATRIX_CFG;

// WEB路径配置
typedef struct
{
	DWORD				dwSize;
	BOOL				bSnapEnable;			// 是否抓图
	int					iSnapInterval;			// 抓图周期
	char				szHostIp[ISIL_MAX_IPADDR_LEN]; // HTTP主机IP
	WORD				wHostPort;
	int					iMsgInterval;			// 状态消息发送间隔
	char				szUrlState[ISIL_MAX_URL_LEN];	// 状态消息上传URL
	char				szUrlImage[ISIL_MAX_URL_LEN];	// 图片上传Url
	char				szDevId[ISIL_MAX_DEV_ID_LEN];	// 机器的web编号
	BYTE				byReserved[2];
} ISIL_DEV_URL_CFG;

// OEM查询
typedef struct
{
	char				szVendor[ISIL_MAX_STRING_LEN];
	char				szType[ISIL_MAX_STRING_LEN];
	char				reserved[128];
} ISIL_DEV_OEM_INFO;


//视频OSD叠加配置
typedef struct
{
	DWORD	rgbaFrontground;		// 物件的前景；按字节表示，分别为红、绿、蓝和透明度
	DWORD	rgbaBackground;			// 物件的背景；按字节表示，分别为红、绿、蓝和透明度
	RECT	rcRelativePos;			// 位置,物件边距与整长的比例*8191
	BOOL	bPreviewBlend;			// 预览叠加使能
	BOOL	bEncodeBlend;			// 编码叠加使能
	BYTE    bReserved[4];           // 保留
} ISIL_DVR_VIDEO_WIDGET;

typedef struct
{
	ISIL_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD叠加的位置和背景色
	char 				SzOSD_Name[ISIL_VIDEO_OSD_NAME_NUM]; 		// OSD叠加的名称
}ISIL_DVR_VIDEOITEM;

// 每个通道的OSD信息
typedef struct
{
	DWORD 				dwSize;
	ISIL_DVR_VIDEOITEM 	StOSDTitleOpt [ISIL_VIDEO_CUSTOM_OSD_NUM]; 	// 每个通道的OSD信息
	BYTE    			bReserved[16];                  		  // 保留
} ISIL_DVR_VIDEOOSD_CFG;

// 配置CDMA/GPRS网络信息
// 时间段结构
typedef struct
{
	BYTE				bEnable;				  // 时间段使能，1表示该时间段有效，0表示该时间段无效。
	BYTE				bBeginHour;
	BYTE				bBeginMin;
	BYTE				bBeginSec;
	BYTE				bEndHour;
	BYTE				bEndMin;
	BYTE				bEndSec;
	BYTE    			bReserved;                //保留
} ISIL_3G_TIMESECT, *LPISIL_3G_TIMESECT;

typedef struct
{
	DWORD 				dwSize;
	BOOL				bEnable;					// 无线模块使能标志
	DWORD               dwTypeMask;                 // 设备支持网络类型掩码;按位表示,第一位;自动选择;第二位：TD-SCDMA网络；
													// 第三位：WCDMA网络;第四位：CDMA 1.x网络;第五位：CDMA2000网络;第六位：GPRS网络;
													// 第七位：EVDO网络;第八位：WIFI
	DWORD               dwNetType;                  // 当前的无线网络类型，为EM_GPRSCDMA_NETWORK_TYPE值
	char				szAPN[128];					// 接入点名称
	char				szDialNum[128];				// 拨号号码
	char				szUserName[128];			// 拨号用户名
	char				szPWD[128];					// 拨号密码

	/* 下面是设备的只读部分 */
	BOOL				iAccessStat;				// 无线网络注册状态
    char				szDevIP[16];				// 前端设备拨号IP，字符串, 包括'\0'结束符共16byte
	char				szSubNetMask [16];			// 前端设备拨号子网掩码，字符串, 包括'\0'结束符共16byte
	char				szGateWay[16];				// 前端设备拨号网关，字符串, 包括'\0'结束符共16byte
	/* 上面是设备的只读部分 */
	int                 iKeepLive;					// 保活时间
	ISIL_3G_TIMESECT		stSect[ISIL_N_WEEKS][ISIL_N_TSECT];// 3G拨号时间段，有效时间段之内，开启拨号；有效时间段之外，关闭拨号。
	BYTE                byActivate;                  //是否需要被语音或短信激活
	char				Reserved[171];				// 保留字节，用于扩展
} ISIL_DEV_CDMAGPRS_CFG;

// 录像打包长度配置
typedef struct
{
	DWORD 				dwSize;
	int					nType;						// 0:按时间，1：按大小
	int					nValue;						// nType = 0时:单位分钟，nType = 1时:单位KB
	char				Reserved[128];				// 保留字节，用于扩展
} ISIL_DEV_RECORD_PACKET_CFG;

// (定向)主动注册服务器信息
typedef struct __DEV_AUTOREGISTER_INFO
{
	LONG			lConnectionID;						// 连接ID
	char			szServerIp[ISIL_MAX_IPADDR_LEN];		// 主动注册服务器的IP
	int				nPort;								// 主动注册服务器端口0- 65535
	int             nState;                             // 服务器的状态：0－注册失败；1-注册成功; 2-连接失败
	char			reserved[16];
} DEV_AUTOREGISTER_INFO;

typedef struct __DEV_SERVER_AUTOREGISTER
{
	DWORD					dwSize;
	int						nRegisterSeverCount;											// 主动注册服务器个数
	DEV_AUTOREGISTER_INFO	stuDevRegisterSeverInfo[ISIL_CONTROL_AUTO_REGISTER_NUM];			// 各主动注册服务器信息
	char					reserved[256];
} DEV_SERVER_AUTOREGISTER, *LPDEV_SERVER_AUTOREGISTER;

// 附件刻录附件上传
typedef struct
{
	DWORD				dwSize;
	char				szSourFile[MAX_PATH_STOR];	// 源文件路径
	int					nFileSize;					// 源文件大小，如果小于等于0，sdk自行计算文件大小.
	char				szBurnFile[MAX_PATH_STOR];	// 刻录后的文件名
	BYTE				bReserved[64];
} ISIL_DEV_BURNFILE_TRANS_CFG;

// 郑州威科姆EC_U视频数据叠加使能配置
typedef struct
{
	BOOL				bEnable;					// 使能
	int					nPort;						// 端口
	BYTE				bReserved[64];
}ISIL_DEV_OSD_ENABLE_CFG;

/////////////////////////////////平台接入/////////////////////////////////

// 平台接入配置 － U网通
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[ISIL_INTERVIDEO_UCOM_CHANID];
} ISIL_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// 接入功能使能
	BOOL				bAliveEnable;			// 心跳使能
	DWORD				dwAlivePeriod;			// 心跳周期，单位秒，0-3600
	char				szServerIp[ISIL_MAX_IPADDR_LEN]; // CMS的IP
	WORD				wServerPort;			// CMS的Port
    char				szRegPwd[ISIL_INTERVIDEO_UCOM_REGPSW]; // 注册密码
	char				szDeviceId[ISIL_INTERVIDEO_UCOM_DEVID];// 设备id
	char				szUserName[ISIL_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[ISIL_INTERVIDEO_UCOM_USERPSW];
    ISIL_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[ISIL_MAX_CHANNUM]; // 通道id,en
} ISIL_DEV_INTERVIDEO_UCOM_CFG;

// 平台接入配置 － 阿尔卡特
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// 公司ID，数值，不同的第三方服务公司，考虑4字节对齐，目前只用数组第一个
    char				szDeviceNO[32];			// 前端设备序列号，字符串，包括'\0'结束符共32byte
    char				szVSName[32];			// 前端设备名称，字符串，包括'\0'结束符共16byte
    char				szVapPath[32];			// VAP路径
    unsigned short		usTcpPort;				// TCP端口，数值：数值 1~65535
    unsigned short		usUdpPort;				// UDP端口，数值：数值 1~65535
    char				bCsEnable[4];			// 中心服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szCsIP[16];				// 中心服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usCsPort[2];			// 中心服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    char				bHsEnable[4];			// 心跳服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szHsIP[16];				// 心跳服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usHsPort[2];			// 心跳服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int					iHsIntervalTime;		// 心跳服务器间隔周期，数值(单位:秒)
    char				bRsEnable[4];			// 注册服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szRsIP[16];				// 注册服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usRsPort[2];			// 注册服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int					iRsAgedTime;			// 注册服务器有效时间，数值(单位:小时)
    char				szAuthorizeServerIp[16];// 鉴权服务器IP
    unsigned short		usAuthorizePort[2];		// 鉴权服务器端口，考虑4字节对齐，目前只用数组第一个
    char				szAuthorizeUsername[32];// 鉴权服务器帐号
    char				szAuthorizePassword[36];// 鉴权服务器密码

    char				szIpACS[16];			// ACS(自动注册服务器) IP
    unsigned short		usPortACS[2];			// ACS Port，考虑4字节对齐，目前只用数组第一个
    char				szUsernameACS[32];		// ACS用户名
    char				szPasswordACS[36];		// ACS密码
    char				bVideoMonitorEnabled[4];// DVS是否定期上报前端视频信号监控信息，数值：true使能，false不使能
    int					iVideoMonitorInterval;	// 上报周期(分钟)

    char				szCoordinateGPS[64];	// GPS坐标
    char				szPosition[32];			// 设备位置
    char				szConnPass[36];			// 设备接入码
} ISIL_DEV_INTERVIDEO_BELL_CFG;

// 平台接入配置 － 中兴力维
typedef struct
{
	DWORD				dwSize;
	unsigned short		nSevPort;				// 服务器端口，数值，数值1~65535
    char				szSevIp[ISIL_INTERVIDEO_NSS_IP]; // 服务器IP地址，字符串，包括'\0'结束符共32byte
    char				szDevSerial[ISIL_INTERVIDEO_NSS_SERIAL]; // 前端设备序列号，字符串，包括'\0'结束符共32byte
    char				szUserName[ISIL_INTERVIDEO_NSS_USER];
    char				szPwd[ISIL_INTERVIDEO_NSS_PWD];
} ISIL_DEV_INTERVIDEO_NSS_CFG;


////////////////////////////////HDVR专用//////////////////////////////////
// 报警联动扩展结构体
typedef struct
{
	/* 消息处理方式，可以同时多种处理方式，包括
	 * 0x00000001 - 报警上传
	 * 0x00000002 - 联动录象
	 * 0x00000004 - 云台联动
	 * 0x00000008 - 发送邮件
	 * 0x00000010 - 本地轮巡
	 * 0x00000020 - 本地提示
	 * 0x00000040 - 报警输出
	 * 0x00000080 - Ftp上传
	 * 0x00000100 - 蜂鸣
	 * 0x00000200 - 语音提示
	 * 0x00000400 - 抓图
	*/

	/* 当前报警所支持的处理方式，按位掩码表示 */
	DWORD				dwActionMask;

	/* 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 */
	DWORD				dwActionFlag;

	/* 报警触发的输出通道，报警触发的输出，为1表示触发该输出 */
	BYTE				byRelAlarmOut[ISIL_MAX_ALARMOUT_NUM_EX];
	DWORD				dwDuration;				/* 报警持续时间 */

	/* 联动录象 */
	BYTE				byRecordChannel[ISIL_MAX_VIDEO_IN_NUM_EX]; /* 报警触发的录象通道，为1表示触发该通道 */
	DWORD				dwRecLatch;				/* 录象持续时间 */

	/* 抓图通道 */
	BYTE				bySnap[ISIL_MAX_VIDEO_IN_NUM_EX];
	/* 轮巡通道 */
	BYTE				byTour[ISIL_MAX_VIDEO_IN_NUM_EX];

	/* 云台联动 */
	ISIL_PTZ_LINK			struPtzLink[ISIL_MAX_VIDEO_IN_NUM_EX];
	DWORD				dwEventLatch;			/* 联动开始延时时间，s为单位，范围是0~15，默认值是0 */
	/* 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 */
	BYTE				byRelWIAlarmOut[ISIL_MAX_ALARMOUT_NUM_EX];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*短信报警使能*/
	BYTE                bySnapshotTimes;       /*短信发送抓图张数 */
	BYTE				bMatrixEn;				/*!< 矩阵使能 */
	DWORD				dwMatrix;				/*!< 矩阵掩码 */
	BYTE				bLog;					/*!< 日志使能，目前只有在WTN动态检测中使用 */
	BYTE				byReserved[511];
} ISIL_MSG_HANDLE_EX;

// 外部报警扩展
typedef struct
{
	BYTE				byAlarmType;			// 报警器类型，0：常闭，1：常开
	BYTE				byAlarmEn;				// 报警使能
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// 处理方式
} ISIL_ALARMIN_CFG_EX, *LPISIL_DEV_ALARMIN_CFG_EX;

// 动态检测报警
typedef struct
{
	BYTE				byMotionEn;				// 动态检测报警使能
	BYTE				byReserved;
	WORD				wSenseLevel;			// 灵敏度
	WORD				wMotionRow;				// 动态检测区域的行数
	WORD				wMotionCol;				// 动态检测区域的列数
	BYTE				byDetected[ISIL_MOTION_ROW][ISIL_MOTION_COL]; // 检测区域，最多32*32块区域
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX		struHandle;				//处理方式
} ISIL_MOTION_DETECT_CFG_EX;

// 视频丢失报警
typedef struct
{
	BYTE				byAlarmEn;				// 视频丢失报警使能
	BYTE				byReserved[3];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// 处理方式
} ISIL_VIDEO_LOST_CFG_EX;

// 图像遮挡报警
typedef struct
{
	BYTE				byBlindEnable;			// 使能
	BYTE				byBlindLevel;			// 灵敏度1-6
	BYTE				byReserved[2];
	ISIL_TSECT			stSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT];	//NSP
	ISIL_MSG_HANDLE_EX	struHandle;				// 处理方式
} ISIL_BLIND_CFG_EX;

// 硬盘消息(内部报警)
typedef struct
{
	BYTE				byNoDiskEn;				// 无硬盘时报警
	BYTE				byReserved_1[3];
	ISIL_TSECT			stNDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struNDHandle;			// 处理方式

	BYTE				byLowCapEn;				// 硬盘低容量时报警
	BYTE				byLowerLimit;			// 容量阀值，0-99
	BYTE				byReserved_2[2];
	ISIL_TSECT			stLCSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struLCHandle;			// 处理方式

	BYTE				byDiskErrEn;			// 硬盘故障报警
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ISIL_TSECT			stEDSect[ISIL_N_WEEKS][ISIL_N_REC_TSECT]; //NSP
	ISIL_MSG_HANDLE_EX	struEDHandle;			// 处理方式
} ISIL_DISK_ALARM_CFG_EX;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ISIL_MSG_HANDLE_EX	struHandle;
} ISIL_NETBROKEN_ALARM_CFG_EX;

// 前端接入配置参数信息
typedef struct __DEV_ENCODER_CFG
{
	int				nChannels;							// 数字通道个数
	DEV_ENCODER_INFO stuDevInfo[32];					// 各数字通道的前端编码器信息
	char			reserved[16];
} DEV_ENCODER_CFG, *LPDEV_ENCODER_CFG;


// 协议信息
typedef struct
{
	char				protocolname[12];		// 协议名
	unsigned int		baudbase;				// 波特率
	unsigned char		databits;				// 数据位
	unsigned char		stopbits;				// 停止位
	unsigned char		parity;					// 校验位
	unsigned char		reserve;
} PROTOCOL_INFO, *LPPROTOCOL_INFO;

// 语音对讲参数配置
typedef struct
{
	// 音频输入参数
	BYTE				byInFormatTag;			// 编码类型，如PCM
	BYTE				byInChannels;			// 声道数
	WORD				wInBitsPerSample;		// 采样深度
	DWORD				dwInSamplesPerSec;		// 采样率

	// 音频输出参数
	BYTE				byOutFormatTag;			// 编码类型，如PCM
	BYTE				byOutChannels;			// 声道数
	WORD				wOutBitsPerSample;		// 采样深度
	DWORD				dwOutSamplesPerSec;		// 采样率
} ISIL_DEV_TALK_CFG, *LPISIL_DEV_TALK_CFG;


extern S32  ISIL_ParseLocalNetMsg(U32 uiMsgType, S08 *data, S32 iLen, S32 iConnectfd);

#ifdef __cplusplus
}
#endif
#endif

