/**
 * @file
 * @brief Header DateTime Class
 * 
 */
/**
 * \class DateTime
 * 
 * @brief DateTime Class
 * @details Represent Date and Time
 * 
 * @note Use Date and Time Class
 * 
 * @author Riva Syafri Rachmatullah (13512036) for .h file
 * @author Indam Muhammad (13512036) and Riva Syafri Rachmatullah (13512036) for .cpp file
 *
 * @version v1.3
 *   
 */
#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include "../Date/Date.h"
#include "../Time/Time.h"
#include <string>

using namespace std;

class DateTime
{
private:
	Date DateComponent;
	Time TimeComponent;

public:
	/**
	 * @relates Date
	 * @relates Time
	 * @brief Initializes a new instance of the DateTime class.
	 */
	DateTime();
	
	/**
	 * @relates Date
	 * @relates Time
	 * @brief Initializes a new instance of the DateTime class from specified DateTime.
	 * 
	 * @param[in] DT The object DateTime that will be copied.
	 */
	DateTime(const DateTime& DT);
	
	/**
	 * @brief Clear an instance of DateTime from memory.
	 */
	~DateTime();
	
	/**
	 * @brief Determines whether the specified object DateTime is equal to the current object DateTime.
	 * 
	 * @param[in] DT The object DateTime to compare with the current object DateTime.
	 * @return true if the specified object DateTime is equal to the current object DateTime; otherwise false.
	 */
	bool operator==(DateTime DT);
	
	/**
	 * @brief Determines whether the specified object DateTime is not equal to the current object DateTime.
	 * 
	 * @param[in] DT The object DateTime to compare with the current object DateTime.
	 * @return true if the specified object DateTime is not equal to the current object DateTime; otherwise false.
	 */
	bool operator!=(DateTime DT);
	
	/**
	 * @brief Determines whether the specified object DateTime is earlier than the current object DateTime.
	 * 
	 * @param[in] DT The object DateTime to compare with the current object DateTime.
	 * @return true if the specified object DateTime is earlier than to the current object DateTime; otherwise false.
	 */
	bool operator<(DateTime DT);
	
	/**
	 * @brief Determines whether the specified object DateTime is later than the current object DateTime.
	 * 
	 * @param[in] DT The object DateTime to compare with the current object DateTime.
	 * @return true if the specified object DateTime is later than to the current object DateTime; otherwise false.
	 */
	bool operator>(DateTime DT);

	/**
	 * @brief Read the specified DateTime to the standard input stream.
	 * 
	 * @param[out] input An instance of class istream.
	 * @param[out] DT An instance of class DateTime.
	 */
	friend istream& operator>>(istream &input, DateTime &DT) {
		int Hour, Minute, Second, Day, Month, Year;
		char dummy;
		do
		{
			input >> Day >> dummy >> Month >> dummy >> Year >> dummy >> Hour >> dummy >> Minute >> dummy >> Second;
			if (!Date::IsComponentofDateValid(Day, Month, Year) ||
				!Time::IsElementofTimeValid(Hour, Minute, Second))
				cout << "Wrong Date input!" << endl;
		} while (!Date::IsComponentofDateValid(Day, Month, Year) ||
			!Time::IsElementofTimeValid(Hour, Minute, Second));
		DT.DateComponent.SetDayofDate(Day);
		DT.DateComponent.SetMonthofDate(Month);
		DT.DateComponent.SetYearofDate(Year);
		DT.TimeComponent.SetHourElement(Hour);
		DT.TimeComponent.SetMinuteElement(Minute);
		DT.TimeComponent.SetSecondElement(Second);
		return input;
	}

	/**
	 * @brief Writes the specified DateTime followed by the current line terminator to the standard output stream.
	 * 
	 * @param[out] output An instance of class ostream.
	 * @param[in] DT An instance of class DateTime.
	 */
	friend ostream& operator<<(ostream &output, const DateTime &DT) {
		output << DT.DateComponent << ";" << DT.TimeComponent;
		return output;
	}

	/**
	 * @brief Gets the date from DateTime.
	 * @return The time from DateTime.
	 */
	Date GetDate();
	
	/**
	 * @brief Gets the time from DateTime.
	 * @return The time from DateTime.
	 */
	Time GetTime();
	
	/**
	 * @brief Set the Date of DateTime with specified Date.
	 * 
	 * @param[in] Date The new Date of DateTime.
	 */
	void SetDate(Date Date);

	/**
	 * @brief Set the Time of DateTime with specified Time.
	 * 
	 * @param[in] Time The new Time of DateTime.
	 */
	void SetTime(Time Time);
};

#endif // DATE_H