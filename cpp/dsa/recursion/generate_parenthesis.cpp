#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    helper(ans, n, n, n, "");

    return ans;
  }

  bool isValid(string res)
  {
    stack<char> s;
    for (int i = 0; i < res.size(); i++)
    {
      if (s.empty() && res[i] == ')')
        return false;
      if (res[i] == '(')
      {
        s.push('(');
      }
      else if (res[i] == ')')
      {
        if (!s.empty() && s.top() == '(')
        {
          s.pop();
        }
        else
        {
          return false;
        }
      }
    }
    return s.empty();
  }
  void helper(vector<string> &ans, int n, int left, int right, string res)
  {
    if (left == 0 && right == 0)
    {
      if (isValid(res))
      {
        ans.push_back(res);
      }
      return;
    }

    if (left > 0)
      helper(ans, n, left - 1, right, res + "(");
    if (right > 0)
      helper(ans, n, left, right - 1, res + ")");
  }
};

//keep track of left and right track 