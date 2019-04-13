/*
   Write a function fibonacci(int n) calculat the nth fib num
   program that uses this funtion and is prime to print out 
   first 5 prim fib numbers
*/
#include<iostream>
using namespace std;

bool isPrime (int num){
   int div = 2;
   int gcd = 1;
  
   while(div<(num/2)+1){
      if (num%div == 0)
         gcd = div;
      div++;
   }
   
   if (gcd!=1 || num== 1)
      return false;
   else 
      return true;
}

int fibonacci(int n){

   int fibnum=1;
   int fibprev=0;
   
   for (int count = 2; count<=n; count++){
   
      fibnum+=fibprev;
      fibprev = fibnum - fibprev;
   
   }
   
   return fibnum;

}

int main(){
   
   int num;
   int max=0;
   
   for(int count = 1; max<5; count++){
      
      num = fibonacci(count);
      
      if(isPrime(num)){
         max++;
         cout<<num<<endl;
      }
      
   
   }

   return 0;
}