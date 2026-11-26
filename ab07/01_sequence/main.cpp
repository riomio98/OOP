/*
 * main.cpp
 *
 *  Created on: 23.11.2026
 *      Author: n3034770
 */

#include <iostream>
#include "sequence.h"

using namespace std;

int main() {
    Sequence<int> seq;

    for (int i = 1; i <= 5; i++) {
        seq.push_back(i);
    }

    int sum = 0;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
    	sum += *it;
        cout << *it << " " << endl;
    }
    cout << sum << endl;
}


