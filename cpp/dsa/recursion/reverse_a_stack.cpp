void helper(stack<int> &s)
{
  if (s.empty())
  {
    return;
  }
  int val = s.top();
  s.pop();
  helper(s); // return a sorted stack and then place the top value
  stack<int> comp;
  while (!s.empty() && s.top() > val)
  {
    comp.push(s.top());
    s.pop();
  }
  s.push(val);
  while (!comp.empty())
  {
    s.push(comp.top());
    comp.pop();
  }
}