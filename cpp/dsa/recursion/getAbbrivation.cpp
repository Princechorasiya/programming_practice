#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

void getAbbrivation(string s, string ans, int ind, int count)
{
  if (ind ==s.length())
  {
    if(count!=0){
      cout << ans + to_string(count) << endl;
    }else {

    cout << ans << endl;
    }
    return;
  }
  string t = ans;
  if (count != 0)
  {
    t += to_string(count);
  }
  getAbbrivation(s, t + s[ind], ind + 1,  0);
  getAbbrivation(s, ans , ind + 1, count+1);
}

int main()
{

  getAbbrivation("pep", "", 0, 0);
}