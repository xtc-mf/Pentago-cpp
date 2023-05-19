#pragma once
ref class BotHandler
{
	System::EventHandler^ moveHandler;
	System::EventHandler^ rotateHandler;

	System::Void timerTick(System::Object^, System::Timers::ElapsedEventArgs^);

	bool type = false; //false -> move; true -> rotate; 

public: 
	BotHandler(System::EventHandler^ moveHandler, System::EventHandler^ rotateHandler);
};

