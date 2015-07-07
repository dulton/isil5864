#ifndef __ISIL_FM_UTILS_H__
#define __ISIL_FM_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__LITTLE_ENDIAN_BITFIELD)
	#undef BIG_BYTES_ORDER
#else
	#define BIG_BYTES_ORDER
#endif

typedef struct sRecDate
{
 	unsigned short Year;   	//��
	unsigned char  Month; 	//��
	unsigned char  day; 	//��
}S_REC_DATE ;

typedef struct sRecTime
{
 	unsigned char  Hour;   	//ʱ
	unsigned char  Minute; 	//��
	unsigned char  Second; 	//��
	unsigned char  Reserve;   // ����(4�ֽڶ���)
}S_REC_TIME ;

typedef struct sRecDateTime
{
	S_REC_DATE  Date;
	S_REC_TIME  Time;
}S_REC_DATE_TIME ;



extern int swap_two_bytes(unsigned short int *small);
extern int swap_three_bytes(unsigned int *small);
extern int swap_four_bytes(unsigned int *small);

extern int ISIL_GetSysTime(S_REC_DATE_TIME* date_time);

extern ssize_t write_r(int fd, void *buf, size_t size);

extern ssize_t read_r(int fd, void *buf, size_t size);


#ifdef __cplusplus
}
#endif

#endif


