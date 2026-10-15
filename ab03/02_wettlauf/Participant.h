/*
 * Participant.h
 *
 *  Created on: 08.10.2026
 *      Author: n3034770
 */

#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "Time.h"
#include <string>

class Participant
{
private:
	std::string name;
	Time zeit;
	static int anz;
public:
	//Konstruktor
	Participant(std::string name);
	Participant();
	//Destruktor
	~Participant();
	//getter
	std::string get_name() const;
	Time get_time() const;
	//setter
	void set_time(const Time& t);
	void set_name(std::string name);
};



#endif /* PARTICIPANT_H */
