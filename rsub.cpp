#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

void print (int array[], int r);	// prints the r-subset
int combination (int n, int r);		// computes C(n,r)
int fact(int n); // Returns factorial of n 

int main()
{
	int n, r;
    char c;
	cout << "Enter a value for n: ";
	cin >> n;
	cout << "Enter a value for r: ";	
	cin >> r;

	int array[r];			// this will hold your r-subsets
	int difference = n-r;	// this quantity is REALLY useful...

	cout << "There are " << combination(n,r); 
	cout << " r-subsets, and here they are:\n";

	// Fills the array with {0, 1, 2...r-1}, the smallest r-subset
	for(int i = 0; i < r; i++)
	{ 
		array[i] = i+1;
	}
	//print (array, r); //prints the first r-subset (which is the smallest)
   
   // Think about when to STOP this, there are two ways
   //to do this, one deals with the difference (line 25 above)
   //the other is to look at the calcualted number of conbinations 



   //First For loop goes from the last element in the r subset to the first one
     for(int j=r; j>-1; j--){
         //inner for loop will continue adding until it gets to the point at which you have added 
         //to the current element in the subset until you have added the difference
    for(int i=0; i<difference; i++)	{		
         array[j]= array[j]+1;
         print(array, r);
        }
         //you can use this to compare to the the largest r-subset
			// YOUR CODE GOES HERE TO FIND THE NEXT R-SUBSET
            //and print it out when you do
            //it's a looping problem with arrays
	}

	return 0;
}

void print (int array[], int r)
{
	for(int i = 0; i < r; i++)
	{
		cout << array[i] << '\t';
	}
	cout << endl;
}

int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

int combination (int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r)); 
} 