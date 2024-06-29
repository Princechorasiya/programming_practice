#include <bits/stdc++.h>
using namespace std;

int main()
{
  char name[20];
  cin >> name; // limitation of cin takes input till space only
  name[2] = 'a';
  cout << name << endl; /////pr stops after encountering first null
}

// find the length of the string
int getLength(char arr[])
{
  int i = 0;
  while (arr[i++] != '\0')
    ;
  return i - 1;
}
// reverse the string

// cehck if the astringis palindrome
void isPalindrome(char arr[])
{
  // same logic
  int l = getLength(arr);
  int s = 0, e = l - 1;
  int flag = 0;
  while (s < e)
  {
    if (arr[s] != arr[e])
    {
      flag = 1;
      break;
    }
    s++, e--;
  }
  if (flag)
  {
    cout << "strins is not palindrome " << endl;
  }
  else
    cout << "string is palindrome" << endl;
}
// convert the character to lower case
char convertLower(char ch)
{
  if (ch >= 'a' && ch <= 'z')
    return ch;
  else
    return ch - 'A' + 'a';

  // ch ='1' ch -'0' =1
}

////2-d array
#include <bits/stdc++.h>
using namespace std;

/// create 2d array take input and print hte output
int main()
{
  // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // hard code the vlaue
  int arr2[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  int arr[3][4];
  /*
  for (int i = 0; i < 3; i++) // row wise input
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> arr[i][j];
    }
  }
  */

  // take columns wise input
  /*for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> arr[i][j];
    }
  }*/
  // print the array in wave form
  for (int i = 0; i < 4; i++)
  {
    if (i % 2 == 0)
    {
      // top to down
      for (int i = 0; i < 3; i++)
      {
        cout << arr[]
      }
    }
    else
    {
      // down to up
    }
  }
}
// 1 2 3 4 5 6 7 8 9 10 11 12

// print the array in sprial form
void printA(vector<vector<int>> v)
{
  // print the spiral
  int rows = v.size();
  int cols = v[0].size();
  int fow = 0, back = rows - 1, down = cols - 1, up = 0;
  while (fow <= back)
  { // we can use count to store printed value and exit when we have printed all values row *col
    for (int i = up; i <= down; i++)
    {
      cout << v[fow][i] << " ";
    }
    for (int i = fow + 1; i < back; i++)
    {
      cout << v[i][down] << " ";
    }
    for (int i = down; i > up; i--)
    {
      cout << v[back][i] << " ";
    }
    for (int i = back; i > fow; i--)
    {
      cout << v[i][up] << " ";
    }
    fow++, back--, up++, down--;
  }
}
// something similar but does not work always

// workd for all
class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &v)
  {
    int rows = v.size();
    int cols = v[0].size();
    int startR = 0, endR = rows - 1;
    int startC = 0, endC = cols - 1;
    int count = 0, total = rows * cols;
    vector<int> ans;
    while (total > count)
    {
      for (int i = startC; i <= endC && total > count; i++)
      {
        ans.push_back(v[startR][i]);
        count++;
      }
      startR++;

      for (int i = startR; i <= endR && total > count; i++)
      {
        ans.push_back(v[i][endC]);
        count++;
      }
      endC--;
      for (int i = endC; i >= startC && total > count; i--)
      {
        ans.push_back(v[endR][i]);
        count++;
      }
      endR--;
      for (int i = endR; i >= startR && total > count; i--)
      {
        ans.push_back(v[i][startC]);
        count++;
      }
      startC++;
    }
    return ans;
  }
};

vector<vector<int>> result(n, vector<int>(n)); // creating a two dimensional matrix on spot

// check prime number in range n
class Solution
{
public:
  int countPrimes(int n)
  {
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
      if (prime[i])
      {
        cnt++;

        for (int j = 2 * i; j < n; j += i)
        {
          prime[j] = false;
        }
      }
    }
    return cnt;
  }
};

// iterative gcd int gcd(int a, int b)
{
  if (a == 0)
    return b;
  if (b == 1)
    return a;
  while (a != b)
  {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

// fast exponentation
int fastExpo(int x, int n, int m)
{
  int res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = (1LL * (res * x % m)) % m;

    x = (1LL * x % m * x % m) % m;
    n = n >> 1;
  }
  return res;
}

// strings
string substr(string s, int st, int len)
{ // generate sssubstring
  string ans = "";
  for (int i = st; i < st + len; i++)
  {
    ans += s[i];
  }
  return ans;
}
int main()
{
  string s = "prince";
  for (int i = 0; i < s.length(); i++)
  { // generate all substrings

    for (int j = 1; j <= s.length() - i; j++)
    {
      cout << substr(s, i, j) << endl;
    }
  }
}

string s = "prince";
for (int i = 0; i < s.length(); i++)
{
  string s1 = "";
  for (int j = i; j < s.length(); j++)
  {
    s1 += s[j]; // generates all substrings
    cout << s1 << endl;
  }
}

int main()
{
  // create 2d array
  int n;
  cin >> n;
  int **arr = new int *[n]; // #creating rows
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n]; /// eachrow poointer pointing to new array allocated dynamically
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;
}


//extra theory 
// c style strings use '\0' as terminating character

#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main1()
{
  char s[] = "Gees";
  cout << s << endl;
  return 0;
}

// string class
int main2()
{
  string str("geeks");
  cout << str;

  string str1(3, 'h');
  cout << str1;
  // declare either using string or using c style string

  return 0;
}

// input as strings
// using cin
int main3()
{
  string s;
  cin >> s;
  cout << s;
  string t;
  getline(cin, t); // gets teh '\n'of the previous line
  getline(cin, t);
  cout << "t = " << t;

  // use of string stream

  return 0;
}

int main4()
{
  string s = "ggjhfskjf jgsfkh adlaj";
  stringstream obj(s);
  string temp;

  while (obj >> temp)
  {
    cout << temp << endl;
  }
  return 0;
}

// passing strings to functions

void print_string(string s)
{
  cout << "Passed string is: " << s << endl;
  return;
}
int main5()
{
  string s = "gfs";
  print_string(s);
  return 0;
}

/// pointer adn string
int main6()
{
  string s = "gerkskfj";
  char *p = &s[0]; // pointer to string correct way

  while (*p != '\0')
  {
    cout << *p;
    p++;
  }
  cout << endl;
}

// functions
// length();
// shrink_to_fit();
// swap();      //
// size();      //
// resize();    //
// find();      //
// push_back(); //
// pop_back();  //
// clear();     //
// strncmp();   // compare first n characters
// strncpy();   // copy first n characters
// strrchr();   // locates teh last occurence of char in the string

// strcat();
// substr();
// compare(); // returns int
// erase();   // delete form certain pos

// iterators
// begin();
// end();
// rfind();
// rbegin();
// rend();
// cbegin();
// cend();
// crbegin();
// crend();

int main23()
{
  string ::iterator itr;
  string ::reverse_iterator rit;

  string s = "gfdsdf";
  itr = s.begin();

  cout << "Point to fist " << *itr << endl;

  itr = s.end() - 1; // last +1-1

  cout << "last " << *itr << endl;

  rit = s.rbegin();

  cout << "last char : " << *rit << endl;

  rit = s.rend() - 1;
  cout << "first char: " << *rit << endl;
  return 0;
}

// #include <string> //has the string class

int main2324()
{
  string str = "gfdgdgsfgs";

  string::iterator it;

  string::reverse_iterator it1;

  cout << "Str: " << str << "\n";

  cout << "forward iterator: " << endl;

  for (it = str.begin(); it != str.end(); it++)
  {
    if (it == str.begin())
      *it = 'G';

    cout << *it;
  }
  cout << endl;
  cout << "reverse iterator: " << endl;

  for (it1 = str.rbegin(); it1 != str.rend(); it1++)
  {
    if (it1 == str.rbegin())
      *it1 = 'S';
    cout << *it1;
  }
  cout << endl;
  // similary u can use const pointers but the modifications are not allowed
}

int main94039()
{
  string str1 = "ahjdhkjcbnbveiqruoei";
  string str2 = "fgkslfjg;lsn jghsfj";

  char ch[80];

  str1.copy(ch, 13, 0); // target char array len pos
  cout << "new array: " << ch << endl;
  cout << "str1: " << endl;
  cout << str1 << endl;
  cout << "str2: " << endl;
  cout << str2 << endl;

  str1.swap(str2);

  cout << "str1<< " << str1 << " str2<< " << str2 << endl;
}

// creating array if strings
void pointers()
{
  const char *color[4] = {"blue", "red", "oreange", "yellow"};

  for (int i = 0; i < 4; i++)
    cout << color[i] << endl;
  return;
}

// using 2d arrays
void twodArr()
{
  char color[4][10] =
      {"blue", "Red", "orange", "yellow"};

  for (int i = 0; i < 3; i++)
  {
    cout << color[i] << endl;
  }
}

// using stirng class

void strings()
{
  string color[4] = {"r", "g", "b", "g"};

  for (int i = 0; i < 4; i++)
    cout << color[i] << endl;
}

// using vectors  vector<string> v;
// suign array array<string,4>

// concatenating strings

// s1.append(s2);
// using + operator
// strcat() // c style characters
// using for loops

// using inhertience
class base
{
protected:
  virtual string concatenate(string &str1, string &str2) = 0;
};

class derive : protected base
{
public:
  string concatenate(string &str1, string &str2)
  {
    string temp;
    temp = str1 + str2;
    return temp;
  }
};

int mainireoi()
{
  // derive obj;
  // obj.concatenate(init, add);
  return 0;
}

// friend functions and strcat

// tokenizing a string
// spliting a stirng according to a dleimeiter

int maineruutoier()
{
  string line = "gksgjkls,kfjlsk,skjfgk ]:kfgsklj kjfgkls";

  vector<string> tokens;
  stringstream check1(line); // converting a stirng into tokens
  string intermediate;

  while (getline(check1, intermediate, ','))
  {
    tokens.push_back(intermediate);
  }

  for (int i = 0; i < tokens.size(); i++)
  {
    cout << tokens[i] << endl;
  }
}
// o(N) me kam hogaya

int delimit()
{
  char str[] = "geeks=for=geeks";
  char *token = strtok(str, "-"); // works for c sytle string

  while (token != NULL)
  {
    cout << *token;
    token = strtok(NULL, '-');
  }
}

// substrings
// string substr(size_t pos, size_t len) const;
int main()
{
  string s1 = "geeks";

  string r = s1.substring(3, 2); // pso greater than length throw out_of_range

  cout << "string is :" << r;
  return 0;
}

int after()
{
  string s = "dig:fkdjg";
  int pos = s.find(":");
  string sub = s.substr(pos + 1); // after the char

  string sub1 = s.substr(0, pos); // before the char

  cout << "string is : " << sub;
}

int print_all()
{
  string s;
  int n; // size of stirng
  for (int i = 0; i < n; i++)
  {
    for (int i = 1; len <= n - i; len++)
      cout << s.substr(i, len) << endl;
  }
}
// o(n3)

// sum_all repreeenting a number
int todigit(char ch)
{
  return (ch - '0');
}

int sumOfSubstrings(string num)
{
  int nn = num.length();
  int sumofdigit[n];
  sumofdigit[0] = todigit(num[0]);
  int res = sumofdigit[0];

  for (int i = 1; i < n; i++)
  {
    int numi = toDigit(num[i]);

    sumofdigit[i] = (i + 1) * numi + 10 * sumofdigit[i - 1];

    res += sumofdigit[i];
  }
  return res;
}

// max value of all substrings representing a number

void subStr_max(string s, int n)
{
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    for (int len = 1; len <= n - 1; len++)
    {
      string sub = (s.substr(i, len));
      int x = stoi(sub);
      v.push_back(x);
    }
  }
  cout << *max_element(v.begin(), v, end());
  cout << *min_element(v.begin(), v, end());
}
// min value of all substring representing a
