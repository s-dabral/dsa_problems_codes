#include<bits/stdc++.h>
using namespace std;

//This is the function for finding the depth of the binary tree
//You can practice this in the leetcode link given below
//https://leetcode.com/problems/maximum-depth-of-binary-tree/



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int maxDepth(TreeNode * node)
{
    if(node==NULL)
    {
        return 0;
    }
    int lh=maxDepth(node->left);
    int rh=maxDepth(node->right);
    int maxi= 1+max(lh,rh);
    return maxi;
}