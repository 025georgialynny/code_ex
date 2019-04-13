/*
Georgia Smith CSC 2180 Lab 8
This lab will be an INDIVIDUAL grade.

This lab is in two parts:

a.) Complete Chapter 6 Programming Exercise #12
Write a recursive algorithm to multiply two positive integers m and n using
repeated addition. Specify the base case and the recursive case.
b.) Complete Chapter 6 Programming Exercise #13

Note: You may complete each of these as part of the same program and submit that file via Moodle before the due date.

Additional Note: Notice that when dealing with C(n,r), if r = 0 or r=n then the result is 1.  Additionally, C(n,r) = C(n-1, r-1) + C(n-1,r).
*/
#include <iostream>
using namespace std;

int multInt(int m, int n){
  if(n==0){
    return 0;//base case
  }
  else return m+(multInt(m, n-1));//recursively adds m n times
}

int com(int n, int r){
  if(r==0||r==n) return 1;//base case(s)
  else{
    return com(n-1, r-1)+com(n-1, r);//formula to find
  }

}


int main(){

  cout<<com(5, 2)<<endl;//test of excercise 13

  cout<<multInt(3,30)<<endl;//test of excercise 12
  return 0;
}
