#include <stdio.h>
#include <stdlib.h>

#include "isil_video_manage.h"
#include "isil_common.h"
#include "isil_debug.h"
#include "isil_cfg_file_manage.h"
#include "isil_messagestruct.h"
#include "isil_endian_trans.h"


#define VIDEO_CFG_ "/flash/config/video/video_"

static S08 g_path[ISIL_CFG_PATH_LEN];

static S08* ISIL_GetVideoPath(S32 iChannel, S32 iVideoCfgType)
{
	S08 *pTemp = NULL;
	memset(g_path, 0, ISIL_CFG_PATH_LEN);
	switch(iVideoCfgType)
	{
		case VIDEO_LOST:
			pTemp = "lost";
			break;
		case VIDEO_MASK:
			pTemp = "mask";
			break;

		case VIDEO_SHELTER:
			pTemp = "shelter";
			break;


		case VIDEO_MOTION:
			pTemp = "motion";
			break;
		case VIDEO_SIGNAL:
			pTemp = "signal";
			break;
		default:
			pTemp = NULL;
			break;
	}
	if(NULL != pTemp)
	{
		sprintf(g_path, "%s%s_ch%d", VIDEO_CFG_, pTemp, iChannel);
	}
	return g_path;
}

/********************************************************
 *Function: ISIL_SaveVideoCfg
 *Description: ������Ƶ��ص������ļ�
 *Input:
 *	S32 iChannel:ͨ����
 *	S32 iVideoCfgType:��Ƶ��������:
				 	VIDEO_LOST		1
					VIDEO_MASK 		2
					VIDEO_SHELTER	3
					VIDEO_MOTION	4
					VIDEO_SIGNAL	5
	S32 iCfgSize:��Ƶ���ýṹ�Ĵ�С
	void * pVideoCfg:��Ҫ���������
 *output:
 *       No
 *return:
 *        Success, 1; FALAE, -1
 *******************************************************/

S32 ISIL_SaveVideoCfg(S32 iChannel, S32 iVideoCfgType, S32 iCfgSize, void * pVideoCfg)
{
	S08 *sPath;
	S32 iRet;
	S32 iType;

	if(NULL == pVideoCfg)
	{
		return ISIL_FAIL;
	}
	sPath = ISIL_GetVideoPath(iChannel, iVideoCfgType);
	ISIL_TRACE(BUG_NORMAL, "path:%s", sPath);
	if(NULL != sPath)
	{
		iRet = ISIL_WriteConfigFile(sPath, 0, iCfgSize, &iType, pVideoCfg);
		if(iRet < 0)
		{
			return ISIL_FAIL;
		}
		return ISIL_SUCCESS;
	}
	return ISIL_FAIL;
}

/********************************************************
 *Function: ISIL_SaveVideoCfg
 *Description: �����Ƶ��ص������ļ�
 *Input:
 *	S32 iChannel:ͨ����
 *	S32 iVideoCfgType:��Ƶ��������:
				 	VIDEO_LOST		1
					VIDEO_MASK 		2
					VIDEO_SHELTER	3
					VIDEO_MOTION	4
					VIDEO_SIGNAL	5
	S32 iCfgSize:��Ƶ���ýṹ�Ĵ�С
	void * pVideoCfg:Ҫ��õ�����ָ��
 *output:
 *       No
 *return:
 *        Success, 1; FALAE, -1
 *******************************************************/


S32 ISIL_GetVideoCfg(S32 iChannel, S32 iVideoCfgType, S32 iCfgSize, void *pVideoCfg)
{
	S08 *sPath;
	S32 iRet;
	S32 iType;

	if(NULL == pVideoCfg)
	{
		return ISIL_FAIL;
	}
	sPath = ISIL_GetVideoPath(iChannel, iVideoCfgType);
	if(NULL != sPath)
	{
		iRet = ISIL_ReadConfigFile(sPath, 0, iCfgSize, &iType, pVideoCfg);
		if(iRet < 0)
		{
			return ISIL_FAIL;
		}
		return ISIL_SUCCESS;
	}
	return ISIL_FAIL;
}


