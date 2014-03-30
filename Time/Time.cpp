/**
 * @file
 * @brief Implementation Time Class
 * 
 */
#include "Time.h"

Time::Time()
{
	HourElement = 0;
	MinuteElement = 0;
	SecondElement = 0;
}
	
Time::Time(const Time& T)
{
	HourElement = T.HourElement;
	MinuteElement = T.MinuteElement;
	SecondElement = T.SecondElement;
}

Time::~Time() {}

bool Time::operator==(const Time &T) 
{
	return HourElement == T.HourElement &&
		MinuteElement == T.MinuteElement &&
		SecondElement == T.SecondElement;
}

bool Time::operator!=(const Time &T)
{
	return HourElement != T.HourElement || 
		MinuteElement != T.MinuteElement ||
		SecondElement != T.SecondElement;
}

bool Time::operator<(const Time &T)
{
	if (HourElement == T.HourElement)
	{
		if (MinuteElement == T.MinuteElement)
			return SecondElement < T.SecondElement;
		else
			return MinuteElement < T.MinuteElement;
	}
	else
		return HourElement < T.HourElement;
}

bool Time::operator>(const Time &T)
{
	if (HourElement == T.HourElement) 
	{
		if (MinuteElement == T.MinuteElement)
			return SecondElement > T.SecondElement;
		else
			return MinuteElement > T.MinuteElement;
	}
	else
		return HourElement > T.HourElement;
}

bool Time::IsElementofTimeValid (int HourElement, int MinuteElement, int SecondElement)
{
	return ((HourElement >= 0) && (HourElement <= 23) &&
		(MinuteElement >= 0) && (MinuteElement <= 59) &&
		(SecondElement >= 0) && (SecondElement <= 59));
}
	
int Time::GetHourElement() {
	return HourElement;
}

int Time::GetMinuteElement() {
	return MinuteElement;
}

int Time::GetSecondElement() {
	return SecondElement;
}

void Time::SetHourElement(int HourElement) {
	this->HourElement = HourElement;
}

void Time::SetMinuteElement(int MinuteElement) {
	this->MinuteElement = MinuteElement;
}

void Time::SetSecondElement(int SecondElement) {
	this->SecondElement = SecondElement;
}
