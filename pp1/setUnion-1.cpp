//
//  setUnion.cpp
//  
//  Created by Bob Signorile on 2/5/21.
//  to compile: g++ -std=c++11 -o setUnion setUnion.cpp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//prototypes
vector<char> makeUnion ( vector<char>  s1, vector<char>  s2 );
vector<char> createSet();
void printVector(vector<char>  s1);

int main () {
    vector<char>  set1;
    vector<char>  set2;
    vector<char>  setUnion;
    cout << "For Set1" << endl;
    set1 = createSet();
    
    cout << "For Set2" << endl;
    set2 = createSet();
   
    cout << "For Set1" << endl;
    printVector(set1);
    
    cout << "For Set2" << endl;
    printVector(set2);

    cout << "makeUnion" <<endl;

    setUnion = makeUnion (set1, set2);
    //sort(test.begin(), test.end());
    printVector(setUnion);
    
    return 0;
}

vector<char> makeUnion (vector<char>s1, vector<char>s2){
    //A ∪ B = {x | x ∈ A ∨ x ∈ B}, but remember, no duplicates.
    vector<char> theUnion;  //this will contain the union of s1 and s2
    int size1 = s1.size(); //this is actually the Cardinality for set s1
    int size2 = s2.size(); //this is actually the Cardinality for set s2
    
    bool match = false;
    for(int i=0; i < size2; i++){
        theUnion.push_back(s2[i]); //adds to rear of vector
    }
    for(int i=0; i < size1; i++){
        for(int j=0; j < size2; j++){
            if (s1[i] == s2[j]){
                match = true;
                break;
            }
        }
        if (!match){
            theUnion.push_back(s1[i]); //adds to rear of vector
        }
        match = false;
    }
    
    return theUnion;
}


vector<char> createSet(){
    vector<char> temp;
    char element;
    cout<< "Please enter letters for your set(NO SPACES, RETURN TO QUIT): ";
    while (1){
        element = getc(stdin);
        if ( element == '\n')
            break;
        temp.push_back(element); //adds to rear of vector
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

