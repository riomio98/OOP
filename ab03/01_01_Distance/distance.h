/*
 * distance.h
 *
 *  Created on: 07.10.2026
 *      Author: n3034770
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_



class Distance{
private:
    int km;
    int m;
public:
    //Konstruktor
    Distance(int km = 0, int m = 0);
    //getter
    int get_km() const;
    int get_m() const;
    //setter
    int justmeters() const;
    bool add(const Distance& d);
    bool add_km(int x);
    bool add_m(int x);
    int diff(const Distance& d) const;



};




#endif /* DISTANCE_H_ */
