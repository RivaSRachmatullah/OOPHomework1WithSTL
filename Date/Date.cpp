/**
 * @file
 * @brief Implementation Date Class
 * 
 */
#include "Date.h"

Date::Date()
{
	DayComponent = 1;
	MonthComponent = 1;
	YearComponent = 1;
}
	
Date::Date(const Date& D)
{
	DayComponent = D.DayComponent;
	MonthComponent = D.MonthComponent;
	YearComponent = D.YearComponent;
}
	
Date::~Date() {}

bool Date::operator==(const Date &D)
{
	return DayComponent == D.DayComponent &&
		MonthComponent == D.MonthComponent &&
		YearComponent == D.YearComponent;
}

bool Date::operator!=(const Date &D)
{
	return DayComponent != D.DayComponent ||
		MonthComponent != D.MonthComponent ||
		YearComponent != D.YearComponent;
}

bool Date::operator<(const Date &D)
{
	if (YearComponent == D.YearComponent)
	{
		if (MonthComponent == D.MonthComponent)
			return DayComponent < D.DayComponent;
		else
			return MonthComponent < D.MonthComponent;
	}
	else
		return YearComponent < D.YearComponent;
}

bool Date::operator>(const Date &D)
{
	if (YearComponent == D.YearComponent)
	{
		if (MonthComponent == D.MonthComponent)
			return DayComponent > D.DayComponent;
		else
			return MonthComponent > D.MonthComponent;		
	}
	else
		return YearComponent > D.YearComponent;
}

bool Date::IsComponentofDateValid(int DayComponent, int MonthComponent, int YearComponent)
{
	if (IsKabisat(YearComponent) && YearComponent > 0)
	{
		if (MonthComponent == 2)
			return DayComponent >= 1 && DayComponent <= 29;
		else if (MonthComponent == 1 || MonthComponent == 3 ||
				MonthComponent == 5 || MonthComponent == 7 ||
				MonthComponent == 8 || MonthComponent == 10 ||
				MonthComponent == 12)
			return DayComponent >= 1 && DayComponent <= 31;
		else if (MonthComponent == 4 || MonthComponent == 6 ||
				MonthComponent == 9 || MonthComponent == 11)
			return DayComponent >= 1 && DayComponent <= 30;
		else
			return false;
	}
	else if (!IsKabisat(YearComponent) && YearComponent > 0)
	{
		if (MonthComponent == 2)
			return DayComponent >= 1 && DayComponent <= 28;
		else if (MonthComponent == 1 || MonthComponent == 3 ||
				MonthComponent == 5 || MonthComponent == 7 ||
				MonthComponent == 8 || MonthComponent == 10 ||
				MonthComponent == 12)
			return DayComponent >= 1 && DayComponent <= 31;
		else if (MonthComponent == 4 || MonthComponent == 6 ||
				MonthComponent == 9 || MonthComponent == 11)
			return DayComponent >= 1 && DayComponent <= 30;
		else
			return false;
	}
	else
		return false;
}

bool Date::IsKabisat(const int &YearComponent)
{
	if (YearComponent > 0)
		return ((YearComponent % 4 == 0) && (YearComponent % 100 != 0))
			|| YearComponent % 400 == 0;
	else
		return false;
}


int Date::GetDayofDate()
{
	return DayComponent;
}
	
int Date::GetMonthofDate()
{
	return MonthComponent;
}

int Date::GetYearofDate()
{
	return YearComponent;
}

void Date::SetDayofDate(int DayComponent)
{
	this->DayComponent = DayComponent;
}

void Date::SetMonthofDate(int MonthComponent)
{
	this->MonthComponent = MonthComponent;
}

void Date::SetYearofDate(int YearComponent)
{
	this->YearComponent = YearComponent;
}
