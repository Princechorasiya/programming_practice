#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    // set<vector<int>> s;
    helper(candidates, {}, ans, target, 0);
    class Solution
    {
    public:
      vector<vector<int>> combinationSum3(int k, int n)
      {
        set<vector<int>> s; // set to store the elements;
        helper(s, {}, k, n, 1);
        vector<vector<int>> v(s.begin(), s.end());
        return v;
      }

      void helper(set<vector<int>> &s, vector<int> res, int k, int n, int ind)
      {
        if (k == 0)
        {
          if (n == 0)
          {
            s.insert(res);
          }
          return;
        }
        if (n < 0)
          return;
        for (int i = ind; i <= 9; i++)
        {
          res.push_back(i);

          helper(s, res, k - 1, n - i, i + 1);

          res.pop_back();
        }
      }
    };

    return ans;
  }

  void helper(vector<int> &arr, vector<int> ans, vector<vector<int>> &res, int sum, int ind)
  {
    if (sum == 0)
    {

      res.push_back(ans);
      return;
    }
    if (ind == arr.size())
      return;
    if (sum < 0)
      return;
    for (int i = ind; i < arr.size(); i++)
    {
      if (i > ind && arr[i] == arr[i - 1]) //skip the duplicates 
      {
        continue;
      }

      ans.push_back(arr[i]);
      helper(arr, ans, res, sum - arr[i], i + 1);
      ans.pop_back();
    }
  }
};
int main(){
}


//combination sum 3
class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    set<vector<int>> s; // set to store the elements;
    helper(s, {}, k, n, 1);
    vector<vector<int>> v(s.begin(), s.end());
    return v;
  }

  void helper(set<vector<int>> &s, vector<int> res, int k, int n, int ind)
  {
    if (k == 0)
    {
      if (n == 0)
      {
        s.insert(res);
      }
      return;
    }
    if (n < 0)
      return;
    for (int i = ind; i <= 9; i++)
    {
      res.push_back(i);

      helper(s, res, k - 1, n - i, i + 1);

      res.pop_back();
    }
  }
};