#include <bits/stdc++.h>
#include "./print.h"
using namespace std;
using vecti = vector<int>;
using vects = vector<string>;
using vectpi = vector<pair<int, int>>;
using vecti_2d = vector<vector<int>>;
class node
{
public:
  int val;
  node *left;
  node *right;
  node(int n)
  {
    val = n;
    left = nullptr;
    right = nullptr;
  }
};

class pr
{
public:
  node *root;
  int st;
  pr() {};
  pr(node *rt, int x)
  {
    root = rt;
    st = x;
  }
};
// solution without use of helper have faith in recursion that it will genrate tehe preorder of left right then from that construct the preorder of whole tree
void helper_pre(node *root, vecti &ans)
{
  if (root == nullptr)
    return;
  ans.push_back(root->val);
  helper_pre(root->left, ans);
  helper_pre(root->right, ans);
}
void helper_post(node *root, vecti &ans)
{
  if (root == nullptr)
    return;
  helper_pre(root->left, ans);
  helper_pre(root->right, ans);
  ans.push_back(root->val);
}
void helper_in(node *root, vecti &ans)
{
  if (root == nullptr)
    return;
  helper_pre(root->left, ans);
  ans.push_back(root->val);
  helper_pre(root->right, ans);
}
vector<int> preOrder(node *root)
{
  vector<int> ans;
  helper_pre(root, ans);

  return ans;
}
vector<int> postOrder(node *root)
{
  vector<int> ans;
  helper_post(root, ans);

  return ans;
}
vector<int> inOrder(node *root)
{
  vector<int> ans;
  helper_in(root, ans);

  return ans;
}

// iterative solution
vector<int> preOrderI(node *root)
{
  if (root = nullptr)
    return {};
  stack<node *> s;
  vector<int> ans;
  s.push(root);
  while (!s.empty())
  {
    node *new_node = s.top();
    s.pop();
    ans.push_back(new_node->val);
    if (new_node->right != nullptr)
    {
      s.push(new_node->right);
    }
    if (new_node->left != nullptr)
    {
      s.push(new_node->right);
    }
  }
  return ans;
}

vector<int> postOrderI(node *root)
{
  if (root == nullptr)
    return {};
}

vector<int> preOrderIterative(node *root){
  stack<pr *> st;
  st.push(new pr(root, 1));
  vector<int> ans;
  while (st.empty() == false)
  {
    pr *curr = st.top();
    if(curr->st==1){
      // we are in pre area;
      ans.push_back(curr->root->val);
      curr->st = (curr->st ) + 1;
      if(curr ->root->left!= nullptr){
        st.push(new pr(curr->root->left, 1));
      }
    }else if(curr->st==2){
      curr->st = (curr->st) + 1;
      if (curr->root->right != nullptr)
      {
        st.push(new pr(curr->root->right, 1));
      }
    }else{
      st.pop();
    }
  }
}

vector<int> inOrderIterative(node *root)
{
  stack<pr *> st;
  st.push(new pr(root, 1));
  vector<int> ans;
  while (st.empty() == false)
  {
    pr *curr = st.top();
    if (curr->st == 1)
    {
      // we are in pre area;
      ans.push_back(curr->root->val);
      curr->st = (curr->st) + 1;
      if (curr->root->left != nullptr)
      {
        st.push(new pr(curr->root->left, 1));
      }
    }
    else if (curr->st == 2)
    {
      curr->st = (curr->st) + 1;
      if (curr->root->right != nullptr)
      {
        st.push(new pr(curr->root->right, 1));
      }
    }
    else
    {
      st.pop();
    }
  }
}

//given pre order and in order of a tree construct a unique binary tree 

//use indexes instead of crating new vector ps pe is ie 
node *constructTree(vector<int> &preorder ,vector<int> &inorder){
  node *root = new node(preorder[0]);
  int ans = 0;
  for (int i = 0; i < inorder.size();i++){
    if(inorder[i]==preorder[0]){
      ans = i;
      break;
    }
  }
  vector<int> preLst;
  vector<int> inLst;
  for (int i = 1; i <= ans;i++){
    preLst.push_back(preorder[i]);
  }
  for (int i = 0; i < ans; i++)
  {
    inLst.push_back(inorder[i]);
  }
  root->left = constructTree(preLst, inLst);
  vector<int> preRst;
  vector<int> inRst;
  for (int i = ans+1; i < preorder.size(); i++)
  {
    preRst.push_back(preorder[i]);
  }
  for (int i = ans+1; i <preorder.size(); i++)
  {
    inRst.push_back(inorder[i]);
  }
  root->right = constructTree(preRst, inRst);
}

//post order and inorder tree 
int main()
{
}