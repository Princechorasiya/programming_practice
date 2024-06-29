#include <bits/stdc++.h>
using namespace std;

// using
int sing_coin(vector<int> &v, int ind, int tar)
{
  if (tar == 0)
  {
    return 1;
  }

  // this wont be called if we check and then call;
  //  else if (tar < 0)
  //    return 0;

  // if (ind == v.size()) //for loop will take car of this
  //   return 0;

  int ans = 0;
  for (int i = ind; i < v.size(); i++)
  {
    // ans += sing_coin(v, ind + 1, tar - v[i]);/
    if (v[i] <= tar)
    {
      ans += sing_coin(v, i + 1, tar - v[i]);
    }
  }
  return ans;
}

int sing_coin_per(vector<int> &v, int ind, int tar)
{
  if (tar == 0)
  {
    return 1;
  }

  // this wont be called if we check and then call;
  else if (tar < 0)
    return 0;

  if (ind == v.size()) // for loop will take car of this
    return 0;

  int ans = 0;

  for (int i = 0; i < ind; i++)
  {

    ans += sing_coin_per(v, i, tar - v[i]);
  }
  for (int i = ind + 1; i < v.size(); i++)
  {
    ans += sing_coin_per(v, i, tar - v[i]);
  }

  return ans;
}

int inf_coin_per(vector<int> &v, int tar)
{
  if (tar == 0)
  {
    return 1;
  }

  // this wont be called if we check and then call;
  else if (tar < 0)
    return 0;

  int ans = 0;

  for (int i = 0; i < v.size(); i++)
  {

    ans += inf_coin_per(v, tar - v[i]);
  }

  return ans;
}

int inf_coin_per(vector<int> &v, int ind, int tar)
{
  if (tar == 0)
  {
    return 1;
  }

  // this wont be called if we check and then call;
  else if (tar < 0)
    return 0;

  int ans = 0;

  for (int i = 0; i < ind; i++)
  {

    ans += inf_coin_per(v, i + 1, tar - v[i]);
  }
  for (int i = ind + 1; i < v.size(); i++)
  {
    ans += inf_coin_per(v, i + 1, tar - v[i]);
  }

  return ans;
}

bool isValid(vector<vector<int>> &matrix, vector<vector<int>> &visited, int sr, int sc)
{
  int row = matrix.size();
  int col = matrix[0].size();
  if (sr >= row || sc >= col)
    return false;

  if (matrix[sr][sc] == 1)
    return false;

  if (visited[sr][sc] == 1)
    return false;

  return true;
}
void ratMaze(vector<vector<int>> &matrix, vector<vector<int>> &visited, int sr, int sc, int dr, int dc, string path)
{

  if (sr == dr && sc == dc)
  {
    cout << path << endl;
    return;
  }
  if (sr < dr && sc < dc)
  {
    visited[sr][sc] = 1;
    if (isValid(matrix, visited, sr, sc + 1))
    { // left move

      ratMaze(matrix, visited, sr, sc + 1, dr, dc, path + "R");
    }
    if (isValid(matrix, visited, sr, sc - 1))
    { // right move

      ratMaze(matrix, visited, sr, sc - 1, dr, dc, path + "L");
    }
    if (isValid(matrix, visited, sr + 1, sc))
    { // down move

      ratMaze(matrix, visited, sr + 1, sc, dr, dc, path + "D");
    }
    if (isValid(matrix, visited, sr - 1, sc))
    { // up move

      ratMaze(matrix, visited, sr - 1, sc, dr, dc, path + "U");
    }
    visited[sr][sc] = 0;
  }
}
int main()
{
  vector<vector<int>> maze = {{0, 0, 0},
                              {0, 0, 1},
                              {0, 0, 0}};
  vector<vector<int>> visited(maze.begin(), maze.end());
  ratMaze(maze, visited, 0, 0, 2, 2, "");
}