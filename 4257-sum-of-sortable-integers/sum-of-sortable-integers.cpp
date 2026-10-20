
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Prefix maximum and suffix minimum
        vector<int> preMax(n), sufMin(n);

        preMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            preMax[i] = max(preMax[i - 1], nums[i]);

        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sufMin[i] = min(sufMin[i + 1], nums[i]);

        // Count descents in each prefix
        vector<int> desc(n, 0);
        for (int i = 1; i < n; i++)
            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);

        int ans = 0;

        // Check every divisor k of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;

                // Elements in earlier blocks must be <=
                // elements in later blocks.
                if (l > 0 && preMax[l - 1] > sufMin[l]) {
                    valid = false;
                    break;
                }

                // Check if this block can be sorted by rotation.
                int d = desc[r] - desc[l];
                if (nums[r] > nums[l])
                    d++;

                if (d > 1) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};
