#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

int main(){
}
bool isPossible(string s1, string s2, string s3, vecti &ans, map<char, int> &m)
{

  int lhs = 0, rhs = 0;
  for (auto i : s1 + s2)
  {
    lhs += ans[m[i]];
  }
  for (auto i : s3)
  {
    rhs += ans[m[i]];
  }

  return lhs == rhs;
}
void generateAns(string &s1, string &s2, string &s3, vecti &ans, map<char, int> &m, vecti &arr, vecti &visited, int ind)
{
  if (ind == arr.size()) //the problem with this is we are not sure that there are only 10 unique character 
  {
    if (isPossible(s1, s2, s3, ans, m))
    {
      for (auto [k, v] : m)
      {
        cout << k << " " << ans[m[k]] << endl;
      }
    }
    return;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    if (visited[i] == 0)
    {
      visited[i] = 1;
      int ele = arr[i];
      ans.push_back(ele);
      generateAns(s1, s2, s3, ans, m, arr, visited, ind + 1);
      ans.pop_back();
      visited[i] = 0;
    }
  }
}
void crypticA(string s1, string s2, string s3)
{
  map<char, int> m; // pair the character with indexes
  for (auto i : s1 + s2 + s3)
  {
    m[i] = 0;
  }
  int count = 0;
  for (auto &[k, v] : m)
  {
    m[k] = count++;
  } /// assign indexes to the values

  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vecti ans;
  vecti visited = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  generateAns(s1, s2, s3, ans, m, arr, visited, 0);
}



//back tracking approach
#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

// generate all permutations of a string

// crypt arithmetic

bool isPossible(string s, int n, map<char, int> &m)
{

  int lhs = 0, rhs = 0;
  for (int i = 0; i < n; i++)
  {
    lhs += m[s[i]];
  }
  for (int i = n; i < s.length(); i++)
  {
    rhs += m[s[i]];
  }

  return lhs == rhs;
}

void generateAns(string &s1, string &unq, map<char, int> &m, int ind, vecti &visited, int n)
{

  if (ind == unq.size())
  {
    // checked code for all a
    if (isPossible(s1, n, m))
    {
      // print hte characters
      for (auto [k, v] : m)
      {
        cout << k << " -> " << v << ";";
      }
      cout << endl;
    }
    return;
  }
  for (int i = 0; i <= 9; i++)
  {
    if (visited[i] == 0)
    {
      m[unq[ind]] = i;
      visited[i] = 1;
      generateAns(s1, unq, m, ind + 1, visited, n);
      visited[i] = 0;
      m[unq[ind]] = -1;
    }
  }
}
void crypticA(string s1, string s2, string s3)
{
  // extract the unique characters
  map<char, int> m;
  for (auto i : s1 + s2 + s3)
  {
    m[i] = -1;
  }
  vecti visited(10, 0);
  string new_s = s1 + s2 + s3;
  string unq = "";
  for (auto [k, v] : m)
  {
    unq += k;
  }
  cout << unq << endl;
  generateAns(new_s, unq, m, 0, visited, s1.length() + s2.length() - 1);
}
int main()
{
  crypticA("send", "more", "money");
}
