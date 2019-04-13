/*
   Write a function factorIt that writes out the prime factorization of an int
*/

#include <iostream>
using namespace std;

bool isPrime (int num){//determines whether a number is Prime
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

bool isEven(int n){//determines whether a number is even

   if(n%2==0)
      return true;
   else
      return false;
   
}

int fact(int& n){//determines a factor of a number if it isn't prime
   int ext = 1;
   int c;
   for(c = 1; ext!=0;){
      c++;
      if (n%c ==0){
         ext = 0;
         n=n/c;       
      }
   }
   return c;
}

void factorIt(int n){//prints out the prime factors of a number
   
   int c;
   int i = 1;
   
   if(isPrime(n))
      cout<<n<<", 1"<<endl;
   else{
      if (isEven(n)){
         cout<<"2, ";
         n/=2;
         if (isPrime(n)){
            cout<<n<<endl;
            return;
         }
      }
         while(i!=999){
            c = fact(n);
               cout<<c<<", ";
            if(isPrime(n)){
               i = 999;
               cout<<n<<endl;
               }
         }
   }

}

int main(){

   int num;
   
   cout<<"Enter an integer and I will give you its prime factorization."<<endl;
   cin>>num;
   
   factorIt(num);

   return 0;
}