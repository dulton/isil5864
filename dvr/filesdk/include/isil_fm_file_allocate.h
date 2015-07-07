#ifndef _ISIL_FM_FILE_ALLOCATE_H_
#define _ISIL_FM_FILE_ALLOCATE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"
#include "isil_fm_utils.h"


/*֧�ֵ����ͨ����Ŀ:32*/
#define ISIL_ALLOCATE_MAXCHANNEL  CHANNEL_NUMBER//(1)

/*¼�������ظ�Ŀ¼·����󳤶�*/
#define REC_ROOT_DIR_MAX_LEN (32)

#define ISIL_DATA_DIR        "data/"
#define ISIL_INDEX_DIR       "index/"
#define ISIL_REC_INDEX_DIR   "264_index/"
#define ISIL_FILE_INDEX_DIR  "file_index/"
#define ISIL_FILE_INDEX_NAME "index00.bin"

//add for mjpg
#define ISIL_MJPG_INDEX_DIR  "mjpg_index/"

/*д�ļ����������*/
#define ISIL_ALLOCATE_WRITE_BITRATE_MAX (256)//kB,(2*1024/8)
#define ISIL_ALLOCATE_WRITE_BITRATE_MIN (128)//kB,(1*1024/8)

/*��̬�ļ��Ĵ�С*/
//#define ISIL_ALLOCATE_FILE_SIZE_2048M (2048*1024)//2G
#define ISIL_ALLOCATE_FILE_SIZE_512M  (512*1024)//512MB//
#define ISIL_ALLOCATE_FILE_SIZE_256M  (256*1024)//256MB//
#define ISIL_ALLOCATE_FILE_SIZE_128M  (128*1024)//128MB
#define ISIL_ALLOCATE_FILE_SIZE_64M   (64*1024)//64MB
#define ISIL_ALLOCATE_FILE_SIZE_32M   (32*1024)//32MB
#define ISIL_ALLOCATE_FILE_SIZE_16M   (16*1024)//16MB
#define ISIL_ALLOCATE_FILE_SIZE_512K  (512)//512kB

/*¼����̼�¼ʱ��*/
#define ISIL_ALLOCATE_REC_MINTIME   (2)//2s
#define ISIL_ALLOCATE_REC_MINLEN    (2*1024/ISIL_ALLOCATE_REC_MINTIME/8)//512k

/*¼���ļ�������С�����ڸ�������gopnal,file tail*/
#define ISIL_ALLOCATE_REC_REMAIN_SIZE  (1024)//1k

/*һ��mjpgƽ����С��С*/
#define ISIL_MJPG_MINMUM_SIZE (50)//unit in B, 50KB per each mjpg frame minimum size


typedef struct
{
    unsigned int u32RecFileTotle;//¼���ļ�����
    unsigned int u32Reserved;//����
    unsigned int u32RecIndexSumEachFile;//ÿ����̬�ļ�����Ķ�����������
    unsigned int u32RecIndexSize;//ÿ������������Ĵ�С
    //int s32RecIndexTotle;//��̬����Ķ��������ļ���Ŀ
    //int s32RecIndexUsed;//�Ѿ�ʹ�õĶ��������ļ���Ŀ
    unsigned int u32FileTotle;//��̬������ļ�����
    unsigned int u32UsedFileSum;//ʹ�ù����ļ���Ŀ
    unsigned int u32FullFileSum;//�Ѿ�д�����ļ���Ŀ
    unsigned int u32CoveredFileSum;//���ǵ��ļ���Ŀ
}ISIL_ALLOCATE_FILE_BASEINFO;

typedef struct
{
    unsigned int                u32UsingFileID;
    unsigned short              u16RecSum;//�þ�̬�ļ����¼���ļ���Ŀ,counting from 1
    unsigned short              u16LogSum;//�þ�̬�ļ����¼����־��Ŀ��һ��¼����ܶ�Ӧ�����־, counting from 1
    S_REC_DATE_TIME             stStartDT;
    unsigned char               u8HaveMjpg;//whether exit mjpg or not,exit :1,  not: 0
    char                        s8Reserved[15];
}ISIL_ALLOCATE_FILE_USING_INFO;


typedef struct
{
    unsigned int                u32FileID;
    unsigned int                u32Channel;
    unsigned short              u16RecSum;//�þ�̬�ļ����¼���ļ���Ŀ
    unsigned short              u16LogSum;//�þ�̬�ļ����¼����־��Ŀ��һ��¼����ܶ�Ӧ�����־
    S_REC_DATE_TIME             stStartDT;
    unsigned char               u8HaveMjpg;//whether exit mjpg or not,exit :1,  not: 0
    char                        s8Reserved[11];
}ISIL_ALLOCATE_FILE_FULL_INFO;

typedef struct
{
    unsigned char               u8RecType;
    unsigned char               u8SubType;
    unsigned char               u8RecFileID;//���ڵڼ���¼���ļ�����־
    unsigned char               u8Channel;
    S_REC_DATE_TIME             stStartDT;
    S_REC_DATE_TIME             stStopDT;
    unsigned int                u32StartOffset;
    unsigned int                u32StopOffset;
    unsigned int                u32RecIndexId;
}ISIL_ALLOCATE_FILE_REC_INFO;

typedef struct
{
    unsigned int IsFormat;//�Ƿ��Ѿ���ʽ��
    unsigned int FILE_INDEX_RECLOG_SUM;//ÿ����̬�ļ���¼���¼Ԥ��������
    unsigned int FILE_NUM;//ʵ�ʷ���ľ�̬�ļ���Ŀ
    unsigned int FILE_SIZE;//��̬�ļ���С
    unsigned int REC_INDEX_SIZE;//ÿ�������ļ��ĳ���
    unsigned int ISIL_FM_DISK_OVER_WRITE;//Ӳ�̸���,1:����,0:������
    unsigned int u32RecIndexSumEachFile;//ÿ����̬�ļ�����Ķ�����������
    unsigned int u32RecIndexSize;//ÿ������������Ĵ�С
    unsigned int u32MaxRecChannel;//���¼��ͨ����Ŀ
}ISIL_SAVE_DISK_INFO;


/*******************����Ϊ�洢MJPG�ļ���ʽ******************************/
/*1 mjpg������Ȼ��h264����Ƶ����һ����Ϸ���һ�𣬵���gopnal�в��洢mjpg��Ϣ*/
/*2 mjpg��������һ��Ԥ�Ⱦ�̬����õ��ļ���ʵ�ּ�����Ŀ¼����:index/mjpg_index/xx.bin*/
/*3 �ڸ��ļ��У�ǰ16��byte��¼���ļ���С����ǰ���ô�С��mjpg������������Ѿ��õ���������*/
/*4 �ļ���С�ļ��㷽��:header_size + �����ļ���С/mjpgƽ����С֡��С*  */

typedef struct{
    unsigned int u32FileTotleSize;//�������ļ��Ĵ�С
    unsigned int u32CurSize;//��ռ�ô�С
    unsigned int u32IndexTotleNum;//mjpg��������
    unsigned int u32IndexCurNum;//mjpg������
    unsigned int u32Channel;//which channel,init value is 0xffffffff
    char         cReserved[12];
}ISIL_MJPG_INDEX_HEADER;


typedef struct{
    S_REC_DATE_TIME stDT;//date and time
	unsigned int    u32offset;//mjpg frame offset in data file
    unsigned int    u32Len;//mjpg frame size
	unsigned char   u8RecType;
    unsigned char   u8SubType;
	char            cReserved[2];
}ISIL_MJPG_INDEX;

extern char HDD_REC_DIR[];

/*API*/
/*����Ӳ���Ƿ񸲸�*/
extern void ISIL_FM_FILE_ALLOCATE_SetDiskOverWrite(unsigned int u32IsOverWrite);
/*��ȡ���Ǳ�־λ*/
extern int ISIL_FM_FILE_ALLOCATE_GetDiskOverWrite(void);
/*��������ľ�̬�ļ��еõ�һ�����õ�h264 data�ļ�*/
extern int ISIL_FM_FILE_ALLOCATE_GetDataFile(int s32IndexFd, unsigned int u32Channel);
/*��������ľ�̬�����ļ��еõ�һ�����õ�¼����������ļ�*/
//extern int ISIL_FM_FILE_ALLOCATE_GetRecIndexFile(int s32IndexFd);
/*���ļ�*/
extern int ISIL_FM_FILE_ALLOCATE_OpenFile(char *pPathName);
/*update file index*/
extern int ISIL_FM_FILE_ALLOCATE_UpdateFileIndex(int s32IndexFd, unsigned int u32FileID, ISIL_ALLOCATE_FILE_REC_INFO stIndexRecLog);
/*��ȡ��̬�ļ��Ĵ�С*/
extern unsigned int ISIL_FM_FILE_ALLOCATE_GetFileSize();
/*����һ���ļ�д��ʱ����*/
extern int ISIL_FM_FILE_ALLOCATE_UpdateFull(int s32IndexFd, unsigned int u32Channel);
/*update indexRecLog*/
/*��Ҫ���ļ�����ʱ����,ÿ2sҲ��Ҫ����һ��*/
extern int ISIL_FM_FILE_ALLOCATE_UpdateIndexRecLog(int s32IndexFd, unsigned int u32Channel, unsigned int u32StopOffset);
/*add a rec log*/
extern int ISIL_FM_FILE_ALLOCATE_AddIndexRecLog(int s32IndexFd, unsigned int u32ChNum, unsigned char u8RecType, unsigned char u8SubType, unsigned int u32StartOffset);

/*��ȡ�����ļ���������*/
extern int ISIL_FM_FILE_ALLOCATE_ReadIndexBase(int s32Fd, ISIL_ALLOCATE_FILE_BASEINFO *stBaseInfo);
extern int ISIL_FM_FILE_ALLOCATE_ReadIndexUsing(int s32Fd, unsigned int u32Channel, ISIL_ALLOCATE_FILE_USING_INFO *stUsingInfo);
extern int ISIL_FM_FILE_ALLOCATE_ReadIndexFull(int s32Fd, unsigned int u32FileID, ISIL_ALLOCATE_FILE_FULL_INFO *stFullInfo);
extern int ISIL_FM_FILE_ALLOCATE_ReadIndexRec(int s32Fd, unsigned int u32FileID, unsigned int u32RecID, ISIL_ALLOCATE_FILE_REC_INFO *stRecInfo);

extern void ISIL_FM_FILE_ALLOCATE_LockIndex(void);
extern void ISIL_FM_FILE_ALLOCATE_UnlockIndex(void);

/*��ȡ��������д����ʼλ��,�ɹ�����offset,ʧ�ܷ���0*/
extern int ISIL_FM_FILE_ALLOCATE_GetRecIndexStartOffset(int s32IndexFd, unsigned int u32Channel);
extern int ISIL_FM_FILE_ALLOCATE_GetRecIndexStartOffsetById(unsigned int u32RecIndexId);

/*���̵ĳ�ʼ���������Լ���ר��Ŀ¼�ṹ*/
extern int ISIL_FM_FILE_ALLOCATE_Format();
/**/
extern int ISIL_FM_FILE_ALLOCATE_ReadAllocParam();

extern int ISIL_FM_FILE_ALLOCATE_SetNodePath(char *NodePath);

extern int ISIL_FM_FILE_ALLOCATE_GetRecIndexSize(void);

extern int ISIL_FILE_ALLOCATE_OpenMidx(unsigned int u32MidxFileID);
extern int ISIL_FM_FILE_ALLOCATE_ReadMIdxHeader(int s32MidxFd, ISIL_MJPG_INDEX_HEADER *pMidxHeader);
extern int ISIL_FM_FILE_ALLOCATE_WriteMIdxHeader(int s32MidxFd, ISIL_MJPG_INDEX_HEADER *pMidxHeader);
extern int ISIL_FM_FILE_ALLOCATE_ReadMIdx(int s32MidxFd, unsigned int u32MidxNum, ISIL_MJPG_INDEX *pMidx);
extern int ISIL_FM_FILE_ALLOCATE_WriteMIdx(int s32MidxFd, unsigned int u32MidxNum, ISIL_MJPG_INDEX *pMidx);
extern int IS_MJPG_TYPE(unsigned char type);

#ifdef __cplusplus
    }
#endif
#endif

