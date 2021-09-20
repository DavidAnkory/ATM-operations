#pragma once
#include <iostream>

using namespace std;


class Clock
{
private:
	int hour;
	int minute;
	int second;


public:
	//constructors
	//Clock();
	Clock(int h = 0, int m = 0, int s = 0);
	Clock(const Clock& c);

	//get & set
	void sethour(int h);
	void setminute(int m);
	void setsecond(int s);
	int gethour() { return hour; };
	int getminute() { return minute; };
	int getsecond() { return second; };
	friend ostream& operator<<(ostream& out, Clock& c);
	friend istream& operator>>(istream& in, Clock& c);

	//operators
	Clock operator+=(int s);
};

