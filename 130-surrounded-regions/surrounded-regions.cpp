class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& board, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            board[i][j] != 'O') {
            return;
        }
        vis[i][j] = true;

        dfs(i - 1, j, vis, board, n, m); // top
        dfs(i, j + 1, vis, board, n, m); // right
        dfs(i + 1, j, vis, board, n, m); // bottom
        dfs(i, j - 1, vis, board, n, m); // left
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // find safe O cells from the boundaries
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, vis, board, n, m);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, n, m);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, vis, board, n, m);
            }
            if (board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};