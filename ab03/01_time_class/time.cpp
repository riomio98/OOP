#include "Time.h"
#include <cstdint>

Time::Time(uint32_t hour, uint32_t minute, uint32_t second)
    : hour(hour), minute(minute), second(second)
{
}

uint32_t Time::getHour() const
{
    return hour;
}

uint32_t Time::getMinute() const
{
    return minute;
}

uint32_t Time::getSecond() const
{
    return second;
}

uint32_t Time::justseconds() const
{
    return hour * 3600 + minute * 60 + second;
}

bool Time::add_hour(uint32_t x)
{
    return add_second(x * 3600);
}

bool Time::add_minute(uint32_t x)
{
    return add_second(x * 60);
}

bool Time::add_second(uint32_t x)
{
	uint32_t neu = justseconds() + x;

    if (neu < 0 || neu >= 24 * 3600)
        return false;

    hour = neu / 3600;
    neu = neu % 3600;

    minute = neu / 60;
    second = neu % 60;

    return true;
}

bool Time::add(const Time& t)
{
    return add_second(t.justseconds());
}

uint32_t Time::diff(const Time& t) const
{
    return justseconds() - t.justseconds();
}
