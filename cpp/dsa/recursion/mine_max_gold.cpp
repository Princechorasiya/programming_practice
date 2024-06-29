#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

// get max gold from the matrix

// find the max gold possible from every single cell



void getGold(vecti_2d &mine, vecti_2d &visited, vectpi &dir, int i, int j, int &score)
{
  if(i<0 || j<0 || i>=mine.size() || j>= mine[0].size() || mine[i][j] ==0 ||visited[i][j]==1)
    return ;
  visited[i][j] = 1; // this makes sure we travel that island only once
  score += mine[i][j];
  for (auto k : dir)
  {
    getGold(mine, visited, dir, i + k.first, j + k.second, score);
  }
}
int findMaxGold(vecti_2d &mine, vecti_2d &visited, int m, int n)
{
  int maxi = 0;
  vectpi dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {

      if (mine[i][j] != 0 && visited[i][j] ==0)
      {
        int gold = 0;
        getGold(mine, visited, dir, i, j, gold);
        maxi = max(maxi, gold);
      }
    }
  }
  return maxi;
}

int main()
{
  vecti_2d mine = {{1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
  int m = 4, n = 4;
  vecti_2d visited(m,vector<int> (n,0));
  cout << findMaxGold(mine, visited, m, n);
}





