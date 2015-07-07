#ifndef __ISIL_FM_H264_H__
#define __ISIL_FM_H264_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
	E_H264_FRAME_TYPE_NULL = 0x00,
	//master stream of h264
	E_FRAME_TYPE_MAIN	= 0x10,
	E_H264_FRAME_TYPE_MAIN_SPS,
	E_H264_FRAME_TYPE_MAIN_PPS,
    E_H264_FRAME_TYPE_MAIN_IDR,
    E_H264_FRAME_TYPE_MAIN_I,
    E_H264_FRAME_TYPE_MAIN_P,
    E_H264_FRAME_TYPE_MAIN_B,
    E_H264_FRAME_TYPE_MAIN_SI,
    E_H264_FRAME_TYPE_MAIN_SP,
    E_H264_FRAME_TYPE_MAIN_MV,
	//add new type here of h264 main
	E_FRAME_TYPE_MAIN_END = 0x1f,

	//sub stream of h264
	E_FRAME_TYPE_SUB = 0x20,
	E_H264_FRAME_TYPE_SUB_SPS,
	E_H264_FRAME_TYPE_SUB_PPS,
	E_H264_FRAME_TYPE_SUB_IDR,
    E_H264_FRAME_TYPE_SUB_I,
    E_H264_FRAME_TYPE_SUB_P,
    E_H264_FRAME_TYPE_SUB_B,
    E_H264_FRAME_TYPE_SUB_SI,
    E_H264_FRAME_TYPE_SUB_SP,
    E_H264_FRAME_TYPE_SUB_MV,
	//add new type here of h264 sub
	E_FRAME_TYPE_SUB_END = 0x2f,

	//mjpg stream
	E_FRAME_TYPE_MJPG = 0x30,
    E_H264_MJPEG_FRAME_TYPE,
	//add new type here of mjpg
	E_FRAME_TYPE_MJPG_END = 0x3f,

	//audio stream
	E_FRAME_TYPE_AUDIO = 0x40,
    E_AUDIO_FRAME_TYPE_PCM,
	E_AUDIO_FRAME_TYPE_ADPCM,
	E_AUDIO_FRAME_TYPE_ALAW,
	E_AUDIO_FRAME_TYPE_ULAW,
	//add new type here of audio
	E_FRAME_TYPE_AUDIO_END = 0x4f,

	//add new type
}eframe_type;


typedef struct
{
    unsigned char   *payload;      //ָ����Ƶ���ݵĵ�ַ
    unsigned int    type;            //��Ƶ֡������
    unsigned int    len;             //��Ƶ���ݵĴ�С����byteΪ��λ
    unsigned int    timestamp;       //��Ƶ��ʱ��
}stDriverFrame;


/*H264�ļ���¼��������Ҫ��ͬ�õ������ݽṹ��������*/

/*����¼���ļ���׺��*/
#define H264_FILE_SUFFIX  "264"

//Windows �ļ���ʽ
//h264: (sps,pps,idr,p, .. ,GopNal), ..., FileIdxNal,FileTailNal

//linux �ļ���ʽ
//h264:    (sps,pps,idr,p, .. ,GopNal), ...,FileTailNal
//IdxFile: FileIdxNal

//���У�
//GopNal:     ISIL_GOP_NAL,ISIL_NAL_INDEX,...
//FileIdxNal: ISIL_FILE_INDEX_NAL,ISIL_FILE_INDEX_NAL,...

/*¼���ļ���֡���Ͷ���*/
/*enum eISIL_FILE_NAL_TYPE
{
	ISIL_NAL_UNKNOWN      	= 0,
	ISIL_NAL_SPS          	= 0xA0,
	ISIL_NAL_PPS          	= 0xA1,
	ISIL_NAL_SLICE        	= 0xB0,
	ISIL_NAL_SLICE_IDR   	= 0xB1,
	ISIL_NAL_SLICE_DPA  	    = 0xB2,
	ISIL_NAL_SLICE_DPB    	= 0xB3,
	ISIL_NAL_SLICE_DPC    	= 0xB4,
	ISIL_NAL_SLICE_P      	= 0xB5,
	ISIL_NAL_AUDIO_PCM    	= 0xC0,
	ISIL_NAL_AUDIO_ALAW      = 0xC1,
	ISIL_NAL_AUDIO_ULAW  	= 0xC2,
	ISIL_NAL_AUDIO_ADPCM 	= 0xC3
};
*/
enum eISIL_NAL_TYPE
{
    ISIL_NAL_UNKNOWN      = 0,
    ISIL_NAL_MJPEG        = 0x80,
    ISIL_NAL_BMP          = 0x81,
    ISIL_NAL_SPS          = 0xA0,
    ISIL_NAL_PPS          = 0xA1,
    ISIL_NAL_SLICE        = 0xB0,
    ISIL_NAL_SLICE_IDR    = 0xB1,
    ISIL_NAL_SLICE_DPA    = 0xB2,
    ISIL_NAL_SLICE_DPB    = 0xB3,
    ISIL_NAL_SLICE_DPC    = 0xB4,
    ISIL_NAL_SLICE_P      = 0xB5,
    ISIL_NAL_SLICE_I      = 0xB6,
    ISIL_NAL_AUDIO_PCM    = 0xC0,
    ISIL_NAL_AUDIO_ALAW   = 0xC1,
    ISIL_NAL_AUDIO_ULAW   = 0xC2,
    ISIL_NAL_AUDIO_ADPCM  = 0xC3,
    ISIL_NAL_AUDIO_IMAADPCM  = 0xC4,
};


/*H264 Nal �ṹ*/
typedef struct _tagISIL_NAL_INDEX
{
	unsigned long cNalType:8;
	unsigned long lNalSize:24;
	unsigned long lNalOffset;//��NAL������H264�ļ��е�λ��
	unsigned long lTimeStamp;
}ISIL_NAL_INDEX;

/*define H264 GopNal data struct*/
typedef struct _tagISIL_GOP_NAL      //һ������
{
	unsigned long  lGopFlag;        //NAL_HEAD 00 00 00 01 78

#if 0
defined(__LITTLE_ENDIAN_BITFIELD)
	unsigned long  cGopFlag:8;
	unsigned long  lLastGopSize:24; //��һ��GopNal��С
//#else

	unsigned long  lLastGopSize:24; //��һ��GopNal��С
    unsigned long  cGopFlag:8;

#else
    unsigned long  cGopFlag:8;
	unsigned long  lLastGopSize:24; //��һ��GopNal��С
#endif
	unsigned long  lLastGopOffset;  //��һ��GopNalƫ��λ��
	unsigned short nGopID;          //��ǰGop ID ��
	unsigned short nNalCount;       //��ǰGopNal �ж�Ӧ�ö��ISIL_NAL_INDEX//
	ISIL_NAL_INDEX  Nal_Index[0];
}ISIL_GOP_NAL;

/**Gop index*/
typedef struct _tagISIL_GOP_INDEX
{
	unsigned long  lGopOffset;//��GOP������H264�ļ��е�λ��
	unsigned short nGopSize;
	unsigned short nIFrameCount;  //I frame count in gop
}ISIL_GOP_INDEX;


typedef struct _tagISIL_FILE_INDEX_NAL  //��������,����д���ļ�β��Ҳ���Ե���д���ļ�
{
	unsigned long  lIndexFlag;         //NAL_HEAD 00 00 00 01 79
	unsigned long  cIndexFlag:8;
	unsigned long  lGopCount:24;
	ISIL_GOP_INDEX  Gop_Index[0];
}ISIL_FILE_INDEX_NAL;

typedef struct _tagISIL_FILE_TAIL_NAL
{
	unsigned long lTailFlag;       //NAL_HEAD 00 00 00 01 7A
	unsigned long cTailFlag:8;
	unsigned long lIndexSize:24;   //���������ļ��еĴ�С,����ļ���û��FileIdxNal,���ʾ�ļ����һ��GopNal��С
	unsigned long lIndexOffset;    //���������ļ��е�ƫ��,����ļ���û��FileIdxNal,���ʾ�ļ����һ��GopNalƫ��λ��
	unsigned long lAllNalCount;    //���ļ��г�ȥ����Nal�⣬�ܹ���Nal����, ����ISIL_NAL_INDEX ����
  	unsigned long lTimeBegin;      //�ļ���Ƶ����ʼʱ��
	unsigned long lTimeEnd;        //�ļ���Ƶ�Ľ���ʱ��
	unsigned long lMaxNalSize;     //�ļ�����Ƶ����Ƶ����NAL��С
	unsigned long lMaxGopNalSize;  //�ļ���Gop����NAL��С
	unsigned long lMaxKeyFrameInterval; //���ؼ�֡���
}ISIL_FILE_TAIL_NAL;





#ifdef __cplusplus
    }
#endif

#endif

