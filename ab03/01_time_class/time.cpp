
#include "Time.h"
#include <iostream>
#include <limits>

using namespace std;

Time::Time(int hour, int minute, int second)
    : hour_(0), minute_(0), second_(0)
{
    add_seconds(int64_t(hour) * 3600 + int64_t(minute) * 60 + second);
}

int Time::hour() const
{
    return hour_;
}

int Time::minute() const
{
    return minute_;
}

int Time::second() const
{
    return second_;
}

int64_t Time::justseconds() const
{
    return int64_t(hour_) * 3600 + minute_ * 60 + second_;
}

bool Time::add_hours(int x)
{
    return add_seconds(int64_t(x) * 3600);
}

bool Time::add_minutes(int x)
{
    return add_seconds(int64_t(x) * 60);
}

bool Time::add_seconds(int64_t x)
{
    int64_t alt = justseconds();

    if (x < -alt)
    {
        hour_ = 0;
        minute_ = 0;
        second_ = 0;
        return false;
    }

    // testet überlauf
    if (x > int64_t(numeric_limits<int>::max()) * 3600 + 3599 - alt)
    {
        return false;
    }

    int64_t neu = alt + x;

    hour_ = neu / 3600;
    neu = neu % 3600;

    minute_ = neu / 60;
    second_ = neu % 60;

    return true;
}

bool Time::add(const Time& t)
{
    return add_seconds(t.justseconds());
}

int64_t Time::diff(const Time& t) const
{
    return justseconds() - t.justseconds();
}

void Time::print() const
{
    cout << hour_ << ":";

    if (minute_ < 10)
        cout << "0";

    cout << minute_ << ":";

    if (second_ < 10)
        cout << "0";

    cout << second_;
    cout << endl;
}
