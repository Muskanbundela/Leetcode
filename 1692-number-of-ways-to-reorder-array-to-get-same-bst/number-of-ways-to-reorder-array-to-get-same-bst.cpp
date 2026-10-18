class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<long long>> comb;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return 1;
        }

        vector<int> leftTree, rightTree;

        // Partition nodes according to the root
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                leftTree.push_back(nums[i]);
            } else {
                rightTree.push_back(nums[i]);
            }
        }

        int L = leftTree.size();
        int R = rightTree.size();

        // Ways to interleave the left and right subtrees
        long long ways = comb[L + R][L];

        // Recursively count valid reorderings
        ways = ways * solve(leftTree) % MOD;
        ways = ways * solve(rightTree) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute binomial coefficients
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] +
                     comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};