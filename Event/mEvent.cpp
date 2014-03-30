/**
 * @file
 * @brief Driver Event Class
 * 
 */
#include <iostream>
#include "Event.h"

using namespace std;

int main()
{
	int NumberofTeller;
	DateTime Deadline, DT;
	cout << "Deadline : ";
	cin >> Deadline;
	cout << "Number of Teller : ";
	cin >> NumberofTeller;
	Event E(NumberofTeller);
	E.SetDeadline(Deadline);
	bool stop = false;
	do
	{
		cout << endl << "Input Event : " << endl;
		cin >> E;
		if (E.GetDeadline() < E.GetDateTime() || E.GetDeadline() == E.GetDateTime())
			stop = true;
	} while (!stop);
	E.Close();
	return 0;
}