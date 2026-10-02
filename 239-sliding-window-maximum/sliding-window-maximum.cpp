class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove elements outside the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // Add current index
            dq.push_back(i);
            // Window is ready
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};