/*
   Write a function reverse(int n) that reversed digits in param and returns the result
   927>>729
   program takes 10 user nums and reverses them;
*/

#include <iostream>
#include <cmath>
using namespace std;

int reverse(int n){
   int mult;
   int rev=0;
   n*=10;
   int count=10;
   while (n>0){
      n/=10;
      mult = pow(10, count);
      rev+=(n%10)*mult;
      count--;   
   }
   while (rev%10==0){
      rev/=10;   
   }
   
   
   return rev;
}

int main(){

   int usernum, revnum;
   
   cout<<"Enter number:"<<endl;
   cin>>usernum;
   
   revnum = reverse(usernum);
   
   cout<<"The number in reverse is "<<revnum<<"."<<endl;

   return 0;
}