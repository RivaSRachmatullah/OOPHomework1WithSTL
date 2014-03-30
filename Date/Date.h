/**
 * @file
 * @brief Header Date Class
 * 
 */

/**
 * \class Date
 * 
 * @brief Date Class
 * @details Represent a Date
 * 
 * @author Riva Syafri Rachmatullah (13512036) for .h file
 * @author Indam Muhammad (13512026) and Riva Syafri Rachmatullah (13512036) for .cpp file
 *
 * @version v1.3
 *  
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
	int DayComponent, MonthComponent, YearComponent;

public:
	/**
	 * @brief Initializes a new instance of the Date class.
	 */
	Date();
	
	/**
	 * @brief Initializes a new instance of the Date class from specified Date.
	 * 
	 * @param[in] D The object Date that will be copied.
	 */
	Date(const Date& D);
	
	/**
	 * @brief Clear an instance of Date from memory.
	 */
	~Date();
	
	/**
	 * @brief Determines whether the specified object Date is equal to the current object Date.
	 * 
	 * @param[in] D The object Date to compare with the current object Date.
	 * @return true if the specified Date is equal to the current Date; otherwise false.
	 */
	bool operator==(const Date &D);
	
	/**
	 * @brief Determines whether the specified object Date is not equal to the current object Date.
	 * 
	 * @param[in] D The object Date to compare with the current object Date.
	 * @return true if the specified Date is not equal to the current Date; otherwise false.
	 */
	bool operator!=(const Date &D);
	
	/**
	 * @brief Determines whether the specified object Date is earlier than the current object Date.
	 * 
	 * @param[in] D The object Date to compare with the current object Date.
	 * @return true if the specified Date is earlier to the current Date; otherwise false.
	 */
	bool operator<(const Date &D);
	
	/**
	 * @brief Determines whether the specified object Date is later than the current object Date.
	 * 
	 * @param[in] D The object Date to compare with the current object Date.
	 * @return true if the specified Date is later to the current Date; otherwise false.
	 */
	bool operator>(const Date &D);

	/**
	 * @brief Read the specified Date to the standard input stream.
	 * 
	 * @param[out] input An instance of class istream.
	 * @param[out] D An instance of class Date.
	 */
	friend istream& operator>>(istream &input, Date &D)
	{
		int Day, Month, Year;
		char dummy;
		input >> Day >> dummy >> Month >> dummy >> Year;
		while (!IsComponentofDateValid(Day, Month, Year))
		{
			cout << "Wrong input!" << endl;
			input >> Day >> dummy >> Month >> dummy >> Year;
		}
		D.DayComponent = Day;
		D.MonthComponent = Month;
		D.YearComponent = Year;
		return input;
	}
	
	/**
	 * @brief Writes the specified Date followed by the current line terminator to the standard output stream.
	 * 
	 * @param[out] output An instance of class ostream.
	 * @param[in] D An instance of class Date.
	 */
	friend ostream& operator<<(ostream &output, const Date &D)
	{
		output << D.DayComponent << "-" << D.MonthComponent << "-" << D.YearComponent;
		return output;
	}

	/**
	 * @brief Determines if the specified components of date is a valid date.
	 * @details Components of Date will be valid if DayComponent is within Maximum Day in certain Month, MonthComponent is within 1 to 12, and YearComponent is greater than 0.
	 * 
	 * @param[in] DayComponent The day component of date.
	 * @param[in] MonthComponent The month component of date.
	 * @param[in] YearComponent The year component of date.
	 * @return true if all components of Date is valid.
	 */
	static bool IsComponentofDateValid(int DayComponent, int MonthComponent, int YearComponent);

	/**
	 * @brief Determines if the year component of date is Kabisat or not.
	 * @details Year is Kabisat if Year can be divided by 4 but can't be divided by 100 or can be divided by 400
	 * 
	 * @param[in] YearComponent The year component of date.
	 * @return true if YearComponent is kabisat; otherwise false.
	 */
	static bool IsKabisat(const int &YearComponent);
	
	/**
	 * @brief Gets the day of specified date.
	 * @return The day component of date.
	 */
	int GetDayofDate();
	
	/**
	 * @brief Gets the month of specified date.
	 * @return The month component of date.
	 */
	int GetMonthofDate();
	
	/**
	 * @brief Gets the year of specified date.
	 * @return The year component of date.
	 */
	int GetYearofDate();
	
	/**
	 * @brief Set the day component of date with specified day.
	 * @details Parameter must be a valid DayComponent
	 * 
	 * @param[in] DayComponent The new day component of date.
	 */
	void SetDayofDate(int DayComponent);
	
	/**
	 * @brief Set the month component of date with specified month.
	 * @details Parameter must be a valid MonthComponent
	 * 
	 * @param[in] MonthComponent The new month component of date.
	 */
	void SetMonthofDate(int MonthComponent);
	
	/**
	 * @brief Set the year component of date with specified year.
	 * @details Parameter must be a valid YearComponent
	 * 
	 * @param[in] YearComponent The new year component of date.
	 */
	void SetYearofDate(int YearComponent);
};

#endif