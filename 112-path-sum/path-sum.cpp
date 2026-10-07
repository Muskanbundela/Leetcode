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
    bool isSum(TreeNode*  root , int currSum , int targetSum){
        if(root == NULL){
            return false;
        }
        currSum += root->val;

        if(root->left == NULL && root->right == NULL){
            return currSum == targetSum;
        }

        return isSum(root->left , currSum , targetSum) ||
        isSum(root->right , currSum , targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isSum(root , 0 , targetSum);
        
    }
};