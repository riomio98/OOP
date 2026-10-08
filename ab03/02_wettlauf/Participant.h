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
public:
	Participant(std::string name);
	//getter
	std::string get_name() const;
	Time get_time() const;
	//setter
	void set_time(const Time& t);

};



#endif /* PARTICIPANT_H */
