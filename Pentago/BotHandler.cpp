#include "BotHandler.h"
#include "PointEvent.h"
#include <stdlib.h>

BotHandler::BotHandler(System::EventHandler^ moveHandler, System::EventHandler^ rotateHandler) {
	this->moveHandler = moveHandler;
	this->rotateHandler = rotateHandler;

	System::Timers::Timer^ timer = gcnew System::Timers::Timer();
	timer->Interval = 250;
	timer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &BotHandler::timerTick);
	timer->Start();
}

System::Void BotHandler::timerTick(System::Object^, System::Timers::ElapsedEventArgs^) {
	int i = rand() % 4;
	int x = rand() % 3;
	int y = rand() % 3;
	int r = rand() % 4;

	if (this->type) this->moveHandler(nullptr, gcnew PointEvent(i, x, y));
	else this->rotateHandler(nullptr, gcnew PointEvent(r));

	this->type = !this->type;
}