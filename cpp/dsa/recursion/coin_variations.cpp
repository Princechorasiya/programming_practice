#include <bits/stdc++.h>
using namespace std;

using vecti = vector<int>;

// single coin use but using for loop
// single time use coin combination

int sing_coin(vector<int> &v, int ind, int tar)
{
  // sub sequence method //include one and exclude other
  if (tar == 0)
    return 1;
  if (ind == -1)
    return 0;
  int ans = 0;

  if (v[ind] <= tar)
  {
    ans += sing_coin(v, ind - 1, tar - v[ind]);
  }
  ans += sing_coin(v, ind - 1, tar);
  return ans;
}

int sing_coin(vecti &v, int ind, int tar)
{
  if (tar == 0)
    return 1;
  int ans = 0;
  for (int i = ind; i < v.size(); i++)
  {
    if (v[i] <= tar)
    { // check before calling
      ans += sing_coin(v, i + 1, tar - v[i]);
    }
  }
  return ans;
}
// infinite time use combination

int inf_coin(vecti &v, int ind, int tar)
{
  // by subsequence
  if (tar == 0)
    return 1;

  if (ind == -1)
    return 0;
  int ans = 0;
  if (v[ind] <= tar)
  {
    ans += inf_coin(v, ind, tar - v[ind]);
  }
  ans += inf_coin(v, ind - 1, tar);
  return ans;
}

// infinite sum for loop

//  single time use permutation
int sing_coin(vector<int> v, int tar)
{ // permutation

  int ans = 0;
  if (tar == 0)
    return 1;

  for (int i = 0; i < v.size(); i++)
  {
    vecti new_v(v.begin(), v.begin() + i);
    for (int j = i + 1; j < v.size(); j++)
    {
      new_v.push_back(v[j]);
    }

    if (v[i] <= tar)
      ans += sing_coin(new_v, tar - v[i]);
  }
  return ans;
}
//  infinite time use permutation
int inf_coin(vector<int> v, int tar)
{ // permutation //can be done with subseuqence ?

  int ans = 0;
  if (tar == 0)
    return 1;

  for (int i = 0; i < v.size(); i++)
  {

    if (v[i] <= tar)
      ans += inf_coin(v, tar - v[i]);
  }
  return ans;
}