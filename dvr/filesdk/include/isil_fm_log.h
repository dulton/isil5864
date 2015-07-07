#ifndef _ISIL_FM_LOG_H_

#define _ISIL_FM_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "isil_fm_utils.h"
//*********************************config*********************************/

#define LOG_PATH_MAX_LEN (32)

/*��־�ļ���*/
#define ISIL_LOG_NAME "isillog.bin"

/*����֧�ֵ�log����*/
#define ISIL_FM_LOG_MAXSUM (1000)

/*��־�ļ��Ƿ���Ը��ǣ�Ĭ�ϸ���*/
#define ISIL_FM_LOG_OVERWRITE (1)



/*������־����*/
typedef enum
{
    LOG_TYPE_INVALID,
    LOG_TYPE_SYSTEM_OPT,       //ϵͳ�������������ػ���
    LOG_TYPE_CFG_OPT,          //���ò�������������Ƶ������
    LOG_TYPE_DATA_MANAGE,      //���ݹ���
    LOG_TYPE_ALARM_EVENT,      //�����¼�
    LOG_TYPE_REC_OPT,          //¼��������翪ʼֹͣ��¼���
    LOG_TYPE_USER_MANAGE,     //�û�����,��¼,�ǳ�
    LOG_TYPE_FILE_OPT,         //�ļ�����,���ŵ�
    LOG_TYPE_LOG_CLEAR,        //��־���
}ISIL_FM_LOG_MAIN_TYPE;

/*��־��������*/
typedef struct
{
    S_REC_DATE_TIME StartDT;//��ʼ����ʱ��
    S_REC_DATE_TIME StopDT;//��������ʱ��
    unsigned char   u8Type;//������
    char            cReserved[3];
}MSG_FM_LOG_SEARCH;

/*��־�ļ���¼���ݽṹ*/
typedef struct
{
    S_REC_DATE_TIME stDT;//����ʱ��
    unsigned char   u8Type;//������
    unsigned char   u8Channel;//ͨ��
    char 			strUsrName[8];//�û���
    unsigned short  strId;//�¼��ַ���ID
}ISIL_FM_LOG_CONTEXT;

/*��־���������������*/
typedef struct
{
    int                 s32MsgSum;//���ص�msg����
    ISIL_FM_LOG_CONTEXT  stMsg[0];//msg��������
}MSG_FM_LOG_SEARCH_RESULT;

/*********************************API*********************************/
extern int ISIL_FM_LOG_GetFileSize();
extern int ISIL_FM_FILE_Log_SetDir(char *Dir);
extern int ISIL_FM_LOG_Init();
extern int ISIL_FM_LOG_Write(unsigned char u8Type, unsigned char u8Channel, char strUsrName[8], unsigned short strId);
extern int ISIL_FM_LOG_Search(MSG_FM_LOG_SEARCH stLogSearch, MSG_FM_LOG_SEARCH_RESULT *LogBuff);//Type Ϊ0,���ʾ����ȫ������
extern int ISIL_FM_LOG_Clear();



#ifdef __cplusplus
}
#endif

#endif

