
#include "fdfs_download_file.hpp"
#include "fcgi_stdio.h"
#include <stdlib.h>
#include "mysql_query.hpp"
 
int main(void)
{
		//int fdfs_download_file(int argc, char *argv[]);
		/*printf("Usage: %s <config_file> <file_id> " \
			"[local_filename] [<download_offset> " \
			"<download_bytes>]\n", argv[0]);
		*/
		char fileid[128];
		int result;
    while (FCGI_Accept() >= 0){
    	//ҵ��
    	
    	//��httpЭ���еõ�filename
    	/*
    		getenv(QUERY_STRING);
    	*/
    	
    	//���ݿ��в�ѯfilename->file_id
   
    	result = mysql_query(char *filename/*in*/,char *fileid/*out*/);
    	if (result != 0) 
    		{
    			printf("mysql_query error\n");
    		}
    		
    		
    	//int fdfs_download_file(int argc, char *argv[])
    	int argc = 2;
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
		
    	
    	fdfs_download_file(argc, argv[]);
    
    }
    return 0;
}

