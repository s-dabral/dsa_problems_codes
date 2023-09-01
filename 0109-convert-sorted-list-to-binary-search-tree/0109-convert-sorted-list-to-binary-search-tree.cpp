/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head){
    	return create( head, NULL );
    }

    TreeNode *create(ListNode *head, ListNode *tail){
    	// base case
        if(head == tail)
    		return NULL;

        // find middle of LL
    	ListNode *mid = head, *temp = head;
    	while( temp != tail && temp->next != tail ) {
    		mid = mid->next;
    		temp = temp->next->next;
    	}

        // Create new node with mid->val and recursively find its left and right subtree
    	TreeNode *root = new TreeNode( mid->val );
    	root->left = create( head, mid );
    	root->right = create( mid->next, tail );
    	return root;
    }
};