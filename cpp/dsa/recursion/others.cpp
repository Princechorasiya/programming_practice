#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

// generate all keyboard permutations
void generateKey(string s, string ans, int ind, vector<string> &mapp)
{
  if (ind == s.length())
  {
    cout << ans << endl;
    return;
  }
  int t = s[ind] - '0';
  for (auto i : mapp[t])
  {
    ans += i;
    generateKey(s, ans, ind + 1, mapp);
    ans.pop_back();
  }
}

// generate all binary string without consecutive ones
void generateB(int n, int l, string ans)
{
  if (l == n)
  {
    cout << ans << endl;
    return;
  }
  if (l == 0 || ans[ans.length() - 1] == '0')
  {
    generateB(n, l + 1, ans + "0");
    generateB(n, l + 1, ans + "1");
  }
  else
  {
    generateB(n, l + 1, ans + "0");
  }
}
int main()
{
  // vector<string> mapp = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
  // string s = "123";
  generateB(4, 0, "");
}



// josephus problem kill all
void killAll(int n, int k, vecti &alive, int steps, int count)
{
  if (n == 1)
  {
    print(alive);
    return;
  }
  int ind = count % alive.size();
  if (steps % k == 0 && alive[ind] == 1)
  {
    // time to kill that punk
    alive[ind] = 0;
    killAll(n - 1, k, alive, 1, count + 1);
  }
  else if (alive[ind] == 0)
  {
    killAll(n, k, alive, steps, count + 1);
  }
  else
  {
    killAll(n, k, alive, steps + 1, count + 1);
  }
}


//we kill the ith index and then convert it into problem of n-1 with shifted indexes  
int killAll(int n, int k)
{
  if (n == 1)
    return 0;
  int ans = killAll(n - 1, k);
  return (ans + k) % n;
}


//print lexicographically 
void printLex(int n, string res)
{
  if (stoi(res) > n)
  {
    return;
  }
  cout << res << " ";
  for (int i = 0; i <= 9; i++)
  {
    res += to_string(i);
    printLex(n, res);

    res.pop_back();
  }
}


int main()
{
  int n = 8, k = 3;
  for (int i = 1; i <= 9; i++)
  {
    printLex(1000, to_string(i));
    cout << endl;
  }
}

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
  if (i < 0 || j < 0 || i >= mine.size() || j >= mine[0].size() || mine[i][j] == 0 || visited[i][j] == 1)
    return;
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

      if (mine[i][j] != 0 && visited[i][j] == 0)
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
  vecti_2d visited(m, vector<int>(n, 0));
  cout << findMaxGold(mine, visited, m, n);
}
