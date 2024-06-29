#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

bool isValid(vecti_2d &visited, int row, int col)
{
  int n = visited.size();
  if (row >= n || col >= n)
    return false;
  if (row < 0 || col < 0)
    return false;

  if (visited[row][col] == true)
    return false;

  return true;
}

// how to debug this code
void knight_tour(vecti_2d &matrix, vecti_2d &visited, int row, int col, vectpi &dir, int moves)
{
  if (moves ==matrix.size() * matrix.size())
  {
    matrix[row][col] = moves;
    print(matrix);
    cout << endl;
    matrix[row][col] = 0;
    return;
  }

  for (auto i : dir)
  {
    visited[row][col] = true;
    if (isValid(visited, row + i.first, col + i.second))
    {
      matrix[row + i.first][col + i.second] = moves;
      knight_tour(matrix, visited, row + i.first, col + i.second, dir, moves + 1);

      matrix[row + i.first][col + i.second] = 0;
    }
    visited[row][col] = false;
  }
}

int main()
{
  int n = 5;
  vecti v(n, 0);
  vecti_2d matrix(n, v);
  vecti_2d visited(n, v);
  vectpi dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-2, -1}};

  matrix[0][0] = 1;
  knight_tour(matrix, visited, 0, 0, dir, 1);
}