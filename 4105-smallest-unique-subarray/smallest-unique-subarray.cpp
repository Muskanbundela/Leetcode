class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        // Build suffix array
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                    (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        // Kasai's LCP algorithm
        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0)
                continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0)
                h--;
        }

        // Find smallest unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int longestLCP = lcp[i];

            if (i + 1 < n)
                longestLCP = max(longestLCP, lcp[i + 1]);

            int len = longestLCP + 1;

            if (sa[i] + len <= n)
                ans = min(ans, len);
        }

        return ans;
    }
};