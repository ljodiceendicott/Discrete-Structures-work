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
int main(){
    int state = awake;
    int par=menu();
    while(par!=8){
        cout<<endl;
        switch(par){
            case fatigue_low :
                if(state == sleeping){
                    state = awake;
                    cout<<"Next State:Awake";
                }
                else{
                    cout<<"State stays the same";
                }
            case fatigue_high :
                if(state == awake){
                    state = sleeping;
                    cout<<"Next State: Sleeping";
                }
                else{
                    cout<<"State stays the same";
                }
            case hungry_no_target_in_sight:
                if(state == awake){
                    state = searching;
                    cout<<"Next State: Searching";
                }
                else{
                    cout<<"State stays the same";
                }
            case target_found:
                if(state == searching){
                    state = hunting;
                    cout<<"Next State: Hunting";
                }
                else{
                    cout<<"State stays the same";
                }
            case predator_spotted:
                state = fleeing;
            case hungry_target_in_sight:
                if(state == awake){
                    state = hunting;
                    cout<<"Next State: Hunting";
                }
                else{
                    cout<<"State stays the same";
                }
            case target_gone_still_hungry:
                if(state == hunting){
                    state = searching;
                    cout<<"Next State: Searching";
                }
                else{
                    cout<<"State stays the same";
                }
            case hunger_sated:
                if(state ==hunting){
                    state = awake;
                    cout<<"Next State: Awake";
                }
                else{
                    cout<<"State stays the same";
                }
            case recovery_over:
                if(state ==recovering){
                    state = awake;
                    cout<<"Next State: Awake";
                }
                else{
                    cout<<"State stays the same";
                }
            case predator_gone:
                if(state == fleeing){
                    state = recovering;
                    cout<<"Next State: Recovering";
                }
                else{
                    cout<<"State stays the same"; 
                }
            case quit:
                cout<<"Game over!!!";
            default :
                cout << "State stays the same" << endl;
        }   

    }
    
}
int menu(){
    int parameter=-1;
    //this would need to be adjusted when more parameters are added
      cout << RESET << "please choose a parameter by the number" << endl;
      cout << "   0 fatigue_low" << endl;
      cout << "   1 fatigue_high" << endl;
      cout << "   2 hungry_no_target_in_sight" << endl;
      cout << "   3 target_found" << endl;
      cout << "   4 predator_spotted" << endl;
      cout << "   5 hungry_target_in_sight" << endl;
      cout << "   6 target_gone_still_hungry" << endl;
      cout << "   7 hunger_sated" << endl;
      cout << "   8 quit" << endl;
      cout << "parameter: ";
    }
}