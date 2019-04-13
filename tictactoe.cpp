#include <iostream>
#include <string>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;
int choosecol();
int chooserow();
int *block(int, int[3][3]);
int *compmove (int board[3][3]){
   static int rowcol[2];
   int next = -1;
   int *blockch = block(next, board);
   while(next<8 && next!=999){
      if (board[blockch[0]][blockch[1]]>1){
         rowcol[0] = blockch[0];
         rowcol[1]= blockch[1];
         next = 999;
      }
      else if (next< 7){
         next = blockch[2];
         block(next, board);
      }
      else 
         next = 8;
   }
   if (next!=999){
      rowcol[0] = chooserow();
      rowcol[1]= choosecol();
   }
   return rowcol;
}
int chooserow(){
   return 0;
};
int choosecol(){
   return 0;
};
    /*[00, 01, 02]
      [10, 11, 12]
      [20, 21, 22]*/
int *block(int next, int board[3][3]){
   static int choice[3];
   //across options
   if (((board[0][0] ==1 && board [0][1] == 1) || (board[1][0] ==1 && board [1][1] == 1) ||(board[2][0] ==1 && board [2][1] == 1))&& next<0){
      choice[1] = 2;
      choice [2] = 0;
      if (board[0][0] ==1 && board [0][1] == 1)
         choice[0] = 0;
      else if (board[1][0] ==1 && board [1][1] == 1)
         choice [0] = 1;
      else if (board[2][0] ==1 && board [2][1] == 1)
         choice[0] = 2;
   }
   else if (((board[0][0] ==1 && board [0][2] == 1) || (board[1][0] ==1 && board [1][2] == 1) ||(board[2][0] ==1 && board [2][2] == 1))&& next<1){
      choice [1] = 1;
      choice [2] = 1;
      if (board[0][0] ==1 && board [0][2] == 1)
         choice[0] = 0;
      else if (board[1][0] ==1 && board [1][2] == 1)
         choice [0] = 1;
      else if (board[2][0] ==1 && board [2][2] == 1)
         choice[0] = 2;
   }
   else if (((board[0][1] ==1 && board [0][2] == 1) || (board[1][1] ==1 && board [1][2] == 1) ||(board[2][1] ==1 && board [2][2] == 1))&& next<2){
      choice [1] = 0;
      choice [2] = 2;
      if (board[0][1] ==1 && board [0][2] == 1)
         choice[0] = 0;
      else if (board[1][1] ==1 && board [1][2] == 1)
         choice [0] = 1;
      else if (board[2][1] ==1 && board [2][2] == 1)
         choice[0] = 2;
   }
   //down options
   else if (((board[0][0] ==1 && board [1][0] == 1) || (board[0][1] ==1 && board [1][1] == 1) ||(board[0][2] ==1 && board [1][2] == 1))&& next<3){
      choice[0] = 2;
      choice [2] = 3;
      if (board[0][0] ==1 && board [1][0] == 1)
         choice[1] = 0;
      else if (board[0][1] ==1 && board [1][1] == 1)
         choice [1] = 1;
      else if (board[0][2] ==1 && board [1][2] == 1)
         choice[1] = 2;
   }
   else if (((board[0][0] ==1 && board [2][0] == 1) || (board[0][1] ==1 && board [2][1] == 1) ||(board[0][2] ==1 && board [2][2] == 1))&& next<4){
      choice [0] = 1;
      choice [2] = 4;
      if (board[0][0] ==1 && board [2][0] == 1)
         choice[1] = 0;
      else if (board[0][1] ==1 && board [2][1] == 1)
         choice [1] = 1;
      else if (board[0][2] ==1 && board [2][2] == 1)
         choice[1] = 2;
   }
   else if (((board[1][0] ==1 && board [2][0] == 1) || (board[1][1] ==1 && board [2][1] == 1) ||(board[1][2] ==1 && board [2][2] == 1))&& next<5){
      choice [0] = 0;
      choice [2] = 5;
      if (board[1][0] ==1 && board [2][0] == 1)
         choice[1] = 0;
      else if (board[1][1] ==1 && board [2][1] == 1)
         choice [1] = 1;
      else if (board[1][2] ==1 && board [2][2] == 1)
         choice[1] = 2;
   }
   //criss cross options
   else if (((board[0][0] ==1 && board [1][1] == 1) || (board[0][2] ==1 && board [1][1] == 1))&& next<6){
      choice[0] = 2;
      choice [2] = 6;
      if (board[0][0] ==1 && board [1][1] == 1)
         choice[1] = 2;
      else if (board[0][2] ==1 && board [1][1] == 1)
         choice [1] = 0;
   }
   else if (((board[2][0] ==1 && board [1][1] == 1) || (board[2][2] ==1 && board [1][1] == 1))&& next<7){
      choice [0] = 0;
      choice [2] = 7;
      if (board[2][0] ==1 && board [1][1] == 1)
         choice[1] = 2;
      else if (board[2][2] ==1 && board [1][1] == 1)
         choice [1] = 0;
   }
   else{
      choice[2] = 8;
   }
    /*[00, 01, 02]
      [10, 11, 12]
      [20, 21, 22]*/
   return choice;
};
int win(int gb[3][3], int sum){
   int key;
   if ((gb[0][0] == 1 && gb[1][0]==1 && gb[2][0]==1)||(gb[0][0] == 0 && gb[1][0]==0 && gb[2][0]==0)){
         if (gb[0][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[0][0] == 1 && gb[0][1]==1 && gb[0][2]==1)||(gb[0][0] == 0 && gb[0][1]==0 && gb[0][2]==0)){
         if (gb[0][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[0][1] == 1 && gb[1][1]==1 && gb[2][1]==1)||(gb[0][1] == 0 && gb[1][1]==0 && gb[2][1]==0)){
         if (gb[0][1] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
      else if ((gb[0][2] == 1 && gb[1][2]==1 && gb[2][2]==1)||(gb[0][2] == 0 && gb[1][2]==0 && gb[2][2]==0)){
         if (gb[0][2] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[1][0] == 1 && gb[1][1]==1 && gb[1][2]==1)||(gb[1][0] == 0 && gb[1][1]==0 && gb[1][2]==0)){
         if (gb[1][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[2][0] == 1 && gb[2][1]==1 && gb[2][2]==1)||(gb[2][0] == 0 && gb[2][1]==0 && gb[2][2]==0)){
         if (gb[2][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[0][0] == 1 && gb[1][1]==1 && gb[2][2]==1)||(gb[0][0] == 0 && gb[1][1]==0 && gb[2][2]==0)){
         if (gb[0][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if ((gb[2][0] == 1 && gb[1][1]==1 && gb[0][2]==1)||(gb[2][0] == 0 && gb[1][1]==0 && gb[0][2]==0)){
         if (gb[2][0] == 1){
            cout<<"You Won!";
            key = 1;
         }
         else{
            cout<<"Computer Won!";
            key = 1;
         }
      }
   else if (sum<10){
      cout<<"Tie Game!!";
      key = 1;
   }
   else 
      key = 0;
   

   return key;
}

int main(){
   srand(time(0));
   char def[9][15]={
      {'c','o','l','|',' ','1',' ','|',' ','2',' ','|',' ','3',' '},
      {'_','_','_','|','_','_','_','_','_','_','_','_','_','_','_'},
      {'r','o','w','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','1',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {'-','-','-','|','-','-','-','-','-','-','-','-','-','-','-'},
      {' ','2',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {'-','-','-','|','-','-','-','-','-','-','-','-','-','-','-'},
      {' ','3',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_'},
   };
   char board[9][15]={
      {'c','o','l','|',' ','1',' ','|',' ','2',' ','|',' ','3',' '},
      {'_','_','_','|','_','_','_','_','_','_','_','_','_','_','_'},
      {'r','o','w','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      {' ','1',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {'-','-','-','|','-','-','-','-','-','-','-','-','-','-','-'},
      {' ','2',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {'-','-','-','|','-','-','-','-','-','-','-','-','-','-','-'},
      {' ','3',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
      {' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_'},
   };
   string keep = "yes", cont;
   int gb[3][3];
   int key;
   int count = 1;
   for(int i=0, p = 10; i<3; i++){
      for(int j=0; j<3; j++){
         gb[i][j]=10;
      }
   }
   int urow, ucol, comrow, comcol, brow, bcol, tie = 0;
   /*"col| 1 | 2 | 3 "
   "___|___________"
   "row|"<<endl;
   " 1 |   |   |   "
   "---|-----------"
   " 2 |   |   |   "
   "---|-----------"
   " 3 |   |   |   "
   "\t|___________"*/

   while (keep == "yes"){
      for(int i = 0; i<9; i++){
         for(int j = 0; j<15; j++){
            cout<<board[i][j];
         }
         cout<<endl;
      }  
      for(int county = 0; county<1;){
         cout<<"Which row would you like to put your x in(enter an integer 1-3)?"<<endl;
         cin>>urow;
         urow--;
         cout<<"Which column?"<<endl;
         cin>>ucol;
         ucol--;
         if (gb[urow][ucol] >1 && (urow<=2 && ucol<=2 && urow>=0 && ucol>=0)){
            gb[urow][ucol] = 1;
            county++;
            }
         else if ((urow>2 || ucol>2)||(urow<0||ucol<0))
            cout<<"Error: enter an integer 1-3"<<endl;
         else
            cout<<"This spot is taken! Enter another row and column."<<endl;
      }
      switch (urow){
         case 0:
            brow = 3;
            break;
         case 1:
            brow = 5;
            break;
         case 2: 
            brow = 7;
            break;
      }
      switch (ucol){
         case 0:
            bcol = 5;
            break;
         case 1:
            bcol = 9;
            break;
         case 2:
            bcol = 13;
            break;
      }
      board[brow][bcol] = 'x';
      cout<<endl;
      tie = 0;
      for (int j = 0; j<3; j++){
         for (int i = 0; i<3; i++){
            tie += gb[j][i];
         }
      }
      key = win(gb, tie);
      if (key!=1){
            if (count==1){
               if (gb[1][1]>1){
                  comrow = 1;
                  comcol = 1;
                  gb[1][1] = 0;
               }
               else{
                  comrow = 2;
                  comcol = 2;
                  gb[2][2] = 0;
               }
               count++;
            }
            else {
               int *choice = compmove(gb);
               comrow = choice[0];
               comcol = choice[1];
               gb[comrow][comcol] = 0;
               
            }
           switch (comrow){
            case 0:
               brow = 3;
               break;
            case 1:
               brow = 5;
               break;
            case 2: 
               brow = 7;
               break;
         }
         switch (comcol){
            case 0:
               bcol = 5;
               break;
            case 1:
               bcol = 9;
               break;
            case 2:
               bcol = 13;
               break;
         }
         board[brow][bcol] = 'o';
       key = win(gb, tie);
      }
    if (key == 1){
      cout<<endl;
      for(int i = 0; i<9; i++){
         for(int j = 0; j<15; j++){
            cout<<board[i][j];
         }
         cout<<endl;
      }
    }
    /*[00, 10, 20]
      [01, 11, 21]
      [02, 12, 22]*/
     
     key = win(gb, tie);
     
     while(key == 1){
      cout<<endl;
      cout<<endl<<"Would you like to play again(yes or no)?"<<endl;
      cin>>keep;
      if (keep == "yes"||keep == "no"){
         key = 0;
         if (keep == "yes"){
            for(int i=0, p = 10; i<3; i++){
               for(int j=0; j<3; j++){
                  gb[i][j]=10;
               }
            } 
            for(int i=0; i<9; i++){
               for(int j=0; j<14; j++){
                  board[i][j]=def[i][j];
               }
            }
            count = 1;
         }
      }
      else 
         cout<< "Error: please enter yes or no."<<endl;
     }
      
            
  }
      


   return 0;
}