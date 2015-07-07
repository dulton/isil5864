#ifndef __ISIL_FM_FDISK_H_
#define __ISIL_FM_FDISK_H_

#ifdef __cplusplus
extern "C" {
#endif

//define partion type
enum _eFSTYPE
{
    FS_TYPE_EXT3 = 0x83,//ext3
    FS_TYPE_FAT32= 0x01,//fat32
}ISIL_FM_FDISK_FS_TYPE;


#ifndef MAX_PATH_LEN

#define MAX_PATH_LEN (32)//�����豸�ڵ㼰mount�豸·������󳤶�

#endif

//���÷�������
extern int ISIL_FM_DISK_SetPartionType(unsigned char PartionType);

//����,Ŀǰֻ��һ����
extern int ISIL_FM_DISK_Fdisk(char SysType);

//�����ļ�ϵͳ
extern int ISIL_FM_DISK_Mkfs(char *strFsType);

//�����������ļ�ϵͳ
extern int ISIL_FM_DISK_Format();

//������KBΪ��λ��ֵ
extern unsigned int ISIL_FM_DISK_GetDiskCapacity();

//�����豸�ڵ�
extern int ISIL_FM_DISK_SetNodePath(char *NodePath, char *MntPath);

#ifdef __cplusplus
}
#endif
#endif



