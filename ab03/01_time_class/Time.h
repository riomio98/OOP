/*
 * Time.h
 *
 *  Created on: 06.10.2026
 *      Author: n3034770
 */

#ifndef TIME_H_
#define TIME_H_

#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int hour = 0, int minute = 0, int second = 0);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    int justseconds() const;

    bool add_hour(int x);
    bool add_minute(int x);
    bool add_second(int x);

    bool add(const Time& t);
    int diff(const Time& t) const;
};

#endif



#endif /* TIME_H_ */
