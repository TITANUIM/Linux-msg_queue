//客户端程序

#include"comm.h"

int main()
{
	#include"comm.h"

int main()
{
	//int msg_id = creat_msg_queue();
	
	//if(msg_id <0)
	//{
	//	printf("%d : %s\n",errno,strerror(errno));
	//	return 1;
	//}
	//
	//
	int msg_id = get_msg_queue();

	char buf[_SIZE_];
	while(1)
	{
		printf("Please Enter:");
		fflush(stdout);
		ssize_t _s = read(0,buf,sizeof(buf)-1);
		if(_s >0 )
		{
			buf[_s - 1] = '\0';
		}
		send_msg(msg_id,client_type,buf);
		if(strcasecmp(buf,"quit") == 0)
		{
			break;
		}

		memset(buf,'\0',sizeof(buf));
		recv_msg(msg_id,server_type,buf);
		printf("server# %s\n",buf);
	}

	return 0;
}

	int msg_id = get_msg_queue();

	char buf[_SIZE_];
	while(1)
	{
		printf("Please Enter:");
		fflush(stdout);
		ssize_t _s = read(0,buf,sizeof(buf)-1);
		if(_s >0 )
		{
			buf[_s - 1] = '\0';
		}
		send_msg(msg_id,client_type,buf);
		if(strcasecmp(buf,"quit") == 0)
		{
			break;
		}

		memset(buf,'\0',sizeof(buf));
		recv_msg(msg_id,server_type,buf);
		printf("server# %s\n",buf);
	}

	return 0;
}
