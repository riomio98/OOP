#include "Time.h"

Time::Time(int hour, int minute, int second)
    : hour(hour), minute(minute), second(second)
{
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSecond() const
{
    return second;
}

int Time::justseconds() const
{
    return hour * 3600 + minute * 60 + second;
}

bool Time::add_hour(int x)
{
    return add_second(x * 3600);
}

bool Time::add_minute(int x)
{
    return add_second(x * 60);
}

bool Time::add_second(int x)
{
    int neu = justseconds() + x;

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

int Time::diff(const Time& t) const
{
    return justseconds() - t.justseconds();
}
