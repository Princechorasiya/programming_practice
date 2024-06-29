#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> ans;
    helper(candidates, {}, ans, target, 0);
    return ans;
  }
  void helper(vector<int> &arr, vector<int> ans, vector<vector<int>> &res, int sum, int i)
  {
    if (i >= arr.size())
    {
      if (sum == 0)
      {
        res.push_back(ans);
      }
      return;
    }
    if (sum < 0)
      return;
    // include the
    ans.push_back(arr[i]);
    helper(arr, ans, res, sum - arr[i], i);
    ans.pop_back();
    // exclude this
    helper(arr, ans, res, sum, i + 1);
  }
};
int main()
{
  Solution s;
  vector<int> arr = {2, 3, 6, 7};
  print(s.combinationSum(arr, 7));
}

int main(){
}

