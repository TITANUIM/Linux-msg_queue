//对各个接口进行定义

#include"comm.h"

int server_type = 1;
int client_type = 2;


static int comm_msg_queue(int flags) //生成新消息队列或者取得已存在的消息队列
{
	key_t _key = ftok(_PATH_NAME_,_PROJ_ID_); 
	if(_key < 0)
	{
		printf("%d : %s",errno,strerror(errno));
		return -1;
	}

	int msg_id = msgget(_key,flags);
	//int msg_id = msgget(_key,IPC_CREAT | IPC_EXCL | 0666);
	return msg_id;
}

int creat_msg_queue()  //创建
{
	int flags = IPC_CREAT | IPC_EXCL | 0666;
	return comm_msg_queue(flags);
}

int get_msg_queue() //获取
{
	int flags = IPC_CREAT;
	return comm_msg_queue(flags);
}

int destroy_queue(int msg_id) //销毁
{
	if(msgctl(msg_id,IPC_RMID,NULL) != 0)
	{
		printf("%d : %s",errno,strerror(errno));
		return -1;
	}

	return 0;
}

int send_msg(int msg_id,int send_type,const char* msg) //发送
{
	struct msgbuf _buf;
	_buf.mtype = send_type;
	strncpy(_buf.mtext,msg,strlen(msg)+1);

	if(msgsnd(msg_id,&_buf,sizeof(_buf.mtext),0) < 0)
	{
		printf("%d : %s",errno,strerror(errno));
	    return -1;
	}
	return 0;
}

int recv_msg(int msg_id,int recv_type,char* msg_out) //接收
{
	struct msgbuf _buf;
	_buf.mtype = 0;
	memset(_buf.mtext,'\0',sizeof(_buf.mtext));

	if(msgrcv(msg_id,&_buf,sizeof(_buf.mtext),recv_type,0) < 0)
	{
		printf("%d : %s",errno,strerror(errno));
	    return -1;
	}

	strcpy(msg_out,_buf.mtext);
	return 0;
}

