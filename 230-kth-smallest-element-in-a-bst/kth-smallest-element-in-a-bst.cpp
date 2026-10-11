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
    int prevOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        if(root->left){
            int leftans = kthSmallest(root->left , k);
            if(leftans != -1){
                return leftans;
            }
        }
        if(prevOrder +1 == k){
            return root->val;
        }
        prevOrder = prevOrder+1;

        if(root->right){
            int rightans = kthSmallest(root->right, k);
            if(rightans != -1){
                return rightans;
            }
        }
        return -1;

        
    }
};