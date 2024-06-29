// #include <bits/stdc++.h>
using namespace std;
#ifndef PRINT_H
#define PRINT_H



void print(int n){
  cout << n << endl;

}

void print(int (*arr)[5], int a, int b)
{
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      cout << arr[i][j];
    }
    cout << endl;
  }
}

void print(int arr[][4])
{
}
void print(vector<double> v)
{
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void print(vector<T> v)
{
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}
template <typename V>
void print(vector<vector<V>> v)
{
  for (auto i : v)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

void print(vector<vector<double>> v)
{
  for (auto i : v)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

void print(int *p, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << p[i] << " ";
  }
  cout << endl;
}

void print(char *p, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << p[i] << " ";
  }
  cout << endl;
}

void print(pair<int, int> p)
{
  cout << "first: " << p.first << " second: " << p.second << endl;
}

#endif