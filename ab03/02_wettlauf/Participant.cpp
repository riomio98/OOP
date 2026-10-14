#include "Participant.h"
#include <iostream>


int Participant::anz = 0;

Participant::Participant(std::string name)
	:name(name), zeit(0,0,0)
{
	anz += 1;
	std::cout << "Kostruktor: " <<  anz << std::endl;
}
Participant::~Participant()
{
	anz-=1;
	std::cout << "Destruktor: " <<  anz << std::endl;
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