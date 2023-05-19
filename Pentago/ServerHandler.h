#pragma once
#include <WinSock2.h>

using namespace System::Runtime::InteropServices;

ref class ServerHandler
{
	System::EventHandler^ moveHandler;
	System::EventHandler^ rotateHandler;
	System::EventHandler^ winHandler;
	SOCKET socket;

	void handle();

public:
	ServerHandler(System::EventHandler^ moveHandler, System::EventHandler^ rotateHandler, System::EventHandler^ winHandler);

	void start(SOCKET socket);

	void sendMsg(System::String^ msg) {
		auto ptrToNativeString = Marshal::StringToHGlobalAnsi(msg + L" ");
		char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());	

		send(this->socket, nativeString, 256, NULL);
	}
};