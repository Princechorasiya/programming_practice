// stored at contiguous memory location  same type

#vector uses and functions
// vector dynamic array with the ability to resize themselves
// vector header file

// vector<int> v;
// methods
// v.begin()//first element iterator
// v.end() //last element iterator +!
v.rbegin(); // last element
v.rend();   // first ele -1
v.cbegin(); // const begin +1
v.cend();   // constant end  +1
// v.crbegin()
// v.crend()

// related to capacity

v.size();
v.max_size(); // max size vector can hold
v.capacity(); //
v.resize(n);
v.empty();
v.shrink_to_fit();
v.reserve(n); // at least have n elements in the vector

// element access
v[];
v.at(g); // refrence to that element
v.front();
v.back();
v.data(); // pointer to memory array used by the vector

// modifiers
v.assign(v2);
v.push_back();
v.pop_back();
v.insert(pos, val);
v.erase(pos);
v.swap(v2);
v.clear(); // clear the entire array
v.emplace(pos, value);
v.emplace_back();

v1 = v2; // copy all the values in vector 2 to v1

vector<vector<int>> v; // 2d vector

// use reverse of algorithm to reverse the vector

// finding he element
// find(v.begin(),v.end(),val)
s
    // the arrays have fixed size
    // decleration
    // int arr[5];
    // char arr[10];
    // float arr[20];

    // why
    // one d array
    // int nums[5];
    int nums[5][10]; // 2 d arrays
// 3d array
int nums[5][10][2];

// ways to access
// for(double const &n:num)
// arr[i]
// *(arr + i);
// i[a] as well

// why does acess take o(1) because they are stored in coninous manner all operations are arithmetic

// unsorted

// inserting at end of the array
#include <iostream>
using namespace std;
int main()
{
  int n = 4;
  int arr[10] = {1, 2, 3, 4, 5};
  int val = 6;

  n++;
  arr[n] = val;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
  }

  // inserting in sorted array
}

// #insert any position
#include <bits/stdc++.h>

using namespace std;
void insertElement(int arr[], int n, int x, int pos)
{
  for (int i = n - 1; i >= pos; i--)
    arr[i + 1] = arr[i];

  arr[pos] = x;
}

// inserting element in sorted array
int insertSorted(int arr[], int n, int x, int capacity)
{
  if (n >= capacity)
    return n;

  int i;

  for (i = n - 1; (i >= 0 && arr[i] > key); i--)
    arr[i + 1] = arr[i];

  arr[i + 1] = key;
  return (n + 1);
}

// searching in a array
// linear search on unosrted array /
int linearUnsorted(int arr[], int n, int target)
{
  int i;

  for (i = 0; i < n; i++)
    if (arr[i] == target) // if found
      return i;

  return -1; // not found
}

// linear seach in sorted
// most trivail method for a sorted array
int linearSorted(int arr[], int n, int target)
{
  int i;
  for (int i = 0; i < n; i++)
    if (arr[i] == target) // found
      return i;

  return -1; // not found
}

// binary search o(log n)

// iterative approach o(1) space o(log n)//time
int binarySearch(int arr[], int n, int target) // n is the size not the last index
{                                              // we can take high low as parameters as well
  int low = 0, high = n - 1;

  int mid = low + (high - low) / 2;
  while (low < high)
  {
    if (arr[mid] == target)
      return mid;
    if (target > arr[mid])
      low = mid + 1;
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}
// recursive approach
// o(log n) space for recursive
int binarySearchR(int arr[], int n, int low, int high, int target)
{
  if (high < low)

    return -1;

  int mid = low + (high - low) / 2;

  if (arr[mid] == target)
    return mid;
  if (target > arr[mid])
    return binarySearchR(arr, n, mid + 1, high, target);

  return binarySearchR(arr, n, low, mid - 1, target);
}

// deleting array elements
// unsorted perform linear search and delete

int deleteUnsorted(int arr[], int n, int target) // returns size
{
  int pos = linearUnsorted(arr, n, target);

  if (pos == -1) // not found
  {
    cout << "Element not found: ";
    return n;
  }
  int i;
  for (i = pos; i < n - 1; i++)
    arr[i] = arr[i + 1];
  return n - 1;
}

// delete array when sorted
// returns new size

// time o(N) space o(1) or o(log n) iterative /recursive
int deleteSorted(int arr[], int n, int target)
{
  // find pos
  int pos = binarySearch(arr, n, target);
  if (pos == -1) // not found
  {
    cout << "Not in teh array";
    return n;
  }
  int i;
  for (i = pos; i < n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  return n - 1;
}

// #insert any position
#include <bits/stdc++.h>

using namespace std;
void insertElement(int arr[].int n, int x, int pos)
{
  for (int i = n - 1; i >= pos; i--)
    arr[i + 1] = arr[i];

  arr[pos] = x;
}

// inserting element in sorted array
int insertSorted(int arr[], int n, int x, int capacity)
{
  if (n >= capacity)
    return n;

  int i;

  for (i = n - 1; (i >= 0 && arr[i] > key); i--)
    arr[i + 1] = arr[i];

  arr[i + 1] = key;
  return (n + 1);
}

#include <bits/stdc++.h>
using namespace std;
// selection sort

// select the smallest element and add it to sorted portion
// select smallest and swap it with first of unsorted part
// iterative
void selection_sort(int arr[], int n)
{
  // find min
  //  swap

  int i, j, min_index;
  for (i = 0; i < n - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_index])
        min_idx = j;
    }

    if (min_idx != i)
      swap(arr[min_idx], arr[i]);
  }
}
void printArray(int arr[], int n)
{
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
}

// small data set
// unstable
// o(n2) and o(1)

// recursive
int minIndex(int a[], int i, int j)
{
  if (i == j)
    return i;
  // min of remaining array
  int k = minIndex(a, i + 1, j);

  // return min of current and remaining
  return (a[i] < a[k]) ? i : k;
}

// O(n2) and  O(n) in all cases
void recursive_sort(int arr[], int n, int index = 0)
{
  if (index == n)
    return;
  int k = minIndex(a, index, n - 1);

  if (k != index)
    swap(a[k], a[index]);

  recursive_sort(a, n, index + 1);
}

// stable selection sort element with same value appear in the same order
// o(n2) o(1) algo
void stableSelectionSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {

    int min = i;
    for (int j = i + 1; j < n; j++)
      if (a[min] > a[j])
        min = j;

    int key = a[min];             // move the min element to i
    for (int k = min; k > i; k--) // shift left
      a[k] = a[k - 1];
    a[i] = key;
  }
}

// selection sort of linked list
void selection_sortLL(node *head)
{
  node *temp = head;

  while (temp)
  {
    node *min = temp; // min
    node *r = temp->next;

    while (r)
    {
      if (min->data > r->data)
        min = r; // find min
      r = r->next;
    }
    // swap elements

    int x = temp->data;
    temp->data = min->data;
    min->data = x;
    temp = temp->next; // move to next node
  }
}
// improving selection sort /
// keep track of minimum as well as maximum and swap both

void minMaxSelectionSort(int arr[], int n)
{
  for (int i = 0, j = n - 1; i < j; i++, j--)
  {
    int min = arr[i], max = arr[i];
    int min_i = i, max_i = i;

    for (int k = i; k <= j; k++)
    {
      if (arr[k] > max)
      {
        max = arr[k];
        max_i = k;
      }
      else if (arr[k] < min)
      {
        min = arr[k];
        min_i = k;
      }
    }
    // shift the mni
    swap(arr[i], arr[min_i]);

    if (arr[min_i] == max)
      swap(arr[j], arr[min_i]);
    else
      swap(arr[j], arr[max_i]);
  }
}

// bubble sort
// swap teh elements if they are  in wrong order
// after each loop the largest element is moved to the right
#include <bits/stdc++.h>
using namespace std;
// O(n2) O(1) (best case n )
// stable sorting algo

void bubbleSort(int arr[], int n)
{
  int i, j;
  bool swapped;

  for (i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j] << arr[j + 1]);
        swapped = true;
      }
    }
    // no swap already false
    if (swapped = false)
      break;
  }
}

// recursive bubble sort
// base case
// size 1 return
// do one pass ->fixes teh laset element of the array
// recur for other

// o(N2) and O(n)
void recursiveBubbleSort(int arr[], int n)
{
  if (n == 1) // base case
  {
    return;
  }

  int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    // one pass done largest fixed now we go n-1 size
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
      count++;
    }

    if (count == 0)
      return;
    // last element is fixed
    recursiveBubbleSort(arr, n - 1);
  }
}

// bubble sort for linked list
struct Node
{
  int data;
  struct Node *next
} Node;

struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
  struct Node *tmp = ptr2->next;
  ptr2->next = ptr1;
  ptr1->next = tmp;
  return ptr2;
}

int bubbleSort(struct Node **head, int count)
{
  struct Node **h;
  int i, j, swapped;

  for (i = 0; i <= count; i++)
  {
    h = head;
    swapped = 0;

    for (j = 0; j < count - i - 1; j++)
    {
      struct Node *p1 = *h;
      struct Node *p2 = p1->next;

      if (p1->data > p2->data)
      {
        *h = swap(p1, p2);
        swapped = 1;
      }

      h = &(*h)->next;
    }

    if (swapped == 0)
      break;
  }
}

// without loops use recursion
// if 1 element print array
// if two element swap if necessary else print

// store first two elements from current array into vars a ,b

// initalise an array bs[] for remaining array
// place smaller at front place

// recurse this step by appending larger one to end of the bs array
//  soreted array in res[] b
// now recurse the above with a new array(res.size -1)

vector<int> bubble_sort(vector<int> ar)
{

  // base case
  if (ar.size() <= 1)
    return ar;
  if (ar.size() == 2)
  {
    if (ar[0] < ar[1])
      return ar;
    else
      return {ar[1], ar[0]};
  }
  // first two element in ca var

  int a = ar[0];
  int b = ar[1];

  vector<int> bs;
  // rest in bs

  for (int i = 2; i < ar.size(); i++)
    bs.push_back(ar[i]);

  // list after each call
  vector<int> res;

  if (a < b)
  {
    vector<int> temp1;
    temp1.push_back(b); // larger one
    for (itn i = 0; i < bs.size(); i++)
      temp1.push_back(bs[i]);

    vector<int> v = bubble_sort(temp1);
    v.insert(v.begin(), a);
    res = v;
  }
  else
  {
    vector<int> temp1;  // have local scope so cannot be used outside
    temp1.push_back(a); // larger one

    for (int i = 0; i < bs.size(); i++)
    {
      temp1.push_back(bs[i]);
    }
    vector<int> v = bubble_sort(temp1);
    v.insert(v.begin(), b);
    res = v;
  }

  vector<int> pass;
  for (int i = 0; i < res.size() - 1; i++)
    pass.push_back(res[i]);

  vector<int> ans = bubble_sort(pass);
  ans.push_back(res[res.size() - 1]);
  return res;
}

// bubble sort on stack
// learn later

// insertion sort
// split into two parts sorted and unsorted
// pick from unsorted and insert at correct pos in sorted part

// all O(n2) and O(1)

void insertionSort(int arr[], int n)
{
  int i, key, j;

  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    // move elements greater than arr[0..i-1] greater than key

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// binary insertion sort
// stable filtering algo

// a[i] in var key
// iterate for second element to last element
// find the position just greater than a[i]
// in a[0] to a[i-1]  using binary search

int binarySearch(int arr[], int item, int low, int high)
{
  if (high <= low)
    return (item > a[low]) ? (low + 1) : low;

  int mid = (low + high) / 2;
  if (item == a[mid])
    return mid + 1;

  if (item > a[mid])
    return binarySearch(a, item, mid + 1, high);

  return binarySearch(a, item, low, mid - 1);
}

void insertionSort(int a[], int n)
{
  int i, loc, j, k, selected;

  for (i = 0; i < n; i++)
  {
    j = i - 1;
    selected = a[i];
    // find location using binary search
    loc = binarySearch(a, selected, 0, j);

    while (j >= loc)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = selected;
  }
}
// recursive insertion sort
void insertionSortR(int ar[], int n)
{
  if (n <= 1)
    return;

  insertionSortR(arr, n - 1);

  int last = arr[n - 1];
  int j = n - 2;

  while (j >= 0 && arr[j] > last)
  {
    arr[j + 1] = arr[j];

    j--;
  }
  arr[j + 1] = last;
}

// sorting even or odd elements in different order

// O(N2) o(1)

void evenOddInsertionSort(int arr[], int n)
{
  for (int i = 2; i < n; i++)
  {
    int j = i - 2;
    int temp = arr[i];
  }

  // check for odd pos
  if ((i + 1) & 1 == 1)
  {
    // insert even in ascending

    while (temp >= arr[j] && j >= 0)
    {
      arr[j + 2] = arr[j];
      j -= 2;
    }
    arr[j + 2] = temp;
  }
  else
  {
    // sort in descending
    while (temp <= arr[j] && j >= 0)
    {
      arr[j + 2] = arr[j];
      j -= 2;
    }
    arr[j + 2] = temp;
  }
}

// intro to multi dimensional matrix
// int arr[row][col] //decoration '

int arr[4][3] = {1, 2, 3, 4, 5, 6, 20, 80, 90, 100, 110, 120};

int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {20, 80, 90}, {100, 110, 120}};

// data access
x[i][j]; // constant time ith row j th col

// print the grid two loop outer(row) and inner(col)
//  search in matrix
// naive way to loop through the matrix O(n*m)'

// print the diagonal
// print the element such that i ==j

// secondary diagonal is formed with  i+j == n-1

// sort the matrix
// create temp fo size n**2 and copy all matrix elements to the array sort the array and
// copy back the elements to the array
// time(O(n2 log (2 n))) space o(n2)

// roatate the matrix
// by 180 deg
// 1st row with last row and reverse each row

// find the transpose
// reverse columns of transpose
// find the transpose
// reverse the coulums of transpose

#define R 4
#define C 4

void reverseColumns(int arr[R][C])
{
  for (int i = 0; i < C; i++) // for fixing the column
  {
    for (int j = 0, k = C - 1; j < k; j++, k--) // for swapping in the col

      swap(arr[j][i], arr[k][i]);
  }
}

void transpose(int arr[R][C])
{
  for (int i = 0; i < R; i++)
  {
    for (int j = i; j < C; j++)
      swap(arr[i][j], arr[j][i]);
  }
}

void rotate180(int arr[R][C])
{
  transpose(arr);
  reverseColumns(arr);
  transpose(arr);
  reverseColumns(arr);
}

// find unique elements in the matrix
// hashing basic
// create a arr till max elements

// found += 1;
// new = 1;

int unique(int mat[R][C], int n, int m)
{
  int max = 0, flag = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
      if (max < mat[i][j])
        max = mat[i][j];
  }
  int b[max + 1] = {0}; // initalize the array to 0

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int y = mat[i][j];
      b[y]++; // increase teh count of each element
    }
  }

  for (int i = 1; i <= maximum; i++)
  {
    if (b[i] == 1)
    {
      cout << i << " ";
      flag = 1;
    }
  }
  if (!flag)
    cout << "No repeating  element";
}

// learn more problems later after doing graph

// prefix sum
// another array such that sum till i is the value of ar[i]
// eg
//  a = {1, 2, 3, 4};
//  preifx_sum = {1,3,4,10}

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
  prefix[0] = sum[0];

  for (int i = 1; i < n; i++)
    prefixSum[i] = prefixSum[i - 1] + arr[i];
}

/// given array perform m add operations btw a to b
// find the max value

/// naive approach
// loop upto m and another loop from a to b adding all element by 100

// efficient way
// prefix sum
//  scan a and b
//  add 100 to a-1 and subtract 100 from b
//  compute prefix array sum
//  find max

int findMax(int m, vector<pair<int, int>> q)
{
  int mx = 0;
  vector<int> pre(5, 0);

  for (int i = 0; i < m; i++)
  {
    // take input a and b /
    int a = q[i].first, b = q[i].second;
    // add 100 at first index
    //  and subtact 100 from last
    pre[a - 1] += 100;
    pre[b] -= 100;
  }

  for (int i = 1; i < 5; i++)
  {
    pre[i] += pre[i - 1];
    mx = max(mx, pre[i]);
  }
}

// techniques: ;

// sliding window technique
// oiling a chain
// dip in oil and slide on the chain

// use when size is fixed during nested loop
// WHERE TO
//  array string sub array substring larget sum m ax sum ,min sum given an array find the max sum of k consectuive ele
// my way: sort sum last k ele

// max size in size of subarea if suez k
// O(k*n)s o(1)
int maxSum(int arr[], int n, int k)
{
  int max_sum = INT_MIN;
  for (int i = 0; i < n - k + 1; i++)
  {
    int current_sum = 0;

    for (int j = 0; j > k; j++)
    {
      current_sum += arr[i + j]; // efficetvely add the sum of k elelments form i
    }
    max_sum = max(current_sum, max_sum);
  }
  return max_sum;
}

// sliding window technique
// caluculate the sum of first k elements
// move and find sum by adding the first element and
// subtractiong las element

int maxSumW(int arr[], int n, int k)
{
  int max_sum = 0;
  int current_sum = 0;

  for (int i = 0; i < k; i++)
  {
    current_sum += arr[i];
  }
  int max_sum = current_sum;

  for (int i = k; i < n; i++) // sliding window by one place k is the upper end while i-k is the lower end
  {
    current_sum += arr[i] = arr[i - k];
    max_sum = max(max_sum, current_sum);
  }
  return max_sum;
}

// pascals triangle
#include <iostream>
#include <vector>
using namespace std;

void generateP(int n)
{
  vector<vector<int>> v;
  if (n == 0)
  {
    return;
  }
  if (n >= 1)
  {
    v.push_back({1});
  }
  if (n >= 2)
  {
    v.push_back({1, 1});
  }

  for (int i = 2; i < n; i++)
  {
    vector<int> t(i + 1);
    t[0] = 1;
    t[i] = 1;
    for (int j = 1; j < i; j++)
    {
      t[j] = v[i - 1][j] + v[i - 1][j - 1];
    }
    v.push_back(t);
  }
  for (auto i : v)
  {
    for (auto k : i)
    {
      cout << k << " ";
    }
    cout << endl;
  }
}
int main()
{
  int n;
  cin >> n;
  generateP(n);
}
