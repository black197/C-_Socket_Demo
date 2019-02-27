// client.cpp

// 作者：小拳头
// 来源：CSDN
// 原文：https ://blog.csdn.net/xiaoquantouer/article/details/58001960 
// 版权声明：本文为博主原创文章，转载请附上博文链接！

/*
 * VS2017需要把"项目"-"配置属性"-"C/C++"-"常规"中的"SDL检查"改为"否",使函数inet_ntoa能编译通过。
 */

#include<WINSOCK2.H>
#include<STDIO.H>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{
	// 初始化WSA
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	while (true) {
		// 创建套接字
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		// 绑定ip和端口
		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

		// 连接服务端
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{  // 连接失败
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		// 发送数据
		string data;
		cin >> data;
		const char * sendData;
		sendData = data.c_str();   //string转const char* 
								   //char *sendData = "你好，TCP服务端，我是客户端\n";
		send(sclient, sendData, strlen(sendData), 0);

		/* send()用来将数据由指定的socket传给对方主机
		 * int send(int s, const void * msg, int len, unsigned int flags)
		 * s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0
		 * 成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error
		 */

		// 接收数据
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret>0) {
			recData[ret] = 0x00;
			printf(recData);
		}

		closesocket(sclient);
	}

	WSACleanup();
	system("pause");
	return 0;
}
