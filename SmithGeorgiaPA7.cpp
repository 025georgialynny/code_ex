/*
   Georgia Smith CSC 1180
   Programming Assignment 7 Due 10/29/2018
   Write Recursive Functions 
*/

#include <iostream>
using namespace std;

int Power(int base, int pow){
   if (pow == 0){
      return 1;
   }
   else{
      return base * Power(base, pow-1);
   }
}
int maxPower(int base, int max){
   static int count;
   if (Power(base, count)>max){
      return count-1;
   }
   else{
      count++;
      return maxPower(base, max);
   }
}
int reverse(int num){
   int len = 1;
   while (num/len>10){
      len*=10;
   }
   if(num<10){
      return num;
   }
   else{
      return num%10*len + reverse(num/10);
   }   
}
int sum (int max){
   if (max == 0){
      return max;
   }
   else{
      return max + sum(max-1);
   }
}
int product(int max){
   if (max == 0 || max == 1){
      return max;
   }
   else{
      return max * product(max-1);
   }
}
int main(){
   int x, y;
   int choice;
   
   cout<<"Choose from the following options:"<<endl;
   cout<<"1) Power of x raised by y."<<endl;
   cout<<"2) Find the max power a number can be raised to."<<endl;
   cout<<"3) Print out a number with its digits in reversed order."<<endl;
   cout<<"4) Sum of integers from 1 to n."<<endl;
   cout<<"5) Product of integers from 1 to n."<<endl;
   cout<<"6) Quit"<<endl;
   
   cout<<"Your choice: ";
   cin>>choice;

   while(choice!=6){  
      switch(choice){
         case 1://power of x raised to y;
            cout<<"Enter the number to raise: ";
            cin>>x;
            cout<<"Enter the power to raise to: ";
            cin>>y;
            cout<<"The result is: "<<Power(x,y)<<endl;
            break;
         case 2://max power
            cout<<"Enter the number to raise: ";
            cin>>x;
            cout<<"Enter the number not to exceed: ";
            cin>>y;
            cout<<"The result is: "<<maxPower(x,y)<<endl;
            break;
         case 3://reverse
            cout<<"Enter the number to reverse: ";
            cin>>x;
            cout<<reverse(x)<<endl;
            break;
         case 4://sum
            cout<<"Enter the number to sum to: ";
            cin>>x;
            cout<<"The result is: "<<sum(x)<<endl;
            break;
         case 5://product
            cout<<"Enter the number to multiply to: ";
            cin>>x;
            cout<<"The result is: "<<product(x)<<endl;
            break;
         default:
            cout<<"Error enter a number 1-6"<<endl;     
      }
      cout<<endl<<"Choose from the following options:"<<endl;
      cout<<"1) Power of x raised by y."<<endl;
      cout<<"2) Find the max power a number can be raised to."<<endl;
      cout<<"3) Print out a number with its digits in reversed order."<<endl;
      cout<<"4) Sum of integers from 1 to n."<<endl;
      cout<<"5) Product of integers from 1 to n."<<endl;
      cout<<"6) Quit"<<endl;
      
      cout<<"Your choice: ";
      cin>>choice;
   }
   
   return 0;
}