
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        // If k is negative, no absolute difference can equal k
        if (k < 0) {
            return 0;
        }

        // Sort the array so we can use two pointers
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;

        // Start with two different indices
        int i = 0, j = 1;

        while (j < n) {

            // Both pointers cannot point to the same index
            if (i == j) {
                j++;
                continue;
            }

            // Since the array is sorted, this difference is non-negative
            int diff = nums[j] - nums[i];

            if (diff == k) {
                // Found one unique pair
                count++;

                int a = nums[i];
                int b = nums[j];

                // Skip duplicate occurrences of the first value
                while (i < n && nums[i] == a) {
                    i++;
                }

                // Skip duplicate occurrences of the second value
                while (j < n && nums[j] == b) {
                    j++;
                }
            } else if (diff < k) {
                // Difference is too small, move j right
                // to try a larger value
                j++;
            } else {
                // Difference is too large, move i right
                // to reduce the difference
                i++;
            }
        }

        // Return the number of unique pairs
        return count;
    }
};
