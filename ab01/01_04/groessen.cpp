/*
 * groessen.cpp
 *
 *  Created on: 24.09.2026
 *      Author: n3034770
 */
#include <iostream>
#include "pbma.h"
#include <vector>

using namespace std;

struct Person{
	const char* vorname; // pointer -> 8 byte in m64, 4 byte in m32
	const char* nachname; // 8 bzw 4 byte
	unsigned int alter; // 4 byte
	int punkte[10]; // 10x 4 = 40 byte
	// 40 + 4 + 8 + 8 = 60 bytes
};

int calc_alter(Person p[], int anz)
{
	int max_punkte = 0;
	int alter = 0;
	for(int i = 0; i < anz; i++)
	{
		int sum_punkte = 0;
		for(int j = 0; j < 10; j++)
		{
			sum_punkte += p[i].punkte[j];
		}
		if(sum_punkte > max_punkte)
		{
			max_punkte = sum_punkte;
			alter = p[i].alter;
		}
	}

	return alter;
	}

int main()
{

	vector<int> vek =  create_same_randints(170, 0, 20);
	Person personen[17];
	for(int i = 0; i < 17; i++)
	{
		personen[i].vorname = "Susi";
		personen[i].nachname = "Sinnlos";
		personen[i].alter = 18 + i;

		for(int j = 0; j < 10; j++)
		{
			personen[i].punkte[j] = vek[i*10+j];
		}
	}

	for(int i = 0; i < 17; i++)
	{
		cout << personen[i].vorname << " " <<personen[i].nachname << " " << personen[i].alter << ":";
		for(int j = 0; j < 10; j++)
		{
			cout << personen[i].punkte[j] << " ";
		}
		cout << " " << endl;
	}

	cout << "Alter der Person mit den Maximalen Punkten: " << calc_alter(personen, 17) << endl;

	const Person* p1 = &personen[3]; // adresse von person idx 4
	const Person* p2 = &personen[7]; // adresse von person idx 8
	cout << (p2 - p1) << endl; //7 - 3 = 4
	cout << ((char*)p2 - (char*)p1) << endl; // Abstand in bytes
	cout << (&(p1->punkte[5]) - &(personen[2].punkte[1])) << endl; // Adresse von punkte von index 5 von person 4 - adresse von punkte von index 1 von person 3
	cout << ((char*)&(p1->punkte[5]) - (char*)&(personen[2].punkte[1])) << endl; // Adress differenz in bytes


	return 0;
}







