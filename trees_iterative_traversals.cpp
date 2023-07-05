#include<bits/stdc++.h>
using namespace std;


//This is just the function of iterative approach of preorder traversal
//To practice this question, please prefer to the leetcode link below:
//https://leetcode.com/problems/binary-tree-preorder-traversal/



// Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode *>s;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            s.pop();
            ans.push_back(root->val);
            if(root->right!=NULL)
            {
                s.push(root->right);
            }
            if(root->left!=NULL)
            {
                s.push(root->left);
            }
        }
        return ans;
    }
};




//This is just the function of iterative approach of preorder traversal
//To practice this question, please prefer to the leetcode link below:
//https://leetcode.com/problems/binary-tree-inorder-traversal/



/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        stack<TreeNode *>s;
        TreeNode * node=root;
        while(true)
        {
            if(node!=NULL)
            {
                
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()==true) break;
                node=s.top();
                s.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};
*/









//This is just the function of iterative approach of postorder traversal
//To practice this question, please prefer to the leetcode link below:
//https://leetcode.com/problems/binary-tree-postorder-traversal/


/*

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *>s1;
        stack<TreeNode *>s2;
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        s1.push(root);
        while(!s1.empty())
        {
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL)
            {
                s1.push(root->left);
            }
            if(root->right!=NULL)
            {
                s1.push(root->right);
            }
        }
        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};

*/