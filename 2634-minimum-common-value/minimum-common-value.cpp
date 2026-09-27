class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for (int x : nums1) {
            mp[x]++;
        }

        for (int x : nums2) {
            if (mp[x] > 0) {
                return x;
            }
        }
        return -1;
    }
};