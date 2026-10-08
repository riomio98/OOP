
#include <iostream>
#include <string>
#include <vector>
#include "ggts.h"
#include "pbma.h"

using namespace std;


int main(int argc, const char* argv[])
{
    args_t args(argc, argv);

    string fname = args.pos(0, "ggts.dat");

    vector<int> zahlen = read_ints(fname);

    Timer timer1;
    int sum_1 = 0, sum_2 = 0;

    for(size_t i = 0; i+1 < zahlen.size(); i+=2)
    {
    	sum_1 += ggt1(zahlen[i], zahlen[i+1]);

    }
    cout << "Berechnung von ggt1 dauerte " << timer1.human_measure() << endl;
    cout << "Summe mit ggt1: " << sum_1 << endl;

    Timer timer2;
    for(size_t i = 0; i+1 < zahlen.size(); i+=2)
    {
    	sum_2 += ggt2(zahlen[i], zahlen[i+1]);

    }
    cout << "Berechnung von ggt2 dauerte " << timer2.human_measure() << endl;
    cout << "Summe mit ggt2: " << sum_2 << endl;




    return 0;
}


