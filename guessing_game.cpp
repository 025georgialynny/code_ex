#include <iostream>
#include <string>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
   string keep="yes";
   string hi, highlow;
   int yesno=2;
   int guess=50;
   int highest = 100;
   int lowest = 0;
   
   while (keep == "yes"){
      yesno = 2;
      guess = 50;
      highest = 100;
      lowest = 0;
      cout<<"Think of a number between 1-100, then press enter to continue.";
      cout<<endl;
      getline(cin, keep);
      cout<<keep<<endl;
      
         cout<<"Is your number 50?"<<endl;
            cout<<"Type in yes or no."<<endl;
            cin>>hi;
     for (int count=0; yesno!=0;){
        if (hi == "yes"){
         count++;
         cout<<"I guessed your number in "<<count<<" guesses!"<<endl;
         yesno = 0;
        }
        else if (hi == "no"){
         while(hi=="no"){
            yesno = 2;
            count++;
            srand(time(NULL));
            cout<<"Should I guess higher or lower?"<<endl;
            cin>>highlow;
            if (highlow == "higher"){
                  if (guess>lowest)
                  lowest = guess;
                  }
              else if (highlow == "lower"){
                  if (guess<highest)
                  highest = guess;
               }
            while (yesno ==2){
            if(highlow == "higher"){
               guess = lowest+(1+((highest-lowest)*.5));//(rand()%(highest-lowest-1))+(lowest+1);
               cout<<"Is your number "<<guess<<"(enter yes or no)?"<<endl;
               cin>>hi;
               yesno = 3;
            }
            else if (highlow == "lower"){
               guess = 0 +(lowest+((highest-lowest)*.5));//(rand()%(highest-lowest-1))+(lowest+1);
               cout<<"Is your number "<<guess<<"(enter yes or no)?"<<endl;
               cin>>hi;
               yesno = 3;
            }
            else{
                  cout<<"Error: enter higher or lower";
                  cin>>highlow;
                  if (highlow == "higher" || highlow == "lower")
                     yesno = 2;
                  else 
                     yesno =2;
               }
               }
            }
         }
      else{
            cout<<"Error: Type in yes or no."<<endl;
            cin>>hi;
        }
      }
      cout<<"Would you like to play again (enter yes or no)?"<<endl;
      cin>>keep;
      }
      cout<<"Press enter to exit game."<<endl;
      getline(cin, keep);
      getline(cin, keep);
   return 0;
}