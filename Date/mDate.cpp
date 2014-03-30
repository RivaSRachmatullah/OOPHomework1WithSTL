/**
 * @file
 * @brief Driver Date Class
 * 
 */
#include <iostream>
#include "Date.h"

using namespace std;

void Menu();

int main()
{
	Date D1, D2;
	cin >> D1 >> D2;
	int option;
	do
	{
		cout << "D1 : " << D1 << endl << "D2 : " << D2 << endl;
		Menu();
		cout << "Pilihan anda : ";
		cin >> option;
		switch (option)
		{
			case 1	:
				int Day, Month, Year;
				do
				{
					cout << "Day : ";
					cin >> Day;
					cout << "Month : ";
					cin >> Month;
					cout << "Year : ";
					cin >> Year;
				} while (!Date::IsComponentofDateValid(Day, Month, Year));
				D1.SetDayofDate(Day);
				D1.SetMonthofDate(Month);
				D1.SetYearofDate(Year);
				break;
			case 2	:
				do
				{
					cout << "Day : ";
					cin >> Day;
					cout << "Month : ";
					cin >> Month;
					cout << "Year : ";
					cin >> Year;
				} while (!Date::IsComponentofDateValid(Day, Month, Year));
				D2.SetDayofDate(Day);
				D2.SetMonthofDate(Month);
				D2.SetYearofDate(Year);
				break;
			case 3	:
				if (D1 == D2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 4	:
				if (D1 < D2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 5	:
				if (D1 > D2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 6	: 
				break;
			default	:
				cout << "Input salah" << endl;
				break;
		}
	} while (option != 6);
	return 0;
}

void Menu()
{
	cout << endl << "-----------------------------------" << endl;
	cout << "1. Ubah Tanggal, Bulan, dan Tahun pada D1" << endl;
	cout << "2. Ubah Tanggal, Bulan, dan Tahun pada D2" << endl;
	cout << "3. Is Equal to?" << endl;
	cout << "4. Is Earlier than?" << endl;
	cout << "5. Is Later than?" << endl;
	cout << "6. Exit" << endl;
}

