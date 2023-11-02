class Solution {
    int res = 0;

public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }

    pair<int, int> postorder(TreeNode* node) {
        if (!node) {
            return {0, 0}; // sum, number of nodes
        }

        auto left = postorder(node->left);
        auto right = postorder(node->right);

        int totalSum = left.first + right.first + node->val;
        int totalCount = 1 + left.second + right.second;
        res += (node->val == totalSum / totalCount);

        return {totalSum, totalCount};
    }
};