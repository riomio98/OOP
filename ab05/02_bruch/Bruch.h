/*
 * Bruch.h
 *
 *  Created on: 25.10.2026
 *      Author: n3034770
 */

#ifndef BRUCH_H_
#define BRUCH_H_
#error MEINE_BRUCH_H_WIRD_BENUTZT


void kuerzen(int& z, int& n);
class Bruch{
private:
	int _z;
	int _n;

public:
	Bruch(int z, int n = 1);
    int zaehler() const;
	int nenner() const;
    Bruch& operator*=(const Bruch& other);
};

bool operator==(const Bruch& a, const Bruch& b);
bool operator!=(const Bruch& a, const Bruch& b);
Bruch operator*(Bruch a,const Bruch& b);
#endif // BRUCH_H


