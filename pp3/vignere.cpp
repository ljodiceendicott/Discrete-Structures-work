//
//  vignere.cpp
//  Created by Bob Signorile on 2/11/21.
// g++ -std=c++11 -o vignere vignere.cpp
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector <char> alphabet ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

bool elementOfSet ( vector<char>  set, char element );
int letterIndex ( vector<char>  set, char element );

void printVector(string headerMessage,vector<char>  s1);
vector <char> encode(vector <char> s, vector <char> key);
vector <char> decode(vector <char> s, vector <char> key);
vector <char> readCharactersFromTerminal();

int modulo (int a, int b);

int main () {
    char character, cr;
    vector <char> key;
    vector <char> encoded, plain, decoded;
    printVector("Alphabet",alphabet);
    cout << "enter vignere key (some characters)" << endl;
    key = readCharactersFromTerminal();
    cout << "Enter a plain text message to be encoded: ";
    plain = readCharactersFromTerminal();
    for(int i = 0; i<plain.size()-key.size(); i++){
        key.push_back(plain[i]);
    }

/*
    for (int i = 0; i < plain.size(); i++){
      int index = letterIndex (alphabet, key[(i % key.size())]);
      cout << index << " " ;
    }
    cout << endl;
*/

    encoded = encode(plain,key);
    decoded = decode(encoded,key);
    printVector("key",key);
    printVector("Plain text",plain);
    printVector("Encoded text",encoded);
    printVector("Decoded text",decoded);
    return 0;
}

vector <char> encode(vector <char> s, vector <char> key){
    int indexOfPlainLetter=0;
    int indexOfCodedLetter=0;
    int indexOfKeyLetter=0;
    int size = s.size();
    int sizeOfKey = key.size();
    vector <char> encoded;
    
    for (int index = 0; index < size; index++){
        if (elementOfSet ( alphabet, s[index] )){
            indexOfKeyLetter = letterIndex (alphabet, key[(index % key.size())]);
            indexOfPlainLetter =  letterIndex ( alphabet, s[index]);
            indexOfCodedLetter = modulo((indexOfPlainLetter+indexOfKeyLetter),26);
            encoded.push_back(alphabet[indexOfCodedLetter]);
        }
        else //not in our alphbet, so just pass add it to encoded message as is
            encoded.push_back(s[index] );
    }
    cout << endl;
    return encoded;
}

vector <char> decode(vector <char> s, vector <char> key){
    int indexOfPlainLetter=0;
    int indexOfCodedLetter=0;
    int indexOfKeyLetter=0;
    int size = s.size();
    int sizeOfKey = key.size();
    vector <char> decoded;
    
    for (int index = 0; index < size; index++){
        if (elementOfSet ( alphabet, s[index] )){
            indexOfKeyLetter = letterIndex (alphabet, key[(index % key.size())]);
            indexOfCodedLetter  =  letterIndex ( alphabet, s[index]  );
            indexOfPlainLetter = modulo((indexOfCodedLetter-indexOfKeyLetter),26);

            //this will not work:  indexOfPlainLetter = (indexOfCodedLetter - 3) % 26 ; in c++
            //there is an issue with c++ and negative numbers for mod operator
            //the +26 is because the % operator isn't the real "modulo operator" but the "division remainder"
            //operator with the following equality (a/b)*b + a%b == a    (for b!=0)
            //In order to get a positive result (for the modulo operation) you need to add
            //the divisor in case the remainder was negative

            decoded.push_back(alphabet[indexOfPlainLetter]);
        }
        else //not in our alphbet, so just pass add it to encoded message as is
            decoded.push_back(s[index] );
    }
    //cout << endl;
    return decoded;
}

vector <char> readCharactersFromTerminal(){
    vector <char> fromTerminal;
    char character;
    //cout << "Enter a plain text message to be encoded: ";
    while (1){
        character=getc(stdin);
        if (character=='\n'){
            break;
        }
        else
            fromTerminal.push_back(character);
        }
    return fromTerminal;
}

bool elementOfSet ( vector<char>  set, char element ){
    //this determines if element is in set
    int size1 = set.size();
    bool found = false;
    for(int i=0; i < size1; i++){
        if (set[i] == element){
            found = true;
            return found;
        }
    }
    return (found);
}

int letterIndex ( vector<char>  set, char element ){
    //this determines index of element in the alphabet
    int size1 = set.size();
    for(int i=0; i < size1; i++){
        if (set[i] == element){
            return i;
        }
    }
}

void printVector(string headerMessage, vector<char>  s1){
    cout << headerMessage << ":\t";
    cout << "{";
    for(int index=0; index < s1.size(); index++){
        cout << s1[index];  // << " ";
    }
    cout << "}" <<endl;
}

//thisis required to makse sure the remainder is positve
int modulo (int a, int b) { 
    return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; 
}
