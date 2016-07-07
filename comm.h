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

int creat_msg_queue(); // 创建消息队列
int get_msg_queue(); // 获取
//int creat_msg_queue(int msg_id); 
int send_msg(int msg_id,int send_type,const char* msg);  // 发送消息
int recv_msg(int msg_id,int recv_type,char* msg_out); // 接收消息
int destroy_queue(int msg_id); // 销毁消息队列


