
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> m;

            for (int j = i; j < nums.size(); j++) {
                m[nums[j]]++;

                int distinct = m.size();
                sum += distinct * distinct;
            }
        }

        return sum;
    }
};
