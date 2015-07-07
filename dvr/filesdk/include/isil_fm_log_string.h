#ifndef _ISIL_FM_LOG_STRING_H_

#define _ISIL_FM_LOG_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

/*�����ִ�ID*/
typedef enum
{
    //ϵͳ�������
    STRID_SYS_BOOT,//����
    STRID_SYS_SHUT_DOWN,//�ػ�

    //���ò���
    STRID_CFG_AD,//����AD
    STRID_CFG_DA,
    STRID_CFG_DEVICE,
    STRID_CFG_ENCODE,
    STRID_CFG_DECODE,
    STRID_CFG_PTZ,
    STRID_CFG_NETWORKING,

    //�����¼�
    STRID_ALARM_VIDEO_LOST,
    STRID_ALARM_VIDEO_SHELTER,
    STRID_ALARM_MD,

    //¼��
    STRID_REC_MANUAL,
    STRID_REC_TIMING,
    STRID_REC_ALARM,
    STRID_REC_STOP,

    //�û�����
    STRID_USER_LOGIN,
    STRID_USER_LOGOUT,
    STRID_USER_DEL,

    //�ļ�����
    STRID_FILE_PLAY,
    //��־���
    STRID_LOG_CLEAR
}STRID;

extern char *STRING[];

#ifdef __cplusplus
}
#endif

#endif



