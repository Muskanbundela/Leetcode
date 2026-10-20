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
public:
    int prevOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }
        if (root->left) {
            int leftMin = kthSmallest(root->left, k);
            if (leftMin != -1) {
                return leftMin;
            }
        }
        if (prevOrder + 1 == k) {
            return root->val;
        }
        prevOrder = prevOrder + 1;

        if (root->right) {
            int rightMin = kthSmallest(root->right, k);
            if (rightMin != -1) {
                return rightMin;
            }
        }
        return -1;
    }
};