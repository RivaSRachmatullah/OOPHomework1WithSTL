/**
 * @file
 * @brief Header Time Class
 * 
 */
/**
 * \class Time
 * 
 * @brief Time Class
 * @details Represent a Time
 * 
 * @author Riva Syafri Rachmatullah (13512036) for .h file
 * @author Indam Muhammad (13512026) and Riva Syafri Rachmatullah (13512036) for .cpp file
 *
 * @version v1.2
 * 
 */
#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
private:
	int HourElement, MinuteElement, SecondElement;

public:
	/**
	 * @brief Initializes a new instance of Time.
	 */
	Time();

	/**
	 * @brief Initializes a new instance of Time from specified Time instance.
	 * 
	 * @param[in] T The object Time that will be copied.
	 */
	Time(const Time& T);
	
	/**
	 * @brief Clear an instance of Time from memory.
	 */
	~Time();

	/**
	 * @brief Determines whether the specified object Time is equal to the current object Time.
	 * 
	 * @param[in] T The object Time to compare with the current object Time.
	 * @return true if the specified object Time is equal to the current object Time; otherwise false.
	 */
	bool operator==(const Time &T);
	
	/**
	 * @brief Determines whether the specified object Time is not equal to the current object Time.
	 * 
	 * @param[in] T The object Time to compare with the current object Time.
	 * @return true if the specified object Time is not equal to the current object Time; otherwise false.
	 */
	bool operator!=(const Time &T); 
	
	/**
	 * @brief Determines whether the specified object Time is earlier than the current object Time.
	 * 
	 * @param[in] T The object Time to compare with the current object Time.
	 * @return true if the specified object Time is earlier than the current object Time; otherwise false.
	 */
	bool operator<(const Time &T);

	/**
	 * @brief Determines whether the specified object Time is later than the current object Time.
	 * 
	 * @param[in] T The object Time to compare with the current object Time.
	 * @return true if the specified object Time is later than the current object Time; otherwise false.
	 */
	bool operator>(const Time &T);

	/**
	 * @brief Writes the specified Time followed by the current line terminator to the standard output stream.
	 * 
	 * @param[out] output An instance of class ostream.
	 * @param[in] T An instance of class Time.
	 */
	friend ostream& operator<<(ostream &output, const Time& T)
	{
		output << T.HourElement << ":" << T.MinuteElement << ":" << T.SecondElement;
		return output;
	}
	
	/**
	 * @brief Read the specified Time to the standard input stream.
	 * 
	 * @param[out] input An instance of class istream.
	 * @param[out] T An instance of class Time.
	 */
	friend istream& operator>>(istream &input, Time& T) {
		int Hour, Minute, Second;
		char dummy;
		input >> Hour >> dummy >> Minute >> dummy >> Second;
		while (!IsElementofTimeValid(Hour, Minute, Second))
		{
			cout << "Wrong input!" << endl;
			input >> Hour >> dummy >> Minute >> dummy >> Second;
		}
		T.HourElement = Hour;
		T.MinuteElement = Minute;
		T.SecondElement = Second;
		return input;
	}

	/**
	 * @brief Determines if the specified elements of time is a valid time.
	 * @details Elements of Time will be valid if HourElement is equal and between 0 to 23 with MinuteElement and SecondElement are equal and between 0 to 59.
	 * 
	 * @param[in] HourElement The hour element of time.
	 * @param[in] MinuteElement The minute element of time.
	 * @param[in] SecondElement The second element of time.
	 * @return true if all elements of Time is valid.
	 */
	static bool IsElementofTimeValid(int HourElement, int MinuteElement, int SecondElement);
	
	/**
	 * @brief Gets the hour element of specified Time.
	 * @return The hour element of time.
	 */
	int GetHourElement();
	
	/**
	 * @brief Gets the minute element of specified Time.
	 * @return The minute element of time.
	 */
	int GetMinuteElement();
	
	/**
	 * @brief Gets the second element of specified Time.
	 * @return The second element of time.
	 */
	int GetSecondElement();

	/**
	 * @brief Set the hour element of time with specified hour.
	 * @details Parameter must be a valid HourElement.
	 * 
	 * @param[in] HourElement The new hour element of time.
	 */
	void SetHourElement(int HourElement);
	
	/**
	 * @brief Set the minute element of time with specified minute.
	 * @details Parameter must be a valid MinuteElement.
	 * 
	 * @param[in] MinuteElement The new minute element of time.
	 */
	void SetMinuteElement(int MinuteElement);
	
	/**
	 * @brief Set the second element of time with specified second.
	 * @details Parameter must be a valid SecondElement.
	 * 
	 * @param[in] SecondElement The new second element of time.
	 */
	void SetSecondElement(int SecondElement);
};

#endif