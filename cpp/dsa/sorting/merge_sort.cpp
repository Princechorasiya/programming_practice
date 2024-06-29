#include <bits/stdc++.h>
#include "print.h"
using namespace std;

// this merge can be done without use of extra space bu using left shift and right shift
void merge(vector<int> &v, int l, int r, int mid)
{
  int ls = mid - l + 1;
  int rs = r - mid;
  vector<int> la(ls, 0);
  vector<int> ra(rs, 0);
  int index = 0;
  for (int i = l; i <= mid; i++)
  {
    la[index++] = v[i];
  }
  index = 0;
  for (int i = mid + 1; i <= r; i++)
  {
    ra[index++] = v[i];
  }

  index = l;

  int i = 0, j = 0;
  vector<int> merge;
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

int nlargest(vector<int> v, int s, int e, int n)
{
  if (s >= e)
    return v[s];
  int p = partition1(v, s, e);
  if (p == n)
    return v[p];
  else if (p > n)
  {
    return nlargest(v, s, p - 1, n);
  }
  else
  {
    return nlargest(v, p + 1, e, n);
  }
}

void mergeSort(vector<int> &v, int s, int e)
{
  if (s >= e)
    return;
  int mid = s + (e - s) / 2;
  mergeSort(v, s, mid);
  mergeSort(v, mid + 1, e);
  merge(v, s, e, mid);
}
int main()
{
  vector<int> v1 = {{-11, -63, -95, -65, -6, 55, 152, 117, 29, 71, 0}};
  mergeSort(v1, 0, v1.size() - 1);
  print(v1);
}