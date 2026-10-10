/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(vector<int>& nums , int st , int end){
        if(st>end){
            return NULL;
        }

        int mid = st + (end - st)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, st ,mid-1);
        root->right = helper(nums , mid+1 , end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums ;
        ListNode* temp = head;

        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        return helper(nums , 0 , nums.size()-1);

        
    }
};