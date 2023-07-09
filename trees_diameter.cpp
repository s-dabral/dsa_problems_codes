#include<bits/stdc++.h>
using namespace std;





 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 


//This is just the function for calculating the diameter of the tree
//LEETCODE link:
//https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
private:
    int height(TreeNode * node, int & diameter)
    {
        if(!node)
        {
            return 0;
        }
        int lh=height(node->left,diameter);
        int rh=height(node->right,diameter);
        diameter=max(diameter,lh+rh);
        return (1+ max(lh,rh));
    }
    
};