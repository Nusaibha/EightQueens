#include <iostream>
#include <cmath>
using namespace std;

// The same ok function from 1D queens project
bool ok(int q[], int c){
   for(int i=0;i<c;i++){
       // Check if there's a conflict with previously placed queens
       if(q[i]==q[c]||((c-i)==abs(q[c]-q[i])))
            // Conflic found, not a safe position
			return false;
   }
	// No conflicts found, safe postition	
	return true;
}

int main(){
    // Set n to 12 
    int n=12;
    // Set the initial number of solutions for each n queens problem to 0
    int solutions=0;
    for(int i=1;i<=n;i++){
        // Dynamically declare an array of size i and initialize a counter c to 0
        int *q = new int[i], c = 0;
        // Initialize the first element of the array to 0
        q[c] = 0;
        // Increment the counter
        c++;
        while(c >= 0){ 
            // If c is greater than i-1 the array is filled
            if(c > i-1){
                solutions++;
                c--;
            }
            else
            // Reset the current element to -1
            q[c] = -1;
            // Loop to increment the current element and check if it's still within bounds
            while (c >= 0 && c < i){
                q[c]++;
                // If the incremented value equals i decrement c to backtrack
                if(q[c] == i) c--;
                else
                // Call the ok function to check constraints
                if(ok(q, c) == true) {
                    c++;
                    break;
                }
            }
        }
        // print statement that returns the solutions of n queens problem
        cout << "\nThere are " << solutions << " solutions to the " << i << " queens problem." ;
        // reset the number of solutions
    	solutions=0;
    	// delete the array
    	delete q;
    }
   return 0;
}



