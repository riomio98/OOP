/*
 * time.cpp
 *
 *  Created on: 06.10.2026
 *      Author: n3034770
 */

#include<iostream>
#include <vector>
#include <string>

using namespace std;


class Time{
private:
    int hour;
    int minute;
    int second;
public:
    // Konstruktor
    Time(int hour = 0, int minute = 0, int second = 0)
        : hour(hour), minute(minute), second(second)
        {
        }
    // getter
    int getHour() const{
        return hour;
    }
    int getMinute() const{
        return minute;
    }
    int getSecond() const{
        return second;
    }
    // setter
    void addHours(int x){
        this->hour += x;
    }
    void addMinutes(int x){
        this->minute += x;
    }
    void addSeconds(int x){
        this->second += x;
    }


};


int main()
{
    Time t;
    t.addHours(1);
    cout << t.getHour() << endl;
    cout << t.getMinute() << endl;
    cout << t.getSecond() << endl;


    return 0;
}


