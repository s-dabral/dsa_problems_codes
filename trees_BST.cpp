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


//Searching

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         while(root != NULL && root->val != val){
            root = val<root->val? root->left:root->right;
        }
        return root;
    }
};




//FInding ceil (smallest number bigger than the given node)



 int findCeil (TreeNode<int> *root, int key){

	int ceil = -1; 
    while (root) {

        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}




//Finding floor (biggest number that is smaller or equal to the given node)


int floorInBST(TreeNode<int> * root, int key)
{
    int floor = -1; 
    while (root) {
 
        if (root->val == key) {
            floor = root->val;
            return floor;
        }
 
        if (key > root->val) {
            floor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}




// TO insert a node in BST


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode * curr= root;
        while(true){
            if(curr->val <= val){
                if (curr->right!= NULL){
                    curr= curr->right;
                }
                else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr=curr->left;
                }
                else{
                    curr->left=new TreeNode(val);
                    break;
                }
                }
                
            }
            
        return root;
        }
    
};




// To delete a node in BST


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};



