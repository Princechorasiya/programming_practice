#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;

// implement tree
class node
{
public:
  int val;
  node *left;
  node *right;
  node()
  {
    val = 0;
    left = nullptr;
    right = nullptr;
  }
  node(int val)
  {
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
};

node *buildTree()
{
  int val;

  cin >> val;
  if (val == -1)
    return nullptr;
  node *root = new node(val);
  cout << "Enter the val of left node of " << val << endl;
  root->left = buildTree();
  cout << "Enter the val of right node of " << val << endl;
  root->right = buildTree();
  return root;
}

void printTree(node *root)
{
  // print level order
  queue<node *> st;
  if (root == nullptr)
  {
    cout << "root empty " << endl;
    return;
  }
  st.push(root);
  st.push(nullptr);
  while (!st.empty())
  {
    node *curr = st.front();
    st.pop();
    // one level ends
    if (curr == nullptr)
    {
      cout << endl;
      if (!st.empty())
        st.push(nullptr);
      continue;
    }
    cout << curr->val << " ";
    if (curr->left != nullptr)
    {
      st.push(curr->left);
    }
    if (curr->right != nullptr)
    {
      st.push(curr->right);
    }
  }
}

// make a binary tree using level order traversal
void helper(node *root, vector<int> &vec, int i)
{
  queue<node *> q;
  q.push(root);
  int n = vec.size();
  while (!q.empty())
  {
    node *top = q.front();
    q.pop();
    if (i >= n)
    {
      top->left = nullptr;
    }
    else
    {
      top->left = new node(vec[i++]);
    }
    if (i >= n)
    {
      top->right = nullptr;
    }
    else
    {
      top->right = new node(vec[i++]);
    }
    if (top->left != nullptr)
      q.push(top->left);
    if (top->right != nullptr)
      q.push(top->right);
  }
}

void buildTree(node *root, vector<int> &vec)
{
  helper(root, vec, 1);
}

void helperPre(node *root, vector<int> &arr)
{
  if (root == nullptr)
    return;
  arr.push_back(root->val);
  helperPre(root->left, arr);
  helperPre(root->right, arr);
}

vector<int> preOrder(node *root)
{
  vector<int> ans;
  helperPre(root, ans);
  return ans;
}

void helperPost(node *root, vector<int> &arr)
{
  if (root == nullptr)
    return;
  helperPost(root->left, arr);
  helperPost(root->right, arr);
  arr.push_back(root->val);
}

vector<int> postOrder(node *root)
{
  vector<int> ans;
  helperPost(root, ans);
  return ans;
}

void helperIn(node *root, vector<int> &arr)
{
  if (root == nullptr)
    return;
  helperIn(root->left, arr);
  helperIn(root->right, arr);
  arr.push_back(root->val);
}

vector<int> inOrder(node *root)
{
  vector<int> ans;
  helperIn(root, ans);
  return ans;
}

int height1(node *root)
{
  if (root == nullptr)
    return 0;
  return 1 + max(height1(root->left), height1(root->right));
}

// inorder traversal using for loops
// pair of count and node
class pr
{
public:
  node *root;
  int count;
  pr(node *root, int c)
  {
    this->root = root;
    count = c;
  }
};

void preOrderIterative(node *root, vector<int> &vec)
{
  if (root == nullptr)
    return;
  stack<pr *> st;
  st.push(new pr(root, 1));
  while (!st.empty())
  {
    auto top = st.top();
    if (top->count == 1)
    {
      vec.push_back(top->root->val);
      top->count = top->count + 1;
      if (top->root->left != nullptr)
      {
        st.push(new pr(top->root->left, 1));
      }
    }
    else if (top->count == 2)
    {
      top->count = top->count + 1;
      if (top->root->right != nullptr)
      {
        st.push(new pr(top->root->right, 1));
      }
    }
    else
    {
      st.pop();
    }
  }
}

void postOrderIterative(node *root, vector<int> &vec)
{
  if (root == nullptr)
    return;
  stack<pr *> st;
  st.push(new pr(root, 1));
  while (!st.empty())
  {
    auto top = st.top();
    if (top->count == 1)
    {
      top->count = top->count + 1;
      if (top->root->left != nullptr)
      {
        st.push(new pr(top->root->left, 1));
      }
    }
    else if (top->count == 2)
    {
      top->count = top->count + 1;
      if (top->root->right != nullptr)
      {
        st.push(new pr(top->root->right, 1));
      }
    }
    else
    {
      vec.push_back(top->root->val);
      st.pop();
    }
  }
}

void inOrderIterative(node *root, vector<int> &vec)
{
  if (root == nullptr)
    return;
  stack<pr *> st;
  st.push(new pr(root, 1));
  while (!st.empty())
  {
    auto top = st.top();
    if (top->count == 1)
    {
      top->count = top->count + 1;
      if (top->root->left != nullptr)
      {
        st.push(new pr(top->root->left, 1));
      }
    }
    else if (top->count == 2)
    {
      vec.push_back(top->root->val);
      top->count = top->count + 1;
      if (top->root->right != nullptr)
      {
        st.push(new pr(top->root->right, 1));
      }
    }
    else
    {
      st.pop();
    }
  }
}

//check if its height balanced
pair<int, int> height(node *root)
{
  if (root == nullptr)
    return {0, 1};
  auto left = height(root->left);
  auto right = height(root->right);
  if (left.second == 0 || right.second == 0)
  {
    return {max(left.first, right.first) + 1, 0};
  }
  if (abs(left.first - right.first) > 1)
  {
    return {max(left.first, right.first) + 1, 0};
  }
  return {max(left.first, right.first) + 1, 1};
}

bool isBalanced(node *root)
{
  auto ans = height(root);
  return ans.second;
}
// height ,isbalanced


//diameter of binary tree

pair<int, int> heightD(node *root)
{
  if (root == nullptr)
    return {0, 0};
  auto left = heightD(root->left);
  auto right = heightD(root->right);
  int diam = left.second + right.second; // root included ;
  diam = max(max(left.first, right.first), diam);
  int h = max(left.second, right.second) + 1;
  return {diam, h};
}
int diameterOfBinaryTree(node *root)
{
  auto ans = heightD(root);
  return ans.first;
}


// diameter ,height

//max path sum 

//zig zag traversal of binary tree 


int main()
{
  cout << "Enter the node value: ";
  node *root = buildTree();
  printTree(root);
}