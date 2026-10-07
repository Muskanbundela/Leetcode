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
    void allpaths(TreeNode* root, vector<int>& path, int currSum, int targetSum,
                  vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);
        currSum += root->val;

        if (root->left == NULL && root->right == NULL) {

            if (currSum == targetSum) {
                ans.push_back(path);
            }

            // backtrack
            path.pop_back();
            return;
        }

        allpaths(root->left, path, currSum, targetSum, ans); // left

        allpaths(root->right, path, currSum, targetSum, ans); // right

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        allpaths(root, path, 0, targetSum, ans);
        return ans;
    }
};