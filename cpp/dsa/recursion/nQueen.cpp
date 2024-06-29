#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vecti_2d = vector<vector<int>>;

// prepare a vector of 26 ascii value

// prepare a 2d vecotr of size n
bool isSafe(int row, int col, vecti_2d &matrix) //this runs in o(n) n *n times can we reduce it 
{
  int i = row - 1, j = col;
  while (i >= 0)
  {
    if (matrix[i][col] == 1)
    {
      return false;
    }
    i--;
  }
  i = row - 1, j = col - 1;
  while (i >= 0 && j >= 0)
  {
    if (matrix[i][j] == 1)
    {
      return false;
    }
    i--, j--;
  }
  i = row - 1, j = col + 1;
  while (j < matrix.size() && i >= 0)
  {
    if (matrix[i][j] == 1)
      return false;
    j++;
    i--;
  }
  return true;
}

void nQueen(int n, int row, vecti_2d &matrix)
{
  if (row == n)
  {
    print(matrix);
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (isSafe(row, i, matrix))
    {
      matrix[row][i] = 1;
      nQueen(n, row + 1, matrix);
      matrix[row][i] = 0;
    }
  }
}
int main()
{
  int n = 4;
  vecti v(n, 0);
  vecti_2d matrix(n, v);
  nQueen(4, 0, matrix);
}



//optimized using branch and bound for searching the safe position by making it from 3n to O(1)

bool isSafe(int n, int row, int col, vecti &col_track, vecti &d1_track, vecti &d2_track)
{
  // optimisation
  if (col_track[col] == true)
    return false;
  if (d1_track[row + col] == true)
    return false;
  if (d2_track[row - col + n - 1] == true)
    return false;

  return true;
}

void nQueen(int n, int row, vecti_2d &matrix, vecti &col_track, vecti &d1_track, vecti &d2_track)
{
  if (row == n)
  {
    print(matrix);
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (isSafe(row, i, matrix))
    {
      matrix[row][i] = 1;
      col_track[i] = 1;
      d1_track[row + i] = 1;
      d2_track[row - i + n - 1] = 1;
      nQueen(n, row + 1, matrix, col_track, d1_track, d2_track);
      matrix[row][i] = 0;
      col_track[i] = 0;
      d1_track[row + i] = 0;
      d2_track[row - i + n - 1] = 0;
    }
  }
}