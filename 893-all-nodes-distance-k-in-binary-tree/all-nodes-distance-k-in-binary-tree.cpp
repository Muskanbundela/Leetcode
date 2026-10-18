/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        // Step 1: Store parent of every node
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS starting from target
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            // Process one complete level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Explore left child
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Explore right child
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Explore parent
                if (parent.count(node) &&
                    !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            dist++;
        }

        return ans;
    }
};