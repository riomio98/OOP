/*
 * Time.h
 *
 *  Created on: 06.10.2026
 *      Author: n3034770
 */

#ifndef TIME_H_
#define TIME_H_


#include <cstdint>

class Time
{
private:
	uint32_t hour;
    uint32_t minute;
    uint32_t second;

public:
    Time(uint32_t hour = 0, uint32_t minute = 0, uint32_t second = 0);

    uint32_t getHour() const;
    uint32_t getMinute() const;
    uint32_t getSecond() const;

    uint32_t justseconds() const;

    bool add_hour(uint32_t x);
    bool add_minute(uint32_t x);
    bool add_second(uint32_t x);

    bool add(const Time& t);
    uint32_t diff(const Time& t) const;
};



#endif /* TIME_H_ */
