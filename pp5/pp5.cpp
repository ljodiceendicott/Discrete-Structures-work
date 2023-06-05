//Luke Jodice 4/12/21
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

int readInGraph();
void printGraph(int size);
void findAdjacentNodes(int node, int size);
void findTwoMoves(int node, int size);
void calculateDegreeOfVertex(int node, int size);

const int ROWS = 10;
const int COLS = 10; 
int graph[ROWS][COLS];  //gloabal Adjacency Matrix 

int main(int argc,  char** argv){
    ifstream infile;
    int size, node;
    size = readInGraph();
    printGraph(size);

    while (true){
    cout << "enter a node (0 -> " << size-1 << ") and i will find it's degree" << endl;
    cin >> node;
    if ( node < 0 || node >= size)
       cout << "you entered " << node << " but we only have " << size << " nodes, try again." << endl;
    else break;
    }

    calculateDegreeOfVertex(node, size);

    while (true){
    cout << "enter a node (0 -> " << size-1 << ") and i will find ALL it's adjacent neighbors" << endl;
    cin >> node;
    if ( node < 0 || node >= size)
       cout << "you entered " << node << " but we only have " << size << " nodes, try again." << endl;
    else break;
    }

    findAdjacentNodes(node,size);
    while (true){
      cout << "enter a node (0 -> " << size-1 << ") and i will find TWO STEPS" << endl;
      cin >> node;
    if ( node < 0 || node >= size)
       cout << "you entered " << node << " but we only have " << size << " nodes, try again." << endl;
    else break;
    }
    findTwoMoves(node,size);
    return 0;
}

int readInGraph(){
    int size,r=0, c=0;
    ifstream infile;
    infile.open("graph.txt");
    infile >> size;
    for (r = 0; r < size; r++){
        for(c = 0; c < size; c++){
           infile >> graph[r][c];
        }
    }
    infile.close();
    return size;
}

void printGraph(int size){
    int r=0, c=0;
    cout << "  " << "  ";
    for (r = 0; r < size; r++){
        cout << r << " ";
    }
    cout << endl;
    cout << "  " << "  ";
    for (r = 0; r < size; r++){
        cout << "-" << " ";
    }
    cout << endl;
    for (r = 0; r < size; r++){
        cout << r  << " |" << " ";
        for(c = 0; c < size; c++){
           cout << graph[r][c] << " ";
        }
        cout << endl;
    }
    return;
}

void calculateDegreeOfVertex(int node, int size){
    int r=node, c=0;  //r is the row, c will be the columns
    int degree = 0;
    cout << "the degree of nodes " << node <<" is: " ;

    for(c = 0; c < size; c++){ //loop through the columns for row r
        if (graph[r][c] > 0 ) //==1, ie there is a direct connection
            degree++;
    }

    cout << degree << endl;
    return;
}

void findAdjacentNodes(int node, int size){
    int r=node, c=0;
    cout << "the list of adjacent nodes is: " ;
    //your code goes here
    for(c =0; c<size; c++){
        if(graph[r][c]>0){
            cout<<"-"<<c;
        }
    }
    cout<<"-";
    cout << endl;
    return;
}

void findTwoMoves(int node, int size){
    int r=node, c=0, newr=0, cc=0;
    cout << "the list of TWO STEPS is: " ;
    //your code goes here
    for(c =0; c<size; c++){
        //if the node is greater than one it is a neighbor
        if(graph[r][c]>0){
            //loop through neighbor's level to see if it has any neighbors
            for(cc=0; cc<size; cc++){
                if(graph[c][cc]>0&&cc!=r){
                    cout<<"("<<r<<","<<c<<","<<cc<<")";
                }
            }
            cout<<"-";
        }
    }
    cout << endl;
}