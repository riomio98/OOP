
#ifndef TIME_H_
#define TIME_H_

#include <cstdint>

class Time
{
private:
    int hour_;
    int minute_;
    int second_;

public:
    Time(int hour = 0, int minute = 0, int second = 0);

    int hour() const;
    int minute() const;
    int second() const;

    int64_t justseconds() const;

    bool add_hours(int x);
    bool add_minutes(int x);
    bool add_seconds(int64_t x);
    bool add(const Time& t);

    int64_t diff(const Time& t) const;

    void print() const;
};

#endif /* TIME_H_ */
