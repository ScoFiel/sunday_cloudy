#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "mysql.h"
                                     
int mysql_query(char *filename/*in*/,char *fileid/*out*/)
{
	int ret = 0;
	
	MYSQL *mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	//char file_id[128];
	
	char query[1024];
	memset(query,0,sizeof(query));
	sprintf(query,"SELECT fileid FROM test_table where filename = %s",filename);
	mysql = mysql_init(NULL);
	
	mysql =mysql_real_connect(mysql, "localhost", "root", "123456", "mydb2", 0, NULL, 0);
	if (mysql == NULL) {
		ret = mysql_errno(mysql);
		printf("func mysql_real_connect() err\n");
		return ret;
	} else {
		printf(" ok......\n");
	}
	
	ret = mysql_query(mysql, query);	
	if (ret != 0) {
		printf("mysql_query() err:%d\n", ret);
		return ret;
	}
	
	MYSQL_RES *result = mysql_store_result(mysql);
	
	while(row = mysql_fetch_row(result)) {
			strncpy(file_id, row[0],sizeof(fileid));
		}
	
	mysql_close(mysql);
	
	return 0;	
}
