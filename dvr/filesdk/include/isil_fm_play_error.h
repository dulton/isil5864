#ifndef _ISIL_SDK_ERROR_DEFINE_H_
#define _ISIL_SDK_ERROR_DEFINE_H_

//NVM SDK ������
typedef enum _eISIL_ERR_CODE
{
	ISIL_ERR_SUCCESS 			=       0 , //û�д���
	ISIL_ERR_FAILURE             =       -1,	//����ʧ��
	ISIL_ERR_PASSWORD_ERROR      =    -1000, //�û����������
	ISIL_ERR_NOENOUGHPRI,  			        //Ȩ�޲���
	ISIL_ERR_NOINIT, 					    //û�г�ʼ��
	ISIL_ERR_INITERROR,                      //��ʼ��ʧ��
	ISIL_ERR_NOLOGIN,                        //û�е�½
	ISIL_ERR_CHANNEL_ERROR, 			        //ͨ���Ŵ���
	ISIL_ERR_OVER_MAXLINK, 			        //���ӵ�DVR�Ŀͻ��˸����������
	ISIL_ERR_VERSIONNOMATCH,			        //�汾��ƥ��
	ISIL_ERR_NETWORK_FAIL_CREATESOCKET,      //����socketʧ��
	ISIL_ERR_NETWORK_FAIL_CONNECT,	        //���ӷ�����ʧ��
	ISIL_ERR_NETWORK_SEND_ERROR,		        //�����������ʧ��
	ISIL_ERR_NETWORK_RECV_ERROR,		        //�ӷ�������������ʧ��
	ISIL_ERR_NETWORK_RECV_TIMEOUT,	        //�ӷ������������ݳ�ʱ
	ISIL_ERR_NETWORK_ERRORDATA,		        //���͵���������
	ISIL_ERR_CREATEBUFFER_ERROR,             //�ڴ����ʧ��
	ISIL_ERR_ORDER_ERROR,				    //���ô������
	ISIL_ERR_OPERNOPERMIT,			        //�޴�Ȩ��
	ISIL_ERR_COMMANDTIMEOUT,			        //DVR����ִ�г�ʱ
	ISIL_ERR_ERRORSERIALPORT,			    //���ںŴ���
	ISIL_ERR_ERRORALARMPORT,			        //�����˿ڴ���
	ISIL_ERR_PARAMETER_ERROR, 		        //��������
	ISIL_ERR_PARAMETERBUFFERTOOSMALL, 		//���ղ���������̫С
	ISIL_ERR_CHAN_EXCEPTION,				    //������ͨ�����ڴ���״̬
	ISIL_ERR_NODISK,						    //û��Ӳ��
	ISIL_ERR_ERRORDISKNUM,				    //Ӳ�̺Ŵ���
	ISIL_ERR_DISK_FULL,					    //������Ӳ����
	ISIL_ERR_DISK_ERROR,					    //������Ӳ�̳���
	ISIL_ERR_NOSUPPORT,					    //��������֧��
	ISIL_ERR_BUSY,						    //������æ
	ISIL_ERR_MODIFY_FAIL,					//�������޸Ĳ��ɹ�
	ISIL_ERR_PASSWORD_FORMAT_ERROR,		    //���������ʽ����ȷ
	ISIL_ERR_DISK_FORMATING,				    //Ӳ�����ڸ�ʽ����������������
	ISIL_ERR_DVRNORESOURCE,				    //DVR��Դ����
	ISIL_ERR_DVROPRATEFAILED,			    //DVR����ʧ��
	ISIL_ERR_OPENHOSTSOUND_FAIL, 		    //��PC����ʧ��
	ISIL_ERR_DVRVOICEOPENED, 			    //�����������Խ���ռ��
	ISIL_ERR_TIMEINPUTERROR,			        //ʱ�����벻��ȷ
	ISIL_ERR_NOSPECFILE,				        //�ط�ʱ������û��ָ�����ļ�
	ISIL_ERR_DIR_ERROR,					    //·������
	ISIL_ERR_ALLOC_RESOUCE_ERROR,		    //��Դ�������
	ISIL_ERR_AUDIO_MODE_ERROR,			    //����ģʽ����
	ISIL_ERR_NOENOUGH_BUF,				    //������̫С
	ISIL_ERR_CREATESOCKET_ERROR,			    //����SOCKET����
	ISIL_ERR_SETSOCKET_ERROR,				//����SOCKET����
	ISIL_ERR_MAX_NUM,						//�����ﵽ���
	ISIL_ERR_USERNOTEXIST,				    //�û�������
	ISIL_ERR_WRITEFLASHERROR,			    //дFLASH����
	ISIL_ERR_UPGRADEFAIL,				    //DVR����ʧ��
	ISIL_ERR_CARDHAVEINIT,			        //���뿨�Ѿ���ʼ����
	ISIL_ERR_PLAYERFAILED,				    //�������д���
	ISIL_ERR_MAX_USERNUM,			        //�û����ﵽ���
	ISIL_ERR_GETLOCALIPANDMACFAIL,	        //��ÿͻ��˵�IP��ַ�������ַʧ��
	ISIL_ERR_NOENCODEING,					//��ͨ��û�б���
	ISIL_ERR_IPMISMATCH,					    //IP��ַ��ƥ��
	ISIL_ERR_MACMISMATCH,					//MAC��ַ��ƥ��
	ISIL_ERR_UPGRADELANGMISMATCH,		    //�����ļ����Բ�ƥ��
	ISIL_ERR_TALKING,                        //��ǰ�豸���ڶԽ���...
	
	ISIL_ERR_FILE_CREATE        = -1200,		//�����ļ�����
	ISIL_ERR_FILE_WRITE,                     //�ļ�д����
	ISIL_ERR_FILE_OPEN,			            //���ļ�����
	ISIL_ERR_FILE_READ,                      //�ļ�������
	ISIL_ERR_FILE_CREATEINDEX,               //�ļ�����������
	ISIL_ERR_FILE_OPERATE,                   //��������
	ISIL_ERR_FILE_GETPLAYTIME,			    //��ȡ��ǰ���ŵ�ʱ�����
	ISIL_ERR_FILE_FORMAT,		            //�ļ���ʽ����ȷ
	ISIL_ERR_FILE_PLAY,				        //���ų���
	ISIL_ERR_FILE_READDATA_OVERSIZE,         //ȡ�ļ����ݿ���󣬲�Ӧ����64M
	ISIL_ERR_FILE_BEGIN,                     //�ļ�ͷ
 	ISIL_ERR_FILE_END,                       //�ļ�β
	ISIL_ERR_FILE_REMAIN_FRAME,              //��������֡��Ӧ����������getnextframe,���ҵ�ǰȡ�������ǲ���ʾ����Ҫ����֡��ʱ

    ISIL_ERR_DEV_FAILURE         =    -2000,	//����豸�˵Ĳ���ʧ��

}ISILERR_CODE;

#endif