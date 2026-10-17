class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store {digit sum, original number} and original index
        vector<pair<pair<int, int>, int>> digSum;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            // Calculate digit sum of the current number
            while (num > 0) {
                sum += num % 10;  // Extract last digit
                num /= 10;        // Remove last digit
            }

            // Store {{digit sum, number}, original index}
            digSum.push_back({{sum, nums[i]}, i});
        }

        // Sort by digit sum, then by number in ascending order
        sort(digSum.begin(), digSum.end());

        int countSwap = 0;

        // Track elements already visited while finding cycles
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {

            // Skip if already visited or already at the correct position
            if (visited[i] || digSum[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            // Find the cycle of elements that need to change positions
            while (!visited[j]) {
                visited[j] = true;

                // Move to the original index of the current element
                j = digSum[j].second;
                cycleSize++;
            }

            // A cycle of size k requires k - 1 swaps
            if (cycleSize > 1) {
                countSwap += cycleSize - 1;
            }
        }

        return countSwap;
    }
};