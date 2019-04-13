/*
   write a function quadratic (int a, int b, int c, double x)
   determine value of quadratic ax^2+bx+c
*/

#include <iostream>
#include <cmath>
using namespace std;

int quadratic(int a, int b, int c, double x){

   int value=0;
   
   value+=c;
   value+=b*x;
   value+=b*(pow(x, 2));
   
   return value;

}

int main(){

   double quadval;
   int a, b, c;
   double x;
   
   cout<<"Enter the value of a, b, c, and x, each sep by a space"<<endl;
   cin>>a>>b>>c>>x;
   
   quadval = quadratic(a, b, c, x);
   
   cout<<quadval<<endl;

}