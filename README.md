# EightQueens

Description: On an 8x8 chessboard, eight queens are placed on the board under three conditions: a queen cannot be in the same row as another queen, a queen cannot be in the same column as another queen, and a queen cannot be in the same right/left diagonal as another queen. These conditions may seem strict and give the idea that there can only be one solution. However, there is actually a total of 92 solutions! I have created five differnt approaches to finding all 92 solutions and I have also created a program that calculates how many solutions there would be for "n" queens. 

1) EightQueens2D.cpp:
   This version solves the eight queens problem using a recursive backtracking approach with a 2D array to represent the chessboard and prints all valid solutions.

2) EightQueens1D.cpp:
   This version solves the eight queens problem using a iterative backtracking approach with "goto" statements and a 1D array. Each index in the array represents a column on the
   chessboard, and the value at each index indicates the row position of the queen in that column. This approach reduces memory usage and simplifies the diagonal conflict checks. The
   program outputs every valid solution and visualizes it by converting the 1D representation into a 2D board layout.

3) EightQueensWithoutGoto.cpp:
   This version solves the eight queens problem using a iterative backtracking approach and a 1D array. Each array index represents a column, and the value at that index indicates the
   row where the queen is placed. The program avoids recursion and "goto" statements, instead using structured loops and a helper function to check for conflicts. Valid solutions are
   printed both as a row index list and as an 8×8 board visualization.

4) DumbEightQueens.cpp:
   This version solves the eight queens problem using a brute force approach by generating possible combinations of queen placements, one for each column. A helper function verifies
   that no two queens threaten each other by checking rows and diagonals. This method is extremely inefficient compared to backtracking methods.

5) FancyEightQueens.cpp:
   This version features a graphical chessboard printed in the console using ASCII characters. It uses a 1D array and iterative backtracking to find valid queen placements, and
   visually renders each solution with custom designed white and black queens on alternating colored squares. The board is displayed using multi-line character boxes to resemble a
   real 8×8 chessboard, offering a visually rich and satisfying output experience directly in the terminal.

6) nQueens.cpp:
   This versoon solves the N-Queens problem for values of n from 1 to 12. It uses a dynamic 1D array and iterative backtracking to compute the total number of valid queen arrangements on an n × n chessboard. For each board size, it prints the total number of conflict-free solutions. This implementation is efficient, avoids recursion, and dynamically manages memory for each n. 
