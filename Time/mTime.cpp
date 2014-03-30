/**
 * @file
 * @brief Driver Time Class
 * 
 */
#include <iostream>
#include "Time.h"

using namespace std;

void Menu();

int main ()
{
	Time T1, T2;
	int Option;
	cin >> T1 >> T2;
	do
	{
		cout << "T1 : " << T1 << endl << "T2 : " << T2 << endl;
		Menu();
		cout << "Pilihan anda : ";
		cin >> Option;
		switch (Option)
		{
			case 1	:	
				int H,M,S;
				do {
					cout << "Masukkan jam yang diinginkan : ";
					cin >> H;
					cout << "Masukkan menit yang diinginkan : ";
					cin >> M;
					cout << "Masukkan menit yang diinginkan : ";
					cin >> S;
				} while (!Time::IsElementofTimeValid(H,M,S));
				T1.SetHourElement(H);
				T1.SetMinuteElement(M);
				T1.SetSecondElement(S);
				break;
			case 2	:
				do {
					cout << "Masukkan jam yang diinginkan : ";
					cin >> H;
					cout << "Masukkan menit yang diinginkan : ";
					cin >> M;
					cout << "Masukkan detik yang diinginkan : ";
					cin >> S;
				} while (!Time::IsElementofTimeValid(H,M,S));
				T2.SetHourElement(H);
				T2.SetMinuteElement(M);
				T2.SetSecondElement(S);
				break;
			case 3	:
				if (T1 == T2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 4	:
				if (T1 < T2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 5	:
				if (T1 > T2)
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
	} while (Option != 6);
	return 0;
}

void Menu() {
	cout << endl << "-----------------------------------" << endl;
	cout << "1. Ubah Jam, Menit, dan Detik pada T1" << endl;
	cout << "2. Ubah Jam, Menit, dan Detik pada T2" << endl;
	cout << "3. Is Equal?" << endl;
	cout << "4. Is Earlier Than?" << endl;
	cout << "5. Is Later Than?" << endl;
	cout << "6. Exit" << endl;
}

