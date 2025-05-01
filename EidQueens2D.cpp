#include <iostream>
using namespace std;

int queen[8][8] = {0};  // 8x8 chessboard initialized to 0
int count = 0;          // Number of valid solutions

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    // Check left row
    for (int i = 0; i < col; i++) {
        if (queen[row][i] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (queen[i][j] == 1) return false;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (queen[i][j] == 1) return false;
    }

    return true;
}

// Recursive function to solve the 8-Queens problem
void solve(int col) {
    if (col == 8) {
        // Found a valid solution
        count++;
        cout << "Solution #" << count << ":\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << queen[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < 8; row++) {
        if (isSafe(row, col)) {
            queen[row][col] = 1;     // Place queen
            solve(col + 1);          // Recurse to next column
            queen[row][col] = 0;     // Backtrack
        }
    }
}

int main() {
    solve(0);
    cout << "Total solutions: " << count << endl;
    return 0;
}
