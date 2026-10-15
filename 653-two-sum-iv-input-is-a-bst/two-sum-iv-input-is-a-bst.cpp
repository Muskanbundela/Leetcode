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
    
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> arr;
        inorder(root, arr);

        vector<int> values;
        for (int i = 0; i < arr.size(); i++) {
            values.push_back(arr[i]->val);
        }

        int i = 0;
        int j = values.size() - 1;
        while (i < j) {
            int sum = values[i] + values[j];
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};