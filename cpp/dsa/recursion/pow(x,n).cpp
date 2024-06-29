

//normal way 
class Solution
{
public:
  double myPow(double x, int n)
  {
    long power = n;
    if (x == 1)
      return 1;
    if (n < 0)
      power = -1 * power;
    double ans = 1;
    if (n < 0)
      return 1 / (helper(x, ans, power));
    return helper(x, ans, power);
  }
  double helper(double x, double ans, long n)
  {
    if (n == 0)
      return ans;
    return helper(x, ans * x, n - 1);
  }
};


//fast exponentiation


class Solution
{
public:
  double myPow(double x, int n)
  {
    long power = n;
    if (x == 1)
      return 1;
    if (n < 0)
      power = -1 * power;
    double ans = 1;
    if (n < 0)
      return 1 / (helper(x, power));
    return helper(x, power);
  }
  double helper(double x, long n)
  {
    if (n == 0)
      return 1;
    double t = helper(x, n / 2);
    t *= t;
    if (n % 2 == 1)
      t *= x;
    return t;
  }
};
