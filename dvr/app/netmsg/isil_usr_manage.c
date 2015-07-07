/*
*******************************************************************
				Copyright (C), 2005-2009, Dvmicro Tech. Co., Ltd.

	File Name: isil_usr_information.c
	Author: wangjunbin
	Version:0.1
	Date: 2009-03-19
	Description:handle user information.


	Other:
	Function list:
	History:

*******************************************************************
*/
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/types.h>

#include "isil_usr_manage.h"
#include "isil_debug.h"
#include "isil_cfg_file_manage.h"

#define USER_DEFAULT_PWD	"123"


#ifdef MANAGE_USER_SIGNAL
#define LINE_BUF_LEN		1024

/*Define some function*/
S32 ISIL_VerifyUsrInfo(ISIL_USR_LOGIN_S *sUsrLogin);
S32 ISIL_AddUser(ISIL_USR_CFG_S* sUsrInf);
S32 ISIL_DelUser(S08* sUsrName);
S32 ISIL_ModifyUser(S08 *sUsrName, ISIL_USR_CFG_S * sUsrInf);
S32 ISIL_GetUsrInfoByName(S08 *sName, ISIL_USR_CFG_S* sUsrInf);
S32 ISIL_GetUsrInfoByID(U32 uiUsrId, ISIL_USR_CFG_S* sUsrInf);
S32 ISIL_GetUsrInfoCnt(void);

S32 ISIL_AddUsrGroup(ISIL_USR_GROUP_S* sUsrGrp);
S32 ISIL_GetUsrGroupInfoByName(S08* sUsrGrpName, ISIL_USR_GROUP_S* sGrp);
S32 ISIL_GetUsrGroupInfoByID(U32  uiUsrGrpID, ISIL_USR_GROUP_S* sGrp);
S32 ISIL_ModifyUsrGroup(S08* sUsrGrpName, ISIL_USR_GROUP_S* sGrp);
S32 ISIL_DelUsrGroup(S08* sUsrGrpName);
S32 ISIL_AddUsrToGroup(S08 *sUsrName, S08 *sGrpName);
S32 ISIL_DelUsrFromGroup(S08 *sUsrName, S08 *sGrpName);
S32 ISIL_ChangeUsrNameInGrp(S08* sGrpName, S08 * sOldName, S08 * sNewName);
S32 ISIL_UsrLevelMatch(U32 uiUsrID, S32 iLevel);


S32 ISIL_UsrInfoExit(S08 *sUsrName)
{
	S32 iDataSize;
	S32 iLoop = 0;
	ISIL_USR_CFG_S sUsrCfg;
	FILE *fp;
	if(sUsrName == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] name null", __FUNCTION__);
		return ISIL_FAIL;
	}
	if ((fp = fopen(ISIL_USER_INFO_FILE, "r")) == NULL)
	{
		return ISIL_FAIL;
	}

	iDataSize = sizeof(ISIL_USR_CFG_S);
	while((fread(&sUsrCfg, iDataSize, 1, fp)) > 0)
	{
		if((strcmp(sUsrCfg.stUsrNetCfg.sName, sUsrName)) == 0)/*found*/
		{
			fclose(fp);
			return iLoop;
		}
		iLoop++;
	}

	fclose(fp);
	return ISIL_FAIL;
}

/********************************************************
 *Function: ISIL_GetUsrInfoCnt
 *Description:  ���û������ļ��У������ж����û�
 *			������
 *Input:
 *	��
 *output:
 *       ��
 *return:
 *        Success: ��������; Fail : -1
 *******************************************************/

S32 ISIL_GetUsrInfoCnt()
{
	S32 iLoop = 1;
	S32 iDataSize;
	FILE *fp;
	ISIL_USR_CFG_S sUsrIfo;
	if ((fp = fopen(ISIL_USER_INFO_FILE, "r")) == NULL)
	{
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	while((fread(&sUsrIfo, iDataSize, 1, fp)) > 0)
	{
		iLoop++;
	}
	ISIL_TRACE(BUG_NORMAL, "[%s] user information count %d", __FUNCTION__, iLoop);
	fclose(fp);
	return iLoop;
}


/********************************************************
 *Function: ISIL_GetLastUsrID
 *Description:���û��������л�����һ������
 			���û�ID
 *Input:
 *	��
 *output:
 *    ��
 *return:
 *        Success: ���������� �û�ID; Fail : -1
 *******************************************************/

S32 ISIL_GetLastUsrID()
{
	S32 iRet;
	S32 iDataSize;
	ISIL_USR_CFG_S sUsrCfg;
	FILE *fp;

	/*���ļ�*/
    if(ISIL_GetFileSize(ISIL_USER_INFO_FILE) == 0)
    {
        return 0;
    }

	if ((fp = fopen(ISIL_USER_INFO_FILE, "r")) == NULL)
	{
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	iRet = fseek(fp, -iDataSize, SEEK_END);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] seek fail", __FUNCTION__);
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = fread(&sUsrCfg, iDataSize, 1, fp);
	if(iRet > 0)
	{
		fclose(fp);
		return sUsrCfg.iUId;
	}

	fclose(fp);
	return ISIL_FAIL;
}


/********************************************************
 *Function: ISIL_AddUser
 *Description: ����һ���û�
 *Input:
 *	ISIL_USR_CFG_S* sUsrInf:���ӵ��û���Ϣ��ָ��
 *output:
 *       ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_AddUser(ISIL_USR_CFG_S* sUsrInf)
{

	S32 iRet;
	S32 iDataSize;
	FILE *fp;
	iRet = ISIL_UsrInfoExit(sUsrInf->stUsrNetCfg.sName);
	if(iRet != ISIL_FAIL)/*�Ѿ��и��û�*/
	{
		ISIL_TRACE(BUG_ERROR, "[%s] user %s exit", __FUNCTION__, sUsrInf->stUsrNetCfg.sName);
		return ISIL_FAIL;
	}

	if ((fp = fopen(ISIL_USER_INFO_FILE, "a+")) == NULL)
	{
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	iRet = fwrite(sUsrInf, iDataSize, 1, fp);
	fclose(fp);
	if(iRet < 0)
	{
		return ISIL_FAIL;
	}
	return ISIL_SUCCESS;
}

/********************************************************
 *Function: ISIL_AddUser
 *Description: ����һ������Ա�û�
 *Input:
 *	ISIL_USR_CFG_S* sUsrInf:���ӵ��û���Ϣ��ָ��
 *output:
 *       ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_AddAdminUser(ISIL_USR_CFG_S* sUsrInf)
{
	S32 iRet;
	sUsrInf->iGId = 0;
	sUsrInf->iUId = ADMIN_USR_ID;
	memset(sUsrInf->stUsrNetCfg.lLevel, 0xff,
        sizeof(sUsrInf->stUsrNetCfg.lLevel));
	iRet = ISIL_AddUser(sUsrInf);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] add admin %s fail", __FUNCTION__, sUsrInf->stUsrNetCfg.sName);
		return ISIL_FAIL;
	}
	return ISIL_SUCCESS;
}

/********************************************************
 *Function: ISIL_AddUser
 *Description: ����һ����ͨ�û�
 *Input:
 *	ISIL_USR_CFG_S* sUsrInf:���ӵ��û���Ϣ��ָ��
 *output:
 *       ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/


S32 ISIL_AddPublicUser(ISIL_USR_CFG_S* sUsrInf)
{
	S32 iLastUsrID;
	S32 iRet;
	iLastUsrID = ISIL_GetLastUsrID();

	ISIL_TRACE(BUG_ERROR, "[%s] last uid %d", __FUNCTION__, iLastUsrID);
	/*�޷���õ�ǰ�����û���ID*/
	if(iLastUsrID < 0)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] last uid error", __FUNCTION__);
		return ISIL_FAIL;
	}
	else if(iLastUsrID == 0)
	{
		sUsrInf->iUId = USER_START_ID;
	}
	else
	{
		sUsrInf->iUId = iLastUsrID + 1;
	}

	iRet = ISIL_AddUser(sUsrInf);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] add public %s fail", __FUNCTION__, sUsrInf->stUsrNetCfg.sName);
		return ISIL_FAIL;
	}

    /*�����û����û���*/
    if(NULL != sUsrInf->stUsrNetCfg.sUsrGrpName)
    {
    	iRet = ISIL_AddUsrToGroup(sUsrInf->stUsrNetCfg.sName,
			sUsrInf->stUsrNetCfg.sUsrGrpName);
		if(iRet < 0)
		{
			return ISIL_FAIL;
		}
    }
	return ISIL_SUCCESS;
}

/********************************************************
 *Function: ISIL_DelUser
 *Description: �����û�����ɾ��һ���û�
 *Input:
 *	S08* sUsrName:��Ҫɾ�����û���ָ��
 *output:
 *       ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_DelUser(S08* sUsrName)
{
	FILE *fp, *tmp;
	S08 tmpname[ISIL_PATHNAME_LEN];
	S32 iLine = 0;
	S32 iRet;
	S32 iDataSize;
	ISIL_USR_CFG_S sUsrCfg;

	if(NULL == sUsrName)
	{
		return ISIL_FAIL;
	}
	/*���Ҹ��û��Ƿ����*/
	iRet = ISIL_GetUsrInfoByName(sUsrName, &sUsrCfg);
	if(iRet < 0)
	{
		return ISIL_FAIL;
	}
	/*ɾ���û����и��û���Ϣ*/
	iRet = ISIL_DelUsrFromGroup(sUsrName, sUsrCfg.stUsrNetCfg.sUsrGrpName);
	if(iRet < 0)
	{
		return ISIL_FAIL;
	}

	/*�ҵ��û����ļ��е�λ��*/
	iLine = ISIL_UsrInfoExit(sUsrName);
	if(ISIL_FAIL == iLine)/*user not exit*/
	{
		ISIL_TRACE(BUG_ERROR, "[%s] User %s not exit", __FUNCTION__, sUsrName);
		return ISIL_FAIL;
	}

	sprintf(tmpname, "%s%s", ISIL_USER_INFO_FILE, "tmp");
	/*�����ļ�*/
	if (ISIL_FileCP(ISIL_USER_INFO_FILE, tmpname) != ISIL_TRUE)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] copy file fail", __FUNCTION__);
		return ISIL_FAIL;
	}
	if ((tmp = fopen(tmpname, "r+")) == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open temp file fail", __FUNCTION__);
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	unlink(tmpname);
	fseek(tmp, iDataSize*iLine, SEEK_SET);
	truncate(ISIL_USER_INFO_FILE, ftell(tmp));

	if((fp = fopen(ISIL_USER_INFO_FILE, "a")) == NULL)
	{
		fclose(tmp);
		return ISIL_FAIL;
	}

	fseek(fp, 0, SEEK_END);	/* to last place */
	fseek(tmp, iDataSize*(iLine+1), SEEK_SET);


	while((fread(&sUsrCfg, iDataSize, 1, tmp)) > 0)
	{
		fwrite(&sUsrCfg, iDataSize, 1, fp);
	}

	fclose(fp);
	fclose(tmp);

	return ISIL_SUCCESS;
}


/********************************************************
 *Function: ISIL_ModifyUser
 *Description: �����û������޸�һ���û���Ϣ
 *Input:
 *	S08* sUsrName:��Ҫ�޸ĵ��û���ָ��
 *	ISIL_USR_CFG_S * sUsrInf:�û���Ϣָ��
 *output:
 *       ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_ModifyUser(S08 *sUsrName, ISIL_USR_CFG_S * sUsrInf)
{
	S32 iRet = 0;
	S32 iDataSize;
	S32 iLoc;
	FILE * fp;

	if(sUsrName == NULL || sUsrInf == NULL)
	{

		ISIL_TRACE(BUG_ERROR, "[%s] pointer is null", __FUNCTION__);
		return ISIL_FAIL;
	}

	/*�����û��Ƿ����*/
	iLoc = ISIL_UsrInfoExit(sUsrName);
	if(iLoc == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] not find %s", __FUNCTION__, sUsrName);
		return ISIL_FAIL;
	}

	ISIL_TRACE(BUG_ERROR, "[%s] find %s Loc %d", __FUNCTION__, sUsrName, iLoc);
	fp=fopen(ISIL_USER_INFO_FILE, "r+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);

	iRet = fseek(fp, iLoc*iDataSize, SEEK_SET);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] Seek file fail", __FUNCTION__);
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = fwrite(sUsrInf, iDataSize, 1, fp);
	if(iRet < 0)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] read file error", __FUNCTION__);
	}
	else
	{
		/*�޸��û����û�����ص���Ϣ*/
		if((strcmp(sUsrName, sUsrInf->stUsrNetCfg.sName)) == 0)
		{
			iRet = ISIL_ChangeUsrNameInGrp(sUsrInf->stUsrNetCfg.sUsrGrpName,
				sUsrName, sUsrInf->stUsrNetCfg.sName);
		}
	}
	fclose(fp);
	return iRet;
}



/********************************************************
 *Function: ISIL_UsrGrpExit
 *Description: �������룬�ж��û����Ƿ�����
 	���ļ���
 *Input:
 *	S08 *cUsraGrpName:�û�����
 *output:
 *       No
 *return:
 *        Success,�������������ļ��е�λ��;
 *		-1: Fail
 *******************************************************/

S32 ISIL_UsrGrpExit(FILE* fp, S08 *cUsraGrpName)
{
	S32 iDatasize = 0;
	S32 iGropNo = 0;
	ISIL_USR_GROUP_S sGrp;

	if(NULL == cUsraGrpName)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] usr name null", __FUNCTION__);
		return ISIL_FAIL;
	}

	iDatasize = sizeof(ISIL_USR_GROUP_S);

	while(fread(&sGrp, iDatasize, 1, fp) > 0)
	{
		if(0 == strcmp(cUsraGrpName, sGrp.stNetUsrGrp.sName))
		{
			ISIL_TRACE(BUG_ERROR, "[%s] Group %s exit, No %d",
				__FUNCTION__, cUsraGrpName, iGropNo);
			return iGropNo;
		}
		iGropNo++;
	}
	return ISIL_FAIL;
}

/********************************************************
 *Function: ISIL_AddUsrGroup
 *Description: �������룬����һ���û���
 *Input:
 *	S08 *cUsrName:�û������
 *output:
 *       No
 *return:
 *	Success, 0; fail, < 0
 *******************************************************/

S32 ISIL_AddUsrGroup(ISIL_USR_GROUP_S* sUsrGrp)
{
	S32 iRet;
	S32 iDataSize;
	S32 iFileSize;
	FILE * fp;
	ISIL_USR_GROUP_S sGrp;

	fp=fopen(ISIL_USER_GROUP_FILE, "r+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}

	/*����û����Ѿ�����*/
	iRet = ISIL_UsrGrpExit(fp, sUsrGrp->stNetUsrGrp.sName);
	if(iRet >= 0)/*����*/
	{
		ISIL_TRACE(BUG_ERROR, "[%s] group %s exit", __FUNCTION__,
			sUsrGrp->stNetUsrGrp.sName);
		fclose(fp);
		return ISIL_FAIL;
	}

	iFileSize = ISIL_GetFileSize(ISIL_USER_GROUP_FILE);
	if(iFileSize < 0)
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iDataSize = sizeof(ISIL_USR_GROUP_S);

	if(iFileSize > 0)
	{
		/*��λ�����һ���û�����Ϣ��*/
		iRet = fseek(fp, -iDataSize, SEEK_END);
		if(iRet == ISIL_FAIL)
		{
			ISIL_TRACE(BUG_ERROR, "[%s] Seek file fail", __FUNCTION__);
			fclose(fp);
			return ISIL_FAIL;
		}
		iRet = fread(&sGrp, iDataSize, 1, fp);
		if(iRet < 0)
		{
			ISIL_TRACE(BUG_ERROR, "[%s] read file error", __FUNCTION__);
			fclose(fp);
			return ISIL_FAIL;
		}
		sUsrGrp->iGroupID = sGrp.iGroupID + 1;
	}
	else
	{
		sUsrGrp->iGroupID = 0;
	}

	iRet =  fwrite((S08*)sUsrGrp, sizeof(ISIL_USR_GROUP_S), 1, fp);
	fclose(fp);

	ISIL_TRACE(BUG_NORMAL, "[%s] add grp %s ", __FUNCTION__, sUsrGrp->stNetUsrGrp.sName);
	return iRet;

}


/********************************************************
 *Function: ISIL_SyncUsrInfoByGrp
 *Description: �����û�����Ϣ�ĸı䣬ͬ����ÿ���û�
 *Input:
 *	ISIL_USR_GROUP_S *stUsrGrp:�û�����Ϣ
 *	S32 iSynFlag: 0,�޸ģ�1��ɾ��
 *output:
 *       No
 *return:
 *        Success :0
 *		  Fail	  :-1
 *******************************************************/

S32 ISIL_SyncUsrInfoByGrp(ISIL_USR_GROUP_S *stUsrGrp, S32 iSyncFlag)
{
	S32 iRet;
	S32 iLoop;
	S32 iLoop2;
	S32 iUsrCnt;
	S08 *pTemp;
	ISIL_USR_CFG_S sUsrInf;
	if(NULL == stUsrGrp)
	{
		return ISIL_FAIL;
	}
	iUsrCnt = stUsrGrp->stNetUsrGrp.iUsrCnt;
	ISIL_TRACE(BUG_NORMAL, "[%s] usr cnt %d", __FUNCTION__, iUsrCnt);
	for(iLoop = 0; iLoop < iUsrCnt; iLoop++)
	{
		pTemp = stUsrGrp->stNetUsrGrp.cGropList[iLoop];
		if(NULL != pTemp)
		{
			if(iSyncFlag == 0)/*�޸�*/
			{
				memset(&sUsrInf, 0, sizeof(ISIL_USR_CFG_S));
				iRet = ISIL_GetUsrInfoByName(pTemp, &sUsrInf);
				if(iRet < 0)
				{
					continue;
				}
				else
				{
					strncpy(sUsrInf.stUsrNetCfg.sUsrGrpName,
						stUsrGrp->stNetUsrGrp.sName, ISIL_NAME_LEN);

					for(iLoop2 = 0; iLoop2 < ISIL_MAX_LEVEL; iLoop2++)
					{
						sUsrInf.stUsrNetCfg.lLevel[iLoop2] |= stUsrGrp->stNetUsrGrp.iLevel[iLoop2];
					}
					ISIL_ModifyUser(pTemp, &sUsrInf);
				}
			}

			else if(iSyncFlag == 1)/*ɾ��*/
			{
				ISIL_DelUser(pTemp);
			}
		}
	}
}

/********************************************************
 *Function: ISIL_ModifyUsrGroup
 *Description: �������룬�޸��û���
 *Input:
 *	S08 *cUsrName:�û�����
 *	ISIL_USR_GROUP_S* sGrp:�޸��û�����Ϣָ��
 *output:
 *       No
 *return:
 *        Success, 0
 *		   Fail,-1
 *******************************************************/

S32 ISIL_ModifyUsrGroup(S08* sUsrGrpName, ISIL_USR_GROUP_S* sGrp)
{
	S32 iRet = 0;
	S32 iDataSize;
	S32 iLoc;
	FILE * fp;

	if(sUsrGrpName == NULL || sGrp == NULL)
	{

		ISIL_TRACE(BUG_ERROR, "[%s] pointer is null", __FUNCTION__);
		return ISIL_FAIL;
	}
	fp=fopen(ISIL_USER_GROUP_FILE, "r+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}

	iLoc = ISIL_UsrGrpExit(fp, sUsrGrpName);
	if(iLoc == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] not find %s", __FUNCTION__, sUsrGrpName);
		fclose(fp);
		return ISIL_FAIL;
	}

	iDataSize = sizeof(ISIL_USR_GROUP_S);

	iRet = fseek(fp, iLoc*iDataSize, SEEK_SET);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] Seek file fail", __FUNCTION__);
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = fwrite(sGrp, iDataSize, 1, fp);
	if(iRet < 0)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] read file error", __FUNCTION__);
	}
	/*ͬ���ı��Ա��Ϣ*/
	//if()
	fclose(fp);
	return iRet;
}

/********************************************************
 *Function: ISIL_UsrGrpExit
 *Description: �������룬ɾ��һ���û���
 *Input:
 *	S08 *cUsrName:�û�����
 *output:
 *       No
 *return:
 *        Success, 0
 *		   Fail,-1
 *******************************************************/

S32 ISIL_DelUsrGroup(S08* sUsrGrpName)
{
	FILE *fp, *tmp;
	S08 tmpname[ISIL_PATHNAME_LEN];
	S32 iLine = 0;
	S32 iRet;
	S32 iDataSize;
	ISIL_USR_GROUP_S sUsrGrp;

	if ((fp = fopen(ISIL_USER_GROUP_FILE, "r+")) == NULL)
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iLine = ISIL_UsrGrpExit(fp, sUsrGrpName);
	if(iLine == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] not find %s", __FUNCTION__, sUsrGrpName);
		fclose(fp);
		return ISIL_FAIL;
	}

	sprintf(tmpname, "%s%s", ISIL_USER_GROUP_FILE, "tmp");
	if (ISIL_FileCP(ISIL_USER_GROUP_FILE, tmpname) != ISIL_TRUE)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] copy file fail", __FUNCTION__);
		fclose(fp);
		return ISIL_FAIL;
	}

	if ((tmp = fopen(tmpname, "r+")) == NULL)
	{

		ISIL_TRACE(BUG_ERROR, "[%s] open temp file fail", __FUNCTION__);
		fclose(fp);
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_GROUP_S);
	unlink(tmpname);
	iRet = fseek(tmp, iLine*iDataSize, SEEK_SET);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s %d] seek temp file fail", __FUNCTION__, __LINE__);
		goto FAIL;
	}


	ISIL_TRACE(BUG_ERROR, "[%s %d] file part size %d", __FUNCTION__, __LINE__, ftell(tmp));
	truncate(ISIL_USER_GROUP_FILE, ftell(tmp));
	iRet = fseek(fp, 0, SEEK_END);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s %d] seek file fail", __FUNCTION__, __LINE__);
		goto FAIL;
	}
	iRet = fseek(tmp, (iLine+1)*iDataSize, SEEK_SET);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s %d] seek file fail", __FUNCTION__, __LINE__);
		goto FAIL;
	}
	while((fread(&sUsrGrp, iDataSize, 1, tmp)) > 0)
	{
		if((fwrite(&sUsrGrp, iDataSize, 1, fp)) < 0)
		{
			ISIL_TRACE(BUG_ERROR, "[%s %d] write file fail", __FUNCTION__, __LINE__);
			goto FAIL;
		}
	}
	/*��Ҫɾ�����Ա�������Ϣ?*/
	fclose(fp);
	fclose(tmp);
	return ISIL_SUCCESS;
	FAIL:
	fclose(fp);
	fclose(tmp);
	return ISIL_FAIL;
}
/********************************************************
 *Function: ISIL_UsrGrpExit
 *Description: �������룬���ض��������һ��
 *			�û�
 *Input:
 *	S08 *cUsrName:Ҫɾ�����û���
 *	S08 *sGrpName,�û�����
 *output:
 *       No
 *return:
 *        Success, 0
 *		   Fail,-1
 *******************************************************/

S32 ISIL_AddUsrToGroup(S08 *sUsrName, S08 *sGrpName)
{
	S32 iRet;
	S32 iLine;
	S32 iLoop;
	S32 iLevel;
	ISIL_USR_GROUP_S sGrp;
	ISIL_USR_CFG_S sUsr;
	FILE * fp;
	if(NULL == sGrpName || NULL == sGrpName)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] pointor is null", __FUNCTION__);
		return ISIL_FAIL;
	}
	/*����û��Ƿ����*/
	/*iLine = ISIL_ItemIsInFileField(ISIL_USER_INFO_FILE, sUsrName, 1);*/
	iLine = ISIL_UsrInfoExit(sUsrName);
	if(ISIL_FAIL != iLine)/*user exit*/
	{
		ISIL_TRACE(BUG_NORMAL, "[%s] User %s exit", __FUNCTION__, sUsrName);
	}
	else/*User not exit*/
	{
		return ISIL_FAIL;
	}
	/*����û����Ƿ����*/
	fp = fopen(ISIL_USER_GROUP_FILE, "a+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}

	iRet = ISIL_UsrGrpExit(fp, sGrpName);

	if(iRet != ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] Usergroup %s exit", __FUNCTION__, sGrpName);
	}
	else
	{
		fclose(fp);
		return ISIL_FAIL;
	}
	iRet = ISIL_GetUsrGroupInfoByName(sGrpName, &sGrp);
	printf("[%s] ret %d , usrcnt %d\n", __FUNCTION__, iRet, sGrp.stNetUsrGrp.iUsrCnt);
	if(iRet != ISIL_FAIL)
	{
		for(iLoop = 0; iLoop < sGrp.stNetUsrGrp.iUsrCnt; iLoop++)
		{
			if((strcmp(sGrp.stNetUsrGrp.cGropList[iLoop], sUsrName)) == 0)
			{
				fclose(fp);
				return ISIL_FAIL;
			}
		}
		strncpy((sGrp.stNetUsrGrp.cGropList[sGrp.stNetUsrGrp.iUsrCnt]), sUsrName, ISIL_NAME_LEN);
		sGrp.stNetUsrGrp.iUsrCnt++;
		iRet = ISIL_ModifyUsrGroup(sGrpName, &sGrp);
		if(iRet == ISIL_FAIL)
		{	fclose(fp);
			return ISIL_FAIL;
		}
	}
	else
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = ISIL_GetUsrInfoByName(sUsrName, &sUsr);

	if(iRet != ISIL_FAIL)
	{
		iLevel = sizeof(sUsr.stUsrNetCfg.lLevel) / sizeof(sUsr.stUsrNetCfg.lLevel[0]);
		ISIL_TRACE(BUG_NORMAL, "[%s] level size %d", __FUNCTION__, iLevel);
		for(iLoop = 0; iLoop < iLevel; iLoop++)
		{
			sUsr.stUsrNetCfg.lLevel[iLoop] |= sGrp.stNetUsrGrp.iLevel[iLoop];
		}
	}
	else
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = ISIL_ModifyUser(sUsrName, &sUsr);
	fclose(fp);
	return iRet;

}
/********************************************************
 *Function: ISIL_UsrGrpExit
 *Description: �������룬���ض�����ɾ��һ��
 *			�û�
 *Input:
 *	S08 *cUsrName:Ҫɾ�����û���
 *	S08 *sGrpName,�û�����
 *output:
 *       No
 *return:
 *        Success, 0
 *		   Fail,-1
 *******************************************************/

S32 ISIL_DelUsrFromGroup(S08 *sUsrName, S08 *sGrpName)
{
	S32 iRet;
	S32 iLine;
	S32 iLoop;
	S32 iLoop2;
	S32 iLevel;
	ISIL_USR_GROUP_S sGrp;
	ISIL_USR_CFG_S sUsr;
	FILE * fp;
	if(NULL == sGrpName || NULL == sGrpName)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] pointor is null", __FUNCTION__);
		return ISIL_FAIL;
	}
	/*����û��Ƿ����*/
	/*iLine = ISIL_ItemIsInFileField(ISIL_USER_INFO_FILE, sUsrName, 1);*/
	iLine = ISIL_UsrInfoExit(sUsrName);
	if(0 != iLine)/*user exit*/
	{
		ISIL_TRACE(BUG_ERROR, "[%s] User %s exit", __FUNCTION__, sUsrName);
	}
	/*����û����Ƿ����*/
	fp=fopen(ISIL_USER_GROUP_FILE, "r+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}
	iRet = ISIL_UsrGrpExit(fp, sGrpName);
	if(iRet == ISIL_FAIL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] Usergroup %s not exit", __FUNCTION__, sGrpName);
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = ISIL_GetUsrGroupInfoByName(sGrpName, &sGrp);
	/*ɾ��һ���û����������ߵ��û������ƶ�*/
	if(iRet != ISIL_FAIL)
	{
		for(iLoop = 0; iLoop < sGrp.stNetUsrGrp.iUsrCnt; iLoop++)
		{
			if((strcmp(sGrp.stNetUsrGrp.cGropList[iLoop], sGrpName)) == 0)
			{
				for(iLoop2 = iLoop; iLoop2 < sGrp.stNetUsrGrp.iUsrCnt; iLoop2++)
				{
					strncpy(sGrp.stNetUsrGrp.cGropList[iLoop2],
						sGrp.stNetUsrGrp.cGropList[iLoop2+1], ISIL_NAME_LEN);
				}

				break;
			}
		}
		sGrp.stNetUsrGrp.iUsrCnt--;
	}
	else
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = ISIL_GetUsrInfoByName(sUsrName, &sUsr);
	if(iRet != ISIL_FAIL)
	{
		iLevel = sizeof(sUsr.stUsrNetCfg.lLevel) / sizeof(sUsr.stUsrNetCfg.lLevel[0]);
		for(iLoop = 0; iLoop < iLevel; iLoop++)
		{
			sUsr.stUsrNetCfg.lLevel[iLoop] &= sGrp.stNetUsrGrp.iLevel[iLoop];

		}
	}
	else
	{
		fclose(fp);
		return ISIL_FAIL;
	}

	iRet = ISIL_ModifyUser(sUsrName, &sUsr);
	fclose(fp);
	return iRet;

}

S32 ISIL_ChangeUsrNameInGrp(S08* sGrpName, S08 * sOldName, S08 * sNewName)
{
	S32 iRet;
	S32 iLoop;
	ISIL_USR_GROUP_S sGrp;
	if(NULL == sGrpName
		|| NULL == sOldName
		|| NULL == sNewName)
	{
		return ISIL_FAIL;
	}

	iRet = ISIL_GetUsrGroupInfoByName(sGrpName, &sGrp);
	ISIL_TRACE(BUG_NORMAL, "[%s] usr cnt %d", __FUNCTION__, sGrp.stNetUsrGrp.iUsrCnt);
	if(iRet == ISIL_SUCCESS)
	{
		for(iLoop = 0; iLoop < sGrp.stNetUsrGrp.iUsrCnt; iLoop++)
		{
			if((strcmp(sGrp.stNetUsrGrp.cGropList[iLoop], sOldName)) == 0)
			{
				strncpy((sGrp.stNetUsrGrp.cGropList[sGrp.stNetUsrGrp.iUsrCnt]), sNewName, ISIL_NAME_LEN);
				return ISIL_SUCCESS;
			}
		}
	}
	return ISIL_FAIL;
}

#endif



/********************************************************
 *Function: ISIL_GetUsrInfoByName
 *Description: �����û����������û���Ϣ
 *Input:
 *	S08 *sName:��Ҫ���ҵ��û���
 *	ISIL_USR_CFG_S* sUsrInf:����û���Ϣ��ָ��
 *output:
 *       ISIL_USR_CFG_S* sUsrInf:�û���Ϣָ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_GetUsrInfoByName(S08 *sName, ISIL_USR_CFG_S* sUsrInf)
{
	S32 iFound = 0;
	S32 iDataSize;
	FILE *fp;

	if(NULL == sName || NULL == sUsrInf)
	{
		return ISIL_FAIL;
	}

	if ((fp = fopen(ISIL_USER_INFO_FILE, "r")) == NULL)
	{
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	while((fread(sUsrInf, iDataSize, 1, fp)) > 0)
	{
		if((strcmp(sUsrInf->sName, sName)) == 0) /*found*/
		{
			iFound = 1;
			break;
		}
	}

	fclose(fp);
	return iFound ? ISIL_SUCCESS : ISIL_FAIL;
}

/********************************************************
 *Function: ISIL_GetUsrInfoByName
 *Description: �����û�ID�������û���Ϣ
 *Input:
 *	S08 *sName:��Ҫ���ҵ��û���
 *	ISIL_USR_CFG_S* sUsrInf:����û���Ϣ��ָ��
 *output:
 *       ISIL_USR_CFG_S* sUsrInf:�û���Ϣָ��
 *return:
 *        Success: 0; Fail : -1
 *******************************************************/

S32 ISIL_GetUsrInfoByID(U32 uiUsrId, ISIL_USR_CFG_S* sUsrInf)
{
	S32 iFound = 0;
	S32 iDataSize;
	FILE *fp;

	if(NULL == sUsrInf)
	{
		return ISIL_FAIL;
	}

	if ((fp = fopen(ISIL_USER_INFO_FILE, "r")) == NULL)
	{
		return ISIL_FAIL;
	}
	iDataSize = sizeof(ISIL_USR_CFG_S);
	while((fread(sUsrInf, iDataSize, 1, fp)) > 0)
	{
		if(sUsrInf->lUserID == uiUsrId)/*found*/
		{
			iFound = 1;
			break;
		}
	}
	fclose(fp);
	return iFound ? ISIL_SUCCESS : ISIL_FAIL;
}

/********************************************************
 *Function: ISIL_GetUsrGroupInfoByName
 *Description: ���������û����������һ���û������Ϣ
 *Input:
 *	S08 *cUsrName:�û�������
 *	ISIL_USR_GROUP_S* sGrp:�û�����Ϣ����ָ��
 *output:
 *       ISIL_USR_GROUP_S* sGrp:�û�����Ϣ����ָ��
 *return:
 *	Success, 0; fail, -1
 *******************************************************/

S32 ISIL_GetUsrGroupInfoByName(S08* sUsrGrpName, ISIL_USR_GROUP_S* sGrp)
{
	S32 iDataSize;
	S32 iFound;
	FILE * fp;

	if(sUsrGrpName == NULL || sGrp == NULL)
	{

		ISIL_TRACE(BUG_ERROR, "[%s] pointer is null", __FUNCTION__);
		return ISIL_FAIL;
	}

	fp=fopen(ISIL_USER_GROUP_FILE, "r");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}

	iDataSize = sizeof(ISIL_USR_GROUP_S);

	while((fread(sGrp, iDataSize, 1, fp)) > 0)
	{
		if((strcmp(sGrp->sGroupName, sUsrGrpName)) == 0) /*found*/
		{
			iFound = 1;
			break;
		}
	}
	fclose(fp);
	return iFound ? ISIL_SUCCESS : ISIL_FAIL;;

}

/********************************************************
 *Function: ISIL_GetUsrGroupInfoByID
 *Description: ���������û���ID�����һ���û������Ϣ
 *Input:
 *	S08 *cUsrName:�û�������
 *	ISIL_USR_GROUP_S* sGrp:�û�����Ϣ����ָ��
 *output:
 *       ISIL_USR_GROUP_S* sGrp:�û�����Ϣ����ָ��
 *return:
 *	Success, 0; fail, -1
 *******************************************************/

S32 ISIL_GetUsrGroupInfoByID(U32 uiUsrGrpID, ISIL_USR_GROUP_S* sGrp)
{
	S32 iFound = 0;
	S32 iDataSize;
	FILE * fp;

	if(sGrp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] pointer is null", __FUNCTION__);
		return ISIL_FAIL;
	}
	fp=fopen(ISIL_USER_GROUP_FILE, "r+");
	if(fp == NULL)
	{
		ISIL_TRACE(BUG_ERROR, "[%s] open file fail", __FUNCTION__);
		return ISIL_FAIL;
	}

	iDataSize = sizeof(ISIL_USR_GROUP_S);
	while((fread(sGrp, iDataSize, 1, fp)) > 0)
	{
		if(sGrp->lGroupID == uiUsrGrpID)
		{
			ISIL_TRACE(BUG_NORMAL, "[%s] get gid %d", __FUNCTION__, uiUsrGrpID);
			iFound = 1;
			break;
		}
	}

	fclose(fp);
	return (iFound ? ISIL_SUCCESS : ISIL_FAIL);

}


/********************************************************
 *Function: ISIL_SaveAllUserInfo
 *Description: �����û���Ϣ
 *Input:
 *	void *pAllInfo: �û���Ϣָ��(�û�/�û���)
 *	S32 iInfoSize: ��Ҫ������û���Ϣ��С
 *	S32 iInfoType: ������û���Ϣ����
 *				   0:�û���Ϣ
 *				   1:�û�����Ϣ
 *output:
 *       ISIL_USR_GROUP_S* sGrp:�û�����Ϣ����ָ��
 *return:
 *	Success, 0; fail, -1
 *******************************************************/

S32 ISIL_SaveAllUserInfo(void *pAllInfo, S32 iInfoSize, S32 iInfoType)
{
	S32 iRet = ISIL_FAIL;
	S32 iType = 1;
	if(NULL == pAllInfo)
	{
		return ISIL_FAIL;
	}

	if(iInfoType == 0) /*Usr information*/
	{
		iRet = ISIL_WriteConfigFile(ISIL_USER_INFO_FILE, 0, iInfoSize,
			&iType, pAllInfo);
	}
	else if(iInfoType == 1)
	{
		iRet = ISIL_WriteConfigFile(ISIL_USER_GROUP_FILE, 0, iInfoSize,
			&iType, pAllInfo);
	}
	return iRet;
}

/********************************************************
 *Function: ISIL_GetAllUserInfo
 *Description: ����û���Ϣ
 *Input:
 *	void *pAllInfo: �û���Ϣָ��(�û�/�û���)
 *	S32 iInfoSize: ��Ҫ��õ��û���Ϣ��С
 *	S32 iInfoType: �û���Ϣ����
 *				   0:�û���Ϣ
 *				   1:�û�����Ϣ
 *output:
 *       void *pAllInfo:�û�����Ϣָ��
 *return:
 *	Success, 0; fail, -1
 *******************************************************/

S32 ISIL_GetAllUserInfo(void *pAllInfo, S32 iInfoSize, S32 iInfoType)
{
	S32 iRet = ISIL_FAIL;
	S32 iType = 0;
	if(NULL == pAllInfo)
	{
		return ISIL_FAIL;
	}

	if(iInfoType == 0) /*Usr information*/
	{
		iRet = ISIL_ReadConfigFile(ISIL_USER_INFO_FILE, 0, iInfoSize,
			&iType, pAllInfo);
	}
	else if(iInfoType == 1)
	{
		iRet = ISIL_ReadConfigFile(ISIL_USER_GROUP_FILE, 0, iInfoSize,
			&iType, pAllInfo);
	}
	return iRet;
}

S32 ISIL_GetAllUsrInfoSize()
{
    return ISIL_GetFileSize(ISIL_USER_INFO_FILE);
}
S32 ISIL_GetAllUsrGrpInfoSize()
{
    return ISIL_GetFileSize(ISIL_USER_GROUP_FILE);
}


S32 ISIL_InitUsrCfgFile()
{
	S32 fd;
	S32 iRet;
	ISIL_USR_GROUP_S sGrp;
	ISIL_USR_CFG_S sUsr;

	fd = open(ISIL_USER_INFO_FILE, O_CREAT | O_RDONLY,0644);
	if (fd < 0)
	{
		return ISIL_FALSE;
	}
	close(fd);

	fd = open(ISIL_USER_GROUP_FILE, O_CREAT | O_RDONLY,0644);
	if (fd < 0)
	{
		return ISIL_FALSE;
	}
	close(fd);

	iRet = ISIL_GetFileSize(ISIL_USER_INFO_FILE);
	if(iRet == 0)/*����admin*/
	{
		memset(&sUsr, 0, sizeof(ISIL_USR_CFG_S));
		sUsr.lGroupID = 0;
		sUsr.lUserID = 0;
		strncpy(sUsr.sName, "admin", ISIL_NAME_LEN);
		strncpy(sUsr.sPassword, "admin", ISIL_PASSWORD_LEN);
		memset(sUsr.cLevel, 0xff, sizeof(sUsr.cLevel));

		ISIL_SaveAllUserInfo(&sUsr, sizeof(ISIL_USR_CFG_S), 0);
	}
	iRet = ISIL_GetFileSize(ISIL_USER_GROUP_FILE);
	if(iRet == 0)/*����admin*/
	{
		memset(&sGrp, 0, sizeof(ISIL_USR_GROUP_S));
		sGrp.lGroupID = 0;
		strncpy(sGrp.sGroupName, "admin", ISIL_NAME_LEN);
		strncpy(sGrp.sGroupPassword, "admin", ISIL_PASSWORD_LEN);
		memset(sGrp.cLevel, 0xff, sizeof(sGrp.cLevel));

		ISIL_SaveAllUserInfo(&sGrp, sizeof(ISIL_USR_GROUP_S), 1);
	}
	return ISIL_SUCCESS;
}

/********************************************************
 *Function: ISIL_UsrLevelMatch
 *Description: �����û�ID,�鿴�û�Ȩ���Ƿ�ƥ��
 *Input:
 *	S32 iUsrID:�û�ID
 *	S32 iLevel,��ǰ��Ҫ��Ȩ��
 *output:
 *       No
 *return:
 *        Success, 1
 *		  Fail,	   0
 *******************************************************/

S32 ISIL_UsrLevelMatch(U32 uiUsrID, S32 iLevel)
{
	S32 iRet;
	S32 iLevel1;
	S32	iLevelBit;
	ISIL_USR_CFG_S stUsrInfo;
	iLevel1 = iLevel / ISIL_USR_LEVEL_BIT;
	iLevelBit = iLevel % ISIL_USR_LEVEL_BIT;
	iRet = ISIL_GetUsrInfoByID(uiUsrID, &stUsrInfo);
	if(iRet != ISIL_FAIL)
	{
		if(((stUsrInfo.cLevel[iLevel1] >> iLevelBit) & 0x1)
			== 1)
		{
			ISIL_TRACE(BUG_NORMAL, "[%s] user level %d is match", __FUNCTION__, iLevel);
			return ISIL_TRUE;
		}
	}

	ISIL_TRACE(BUG_NORMAL, "[%s] user level %d not match", __FUNCTION__, iLevel);
	return ISIL_FALSE;
}

/********************************************************
 *Function: ISIL_VerifyUsrInfo
 *Description: ��������û������Ƿ���ȷ
 *Input:
 *	ISIL_USR_CFG_S * sUsrInfo: �û�����Ĳ���
 *output:
 *       No
 *return:
 *        not -1: Success; -1: Fail
 *******************************************************/

S32 ISIL_VerifyUsrInfo(ISIL_USR_LOGIN_S *sUsrLogin)
{
	S32 iRet;
	ISIL_USR_CFG_S sUsrInf;
	if(NULL == sUsrLogin)
	{
		ISIL_TRACE(BUG_ERROR,"User infomation pointer null");
		return ISIL_FAIL;
	}
	iRet = ISIL_GetUsrInfoByName(sUsrLogin->sName, &sUsrInf);
	if(ISIL_FAIL != iRet)
	{
		ISIL_TRACE(BUG_NORMAL, "[%s] find usr %s, pwd %s", __FUNCTION__, sUsrInf.sName, sUsrInf.sPassword);
		if((strcmp(sUsrLogin->sPassword, sUsrInf.sPassword) == 0)
			|| (strcmp(sUsrInf.sPassword, USER_DEFAULT_PWD) == 0
			&& strcmp(sUsrLogin->sPassword, "") == 0))

		{
			ISIL_TRACE(BUG_NORMAL, "[%s] %s login success", __FUNCTION__, sUsrLogin->sName);
			return ISIL_SUCCESS;
		}

	}
	ISIL_TRACE(BUG_NORMAL, "[%s] %s login fail", __FUNCTION__, sUsrLogin->sName);
	return ISIL_FAIL;
}


