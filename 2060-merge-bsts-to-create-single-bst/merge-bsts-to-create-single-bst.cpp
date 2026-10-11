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
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> leaves;
    int used = 0;

    // validates BST and merge matching trees recursively
    bool dfs(TreeNode* root, long long low, long long high) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= low || root->val >= high) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && mp.count(root->val)) {
            TreeNode* tree = mp[root->val];
            root->left = tree->left;
            root->right = tree->right;

            mp.erase(root->val);
            used++;
        }
        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (TreeNode* tree : trees) {
            mp[tree->val] = tree;
        }

        for (TreeNode* tree : trees) {
            mp[tree->val] = tree;
        }

        for (TreeNode* tree : trees) {
            if (tree->left) {
                leaves.insert(tree->left->val);
            }
            if (tree->right) {
                leaves.insert(tree->right->val);
            }
        }

        TreeNode* root = NULL;

        for (TreeNode* tree : trees) {
            if (!leaves.count(tree->val)) {
                root = tree;
                break;
            }
        }
        if (root == NULL) {
            return NULL;
        }

        mp.erase(root->val);
        used = 1;

        if (!dfs(root, LLONG_MIN, LLONG_MAX)) {
            return NULL;
        }
        if (used != trees.size() || !mp.empty()) {
            return NULL;
        }
        return root;
    }
};