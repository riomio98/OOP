/*
 * main.cpp
 *
 *  Created on: 15.10.2026
 *      Author: n3034770
 */
 #include <iostream>
 #include <vector>

 using namespace std;


 class A{
 private:
     int _val;
 public:
     A(int val = 17)
         :_val(val)
         {
         }
     int& get_val() {
         return _val;
     }
     const int& get_val() const{
         return _val;
     }
 };

 int main()
 {
     A a; A as[3]; const A ca1; const A ca2 = 42;
     cout << a.get_val() << endl; // 17
     a.get_val() = 42;
     cout << as[2].get_val() << endl; // 17
     cout << a.get_val() << endl; // 42
     cout << ca1.get_val() << " " << ca2.get_val() << endl; // 17 42

     return 0;

 }