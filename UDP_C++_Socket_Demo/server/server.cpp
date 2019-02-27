// server.cpp  

/* �ο�����
 * C++ Socket UDP "Hello World!"
 * https://www.cnblogs.com/findumars/p/5928712.html
 */

#include <stdio.h>
#include <WINSOCK2.H>  

#pragma comment(lib,"WS2_32.lib")  
#define BUF_SIZE    64  

int main()
{
	WSADATA wsd;
	SOCKET  s;
	int     nRet;

	// ��ʼ���׽��ֶ�̬��  
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		printf("WSAStartup failed !/n");
		return 1;
	}

	// �����׽���  
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s == INVALID_SOCKET)
	{
		printf("socket() failed ,Error Code:%d/n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	SOCKET      socketSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	SOCKADDR_IN addrClient;
	char        buf[BUF_SIZE];
	int         len = sizeof(SOCKADDR);

	// ���÷�������ַ  
	ZeroMemory(buf, BUF_SIZE);
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(5000);

	// ���׽���  
	nRet = bind(socketSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (SOCKET_ERROR == nRet)
	{
		printf("bind failed !/n");
		closesocket(s);
		WSACleanup();
		return -1;
	}

	// �ӿͻ��˽�������  
	nRet = recvfrom(socketSrv, buf, BUF_SIZE, 0, (SOCKADDR*)&addrClient, &len);
	if (SOCKET_ERROR == nRet)
	{
		printf("recvfrom failed !/n");
		closesocket(s);
		WSACleanup();
		return -1;
	}
	// ��ӡ���Կͻ��˷�����������  
	printf("Recv From Client:%s\n", buf);

	// ��ͻ��˷�������  
	sendto(socketSrv, "UDP Hello World !", sizeof("UDP Hello World !"), 0, (SOCKADDR*)&addrClient, len);
	closesocket(s);
	WSACleanup();

	system("pause");

	return 0;
}