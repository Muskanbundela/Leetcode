class Solution {
public:
    bool dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<int>>& grid, int n, int m) {

        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }

        if (grid[i][j] == 1 || vis[i][j]) {
            return true;
        }

        vis[i][j] = true;

        bool up = dfs(i - 1, j, vis, grid, n, m);
        bool right = dfs(i, j + 1, vis, grid, n, m);
        bool down = dfs(i + 1, j, vis, grid, n, m);
        bool left = dfs(i, j - 1, vis, grid, n, m);

        return up && right && down && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(i, j, vis, grid, n, m)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};