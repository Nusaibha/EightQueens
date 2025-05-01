#include <iostream>
using namespace std;
bool check (int queen[]) { 
    for (int i = 0; i < 8; i++) { 
        for (int j = i + 1; j < 8; j++) {
            if (queen[i] == queen[j] || abs(queen[i] - queen[j]) == abs(i - j)) { 
                return false;                                     
            }
         }
    }
    return true;
} 
int main() {
    int queen[8] = {0};
    int count = 0;
    for (int i0 = 0; i0 < 8; i0++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    queen[0] = i0;
                                    queen[1] = i1;
                                    queen[2] = i2;
                                    queen[3] = i3;
                                    queen[4] = i4;
                                    queen[5] = i5;
                                    queen[6] = i6;
                                    queen[7] = i7;
                                    if (check(queen)) {
                                        count++;
                                        cout << "This is #" << count << " solution." << endl;
                                        cout << "1D Array #: "; 
                                        for (int z = 0; z < 8; z++){
                                            cout << queen[z] << " "; 
                                        }
                                        cout << endl; 
                                        for (int i = 0; i < 8; i++) {
                                            for (int j = 0; j < 8; j++) {
                                                if (queen[j] == i) {
                                                    cout << "1 ";
                                                } else {
                                                    cout << "0 ";
                                                }
                                            }
                                            cout << endl;
                                        }
                                        cout << endl;
                                    } 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
