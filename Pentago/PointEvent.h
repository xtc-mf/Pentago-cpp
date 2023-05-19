#pragma once

public ref class PointEvent : System::EventArgs
{
public:
	int i;
	int x = 0;
	int y = 0;

	PointEvent(int i, int x, int y) {
		this->i = i;
		this->x = x;
		this->y = y;
	}

	PointEvent(int i) {
		this->i = i;
	}
};