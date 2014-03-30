/**
 * @file
 * @brief Driver DateTime Class
 * 
 */
#include <iostream>
#include "DateTime.h"

using namespace std;

void Menu();

int main ()
{
	Date D;
	Time T;
	DateTime DT1, DT2;
	cin >> DT1 >> DT2;
	int Option;
	do
	{
		cout << "DT1 : " << DT1 << endl << "DT2 : " << DT2 << endl;
		Menu();
		cout << "Pilihan anda : ";
		cin >> Option;
		switch (Option) {
			case 1	:	
				cout << "Date : ";
				cin >> D;
				cout << "Time : ";
				cin >> T;
				DT1.SetDate(D);
				DT1.SetTime(T);
				break;
			case 2	:
				cout << "Date : ";
				cin >> D;
				cout << "Time : ";
				cin >> T;
				DT2.SetDate(D);
				DT2.SetTime(T);
				break;
			case 3	:
				if (DT1 == DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 4	:
				if (DT1 < DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 5	:
				if (DT1 > DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 6	: 
				break;
			default	:
				cout << "Wrong input!" << endl;
				break;
		}
	} while (Option != 6);
	return 0;
}

void Menu()
{
	cout << endl << "-----------------------------------" << endl;
	cout << "1. Ubah Tanggal dan Waktu pada DT1" << endl;
	cout << "2. Ubah Tanggal dan Waktu pada DT2" << endl;
	cout << "3. Is Equal?" << endl;
	cout << "4. Is Earlier Than?" << endl;
	cout << "5. Is Later Than?" << endl;
	cout << "6. Exit" << endl;
}

