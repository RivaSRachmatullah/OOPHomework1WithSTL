/**
 * @file
 * @brief Implementation Teller Class
 * 
 */
#include <cmath>
#include "Teller.h"

using namespace std;

Teller::Teller()
{
	NumberofTeller = 5;
	T = new queue<int>[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int TellerNumber = 0; TellerNumber < NumberofTeller; TellerNumber++)
		TellerServingStatus[TellerNumber] = false;
}

Teller::Teller(int NumberofTeller)
{
	this->NumberofTeller = NumberofTeller;
	T = new queue<int>[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int TellerNumber = 0; TellerNumber < NumberofTeller; TellerNumber++)
		TellerServingStatus[TellerNumber] = false;
}

Teller::Teller(const Teller &T)
{
	NumberofTeller = T.NumberofTeller;
	this->T = new queue<int>[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int TellerNumber = 0; TellerNumber < NumberofTeller; TellerNumber++)
	{
		this->T[TellerNumber] = T.T[TellerNumber];
		TellerServingStatus[TellerNumber] = T.TellerServingStatus[TellerNumber];
	}
}

Teller& Teller::operator=(const Teller &T)
{
	NumberofTeller = T.NumberofTeller;
	if (this->T != NULL)
	{
		delete this->T;
		delete TellerServingStatus;
	}
	this->T = new queue<int>[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int TellerNumber = 0; TellerNumber < NumberofTeller; TellerNumber++)
	{
		this->T[TellerNumber] = T.T[TellerNumber];
		TellerServingStatus[TellerNumber] = T.TellerServingStatus[TellerNumber];
	}
	return *this;
}

Teller::~Teller()
{
	T = NULL;
	TellerServingStatus = NULL;
}

int Teller::DepartureofAnElement(int ID)
{
	bool stop = false;
	int i = 0;
	while (i < NumberofTeller && !stop)
	{
		if (T[i].front() == ID)
			stop = true;
		else
			i++;
	}
	if (!stop)
	{
		cout << "Not Found" << endl;
		return 0;
	}
	else
	{
		int TellerNumber = Jockeying(i);
		if (TellerNumber != -1) {
			queue<int> Qt;
			T[TellerNumber].push(T[i].back());
			while (T[i].size()>1)
			{
				Qt.push(T[i].front());
				T[i].pop();
			}
			T[i].swap(Qt);
		}
		int IDRemoved = T[i].front();
		T[i].pop();
		if (T[i].empty())
			TellerServingStatus[i] = false;
		return IDRemoved;
	}
}

void Teller::ArriveofAnElement(int ID)
{
	int Minimum = 0;
	for (int TellerNumber = 1; TellerNumber < NumberofTeller; TellerNumber++)
	{
		if (T[Minimum].size() > T[TellerNumber].size())
			Minimum = TellerNumber;
	}
	if (T[Minimum].empty())
		TellerServingStatus[Minimum] = true;
	T[Minimum].push(ID);
}

void Teller::DepartureAll()
{
	int NumberofEmptyTeller = 0;
	for (int j = 0; j < NumberofTeller; j++)
	{
		if (!TellerServingStatus[j])
			NumberofEmptyTeller++;
	}
	int TellerNumber = 0;
	while (NumberofEmptyTeller != NumberofTeller)
	{
		if (TellerServingStatus[TellerNumber])
		{
			int IDRemoved = T[TellerNumber].front();
			T[TellerNumber].pop();
			if (T[TellerNumber].empty())
			{
				TellerServingStatus[TellerNumber] = false;
				NumberofEmptyTeller++;
			}
			if (IDRemoved != 0)
				cout << "Departure " << IDRemoved << endl;
		}
		if (TellerNumber == NumberofTeller - 1)
			TellerNumber = 0;
		else
			TellerNumber++;
	}
}

void Teller::Print()
{
	for (int i = 0; i < NumberofTeller; i++)
	{
		if (TellerServingStatus[i])
		{
			cout << "T[" << i << "] = ";
			PrintQueue(i);
			cout << endl;
		}
	}
}

int Teller::Jockeying (int iOrigin)
{
	int Minimum = 0;
	for (int i = 1; i < NumberofTeller; i++) {
		if ((T[Minimum].size() > T[i].size()) ||
			(T[Minimum].size() == T[i].size() &&
			abs(Minimum-iOrigin) > abs(i-iOrigin)))
			Minimum = i;
	}
	if (T[iOrigin].size() > T[Minimum].size() + 2)
		return Minimum;
	else
		return -1;
}
	
void Teller::PrintQueue(int index)
{
	cout << "{";
	if (!T[index].empty())
	{
		queue<int> Qt(T[index]);
		cout << Qt.front();
		Qt.pop();
		while (!Qt.empty())
		{
			cout << "," << Qt.front();
			Qt.pop();
		}
	}
	cout << "}";
}