#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left, * right;
};

struct node * newNode(int data)
{
    struct node * root= (struct node *)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return (root);
}
void preOrder(node * curr, vector<int> &pre)
{
    if(curr==NULL)
    {
        return ;
    }
    
    preOrder(curr->left,pre);
    preOrder(curr->right,pre);
    pre.push_back(curr->data);
}
int main()
{
    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);

    vector<int>pre;
    preOrder(root,pre);
    cout<<"Preorder traversal is:  ";
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i]<<"  ";
    }
    return 0;
}