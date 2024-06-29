//in a maze find the path for the rat
#include <bits/stdc++.h>
using namespace std;
using vecti = vector<int>;
using vecti_2d = vector<vector<int>>;
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
  if (sr < 0 || sc < 0)
    return;
  if (sr > dr || sc > dc)
    return;

  if (matrix[sr][sc] == 1)
    return;

  if (visited[sr][sc] == 1)
    return;

  visited[sr][sc] = 1;

  // ratMaze(matrix, visited, sr, sc + 1, dr, dc, path + "R");

  // ratMaze(matrix, visited, sr, sc - 1, dr, dc, path + "L");

  // ratMaze(matrix, visited, sr + 1, sc, dr, dc, path + "D");

  // ratMaze(matrix, visited, sr - 1, sc, dr, dc, path + "U");
  vector<pair<
      pair<int, int>, string>>
      dir = {
          {{0, 1}, "R"},
          {{0, -1}, "L"},
          {{1, 0}, "D"},
          {{-1, 0}, "U"},

      };

  for (auto i : dir)
  {
    auto j = i.first;
    auto k = i.second;
    ratMaze(matrix, visited, sr + j.first, sc + j.second, dr, dc, path + k);
  }

  visited[sr][sc] = 0;
}
int main()
{
  vector<vector<int>> maze = {{0, 0, 0},
                              {0, 0, 1},
                              {0, 0, 0}};
  vector<vector<int>> visited = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ratMaze(maze, visited, 0, 0, 2, 2, "");
}