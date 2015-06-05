/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.csource.org/ for more detail.
**/
#include "fdfs_upload_file.h"


int main(void)
{
   // int count = 0;
   /*Usage: %s <config_file> <local_filename> [storage_ip:port] [store_path_index]*/
   	int argc = 2;
   	int result;
   	char *argv[3];
   	char fileid;
   	
		//��ȡ��ǰ�������·��
		char current_absolute_path[128];
		int cnt = readlink("/proc/self/exe", current_absolute_path, 128);
		if (cnt < 0 || cnt >= MAX_SIZE)
		{
		    printf("readlink Error\n");
		    exit(-1);
		}
		
		strncpy(argv[0],current_absolute_path,strlen(current_absolute_path));
		strcpy(argv[1],"/etc/fdfs/client.conf");
		strcpy(argv[2],/*filename*/);
		
    while (FCGI_Accept() >= 0)
    {
    	int result;
    	
    	//�û��������룬ʱ�䣬�ļ���argv[2],�ļ�ID file_id_bak
			/*
			char username[30];
			char password[30];
			//char time[];
			//time timestamp
			char	*localfilename;
			char file_id_bak[128];
			*/
			
			//��httpЭ��������Ǹ��ļ���ȡ����
			/*
			getenv(CONTENT_LENGTH);//�ļ���С
			localfilename = getenv(QUERY_STRING);//
			*/
			
			up_load(argc/*in*/, argv/*in*/,fileid/*out:char [128]*/);
			
			result = mysql_insert(filename/*in*/, fileid/*in*/);
			if(result != 0)
			{
				printf("mysql_insert error\n");
			}
			
			//�����ݲ��뵽���ݿ�
			/*
				uploadmysql(void);
			*/
			
    }
       
    return result;
}