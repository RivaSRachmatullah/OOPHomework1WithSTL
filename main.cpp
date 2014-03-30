/**
 * @file
 * @brief Main Program of All Classes
 * 
 */
#include <iostream>
#include "Event/Event.h"

using namespace std;

int main()
{
	int NumberofTeller;
	DateTime Deadline, DT;
	cin >> Deadline;
	cin >> NumberofTeller;
	Event E(NumberofTeller);
	E.SetDeadline(Deadline);
	bool stop = false;
	do {
		cin >> E;
		if (E.GetDeadline() < E.GetDateTime() || E.GetDeadline() == E.GetDateTime())
			stop = true;
	} while (!stop);
	E.Close();
	return 0;
}