
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;
        int i = 0, j = 1;

        while (j < n) {
            if (i == j) {
                j++;
                continue;
            }

            int diff = nums[j] - nums[i];

            if (diff == k) {
                count++;

                int a = nums[i];
                int b = nums[j];

                while (i < n && nums[i] == a) {
                    i++;
                }
                while (j < n && nums[j] == b) {
                    j++;
                }
            }
            else if (diff < k) {
                j++;
            }
            else {
                i++;
            }
        }

        return count;
    }
};
