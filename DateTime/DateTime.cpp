/**
 * @file
 * @brief Implementation DateTime Class
 * 
 */
#include "DateTime.h"

using namespace std;

// 4 SEKAWAN
DateTime::DateTime() {}

DateTime::DateTime(const DateTime& DT)
{
	DateComponent = DT.DateComponent;
	TimeComponent = DT.TimeComponent;
}

DateTime::~DateTime() {}

bool DateTime::operator==(DateTime DT)
{
	return DT.DateComponent == DateComponent &&
		DT.TimeComponent == TimeComponent;
}

bool DateTime::operator!=(DateTime DT)
{
	return DT.DateComponent != DateComponent ||
		DT.TimeComponent != TimeComponent;
}

bool DateTime::operator<(DateTime DT)
{
	if (DateComponent == DT.DateComponent)
		return TimeComponent < DT.TimeComponent;
	else 
		return DateComponent < DT.DateComponent;
}

bool DateTime::operator>(DateTime DT)
{
	if (DateComponent == DT.DateComponent)
		return TimeComponent > DT.TimeComponent;
	else 
		return DateComponent > DT.DateComponent;
}

Date DateTime::GetDate()
{
	return DateComponent;
}

Time DateTime::GetTime() {
	return TimeComponent;
}

void DateTime::SetDate(Date Date) {
	DateComponent = Date;
}

void DateTime::SetTime(Time Time) {
	TimeComponent = Time;
}

