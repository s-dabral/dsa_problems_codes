#include<bits/stdc++.h>
using namespace std;


//This is just the function for finding the right view of the tree
//You can slove this problem in the below leetcode link
//https://leetcode.com/problems/binary-tree-right-side-view/


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
    public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root,0,res);
        return res;
    }
    
        void recursion(TreeNode * root, int level, vector<int>&res)
        {
            if (root==NULL)
            {
                return ;
            }
            if(level==res.size()){
                res.push_back(root->val);
            }
            recursion(root->right,level+1,res);
            recursion(root->left,level+1,res);
        }
};




//For the left view of the tree, change the order of recursive function call as below: 

// recursion(root->left,level+1,res);
// recursion(root->right,level+1,res);
            