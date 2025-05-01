#include <iostream>
using namespace std;

bool ok(int q[], int c) { // ok function to check if it is safe to place a queen
    for (int i = 0; i < c; i++) {
        if ((q[c] == q[i]) || (c - i == abs(q[c] - q[i]))) { 
            return false;
        }
    }
    return true; 
}

void print(int q[]) { // prints solution #, 1d array values, and board
    int i, j, k, l;
    typedef char box[5][7]; // typedef for box
    box bb, wb, *board[8][8]; // bb=black box, wb=white box
    static int solution = 1; 
    
    cout << "Solution #" << solution++ << endl; 
    
    // Print the array values
    cout << "1d array# ";
    for (i = 0; i < 8; i++) {
        cout << q[i] << "|";
    }
    cout << endl;
    
    // create black queen for black spaces
    box bq = { {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
                       {' ', char(219), ' ', char(219), ' ', char(219), ' '},
                       {' ', char(219), char(219), char(219), char(219), char(219), ' '},
                       {' ', char(219), char(219), char(219), char(219), char(219), ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    
    // create white queen for black spaces
    box wq = { {char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
                       {char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
                       {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
                       {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
                       {char(219), char(219), char(219), char(219), char(219), char(219), char(219)}
    };

    //fill in black box and white box
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            wb[i][j] = ' '; 
            bb[i][j] = char(219); 
        }
    }

    // fill board with pointers
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) { // if row + col is even
                if (q[j] == i) { 
                    board[i][j] = &bq; // place black queen
                }
                else { // otherwise 
                    board[i][j] = &wb;
                }
            }
            else  { //   at else if row + col is not even
                if (q[j] == i) {
                    board[i][j] = &wq; // place white queen
                }
                else { //otherwise
                    board[i][j] = &bb;
                }
            }
        }
    }
    // print upper border
    cout << "    ";
    for (i = 0; i < 7 * 8; i++) {
        cout << '_';
    }
    cout << endl;
    
    //print the board
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 5; k++) {
            cout << "   " << char(179);
            for (j = 0; j < 8; j++) {
                for (l = 0; l < 7; l++) {
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << endl;
        }
    }
    cout << "    ";
    for (i = 0; i < 7 * 8; i++) {
        cout << char(196);
    }
    cout << endl;
}

int main() {
    int q[8] = { 0 };
    int c = 0;
    // while loop to go to next col while col is greater than 0 unless col=8
    while (c >= 0) {
        c++;
        if (c == 8) {
            print(q);
            c--;
        }
        else {
            q[c] = -1;
        }
        //while loop to go to next row while col is greater than 0 unless row=8
        while (c >= 0) {
            q[c]++;
            if (q[c] == 8) {
                c--;
            }
            else if (ok(q, c)) {
                break; 
            }
        }
    }
    return 0;
}
