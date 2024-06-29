#include <bits/stdc++.h>
#include "print.h"
using namespace std;

// defination of print function print the vector

// knap sack greedy about the profit
vector<float> fillKnapSack(vector<int> profit, vector<int> weight, int n, int m)
{
  // greedy for profit
  double total_profit = 0;

  vector<float> ans(weight.size(), 0);
  // how will u attach it with the weight create a new 2d vector
  vector<vector<int>> new_v;
  for (int i = 0; i < n; i++)
  {
    // new_v will contain profit associated with weights //
    // we might need to sort in  question not needed here
    new_v.push_back({profit[i], i});
  }
  print(new_v);

  // greedy about the profit
  //  u have a vector having the highest profit first
  for (auto i : new_v)
  {
    if (m == 0)
      break;
    if (weight[i[1]] <= m)
    {
      // include the complete
      ans[i[1]] = 1;
      m -= weight[i[1]];
      total_profit += i[0];
    }
    else
    {
      // fractional protion to be included
      float f = float(m) / weight[i[1]];
      ans[i[1]] = f;
      total_profit += i[0] * f;
      m = 0;
    }
  }
  cout << "the total profit for being greedy about the profit gets: " << total_profit << endl;
  return ans;
}

// knap sack greedy about the weight

vector<float> fillKnapSack(vector<int> profit, vector<int> weight, int n, int m)
{
  // greedy for weight
  double total_profit = 0;

  vector<float> ans(weight.size(), 0);
  // how will u attach it with the weight create a new 2d vector
  vector<vector<int>> new_v;
  for (int i = 0; i < n; i++)
  {
    // new_v will contain profit associated with weights //
    // we might need to sort in  question not needed here
    new_v.push_back({weight[i], i});
  }
  print(new_v);

  // greedy about weight
  sort(new_v.begin(), new_v.end());

  // weight , index of profit
  for (auto i : new_v)
  {
    if (m == 0)
      break;
    if (i[0] <= m)
    {
      // completely include the profit
      total_profit += profit[i[1]];
      m -= i[0];
      ans[i[1]] = 1;
    }
    else
    {
      double f = double(m) / i[0]; // part to be taken
      total_profit += f * profit[i[1]];
      ans[i[1]] = f;
      m = 0;
    }
  }
  cout << "the total profit for being greedy about the weight  gets: " << total_profit << endl;
  return ans;
}

// both of them dont work for the solution

// this version consider profit per unit weight for the greedy approach
vector<double> fillKnapSack(vector<int> profit, vector<int> weight, int n, int m)
{
  // now lest become greedy about the profit per unit weight

  // first prepare the array for the cost per weight and index together
  vector<vector<double>> unitP;
  vector<double> ans(n, 0.0);
  for (int i = 0; i < n; i++)
  {
    double unit = double(profit[i]) / weight[i];
    unitP.push_back({unit, (double)i});
  }
  auto compare = [](const vector<double> &a, const vector<double> &b)
  {
    return a[0] > b[0];
  };

  // sort them for their unit weight order
  sort(unitP.begin(), unitP.end(), compare);

  // finally prepared the vector for output

  double total_profit = 0;
  for (auto i : unitP)
  {
    if (m == 0)
      break;

    int index = i[1];
    double up = i[0];
    if (weight[index] <= m)
    {
      // count the complete weight for that
      ans[index] = 1;
      total_profit += up * weight[index];
      m -= weight[index];
    }
    else
    {
      // we are including only the leftover m
      total_profit += up * m;
      ans[index] = double(m) / weight[index];
      m = 0;
    }
  }
  cout << "The max profit with knapsack is: " << total_profit << endl;
  return ans;
}

// job sequencing with deadlines
// given deadlines with profit maximize the profit and return the answer

// return a vector of jobs which are selected for the task  assume the bt and at as 1 and 0 respectively

vector<int> jobScheduling(vector<int> deadline, vector<int> profit, int n)
{
  // find the max deadline we can have and inilitalize the output of that size
  int maxi = deadline[0];
  for (auto i : deadline)
  {
    maxi = max(i, maxi);
  }
  vector<int> ans(maxi, 0);
  // take the highest profit job and fill up the vector at the most the max possible postion

  // for that we need the profit array to be sorted along with their indexes ;

  vector<vector<int>> new_v;
  for (int i = 0; i < n; i++)
  {
    new_v.push_back({profit[i], i});
  }

  sort(new_v.begin(), new_v.end());
  reverse(new_v.begin(), new_v.end());
  int total_profit = 0;
  for (auto i : new_v)
  {
    // two things index and profit
    int index = deadline[i[1]];
    // check if we can allocate this process ;
    int flag = 0;
    for (int j = index - 1; j >= 0; j--)
    {
      if (ans[j] == 0)
      {
        // place empty fill it up and place the flag as 1;
        ans[j] = i[1] + 1;
        flag = 1;
        total_profit += i[0];
        break;
      }
    }
  }
  cout << "The total profit is " << total_profit << endl;

  return ans;
}

// optimal merge pattern
// optimal merge pattern
int findOptimalMergePattern(vector<int> &v)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto i : v)
  {
    pq.push(i);
  }
  int n = v.size();
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += (a + b);
    pq.push(a + b); // the size of the node
  }
  return ans;
}
// make the tre outof it
//  huffman coding
//  spanning tree
/// three algo for spanning tree
// (dijkstra krushkals and prims )