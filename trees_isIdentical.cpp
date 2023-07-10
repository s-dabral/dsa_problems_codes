#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };




//This is a function to calculate if the given trees are identical or not
//You can practice this problem in the below leetcode link
//https://leetcode.com/problems/same-tree/



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)
        {
            return (p==q);
        }
        return (p->val == q->val)&& isSameTree(p->left, q-> left)
                && isSameTree(p->right, q-> right);
    }
};