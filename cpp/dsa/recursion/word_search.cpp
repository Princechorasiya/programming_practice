#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {

        if (word[0] == board[i][j])
        {
          // explore that point
          visited[i][j] = 1;
          // explore the node
          ans = explore(board, word, 1, i, j, visited);
          if (ans == true)
            return true;
          visited[i][j] = 0;
        }
      }
    }
    return ans;
  }

  bool explore(vector<vector<char>> &board, string word, int ind, int i, int j, vector<vector<int>> &visited)
  {
    if (ind == word.length())
      return true;
    visited[i][j] = 1;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool ans = 0;
    for (auto k : dir)
    {
      if (isValid(i + k.first, j + k.second, visited, word, ind, board))
      {

        ans = explore(board, word, ind + 1, i + k.first, j + k.second, visited);
        if (ans == true)
          return true;
      }
    }

    visited[i][j] = 0;
    return ans;
  }

  bool isValid(int i, int j, vector<vector<int>> &visited, string word, int ind, vector<vector<char>> &board)
  {
    if (i < 0 || j < 0)
      return false;
    if (i >= visited.size() || j >= visited[0].size())
      return false;
    if (visited[i][j] == 1)
      return false;
    if (word[ind] != board[i][j])
      return false;
    return true;
  }
};
int main(){
}