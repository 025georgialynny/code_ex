#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

void pig(string word[20], int wordlng, int length){
   char cword[wordlng+1];
   char let1[20];
   int i;
   for (i = 0 ; i<length; i++){
      strcpy(cword, word[i].c_str());
      let1[i] = cword[0];
      word[i].erase(0,1);
   }
   for (int j = 0; j<length; j++){
      cout<<word[j]<<"-"<<let1[j]<<"ay ";
   }
   
   
}

int main(){
   
   string sentence;
   int i = 0;
   int max;
   
   cout<<"Enter sentence"<<endl;
   getline(cin, sentence);
   string sent[20];
   stringstream ssin(sentence);
    while (ssin.good()){
        ssin >> sent[i];
        ++i;
    }
    int leng = i;
   max = sent[0].size();
   for(i=1; i<20; i++){
      if (sent[i].size()>max)
         max = sent[i].size();
   }
   
   pig(sent, max, leng);

   return 0;
}