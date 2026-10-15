/*
 * main.cpp
 *
 *  Created on: 15.10.2026
 *      Author: n3034770
 */
 #include <iostream>
 #include <vector>


 using namespace std;

 class KVT {
 public:
     double val;

     KVT(int val)
         :val(1)
     {
     }
     KVT(float val)
         :val(17)
     {
     }
     KVT(double val)
         :val(42)
     {
     }
     KVT(char val)
         :val(66)
     {
     }
 };

 void out(KVT kvt) {
     cout << kvt.val << " ";
 }



 int main()
 {

    out(1); out((short)1); out(1.0f); out(3.1415); out('x');
     cout << endl; // 2 2 17 42 66
     return 0;
 }



