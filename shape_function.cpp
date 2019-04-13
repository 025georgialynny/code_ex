#include <iostream>
using namespace std;

void multiPrint(int n, char c, int shape){

    int s, rowtot=0;
    int prin = 1;
    int count = 0;
    int tot=0;
    int runtot = 1;;
                
   if(shape == 1){
        for (int a=0; a<n; count++){ 
            rowtot = 1 + (count*2);
            a = a+rowtot;
            tot = a;
        }
        if (tot> n){
            tot -= rowtot;
        }
        for (int i = 1; i<=count; i++){
            s = count - i;
            for (int sp = 0; sp<s; sp++)
               cout<<" "; 
            if(i!=1){
                prin+=2;
                runtot +=prin;
            }
            if(runtot<=n){
                for(int p =0; p<prin; p++)
                    cout<<c;
            }
            else{
                tot = n - tot;
                for(int l = 0; l<tot;l++)
                    cout<<c;                
            }
            cout<<endl;
        }
   }
   if(shape == 2){
        count = -1;
        for (int a=0; a<n;){
            count++;
            rowtot = 1 + (count*2);
            a = a+rowtot;
            tot = a;
        }
        if (tot> n){
            tot -= rowtot;
        }
        for (int i = count; i>=0; i--){
            s = count - i;
            for (int sp = 0; sp<s; sp++){
               cout<<" "; 
            }
            if(s == 0 && tot!=n){
                tot = n - tot;
                for(int l = 0; l<tot;l++)
                    cout<<c; 
            }
            else{
                prin =(1+(i*2));
                for(int p =0; p<prin; p++)
                    cout<<c;
            }
            cout<<endl;
        }
   }
   if(shape == 3){
         int topn=0;
         int topc, botc;
         int sub = 0;
         count = 0;
         int l = 0;
        while (tot<n){
         if(l%2 == 1){
            rowtot = (1+(count)*2);
            l++;
            tot += rowtot;
            count++;
         }
         else{
               if (count == 0)
                  rowtot = 1;
               else{
                  rowtot = (1+((count)*2));
               }
               tot += rowtot;
                  l++;
         }
         if(l%2 == 1)
            topn+=rowtot;
        }
        sub = tot - n;
        topn-=sub;
        if (l%2 == 1){
            topc = (l/2);
            botc = (l/2)-1;
            
        }
        else{
            topc = (l/2)-1;
            botc = (l/2)-1;
        }
        for (int i = 0; i<=topc; i++){
            s = topc - i;
            for (int sp = 0; sp<s; sp++)
               cout<<" "; 
            if(i!=0){
                prin+=2;
                runtot +=prin;
            }
            if(runtot<=topn){
                for(int p =0; p<prin; p++)
                    cout<<c;
            }
            else{
                prin = prin - sub;
                for(int p = 0; p<prin; p++)
                    cout<<c;                
            }
            cout<<endl;
        }
        prin=0;
        for (int i = botc; i>=0; i--){
            s = botc - i;
            if (l%2 == 1)
               s++;
            for (int sp = 0; sp<s; sp++){
               cout<<" "; 
            }
                prin =(1+(i*2));
                for(int p =0; p<prin; p++)
                    cout<<c;
            cout<<endl;
        }
   }
}

int main(){

   int num, shape;
   char choice;
   string hi="hi";
   
   while(hi!="999"){
   cout<<"Which letter should I print?"<<endl;
   cin>>choice;
   cout<<"How many times should I print it out?"<<endl;
   cin>>num;
   cout<<"Enter 1 for triangle, 2 for upside down triange, and 3 for diamond."<<endl;
   cin>>shape;
   multiPrint(num, choice, shape);
   
   cout<<"Enter anything to continue or enter 999 to quit"<<endl;
   getline(cin, hi);
   getline(cin, hi);
   }
   return 0;
}