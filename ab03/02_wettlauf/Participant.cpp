#include "Participant.h"

Participant::Participant(std::string name)
	:name(name), zeit(0,0,0)
{
}
std::string Participant::get_name() const
{
	return name;
}
Time Participant::get_time() const
{
	return zeit;
}
void Participant::set_time(const Time& t)
{
    zeit = t;
}