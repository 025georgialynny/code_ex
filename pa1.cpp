#include <iostream>
#include <string>
using namespace std;

/*
Georgia Smith Programming Assingment One CSC-2180 2
pg. 57 #2

Definition of class dayType that does day of the week in Program
  stores day (sunday for sunday)
  performs
    set day
    print day
    return day
    return next day
    calculate and return the day by adding certain days to the current day

  default const with no paramaters
  default const with one parameter
  main function shows functionality of class
*/

class dayType{
public:
  dayType(){//no parameter constructor - initializes array and sets day to 0

    week[0] = "Sunday"; week[1] = "Monday";
    week[2] = "Tuesday"; week[3] = "Wednesday";
    week[4] = "Thursday"; week[5] = "Friday";
    week[6] = "Saturday";

    day = 0;

  }
  dayType(int usrDay){//takes in 1 parameter (the day to begin with) and initializes array
    week[0] = "Sunday"; week[1] = "Monday";
    week[2] = "Tuesday"; week[3] = "Wednesday";
    week[4] = "Thursday"; week[5] = "Friday";
    week[6] = "Saturday";
    setDay(usrDay-1);
  }
  void setDay(int usrDay){//member func to set the day (only if between 1-7)
    if (usrDay>=1 && usrDay<=7){
      day = usrDay-1;
    }
    else{
      day = 0;
      cout<<"Invalid entry day set default: "<<week[day]<<endl;
    }
  }
  void printDay(){//just prints the day
    cout<<"The day is "<<week[day]<<endl;
  }
  string retDay(){//returns day as string
    return week[day];
  }
  string nextDay(){//returns next day as string, without changing day
    if(day==6){
      return week[0];
    }
    else{ return week[day+1]; }
  }
  string prevDay(){//returns previous day as string, without changing day
    if(day==0){return week[6];}
    else {return week[day-1];}
  }
  string whichDay(int future){//calculates day in future and returns, without changing day
    int daythrw;
    daythrw = day;
    while(future>0){
      if(daythrw==6){
        daythrw = 0;
      }
      else{
        daythrw++;
      }
      future--;
    }
    return week[daythrw];
  }
private:
  string week[7];
  int day;
};

int main(){

  dayType myday;
  dayType myday2(4);

//cout<<"Instance with no parameter constructor:"<<endl<<"\t";
  myday.printDay(); cout<<endl;
//cout<<"Instance with constructor taking one parameter:"<<endl<<"\t";
  myday2.printDay(); cout<<endl;

  for (int i=1; i<=7; i++){//prints all 5 days of the wekks as they are set using memb function
    myday.setDay(i);
    myday.printDay();
  }

  cout<<endl<<"Today is "<<myday.retDay()<<endl;//test return day function

//test next and previous day functions
  cout<<endl<<myday.nextDay()<<endl;
  cout<<myday.prevDay()<<endl<<endl;

  myday.printDay(); cout<<endl;

//tests which day functions
  cout<<myday.whichDay(1)<<endl;
  cout<<myday.whichDay(2)<<endl;
  cout<<myday.whichDay(7)<<endl;
  cout<<myday.whichDay(5000)<<endl;
  cout<<myday.whichDay(49383)<<endl<<endl;

  myday.printDay();


  return 0;
}
