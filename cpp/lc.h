class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {

    // brute force
    int cnt = 0;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += nums[j];
        if (sum < goal)
        {
          continue;
        }
        else if (sum == goal)
          cnt++;
        else
        {
          break;
        }
      }
    }
    return cnt;
  }
  // print arr jo merea ans satisfy kar rae
  void print(vector<int> &nums, int i, int j)
  {
    for (int k = i; k < j; k++)
    {
      cout << nums[k] << " ";
    }
    cout << endl;
  }
};