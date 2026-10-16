
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> sum, sq, lazy;
    int n;

    // Apply an increment to every value in this segment
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // (x + val)^2 = x^2 + 2*x*val + val^2
        sq[node] = (sq[node]
                    + 2LL * val * sum[node] % MOD
                    + val * val % MOD * len % MOD) % MOD;

        // Update the sum of values in this segment
        sum[node] = (sum[node] + val * len) % MOD;

        // Save the pending update for the children
        lazy[node] += val;
        lazy[node] %= MOD;
    }

    // Push pending updates to child segments
    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    // Add val to every element in the range [ql, qr]
    void update(int node, int l, int r,
                int ql, int qr, long long val) {

        // No overlap
        if (r < ql || l > qr)
            return;

        // Complete overlap
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        // Partial overlap: update the children
        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        // Merge results from both children
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;

        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // Last occurrence of each value
        vector<int> last(100001, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            // Only these starting positions gain
            // a new distinct element
            int left = last[x] + 1;

            update(1, 0, n - 1, left, i, 1);

            // Sum of squared distinct counts for
            // all subarrays ending at index i
            ans = (ans + sq[1]) % MOD;

            // Record the latest occurrence
            last[x] = i;
        }

        return ans;
    }
};
