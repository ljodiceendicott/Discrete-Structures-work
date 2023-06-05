//Luke Jodice 4/12/21
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

int readInGraph();
void findAdjacentNodes(int node, int size);
bool isEulerCircut(int size);
bool isEulerPath(int size);
int calculateDegreeOfVertex(int node, int size);

const int ROWS = 10;
const int COLS = 10; 
int graph[ROWS][COLS];  //gloabal Adjacency Matrix 

int main(int argc,  char** argv){
    ifstream infile;
    int size, node;
    size = readInGraph();
    cout<<"this is:";
    //if it is both a Euler Circut and a Euler Path
    if(isEulerCircut(size)&&isEulerPath(size)){
        cout<<"Both"<<endl;
    }
    //if it is a Euler Circut
    else if(isEulerCircut(size)){
        cout<<"an Euler Circut"<<endl;
    }
    //if it is a Euler Path
    else if(isEulerPath(size)){
        cout<<"an Euler Path"<<endl;
    }
    //Neither
    else{
        cout<<"neither an Euler Path or Euler Circut"<<endl;
    }
}

    int readInGraph(){
    int size,r=0, c=0;
    ifstream infile;
    infile.open("graph17.txt");
    infile >> size;
    for (r = 0; r < size; r++){
        for(c = 0; c < size; c++){
           infile >> graph[r][c];
        }
    }
    infile.close();
    return size;
}

  int calculateDegreeOfVertex(int node, int size){
    int r=node, c=0;  //r is the row, c will be the columns
    int degree = 0;
    for(c = 0; c < size; c++){ //loop through the columns for row r
        if (graph[r][c] > 0 ) //==1, ie there is a direct connection
            degree++;
    }
    return degree;
}
bool isEulerPath(int size){
    int odddegree= 0;
    for(int i=0; i<size; i++){
        int s =calculateDegreeOfVertex(i,size);
        if(s%2==1){
            odddegree++;
        }
    }
    if(odddegree>2){
        return false;
    }
    else{
        return true;
    }
   
}
bool isEulerCircut(int size){
 int s = 0;
    for(int i= 0; i<size; i++){
       int s =calculateDegreeOfVertex(i,size);
        if(s%2==1){
            return false;
        }
    }
    return true;
}


