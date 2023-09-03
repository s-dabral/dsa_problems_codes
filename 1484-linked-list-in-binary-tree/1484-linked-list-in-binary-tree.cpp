
class Solution {
    
    bool dfs(ListNode * head, TreeNode * root)
    {
        if(head == NULL)
            return true;
        
        if(root == NULL || head->val != root->val)
            return false;
        
        return dfs(head->next , root->left) || dfs(head->next, root->right);
    }
    
    bool SolveByRecursion(ListNode * head, TreeNode * root)
    {
        if(head == NULL)
            return true;
        
        if(root == NULL)
            return false;
        
        if(dfs(head, root))
                return true;
        
        return SolveByRecursion(head, root->left) || SolveByRecursion(head, root->right);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {      
        return SolveByRecursion(head, root);
        
    }
};