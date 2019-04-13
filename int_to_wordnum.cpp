#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string printnum(int modu, int count, int omod, int modone, int num, int newmod){

   string word;
   int modcount = count%3;
   if (modcount == 2){
      switch (modu){
         case 1:
               switch(modone){
                  case 1:
                     word = "eleven ";
                     break;
                  case 2:
                     word =  "twelve ";
                     break;
                  case 3:
                     word = "thirteen ";
                     break;
                  case 4:
                     word = "fourteen ";
                     break;
                  case 5:
                     word = "fifteen ";
                     break;
                  case 6:
                     word = "sixteen ";
                     break;
                  case 7:
                     word = "seventeen ";
                     break;
                  case 8:
                     word = "eighteen ";
                     break;
                  case 9:
                     word = "nineteen ";
                     break;
                  default:
                     word = "ten ";
               }
            break;
         case 2:
            word = "twenty ";
            break;
         case 3:
            word = "thirty ";
            break;
         case 4:
            word = "forty ";
            break;
         case 5:
            word = "fifty ";
            break;
         case 6:
            word = "sixty ";
            break;
         case 7:
            word = "seventy ";
            break;
         case 8:
            word = "eighty ";
            break;
         case 9:
            word = "ninety ";
            break;
         default:
            break;
      }
   }

 if ((modcount==1&&omod!=1)||modcount ==0){  
   switch (modu){
      case 1: 
         word = "one ";
         break;
      case 2:
         word = "two ";
         break;
      case 3:
         word = "three ";
         break;
      case 4:
         word = "four ";
         break;
      case 5:
         word = "five ";
         break;
      case 6:
         word = "six ";
         break;
      case 7:
         word = "seven ";
         break;
      case 8:
         word = "eight ";
         break;
      case 9:
         word = "nine ";
         break;
      case 0:
         if (count==1&&num==0){
            word = "zero ";
            }
         break;
      default:
         break;
   }
   }
   if (count==4&&newmod!=0){
      word+="thousand ";
   }
   if ((count%3 == 0)&&newmod!=0){
      word+="hundred ";
   }
   if (count == 7&&newmod!=0){
      word+="million ";
   }
   if (count == 10){
      word+="billion ";
   }
      return word;
};



int main(){
   string fullword;
   string num;
   string numberinput;
   int number, newnumb;
   cout<<"Enter an integer(range -2 bil to 2 bil), or enter x to exit"<<endl;
   cin>>numberinput;
   while (numberinput !="x"){
      fullword= "";
      int mod, modone;
      string print;
      stringstream convert(numberinput);
      convert >> newnumb;
      if (newnumb<0){
         cout<<"negative ";
         newnumb*=-1;
      }
      for(int count = 1, keep=1, omod=3, newmod; keep!=0;){
         if (count%3==1){
            omod = newnumb/10;
            if ((0-omod)!=0){
               omod = omod%10;
               }
            else{
               omod = -1;
               }
         }
         if (count%3==0){
            newmod = newnumb%10;
            if ((newmod)!=0){
               newmod=-1;
               }
            else{
               newmod = 0;
               }
         }
         if (count == 7||count == 4){
            newmod = newnumb%1000;
            if (newmod>0 &&newmod<1000)
               newmod = -1;
            else
               newmod = 0;
         }
         mod = newnumb%10;
         if (count%3 == 1)
            modone = mod;
         print =printnum(mod, count, omod, modone, newnumb, newmod);
         count++;
         fullword = print+fullword;
         newnumb /= 10;
         keep = 0 - newnumb;
      }
      cout<<fullword<<endl;
      cout<<endl<<"Enter an integer(range -2 bil to 2 bil), or enter x to exit"<<endl;
      cin>>numberinput;
   }
   return 0;
}