/*
   Write a function isPrime to test whether is a parameter is prime
   program prints all prime numbers up to 100
*/

#include <iostream>
using namespace std;

bool isPrime (int num){
   int div = 2;
   int gcd = 1;
  
   while(div<(num/2)+1){
      if (num%div == 0)
         gcd = div;
      div++;
   }
   
   if (gcd!=1)
      return false;
   else 
      return true;
}

int main(){
   
   for(int i = 2; i<=100; i++){
      if (isPrime(i))
         cout<<i<<endl;
   }


   return 0;
}