#include <iostream>
using namespace std;

// Function to check if placing a queen at column 'col' is safe
bool ok(int q[], int col) { 
    for (int row = 0; row < col; row++) {
        // Check if there's a conflict with previously placed queens
        if (abs(q[row] == q[col]) || (col - row) == abs(q[col] - q[row]))
            // Conflict found, not a safe position
            return false;
    }
    // No conflicts found, safe position
    return true;
}

int main(){ 
    int board[8], col = 0;
    board[0] = 0;
    // Counter to keep track of solutions
    int count = 0;

    // Loop until all solutions are found
    while (col >= 0) { 
        // Move to the next column
        col++;
        // If all queens are placed (solution found)
        if (col == 8) {
            cout << "Solution " << count++ << ": ";
            // Print the board configuration
            for (int row = 0; row < 8; row++) { 
                cout << board[row];  
            }
            cout << endl;
            // Print the board
            for (int row = 0; row < 8; row++) {
                for (int i = 0; i < 8; i++) {
                    if (board[i] == row)
                        cout << "1";
                    else 
                        cout << "0";
                }
                cout << endl;
            }
            cout << "\n";
            col--; // Similar to backtrack
        } else {
            board[col] = -1;
        }

        // Find a safe position for the queen in the current column
        while (col >= 0) { 
            board[col]++;
            if (board[col] == 8)
                col--;
            else if (ok(board, col))
                break;
        } 
    }
    return 0; 
}
