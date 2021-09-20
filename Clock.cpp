#include <iostream>
#include <cstring>
using namespace std;

#include "Clock.h"


Clock::Clock(int h, int m, int s)
{


	//hour
	if (h > 24)
	{
		cout << "Invalid time - more than 24 hours." << endl;
		sethour(0);
	}
	if (h < 0)
	{
		cout << "Invalid time - negative number of hours." << endl;
		sethour(0);

	}
	if (h <= 24 && h >= 0)
	{
		sethour(h);
	}

	////minute
	if (m > 60)
	{
		cout << "Invalid time - more than 60 minutes." << endl;
		setminute(0);
	}
	if (m < 0)
	{
		cout << "Invalid time - negative number of minutes." << endl;
		setminute(0);

	}
	if (m <= 60 && m >= 0)
	{
		setminute(m);
	}

	//second
	if (s > 60)
	{
		cout << "Invalid time - more than 60 seconds." << endl;
		setsecond(0);
	}
	if (s < 0)
	{
		cout << "Invalid time - negative number of seconds." << endl;
		setsecond(0);

	}
	if (s <= 60 && s >= 0)
	{
		setsecond(s);
	}

}

Clock::Clock(const Clock& c)
{
	hour = c.hour;
	minute = c.minute;
	second = c.second;
}

//Set 
void Clock::sethour(int h)
{
	if (h <= 24 && h > 0)
	{
		hour = h;
	}

	else
		hour = h;
}

void Clock::setminute(int m)
{
	if (m <= 60 && m > 0)
	{
		minute = m;
	}

	else
		minute = m;
}
void Clock::setsecond(int s)
{
	if (s <= 60 && s > 0)
	{
		second = s;
	}

	else
		second = s;
}


//operators
Clock Clock ::operator+=(int sec)
{
	int h, m, s;
	h = hour;
	m = minute;
	s = second + sec;
	if (s >= 60)
	{
		m += s / 60;
		s = (s % 60);
		if (m >= 60)
		{
			h += m / 60;
			m = (m % 60);

			if (h >= 24)
			{
				cout << "Invalid time - more than 24 hours." << endl;
				hour = 0;
				minute = 0;
				second = 0;

				return *this;
			}
		}
	}
	hour = h;
	minute = m;
	second = s;
	return *this;
}

ostream& operator<<(ostream& out, Clock& c)
{
	if (c.hour < 10)
	{
		out << "0" << c.hour << ':';
	}
	else
	{
		out << c.hour << ':';
	}

	if (c.minute < 10)
	{
		out << "0" << c.minute << ':';
	}
	else
	{
		out << c.minute << ':';
	}
	if (c.second < 10)
	{
		out << "0" << c.second;
	}
	else
	{
		out << c.second;
	}

	out << endl;

	return out;

}


istream& operator>>(istream& in, Clock& c) //Doesn't work!
{
	char x;
	int h, m, s;
	in >> h >> x >> m >> x >> s;
	c.sethour(h);
	c.setminute(m);
	c.setsecond(s);

	return in;
}
/*
void Clock::operator+=(int _seconde)
{
	if (this->second + _seconde > 59)//Not in range
	{
		while (this->second + _seconde > 59)
		{
			this->minute++;
			this->second = (this->second + _seconde) - 59;
		}
		while (this->minute > 59)
		{
			this->hour++;
			this->minute -= 60;
		}
		if (this->hour > 23)
		{
			int temp = 0, temp2 = this->hour;
			while (temp2 > 23)
			{
				temp++;
				temp2--;
			}
			this->hour = temp;
		}

	}
	else//in the range
	{
		this->second = second + _seconde;
	}
}
*/