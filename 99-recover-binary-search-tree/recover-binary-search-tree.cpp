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
    void inorder(TreeNode* root, vector<TreeNode*>& arr) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root, arr);
        vector<int> values;

        for (int i = 0; i < arr.size(); i++) {
            values.push_back(arr[i]->val);
        }
        sort(values.begin(), values.end());

        for (int i = 0; i < arr.size(); i++) {
            arr[i]->val = values[i];
        }
    }
};