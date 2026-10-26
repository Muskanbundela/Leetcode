
class Solution {
public:
    long long islandSum = 0;

    void dfs(int i, int j, vector<vector<int>>& grid,
             int n, int m, long long& sum) {
        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] == 0) {
            return;
        }

        sum += grid[i][j];
        grid[i][j] = 0;  // Mark visited

        dfs(i - 1, j, grid, n, m, sum);
        dfs(i + 1, j, grid, n, m, sum);
        dfs(i, j - 1, grid, n, m, sum);
        dfs(i, j + 1, grid, n, m, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    dfs(i, j, grid, n, m, sum);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
