#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

// generate all permutations of a string
void generateP(string s, string res)
{
  if (s == "")
  {
    cout << res << endl;
    return;
  }
  for (int i = 0; i < s.length(); i++)
  {
    auto c = s[i];
    string new_s = s.substr(0, i) + s.substr(i + 1);
    generateP(new_s, s[i] + res);
  }
}

void generateP(vector<int> &arr, int ind, vecti &visited, vector<int> ans)
{
  if (ind == arr.size())
  {
    print(ans);
    return;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    if (visited[i] == 0)
    {
      visited[i] = 1;
      int ele = arr[i];
      ans.push_back(ele);
      generateP(arr, ind + 1, visited, ans);
      ans.pop_back();
      visited[i] = 0;
    }
  }
}
int main()
{
  generateP("abc", "");
  vector<int> arr = {1, 2, 3};
  vector<int> visited = {0, 0, 0};
  generateP(arr, 0, visited, {});
}
