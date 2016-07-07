#pragma once

#include<stdio.h>
//头文件声明各个接口函数

#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define _PATH_NAME_ "/tmp"
#define _PROJ_ID_ 0x6666
#define _SIZE_ 1024

extern int server_type;
extern int client_type;


struct msgbuf
{
	long mtype;
	char mtext[_SIZE_];
};

int creat_msg_queue();
int get_msg_queue();
//int creat_msg_queue(int msg_id);
int send_msg(int msg_id,int send_type,const char* msg);
int recv_msg(int msg_id,int recv_type,char* msg_out);
int destroy_queue(int msg_id);


