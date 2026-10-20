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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> sums;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            sums.push_back(sum);
        }

        if (sums.size() < k) {
            return -1;
        }

        sort(sums.begin(), sums.end(), greater<long long>());

        return sums[k - 1];
    }
};
