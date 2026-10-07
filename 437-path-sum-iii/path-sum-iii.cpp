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
    int countpaths(TreeNode* root,long long  currSum , int targetSum){
        if(root == NULL){
            return 0;
        }
        currSum += root->val;

        int count = 0;

        if(currSum == targetSum){
            count++;
        }

        count += countpaths(root->left , currSum , targetSum);
        count += countpaths(root->right , currSum , targetSum);

        return count;

    }
    //start a new path from every node
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        int count = 0;

        //paths starting from curr Node
        count += countpaths(root , 0, targetSum);

        count += pathSum(root->left , targetSum);
        count += pathSum(root->right , targetSum);

        return count;
    }
};