class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int x : nums){
            if(mp[x] < k){
                ans.push_back(x);
                mp[x]++;
            }
        }

        return ans;
    }
};