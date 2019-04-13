#include <iostream>
using namespace std;

int main(){

   int a = 0, b;
   double av;
   int count=5; 
      cout<<"Enter a number, or press -1 to end.";
      cin>>b;
   while (count<1){
      a+=b;
      cout<<"Enter a number, or press -1 to end."<<endl;
      cin>>b; 
      count++;
   } 
   cout<<a<<endl;
   av = (double)a/count;
   cout<<av<<endl;

   return 0;  
}