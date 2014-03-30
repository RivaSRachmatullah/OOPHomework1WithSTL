/**
 * @file
 * @brief Driver Teller Class
 * 
 */
#include "Teller.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int NumberofTeller, ID = 0;
	cout << "Number of Teller : ";
	cin >> NumberofTeller;
	Teller *T = new Teller(NumberofTeller);
	bool StopLooping = false;
	while (!StopLooping)
	{
		T->Print();
		string Option;
		cin >> Option;
		if (Option.compare("Add")==0)
		{
			ID++;
			T->ArriveofAnElement(ID);
		}
		else if (Option.compare("Del")==0)
		{
			int y;
			cin >> y;
			int x = T->DepartureofAnElement(y);
			cout << "elemen dihapus : " << x << endl;
		}
		else if (Option.compare("Exit")==0)
		{
			cout << "Loop terminate" << endl;
			T->DepartureAll();
			StopLooping = true;
		}
		else
			cout << "Error!" << endl;
	}
	return 0;
}
