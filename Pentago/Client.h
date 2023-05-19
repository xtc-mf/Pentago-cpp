#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable: 4996)

using namespace System::Runtime::InteropServices;

static SOCKET initClientSocket(System::String^ address, int port) {
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
	if (connect(sListen, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
		exit(1);
	}
	return sListen;
}
