#include <iostream>
#include <cstdlib>
using namespace std;

int
main ()
{
  int queen[8] = { };
  int col = 0;
  queen[col] = 0;
  int count = 0;

nextCol:
  col++;
  if (col == 8)
	goto print;
  queen[col] = -1;

nextRow:
  queen[col]++;
  if (queen[col] == 8)
	goto backTrack;
  //row test
  for (int i = 0; i < col; i++)
	{
	  if (queen[i] == queen[col] || abs (queen[col] - queen[i]) == (col - i))
		goto nextRow;
	}
  goto nextCol;

backTrack:
  col--;
  if (col == -1)
	return 0;
  goto nextRow;

print:
  count++;
  int board[8][8] = { 0 };
  cout << "This is #" << count << " solution." << endl;
  cout << "1D array #: |";
  for (int i = 0; i <= 7; i++)
	{
	  cout << queen[i] << "|";
	  board[queen[i]][i] = 1;
	}
  cout << endl;
  for (int j = 0; j <= 7; j += 1)
	{
	  for (int k = 0; k <= 7; k++)
		{
		  cout << board[j][k];
		}
	  cout << endl;
	}
  cout << endl;
  goto backTrack;

  return 0;
}
