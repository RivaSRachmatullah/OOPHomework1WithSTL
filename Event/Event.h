/**
 * @file
 * @brief Header Event Class
 * 
 */
/**
 * \class Event
 * 
 * @brief Event Class
 * @details Represent a Event
 * 
 * @author Riva Syafri Rachmatullah (13512036) for .h file
 * @author Riva Syafri Rachmatullah (13512036) for .cpp file
 *
 * @version v1.2
 * 
 */
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "../DateTime/DateTime.h"
#include "../Teller/Teller.h"

using namespace std;

class Event
{
private:
	static int ID;
	DateTime DT, Deadline;
	char code;
	Teller *T;

public:
	/**
	 * @relates Queue
	 * @brief Initializes a new instance of the Event class with 5 Teller.
	 */
	Event();

	/**
	 * @relates Queue
	 * @brief Initializes a new instance of the Event class with specified amount of Teller.
	 * 
	 * @param[in] NumberofTeller Amount of Teller.
	 */
	Event(int NumberofTeller);

	/**
	 * @brief Clear an instance of Event from memory.
	 */
	~Event();
	
	/**
	 * @brief Read the specified Event to the standard input stream.
	 * 
	 * @param[out] input An instance of class istream.
	 * @param[out] E An instance of class Event.
	 */
	friend istream& operator>>(istream &input, Event &E)
	{
		DateTime DT;
		input >> DT >> E.code;
		while (E.code == ' ' || E.code == '\n')
			input >> E.code;
		if (DT < E.Deadline || DT == E.Deadline)
		{
			if (E.code == 'A' || E.code =='D')
			{
				if (E.code == 'A')
				{
					ID++;
					E.T->ArriveofAnElement(ID);
					E.DT = DT;
				}
				else if (E.code == 'D')
				{
					int ID;
					input >> ID;
					int X = E.T->DepartureofAnElement(ID);
				}
				E.DT = DT;
			}
			else
				cout << "Wrong Input!" << endl;
		}
		E.T->Print();
		return input;
	}

	/**
	 * @brief Gets DateTime on an instance Event.
	 * @return DateTime of Event.
	 */
	DateTime GetDateTime();

	/**
	 * @brief Gets Deadline on an instance Event.
	 * @return Deadline of Event.
	 */
	DateTime GetDeadline();

	/**
	 * @brief Set Deadline on Event.
	 * 
	 * @param[in] Deadline The DateTime for a Deadline of Event.
	 */
	void SetDeadline(DateTime Deadline);

	/**
	 * @brief Clear all the Teller
	 * @details Each of teller will delete an element and print it.
	 */
	void Close();
};

#endif