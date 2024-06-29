#include <bits/stdc++.h>
using namespace std;

// max problem using divide and conquer
int maxi(vector<int> v, int s, int e)
{
  if (s == e)
    return v[s]; // one elemnent in the vector
  if (s == e - 1)
  {
    return max(v[s], v[e]); // two element in the vector;
  }
  int mid = s + (e - s) / 2;
  int a = maxi(v, s, mid);
  int b = maxi(v, mid + 1, e);
  return max(a, b);
}
int main()
{
  vector<int> v = {3, 2, 1, 2, 4, 7, 5, 3, 10, 11, 9, 1, 2, 4};
  int n = v.size();
  // find the max in teh vector using  d and c
  cout << maxi(v, 0, n - 1);
}

// max min problem find the max min together

#include <bits/stdc++.h>
using namespace std;

void maxi(vector<int> &v, int s, int e, int &ma, int &mi)
{
  if (s == e)
  {
    // array has 1 element
    ma = mi = v[s];
    return;
  }
  if (s == e - 1)
  {
    ma = max(v[s], v[e]);
    mi = min(v[s], v[e]);
    return;
  }
  int mid = s + (e - s) / 2;
  int max1 = INT_MIN, min1 = INT_MAX;
  maxi(v, s, mid, max1, min1);
  int max2 = INT_MIN, min2 = INT_MAX;
  maxi(v, mid + 1, e, max2, min2);
  ma = max(max1, max2);
  mi = min(min1, min2);
}
int main()
{
  vector<int> v = {26, 129, 35, 164, 157, 49, 144, -88, -86, 119, 177, -59, 0, 13, -30, 55, 56, -40, 52, 14, 50, 113, 119, -90, -79, 134, 63, 72, 87, 46, -5, -22, 180, -34, 62, -36, 53, 74, 14, 177, 164, 50, 146, 153, -35, -90, 111, -25, 1, 187, 5, 192, 99, 105, 87, 123, -8, 12, 138, 51, 147, -34, 177, 3, -74, -42, 65, -89, -87, 53, 199, -81, -62, 71, 74, -43, 40, 97, 86, 144, -32, 178, 118, 87, 172, -40, 124, 110, -64, 119, -5, -9, 109, 125, 187, 140, 162, 18, -84, -45, 0};
  int n = v.size();
  // find the max in teh vector using  d and ci
  int ma = v[0], mi = v[0];

  maxi(v, 0, n - 1, ma, mi);
  cout << ma << " " << mi << endl;
}

// binary search  //iterative
int main()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  int s = 0, e = v.size() - 1;
  int target = 0;
  int flag = 0;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;
    if (v[mid] == target)
    {
      cout << "The element is found" << endl;
      flag = 1;
      break;
    }
    else if (v[mid] < target)
    {
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }
  if (s > e)
    cout << "Element not found";
}

// recursive bianry search
//  implement the recursive binary search

// find the index at which hte element is found in the array
int binarySearch(vector<int> &v, int s, int e, int target)
{
  // cal mid
  if (s > e)
    return -1;
  int mid = s + (e - s) / 2;
  if (v[mid] == target)
    return mid;
  else if (v[mid] < target)
  {
    return binarySearch(v, mid + 1, e, target);
  }

  return binarySearch(v, s, mid - 1, target);
}

int main()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  int target = 8;
  int n = v.size() - 1;
  cout << binarySearch(v, 0, n, target);
}

// implement the merge sort
//
void merge(vector<int> &v, int s, int e, int mid)
{
  // merge the  lists buy created new list
  int ls = mid + 1 - s;
  int rs = e - mid;
  vector<int> la(ls, 0), ra(rs, 0);
  // copy the element into these two array
  int li = 0;
  for (int i = s; i <= mid; i++)
  {
    // left array
    la[li++] = v[i];
  }
  int ri = 0;
  for (int i = mid + 1; i <= e; i++)
  {
    ra[ri++] = v[i];
  }

  // merge these two arrays back to the original array
  int i = 0, j = 0, index = s;
  // // badd me kar lena
  // // complete the merge sort
  while (i < ls && j < rs)
  {
    if (la[i] < ra[j])
    {
      v[index++] = la[i++];
    }
    else
    {
      v[index++] = ra[j++];
    }
  }
  while (i < ls)
  {
    v[index++] = la[i++];
  }
  while (j < rs)
  {
    v[index++] = ra[j++];
  }
}

void mergeSort(vector<int> &v, int s, int e)
{
  if (s == e)
  {
    // on element in the array sorted
    return;
  }
  int mid = s + (e - s) / 2;
  mergeSort(v, s, mid);
  mergeSort(v, mid + 1, e);
  merge(v, s, e, mid);
}

void print(vector<int> v)
{
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}
int main()
{
  vector<int> v = {8, 7};
  int target = 8;
  int n = v.size() - 1;
  mergeSort(v, 0, n);
  print(v);
}

// #implementing quick sort

// #implement the quick sort /

int partition(vector<int> &v, int s, int e)
{
  // returns the pivot // partition index of the array after solving

  int pivotValue = v[s]; // Pivot value is the first element of the array
  int i = s + 1;
  int j = e;

  while (i <= j)
  {
    while (i <= j && v[i] <= pivotValue)
      i++;

    while (i <= j && v[j] > pivotValue)
      j--;

    if (i < j)
    {
      swap(v[i], v[j]);
      // i++, j--;
    }
  }

  // Move pivot element to its correct position
  swap(v[s], v[j]);

  return j; // Return the partition index
}

void quickSort(vector<int> &v, int s, int e)
{
  if (s >= e)
    return;
  int p /*pivot index*/ = partition(v, s, e);
  quickSort(v, s, p - 1);
  quickSort(v, p + 1, e);
}
void print(vector<int> v)
{
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}
int main()
{
  vector<int> v = {1, 23, 4, 5};
  int target = 8;
  int n = v.size() - 1;
  quickSort(v, 0, n);
  print(v);
}

// place hte values

// #divide and conquer  max subarray sum

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    // brute force

    return helper(nums, 0, nums.size() - 1);
  }

  int cross(vector<int> &nums, int l, int m, int h)
  {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
      sum += nums[i];
      if (sum > left_sum)
      {
        left_sum = sum;
      }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
      sum += nums[i];
      if (sum > right_sum)
        right_sum = sum;
    }

    return max(right_sum, left_sum, right_sum + left_sum - nums[m]);
  }

  int helper(vector<int> &nums, int l, int h)
  {
    if (l > h)
      return INT_MIN;
    if (l == h)
      return nums[l];
    int mid = l + (h - l) / 2;
    return max(helper(nums, 0, mid - 1), helper(nums, mid + 1, h), cross(nums, l, mid, h));
  }

  int max(int a, int b, int c)
  {
    return ::max(a, ::max(b, c));
  }
};