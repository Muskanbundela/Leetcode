/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    int maxSum = 0;
    Info solve(TreeNode* root) {
        if (root == NULL) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal &&
            root->val < right.minVal) {
            int sum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, sum);

            return {true, min(root->val, left.minVal),
                    max(root->val, right.maxVal), sum};
        }
        return {false, INT_MIN, INT_MAX, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        solve(root);
        return maxSum;
    }
};