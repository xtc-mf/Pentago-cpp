#include "ServerHandler.h"
#include "Server.h"
#include "PointEvent.h"
#include <iostream>

using namespace System::Threading;


ServerHandler::ServerHandler(System::EventHandler^ moveHandler, System::EventHandler^ rotateHandler, System::EventHandler^ winHandler) {
	this->moveHandler = moveHandler;
	this->rotateHandler = rotateHandler;
	this->winHandler = winHandler;
}

void ServerHandler::start(SOCKET socket) {
	this->socket = socket;
	Thread^ t = gcnew Thread(gcnew ThreadStart(this, &ServerHandler::handle));
	t->Start();
}

void ServerHandler::handle() {
	while (true)
	{
		try
		{
			char msg[256];
			recv(socket, msg, sizeof(msg), NULL);

			System::String^ recivedMsg = gcnew System::String(msg);

			if (recivedMsg->StartsWith("move_")) // move_i(int)_x(int)_y(int) => move_0_1_2
			{
				auto points = recivedMsg->Substring(5)->Split('_');

				int i = System::Convert::ToInt32(points[0]);
				int x = System::Convert::ToInt32(points[1]);
				int y = System::Convert::ToInt32(points[2]);

				if (this->moveHandler != nullptr) this->moveHandler->Invoke(nullptr, gcnew PointEvent(i, x, y));
			}

			if (recivedMsg->StartsWith("rotate_")) // rotate_i(int) => rotate_0
			{
				auto point = recivedMsg->Substring(7);

				int i = System::Convert::ToInt32(point);

				if (this->rotateHandler != nullptr) this->rotateHandler->Invoke(nullptr, gcnew PointEvent(i));
			}

			if (recivedMsg->StartsWith("win")) // win => win
			{
				if (this->winHandler != nullptr) this->winHandler->Invoke(nullptr, nullptr);
			}

			

			if (recivedMsg == "stop") break;

		}
		catch (const std::exception&)
		{

		}
	}
}