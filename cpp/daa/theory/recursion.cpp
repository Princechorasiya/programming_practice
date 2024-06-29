int f(int n)
{ // find the factorial
  if (n == 1)
    return 1;
  return n * f(n - 1);
}
void print(int n) // 54321
{
  if (n == 0)
    return;
  cout << n << " ";
  print(n - 1);
}
void print2(int n) // 12345
{
  if (n == 0)
    return;
  print2(n - 1);
  cout << n << " ";
}

void reachHome(int n)
{
  if (n == 0)
  {
    cout << "home sweet home" << endl;
    return;
  }
  cout << "home is " << n << " distance away" << endl;
  reachHome(n - 1);
}

void sayDigit(int n)
{
  if (n == 0)
    return;
  sayDigit(n / 10);
  cout << n % 10 << " ";
}

bool isSorted(vector<int> m, int s, int e) // 0 and vi.size()
{
  if (s == e || s == e - 1)
    return true;
  cout << m[s] << " " << m[s + 1] << endl;
  return m[s] < m[s + 1] && isSorted(m, s + 1, e);
}

bool isSorted(vector<int> m, int s, int e) // 0 and vi.size()
{
  if (s == e || s == e - 1)
    return true;
  cout << m[s] << " " << m[s + 1] << endl;
  return m[s] < m[s + 1] && isSorted(m, s + 1, e);
}

int sumArray(vector<int> v, int s, int e)
{ // return the sum of the array
  if (s == e - 1)

    return v[s];
  return v[s] + sumArray(v, s + 1, e);
}

int linearSearch(vector<int> &v, int s, int e, int target)
{
  // code to find out the index of target in arr using linear search

  if (s == e - 1)
  {
    if (v[s] == target)
      return s;
    return -1;
  }
  if (v[s] == target)
    return s;
  return linearSearch(v, s + 1, e, target);
}

int binarySearch(vector<int> &v, int s, int e, int target)
{
  // finds the element in array by using recursive binary search
  // base case
  if (s > e)
    return -1;
  int mid = s + (e - s) / 2; // cal mid
  if (v[mid] == target)      //
    return mid;
  else if (v[mid] < target)
    return binarySearch(v, mid + 1, e, target);
  else
    return binarySearch(v, s, mid - 1, target);
}

// reverse a string using recursion
void reverse1(string &input, string &output, int s, int e)
{
  // reverse the string recursive code
  if (s == e)
    return;
  reverse1(input, output, s + 1, e);
  output += input[s];
}
void reverse(string &input, int s, int e)
{
  // reverse the stirng inplace ;
  if (s > e)
    return;
  swap(input[s], input[e]);
  reverse(input, s + 1, e - 1);
}
int main()
{
  int n = 10;
  string input = "princechorasiya";
  string output = "";
  reverse1(input, output, 0, input.length());
  reverse(input, 0, input.length() - 1); // pass the last index where value exists
  cout << input << endl;
}

// check if hte stirng is palindrome
//  check if the stirng is palindrome
bool isPalindrome(string &input, int i) // single pointer approach
{
  int j = input.length() - i - 1; /// hte other pointer
  if (i > j)
    return true; // string of 0 length
  cout << input[i] << " " << input[j] << endl;
  return (input[i] == input[j]) && isPalindrome(input, i + 1);
}

// fast exponenation recursive
//  recursive fast exponentation
int fastExponetion(int a, int b)
{
  // a base b =power;
  if (b == 0)
    return 1; // base
  int x = fastExponetion(a, b / 2);
  if (b & 1)
  {
    // odd case x is odd
    return x * x * a;
  }
  else
  {
    return x * x;
  }
}
/// brute force using n*n(x-1);

// murge sort
void merge(vector<int> &v, int s, int mid, int e)
{
  // merge two sorted array
  int sizeL = mid - s + 1;
  int sizeR = e - mid;
  vector<int> left;
  vector<int> right;
  for (int i = s; i <= mid; i++)
  {
    left.push_back(v[i]);
  }
  for (int i = mid + 1; i <= e; i++)
  {
    right.push_back(v[i]);
  }
  int rightI = 0, leftI = 0;
  int index = s;
  while (rightI < sizeR && leftI < sizeL)
  {
    if (left[leftI] < right[rightI])
    {
      v[index++] = left[leftI++];
    }
    else
    {
      v[index++] = right[rightI++];
    }
  }
  while (rightI < sizeR)
  {
    v[index++] = right[rightI++];
  }
  while (leftI < sizeL)
  {
    v[index++] = left[leftI++];
  }
}
void mergeSort(vector<int> &v, int s, int e)
{
  // sort the array with merge sort
  if (s >= e)
    return;
  int mid = s + (e - s) / 2;
  mergeSort(v, s, mid);
  mergeSort(v, mid + 1, e);
  merge(v, s, mid, e);
  print(v);
}
int main()
{
  vector<int> v = {2};
  mergeSort(v, 0, v.size() - 1);

  print(v);
}

int partition(vector<int> &v, int s, int e)
{
  // partions the vector
  int pivot = v[s];
  int count = 0;
  for (int i = s + 1; i <= e; i++)
  {
    if (v[i] <= pivot)
      count++;
  }
  int pivotI = s + count;
  swap(v[s], v[pivotI]);
  int i = s, j = e;
  while (i<pivotI & j> pivotI)
  {
    while (v[i] < pivot)
      i++;
    while (v[j] > pivot)
      j--;
    if (i < pivotI && j > pivotI)
      swap(v[i++], v[j--]);
  }
  return pivotI;
}
void quickSort(vector<int> &v, int s, int e)
{
  if (s >= e)
    return; // array of sixe 1
  int p = partition(v, s, e);
  print(v);
  quickSort(v, s, p - 1);
  quickSort(v, p + 1, e);
}

int main()
{
  // code to implement quick sort

  vector<int> v = {3, 4, 2, 1, 7, 5, 4, 3};
  quickSort(v, 0, v.size() - 1);
  print(v);
}

// sort in reverse using quick sort

int partition(vector<int> &v, int s, int e)
{
  // partions the vector
  int pivot = v[s];
  int count = 0;
  for (int i = s + 1; i <= e; i++)
  {
    if (v[i] >= pivot)
      count++;
  }
  int pivotI = s + count;
  swap(v[s], v[pivotI]);
  int i = s, j = e;
  while (i<pivotI & j> pivotI)
  {
    while (v[i] > pivot)
      i++;
    while (v[j] < pivot)
      j--;
    if (i < pivotI && j > pivotI)
      swap(v[i++], v[j--]);
  }
  return pivotI;
}
void quickSort(vector<int> &v, int s, int e)
{
  if (s >= e)
    return; // array of sixe 1
  int p = partition(v, s, e);
  print(v);
  quickSort(v, s, p - 1);
  quickSort(v, p + 1, e);
}

int main()
{
  // code to implement quick sort

  vector<int> v = {3, 4, 2, 1, 7, 5, 4, 3};
  quickSort(v, 0, v.size() - 1);
  print(v);
}

// subsets

void solve(vector<int> v, vector<int> output, int index, vector<vector<int>> &ans)
{
  // base case
  if (index >= v.size())
  {
    ans.push_back(output);
    return;
  }

  // exclusion just increase the i
  solve(v, output, index + 1, ans);

  // inclusion take the element in theoutput and jo on
  output.push_back(v[index]);
  solve(v, output, index + 1, ans);
}
vector<vector<int>> subset(vector<int> v)
{
  vector<vector<int>> ans;
  vector<int> output;
  int index = 0;
  solve(v, output, index, ans);
  return ans;
}

// generate subseuence
void solve(string s, int index, string temp, vector<string> &ans)
{
  /// exclude one and include
  // base case
  if (index >= s.length())
  {
    if (temp.length() == 0)
      return;
    ans.push_back(temp);
    return;
  }

  // exclusion call
  solve(s, index + 1, temp, ans);
  temp.push_back(s[index]);
  solve(s, index + 1, temp, ans);
}
/// find teh subsequneces of a stirng
vector<string> subSeq(string s)
{
  // return the substrings of the strinng
  vector<string> ans;
  string temp = "";
  int index = 0;
  solve(s, index, temp, ans);
  return ans;
}

void solve(char c, string b, int index, vector<string> &ans, string temp)
{
  // for each pair inlcude the
  if (index >= b.length())
  {
    if (temp.length() == 0)
      return;
    return;
  }

  solve(c, b, index + 1, ans, temp);
  temp += c;
  temp += b[index];
  ans.push_back(temp);

  // solve(c, b, index + 1, ans, temp);
}

vector<string> findCombo(string a, string b)
{
  vector<string> ans;

  for (int i = 0; i < a.length(); i++)
  {
    int index = 0;
    string temp = "";
    solve(a[i], b, index, ans, temp);
  }
  return ans;
}

void solve(string digit, string output, int index, vector<string> &ans, vector<string> mapping)
{
  if (index >= digit.length())
  {
    ans.push_back(output);
    return;
  }
  int n = digit[index] - '0';
  // cout << n << endl;
  string value = mapping[n];
  for (int i = 0; i < value.length(); i++)
  {
    output.push_back(value[i]);
    solve(digit, output, index + 1, ans, mapping);
    output.pop_back();
  }
}
vector<string> keyCombos(string s)
{
  vector<string> ans;
  if (s.length() == 0)
    return ans;
  string output = "";
  int index = 0;
  vector<string> mapping = {"",
                            "",
                            "abc", "def", "ghi ", "jkl", "mno ", "pqrs ", "tuv", "wxyz"};
  solve(s, output, index, ans, mapping);
  return ans;
}

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
  // base case
  if (index >= nums.size())
  {
    ans.push_back(nums);
    print(nums);
    return;
  }
  for (int j = index; j < nums.size(); j++)
  {
    swap(nums[index], nums[j]);
    solve(nums, ans, index + 1);
    // backtrack
    swap(nums[index], nums[j]);
  }
}

// #permutations of a string

vector<vector<int>> generatePermutation(vector<int> nums)
{
  vector<vector<int>> ans;
  // generate all permutations
  int index = 0;
  solve(nums, ans, index);
  return ans;
}

// rat in maze get this rat a path out of the maze

bool isSafe(vector<vector<int>> &maze, vector<vector<int>> &visited, int x, int y)
{
  if ((x >= 0 && x <= maze.size() - 1) && (y >= 0 && y <= maze.size() - 1))
  {
    if ((maze[x][y] == 1) && (visited[x][y] == 0))
    {
      return true;
    }
    return false;
  }
  return false;
}

// find the path in the maze rat maze problem
void solve(vector<string> &ans, vector<vector<int>> maze, string path, int x, int y, vector<vector<int>> &visited)
{
  // base case
  if ((x == maze.size() - 1) && (y == maze.size() - 1))
  {
    ans.push_back(path);
    return;
  }
  visited[x][y] = 1;

  // check the upper direction
  if (isSafe(maze, visited, x - 1, y))
  {
    x -= 1;
    visited[x][y] = 1;
    path += "u";
    solve(ans, maze, path, x, y, visited);
    path.pop_back();
    visited[x][y] = 0;
    x += 1;
  }
  // right dir
  if (isSafe(maze, visited, x, y + 1))
  {
    y += 1;
    visited[x][y] = 1;
    path += "r";
    solve(ans, maze, path, x, y, visited);
    path.pop_back();
    visited[x][y] = 0;
    y -= 1;
  }
  // down dir

  if (isSafe(maze, visited, x + 1, y))
  {
    x += 1;
    visited[x][y] = 1;
    path += "d";
    solve(ans, maze, path, x, y, visited);
    path.pop_back();
    visited[x][y] = 0;
    x -= 1;
  }
  // left dir
  if (isSafe(maze, visited, x, y - 1))
  {
    y -= 1;
    visited[x][y] = 1;
    path += "l";
    solve(ans, maze, path, x, y, visited);
    path.pop_back();
    visited[x][y] = 0;
    y += 1;
  }

  visited[x][y] = 0;
}
vector<string> getThisRatAPath(vector<vector<int>> v)
{
  vector<string> ans;
  string path = "";
  int x = 0, y = 0;
  int n = v.size();
  vector<vector<int>> visited(n, vector<int>(n, 0));
  print(v);
  solve(ans, v, path, x, y, visited);
  return ans;
}