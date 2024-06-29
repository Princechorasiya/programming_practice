#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

int select_sq(int k)
{
  int row = k / 9;
  int col = k % 9;

  // figuring out square out and col
  //  int row_s = row / 3 * 3; //this gives the index of starting value of the square
  //  int col_s = col / 3 * 3;
  if (row <= 2)
  {
    if (col <= 2)
      return 1;

    else if (col <= 5)
      return 2;
    else
      return 3;
  }
  else if (row <= 5)
  {
    if (col <= 2)
      return 4;

    else if (col <= 5)
      return 5;
    else
      return 6;
  }
  else
  {
    if (col <= 2)
      return 7;

    else if (col <= 5)
      return 8;
    else
      return 9;
  }
}
bool isSafe(vecti_2d &matrix, int k, int ele, vector<unordered_set<int>> &sq)
{
  // how will u figure out which square we are in
  //  check hte row
  int row = k / 9;
  int col = k % 9;
  int i = 0;
  // check the row
  for (int i = 0; i < 9; i++)
  {
    if (i != row && matrix[i][col] == ele)
    {
      return false;
    }
  }

  // check the column
  for (int i = 0; i < 9; i++)
  {
    if (i != col && matrix[row][i] == ele)
      return false;
  }

  // check the square
  int square = select_sq(k);
  if (sq[square - 1].count(ele) == 1)
    return false;

  return true;
}
void solve_sudoku(vecti_2d &matrix, int n, int k, vector<unordered_set<int>> &sq)
{

  if (k == 81)
  {
    print(matrix);
    cout << endl;
    return;
  }
  int row = k / 9;
  int col = k % 9;

  if (matrix[row][col] == 0)
  {
    for (int j = 1; j <= 9; j++)
    {

      if (isSafe(matrix, k, j, sq))
      {
        int square = select_sq(k);
        matrix[row][col] = j;
        sq[square - 1].insert(j);
        solve_sudoku(matrix, n, k + 1, sq);
        matrix[row][col] = 0;
        sq[square - 1].erase(j);
      }
    }
  }
  else
  {
    solve_sudoku(matrix, n, k + 1, sq);
  }
}

int main()
{
  int n = 9;
  vecti v(n, 0);
  vecti_2d matrix = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  print(matrix);
  vector<unordered_set<int>> sq(9);
  for (int i = 0; i < 81; i++) // inserting the preset values in the sq
  {
    int square = select_sq(i);
    int row = i / 9;
    int col = i % 9;
    sq[square - 1].insert(matrix[row][col]);
  }

  cout << endl;

  solve_sudoku(matrix, 9, 0, sq);
}