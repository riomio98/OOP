/*
 * Participant.cpp
 *
 *  Created on: 08.10.2026
 *      Author: n3034770
 */
#include <iostream>
#include <string>
#include <vector>
#include "pbma.h"
#include "Time.h"
#include "Participant.h"

using namespace std;





int main(int argc, char* argv[])
{
	args_t args(argc, argv);


	vector<Participant> p;

    for(size_t i = 0; i < args.len_pos(); i++)
    {
        p.push_back(args.pos(i));
    }

    vector<int> zeiten = create_randints(p.size(), 0, 1000);

    for(size_t i = 0; i < p.size(); i++)
    {
    	Time t(0,0, 0);
    	t.add_second(zeiten[i]);
		
    	p[i].set_time(t);
    }
	
	int min = p[0].get_time().justseconds();
	size_t min_idx = 0;
	
	for(size_t i = 0; i < p.size(); i++)
	{
		
		
		if(p[i].get_time().justseconds() < min)
		{
			min = p[i].get_time().justseconds();
			min_idx = i;
		}
	}
	cout << "Anzahl Teilnehmer: " << p.size() << endl;
	cout << "Gewinner: " << p[min_idx].get_name() << ", Zeit: " <<  p[min_idx].get_time().justseconds()  << endl;



    return 0;
}




