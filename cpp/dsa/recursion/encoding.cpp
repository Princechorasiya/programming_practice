#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vecti_2d = vector<vector<int>>;

// prepare a vector of 26 ascii value

void getEncoding(string s, vector<char> &alp, string ans)
{
  if (s.length() == 0)
  {
    cout << ans << endl;
    return;
  }
  if (s[0] == '0')
    return;
  int i = 0;
  string t = "";
  while (i < s.length())
  {
    t += s[i];
    i++;
    int num = stoi(t);
    if (num <= 26)
    {
      string rest = s.substr(i);
      getEncoding(rest, alp, ans + alp[num - 1]);
    }
    else
    {
      break;
    }
  }
}

int main()
{
  vector<char> alp(26);
  for (int i = 0; i < 26; i++)
  {
    alp[i] = 'a' + i;
  }
  // print(alp);
  string s = "102";

  getEncoding(s, alp, "");
}