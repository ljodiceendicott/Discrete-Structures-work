//states
#define sleeping 0
#define awake 1
#define searching 2
#define hunting 3
#define recovering 4 
#define fleeing 5 
//define parameters
#define fatigue_low 0
#define fatigue_high 1
#define hungry_no_target_in_sight 2
#define target_found 3
#define predator_spotted 4 
#define hungry_target_in_sight 5 
#define target_gone_still_hungry 6 
#define hunger_sated 7
#define recovery_over 8
#define predator_gone 9
#define quit 10
#include <iostream>
using namespace std;
int main(){
    int state = awake;
      cout <<"please choose a parameter by the number" << endl;
      cout << "   0 fatigue_low" << endl;
      cout << "   1 fatigue_high" << endl;
      cout << "   2 hungry_no_target_in_sight" << endl;
      cout << "   3 target_found" << endl;
      cout << "   4 predator_spotted" << endl;
      cout << "   5 hungry_target_in_sight" << endl;
      cout << "   6 target_gone_still_hungry" << endl;
      cout << "   7 hunger_sated" << endl;
      cout << "   8 recovery_over"<<endl;
      cout << "   9 predator_gone"<<endl;
      cout << "   10 quit" << endl;
      cout << "parameter: ";
    cout<<"what is the parameter that you would like to set?"<<endl;
    cout<<"currentState: "<<awake<<endl;
   int par = -1;
   cin>>par;
   while(par!=10){
   if(par == fatigue_low && state==sleeping){
       state=awake;
   }
   else if(par==fatigue_high && state ==awake){
       state=sleeping;
   }
   else if(state==awake && par==hungry_no_target_in_sight){
       state=searching;
   }
   else if(state==awake && par==hungry_target_in_sight){
       state=hunting;
   }
   else if(state==searching && par == target_found){
       state =hunting;
   }
   else if(state==searching && par == predator_spotted){
       state=fleeing;
   }
   else if(state==fleeing && par == predator_gone){
       state = recovering;
   }
   else if(state == recovering && par==recovery_over){
       state = awake;
   }
   else if(state ==recovering && par == predator_spotted){
       state = fleeing;
   }
   else if(state == hunting && par == hunger_sated){
       state =awake;
   }
   else if(state == hunting && par == target_gone_still_hungry){
       state = searching;
   }
   else if(state == hunting && par == predator_spotted){
       state = fleeing;
   }
   cout<<"the new state is "<<state<<endl;
   }   
    
}
