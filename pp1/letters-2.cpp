//
//  letters.cpp
//  
//
//  Created by Bob Signorile on 2/5/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<char> makeUnion ( vector<char>  s1, vector<char>  s2 );
vector<char> makeIntersection ( vector<char>  s1, vector<char>  s2 );
vector<char> makeDifference ( vector<char>  s1, vector<char>  s2 );
vector<char> createSet();
void printVector(vector<char>  s1);

int main () {
    vector<char>  set1;
    vector<char>  set2;
    cout << "For Set 1" << endl;
    set1 = createSet();  //create Set 1 from input at the terminal
    
    cout << "For Set 2" << endl;
    set2 = createSet();  //create Set 2 from input at the terminal
    
    cout << "For Set 1" << endl;
    printVector(set1);  //print SET 1 data
    
    cout << "For Set 2" << endl;
    printVector(set2);  //print SET 2 data
    
    cout << "makeIntersection:" <<endl;
    vector<char> theInt = makeIntersection (set1, set2); //create INTERSECTION
    printVector(theInt);
    
    cout << "makeDifference:" <<endl;
    vector<char> theDiff = makeDifference (set1, theInt); //create DIFFERENCE
    printVector(theDiff);
    
    return 0;
}

vector<char> makeIntersection (vector<char>s1, vector<char>s2){
    //Remember, A ∩ B  = {x | x ∈ A ∧ x ∈ B}.
    vector<char> theInter; //this will contain the Intersection of s1 and s2
    int size1 = s1.size(); //this is actually the Cardinality for set s1
    int size2 = s2.size(); //this is actually the Cardinality for set s2
    for(int i=0; i<size1; i++){
        for(int j=0;j<size2; j++){
            if(s1[i] ==s2[j]){
            theInter.push_back(s1[i]);
            }   
        }
    }
    
    return theInter;
}

vector<char> makeDifference ( vector<char>  s1, vector<char>  s2 ){
    //in general: A-B = {x | x ∈A ∧ x ∉B}.
    //you can call this function with s1 as set A and
    //s2 as the INTERSECTION of A and B
    //this would give us: A-B = A - (A ∩ B) = {x | x ∈ A ∧ x ∉ B}.
    //or, you can you can call this function with s1 as set B and
    //s2 as the INTERSECTION of A and B
    //this would give us: B-A = B - (A ∩ B) = {x | x ∈ B  ∧ x ∉ A}.
    
    vector<char> theDiff; //this will contain the DIFFERNCE of A and B
    bool match = false;
    int size1 = s1.size(); //this is actually the Cardinality for set s1
    int size2 = s2.size(); //this is actually the Cardinality for set s2
    
    for(int i=0; i<size1; i++){
        match=false;
        for(int j=0; j<size2; j++){
            if(s1[i]==s2[j]){
                match=true;
            }
        }
        if(!match){
            theDiff.push_back(s1[i]);
        }
    }
    
    return theDiff;
}

vector<char> createSet(){
    vector<char> temp;
    char element;
    cout<< "Please enter letters for your set(NO SPACES, RETURNN TO QUIT): ";
    while (1){
        element = getc(stdin);
        if ( element == '\n')
            break;
        temp.push_back(element);
    }
    return temp;
}

void printVector(vector<char>  s1){
    cout << "{";
    for(int index=0; index < s1.size(); index++){
        cout << s1[index] << " ";
    }
    cout << "}" <<endl;
}

