#include <bits/stdc++.h>
#include "./print.h"
using namespace std;

int main1()
{
  // #arrays
  int a[5] = {}; // initalise with function
  print(a, 5);
  cout << a[6] << endl; // garbage using values outside the array

  int ab[] = {1, 2, 3};
  print(ab, 3);

  int third[15] = {1,
                   2};

  print(third, 15);

  cout << sizeof(third) << endl; // 15 but we initalised it with 2 element we need the actual element
  // thats why we send the size variable along with it

  char ch[5] = {}; // initalised with null values  default garbase values

  print(ch, 5);

  // /indexing
}
// using arrays with functions

// find the max and min from the array

/// @brief find the max and min of the array
/// @param p the pointer to array
/// @param n the size of hte array
void find_max_min(int *p, int n)
{
  int maxi = p[0], mini = p[0]; // initialise max to int_min and min to int_max
  for (int i = 1; i < n; i++)
  {
    maxi = max(maxi, p[i]);
    mini = min(mini, p[i]);
  }
  cout << maxi << " " << mini << endl;
}

// find the sum of the array

/// @brief finds the sum of the array
/// @param p pointer to array
/// @param n size of the array
/// @return the sum of the array
int find_sum(int *p, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += p[i];
  }
  return sum;
}

// linar search find the target in array by iterating one by one

/// @brief find the element using linear search
/// @param p pointer to the array
/// @param n size of the array
/// @param target the value which we are searching for
/// @return return the index of the target else -1
int linearSearch(int *p, int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (p[i] == target)
      return i;
  }
  return -1;
}

/// @brief reverses and array
/// @param p  pointer to the array
/// @param n size of the array
void reverse(int *p, int n)
{
  // reverse an array
  int s = 0, e = n - 1;
  while (s < e)
  {
    // till start and end dont cross each other
    swap(p[s], p[e]);
    s++, e--;
  }
}

// swap alternate element

/// @brief task is to swap alternate elements
/// @param p pointer to array
/// @param n  size of the array
void swap_alternate(int *p, int n)
{
  int swaps = n / 2;
  int s = 0;
  for (int i = 0; i < swaps; i++)
  {
    swap(p[s], p[s + 1]);
    s += 2;
  }
}

/// @brief array of n element from all elements occurring twice except one
/// @param p pointer to the array
/// @param n the size of the array
/// @return the unique element of the array
int find_unique(int *p, int n)
{
  // find the unique element in the array
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans ^= p[i];
  }
  return ans;
}

// find the duplicate in arary going up to 1 to n-1 and one repeating element
int find_duplicate(int *p, int n)
{
  // xor
  int array_xor = 0;
  int num_xor = 0;
  for (int i = 0; i < n - 1; i++)
  {
    array_xor ^= p[i];

    num_xor ^= (i + 1);
  }
  array_xor ^= p[n - 1];
  return array_xor ^ num_xor;
}

int (*p)[11] = &arr; // p is a pointer to an array of integers
cout << *(*p + 1) << endl;

// two sorted array find the intersection return the pointer address
// suicide because of the scope so what make a return array of size 100

void find_intersection(int *p, int *q, int n, int m, int *ans)
{
  int i = 0, j = 0;
  int index = 0;
  while (i < n && j < m)
  { // while pointer within limits
    if (p[i] == q[j])
    {
      ans[index] = p[i];
      i++, q++, index++;
    }
    else if (p[i] < q[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
}

// pair sum
void findPairs(int *p, int n, int target)
{
  // brute force check all the elements tc o(n2)

  unordered_map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    m[p[i]] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    int sn = target - p[i];
    if (m[sn] == 1)
    {
      cout << "pair found " << p[i] << " " << sn << endl;
    }
  }
}

/// @brief sort the array containing 0 and 1
/// @param p pointer to the array
/// @param n no of elements int the array
void sort_zero_one(int *p, int n)
{
  // way 1 counting 0 and 1 and then placing them back to the array

  // use two pointers
  int i = 0, j = n - 1;
  while (i < j)
  {
    // iterate the complete array
    if (p[i] == 0)
    {
      i++;
      continue;
    }
    if (p[j] == 1)
    {
      j--;
      continue;
    }
    if (p[i] == 1 && p[j] == 0)
      swap(p[i++], p[j--]);
  }
}

// binary search
/// @brief find the index of target in the array iterative
/// @param p pointer to the array
/// @param n size
/// @param target element we are looking for
/// @return return the index else -1;
int binarySearch(int *p, int n, int target)
{
  int s = 0, e = n - 1;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;
    if (p[mid] == target)
      return mid;
    else if (p[mid] < target)
      s = mid + 1;
    else
      e = mid - 1;
  }
  return -1;
}

/// @brief binary search using recursion
/// @param p pointer to the array
/// @param s start index of the array
/// @param e end index of the array
/// @param target the value we are looking for
/// @return return the index if element found else -1
int rbinarySearch(int *p, int s, int e, int target)
{
  if (s > e)
    return -1;
  if (s == e)
  {
    if (p[s] == target)
      return s;
    return -1;
  }

  int mid = s + (e - s) / 2;
  if (p[mid] == target)
    return mid;
  else if (p[mid] < target)
  {
    return rbinarySearch(p, mid + 1, e, target);
  }
  return rbinarySearch(p, s, mid - 1, target);
}

/// @brief find the first and last occurence in a sorted array using binary search
/// @param p pointer to the array
/// @param n size of the array
/// @param target the value we are looking for
/// @return return a pair of first and last occurence of the value .first first occurence .second last occurence of the value

pair<int, int> findFL(int *p, int n, int target)
{
  pair<int, int> ans;
  // first use two binary search and then check if we can combine

  int s = 0, e = n - 1;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;
    if (p[mid] == target)
    {
      ans.first = mid;
      e = mid - 1;
    }
    else if (p[mid] < target)
    {
      // search the right half
      s = mid + 1;
    }
    else
      e = mid - 1;
  }

  s = 0, e = n - 1;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;
    if (p[mid] == target)
    {
      ans.second = mid;
      s = mid + 1;
    }
    else if (p[mid] < target)
    {
      // search the right half
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  return ans;
}

// find  the peak element of hte mountain array

int peakIndexInMountainArray(vector<int> &arr)
{
  int s = 0, e = arr.size();
  int ans = 0;
  while (s < e)
  {
    int mid = s + (e - s) / 2;
    if (arr[mid] < arr[mid + 1])
    {
      s = mid + 1;
    }
    else
    {
      e = mid;
    }
  }
  return arr[e];
}

/// @brief find the pivot of the array
/// @param arr
/// @return
int findPivot(vector<int> &arr)
{
  int s = 0, e = arr.size() - 1;
  while (s < e)
  {
    cout << "e: " << e << "s: " << s << endl;
    int mid = s + (e - s) / 2;
    if (arr[mid] > arr[0])
      s = mid + 1;
    else
      e = mid;
  }
  return arr[e]; // both s and works fine
}

// find in rotated sorted array

#include <bits/stdc++.h>
#include "print.h"

using namespace std;

class Solution
{
public:
  // find the index at which the element occurs in the array that has been rotated
  int findPivot(vector<int> &arr)
  {
    // return the index
    int n = arr.size() - 1;

    int s = 0, e = n;
    while (s < e)

    {
      int mid = s + (e - s) / 2;
      if (arr[mid] >= arr[0])
      {
        s = mid + 1;
      }
      else
      {
        e = mid;
      }
    }
    return s;
  }

  int binarySearch(vector<int> &arr, int s, int e, int target)
  {
    while (s <= e)
    {
      int mid = s + (e - s) / 2;
      if (arr[mid] == target)
        return mid;
      else if (arr[mid] < target)
        s = mid + 1;
      else
        e = mid - 1;
    }
    return -1;
  }

  int findSorted(vector<int> &arr, int target)
  {
    int p = findPivot(arr);
    int n = arr.size();
    if (target >= arr[0] && target <= arr[p - 1])
    {
      // look in the first sorted half
      return binarySearch(arr, 0, p - 1, target);
    }
    return binarySearch(arr, p, n - 1, target);
  }
}

;

int sqrt(int x)
{
  int s = 1, e = x;
  int ans = 0;
  while (s <= e)
  {

    int mid = s + (e - s) / 2; // middle value
    cout << "mid " << mid << endl;
    if (mid == x / mid)
      return mid;
    else if (mid < x / mid)
    {
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  return ans;
}

int sqrtInt(int x)
{
  int s = 1, e = x;
  int ans = 0;
  while (s < e)
  {

    int mid = s + (e - s) / 2; // middle value
    cout << "mid " << mid << endl;
    if (mid == x / mid)
      return mid;
    else if (mid < x / mid)
    {
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  return ans;
}

double sqrtDouble(int x)
{
  int val = sqrt(x);
  int i = 0;
  double f = 0.1;
  double ans = val;
  while (i < 7)
  {

    double ex = val + f;
    while (ex * ex < x)
    {
      ans = ex;
      ex += f;
    }

    f /= 10;
    i++;
  }
  return ans;
}

class Solution
{
public:
  // book allocation problem

  bool isPossible(vector<int> &books, int m, int mid)
  {
    // now check for is possible
    int n = books.size();
    int student = 1;
    int book = 0;
    for (int i = 0; i < n; i++)
    {
      if (book + books[i] <= mid)
      {
        // we can allocate the books to student
        book += books[i];
        cout << student << " " << book << endl;
      }
      else
      {
        // move on to the next student but this index was skipped
        student++;
        if (student > m || books[i] > mid)
          return false;
        book = books[i];
        // i--; // to prevent this index from being skipped
      }
    }
    if (student > m)
      return false;
    return true;
  }

  int allocateBook(vector<int> &books, int m)
  {
    // possible ans
    int s = 0, e = 0;
    for (auto i : books)
    {
      e += i;
    }
    int ans = books[0];

    while (s < e)
    {
      int mid = s + (e - s) / 2;
      cout << "mid: " << mid << endl;
      if (isPossible(books, m, mid))
      {
        ans = mid;
        cout << "ans: " << ans << endl;

        e = mid - 1;
        // cout << ans << endl;
      }
      else
      {
        s = mid + 1;
      }
      cout << "s: " << s << " e: " << e << endl;
    }
    return ans;
  }
};

class Solution
{
public:
  // painter allocation problem

  // allocate the walls to k painter such that time they to paint the wall  is minimum

  /// @brief return the min days taken to paint
  /// @param arr  walls
  /// @param n painter
  /// @return the min days
  int painterAllocate(vector<int> &arr, int n)
  {
    int s = 0, e = 0, ans = -1;
    for (auto i : arr)
    {
      e += i;
    }
    while (s < e)
    {
      // check for
      int mid = s + (e - s) / 2;
      if (isPossible(arr, n, mid))
      {
        ans = mid;
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }
    return ans;
  }
  /// @brief find if its possible to take mid amount to complete the work
  /// @param arr the walls
  /// @param n  the no. of painter
  /// @param mid  the days it will take them to finish the work
  /// @return  return true if work can be done else return false
  bool isPossible(vector<int> &arr, int n, int mid)
  {
    int painter = 1, wall = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (wall + arr[i] <= mid)
      {
        // we can allocate this wall to the painter
        wall += arr[i];
      }
      else
      {
        painter++;
        if (painter > n || arr[i] > mid)
        {
          return false;
          // more no of painter needed
        }
        // initalise the wall for new painter
        wall = arr[i];
      }
    }
    return true; // if all walls are allocated to painter
  }
};

#include <bits/stdc++.h>
#include "print.h"

using namespace std;

class Solution
{
public:
  // painter allocation problem

  // allocate the walls to k painter such that time they to paint the wall  is minimum

  /// @brief return the min days taken to paint
  /// @param arr  walls
  /// @param n painter
  /// @return the min days
  int painterAllocate(vector<int> &arr, int n)
  {
    int s = 0, e = 0, ans = -1;
    for (auto i : arr)
    {
      e += i;
    }
    while (s <= e)
    {
      // check for
      int mid = s + (e - s) / 2;
      if (isPossible(arr, n, mid))
      {
        ans = mid;
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }
    return ans;
  }
  /// @brief find if its possible to take mid amount to complete the work
  /// @param arr the walls
  /// @param n  the no. of painter
  /// @param mid  the days it will take them to finish the work
  /// @return  return true if work can be done else return false
  bool isPossible(vector<int> &arr, int n, int mid)
  {
    int painter = 1, wall = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (wall + arr[i] <= mid)
      {
        // we can allocate this wall to the painter
        wall += arr[i];
      }
      else
      {
        painter++;
        if (painter > n || arr[i] > mid)
        {
          return false;
          // more no of painter needed
        }
        // initialise the wall for new painter
        wall = arr[i];
      }
    }
    return true; // if all walls are allocated to painter
  }
};

// aggressive cow problem impossible sort and start placing them

// sorting

// selection sort

// pick the smallest and place it on its correct position
// n-1 rounds

int findSmallest(vector<int> &v, int s, int e)
{
  int mini = s;
  for (int i = s; i < e; i++)
  {
    if (v[mini] > v[i])
    {
      mini = i;
    }
  }
  return mini;
}
void selectionSort(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n - 1; i++)
  {
    int smallestIndex = findSmallest(v, i, n);
    if (smallestIndex != i)
      swap(v[i], v[smallestIndex]);
    print(v);
  }
}

// time complexity o(n2) space O(1)
// best case o(n2)
// worst case O(n2)

// use case works well on small size and memory constraints
//  stable or unstable

// bubble sort

void bubbleSort(vector<int> &v)
{
  // bubble sort this array
  int n = v.size();
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      if (v[j] > v[j + 1])
        swap(v[j + 1], v[j]);
    }
    print(v);
  }
}

// best case O(n)
// worst case O(n^2)
// space  O(1)
void bubbleSort(vector<int> &v)
{
  // given an array sort it using bubble sort
  // improve the code
  int n = v.size();
  for (int i = 0; i < n - 1; i++)
  {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (v[j] > v[j + 1])
      {
        swap(v[j], v[j + 1]);
        swapped = true;
      }
    }
    print(v);
    if (!swapped)
    {
      cout << "The array is already sorted" << endl;
      break;
    }
  }
}

// stable unsorted and stable or not

// insertion sort

void insertionSort(vector<int> &v)
{
  int n = v.size();
  for (int i = 2; i < n; i++)
  {
    int key = v[i];
    int j = i - 1;

    while (j >= 0 && v[j] > key)
    {
      v[j + 1] = v[j];
      j--;
    }

    v[j + 1] = key;
  }
}

// why insertion sort stable algo works well for partially sorted array
// complexity space: O(1)
//  time complexity :O(n^2)

// best case already sorted O(N)
// worst case reverse sorted O(n^2)

// #2d array
int arr[3][4];
// pointer to receive this
int (*arr)[4];

// while passsing it to function the columns or the second dimension must be known
// the first dimension gives error
