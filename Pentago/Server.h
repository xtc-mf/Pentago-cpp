#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <string>
#include <iostream>

using namespace System::Runtime::InteropServices;

static SOCKET initServerSocket(System::String^ address, int port) {
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 1), &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr((char*)(void*)Marshal::StringToHGlobalAnsi(address));
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);

	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
		exit(1);
	}

	return newConnection;
}

static System::String^ getIp() {
	//source -> https://github.com/sasarog/Sockets/blob/master/Sockets/Messenger.h

	System::String^ s = "";
	// Получение ip-адреса.
	array <System::Net::IPAddress^>^ masAdress = System::Net::Dns::GetHostByName(System::Net::Dns::GetHostName())->AddressList;
	for each (System::Net::IPAddress ^ var in masAdress)
	{
		s += var->ToString() + "\n";
	}

	return s;
}