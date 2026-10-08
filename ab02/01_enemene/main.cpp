/*
 * main.cpp
 *
 *  Created on: 26.09.2026
 *      Author: n3034770
 */

#include <iostream>
#include <string>
#include <vector>
#include "pbma.h"

using namespace std;


void compare(vector<string>& vec_words, vector<string>& vec_kids, bool ausgabe)
{
    size_t idx = 0;

    while (vec_kids.size() > 1)
    {
        for (size_t i = 0; i < vec_words.size(); i++)
        {
            if (vec_words[i] == "Du")
            {
                if (ausgabe)
                {
                    cout << vec_kids[idx] << endl;
                }

                vec_kids.erase(vec_kids.begin() + idx);

                if (idx >= vec_kids.size())
                {
                    idx = 0;
                }

                break;
            }
            else
            {
                idx++;

                if (idx >= vec_kids.size())
                {
                    idx = 0;
                }
            }
        }
    }

    cout << "Gewinner: " << vec_kids[0] << endl;
}


int main(int argc, const char* argv[])
{
    string filename = "enemene.txt";

    vector<string> vec_words = read_words(filename);
    vector<string> vec_kids;

    bool ausgabe = true;


    // Kommandozeilenargumente auswerten
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-v")
        {
            ausgabe = true;
        }
        else
        {
            vec_kids.push_back(arg);
        }
    }


    // Keine Kinder angegeben -> Default-Liste
    if (vec_kids.empty())
    {
        vec_kids.push_back("Rudi");
        vec_kids.push_back("Susi");
        vec_kids.push_back("Rudolf");
        vec_kids.push_back("Peter");
        vec_kids.push_back("Arnold");
        vec_kids.push_back("Gertrud");
        vec_kids.push_back("Marc");
        vec_kids.push_back("Olaf");
        vec_kids.push_back("Hans");
        vec_kids.push_back("Otto");
        vec_kids.push_back("Rio");
    }


    compare(vec_words, vec_kids, ausgabe);

    return 0;
}
