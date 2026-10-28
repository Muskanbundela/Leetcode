class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int K = 1024;

        vector<vector<bool>> prev(n, vector<bool>(K, false));

        for (int i = 0; i < m; i++) {
            vector<vector<bool>> curr(n, vector<bool>(K, false));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    curr[j][val] = true;
                    continue;
                }

                if (i > 0) {
                    for (int x = 0; x < K; x++) {
                        if (prev[j][x]) {
                            curr[j][x ^ val] = true;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < K; x++) {
                        if (curr[j - 1][x]) {
                            curr[j][x ^ val] = true;
                        }
                    }
                }
            }

            prev = curr;
        }

        for (int x = 0; x < K; x++) {
            if (prev[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};