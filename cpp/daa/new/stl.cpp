#include <bits/stdc++.h>
using namespace std;

void pairt()
{
  pair<int, int> p;
  p.first;
  p.second;
  pair<int, pair<int, int>> q;
  p.first;
  q.second.first;
  q.second.second;
  pair<int, int> pq[10];
}

void vectorsT()
{
  vector<int> v; // dynamic how it is made
  v.push_back(1);
  v.emplace_back(2); // faster and doesn't create a copy

  vector<pair<int, int>> pq;
  pq.push_back({1, 2});
  pq.emplace_back(1, 2);
  v[1];
  v.begin();
  (*t);
  v.at();
  v.front();
  v.back();
  v.end(); // memory location beyond the last iterator
  v.rend();
  v.rbegin();
  v.cbegin();
  v.cend();

  v.erase(v.begin() + 1);
  v.erase((v.begin() + 1, v.begin() + 4));[start,end);
  v.insert(v.begin(),val);
  v.insert(v.begin(),1,10);//no of element,value
  v.size() ;
  v.pop_back();
  v.swap(v2);
  v.clear();
  v.empty();
}

void exlpainList()
{
  list<int> ls;
  ls.push_back();  // emplace there as well
  ls.push_front(); // emplace there as well
  ls.pop_back();
  ls.pop_front();
}

void explainDeque()
{
  deque<int> dq;
  push_back(), push_front();
  pop_back(), pop_front();
  dq.front(), dq.back();
}

void explainStack()
{
  // lifo
  stack<int> st;
  push() pop() emplace();
  top() size() empty();
}

void explainQueue()
{
  queue<int> q;
  /// fifo
  push() pop() back() front();
}

void explainPq()
{

  priority_queue<int> pq; // max heap
  pq.pop()                // log n
      pq.push();          // log n
  pq.top();
  pq.emplace();

  priority_queue<int, vector<int>, greater<int>> pq; // min heap
}

void explainSEt()
{
  // set unique and sorted
  set<int> s;
  s.insert();
  s.emplace();
  auto it = s.find(val); // log time s.end() if not found
  s.erase(4);            // log time
  int cnt = st.count();  // 1 or 0
  s.erase(s.find(4));    /// constant time

  st.lower_bound();
  s.upper_bound();
}

void multiset()
{
  multiset<int> n;
  s.insert(1);
  s.insert(1);
  n.erase(1); // erase all the 1 use find and delete the first one
}

unordered_set<int> p; // same but unsorted most cases O(1) but can go to O(n)
// and lower_bound and upper_bound doesnt work

map<int, int> m;
m.insert({}); // log
m.emplace(1, 2);

// keys are unique but values can be duplicates
// sorted order keys
m[1] = 2;
m[1].first;
m[1].second;
m.find(4);

m.lower_bound()
    m.upper_bound();

multimap<int, int> m;
duplicates;

unordered_map<int, int>
    dp; // unsorted
// algorithms
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>) // descending order
    sort(v.begin(), v.end(), comp);

bool comp(pair<int, int> pq, pair<int, int> p2) // sort in ascending order of second element
{
  if (p1.second < p2.second)
    return true;
  if (p1.second > p2.second)
    return false
}

// custromise your own comparator s
int num = 7;
int nct = __builtin_popcountll(); // return the numeber of set bit

string s = "123" do
{
  cout << s << endl;
}
while (next_permutation(s.begin(), s.end());

int maxi = *max_element(a,a+n);
int mini = *min_element(a,a+t);