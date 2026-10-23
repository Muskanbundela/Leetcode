class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& board, int n, int m) {

        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || board[i][j] == '.') {
            return;
        }

        vis[i][j] = true;

        dfs(i - 1, j, vis, board, n, m);
        dfs(i, j + 1, vis, board, n, m);
        dfs(i + 1, j, vis, board, n, m);
        dfs(i, j - 1, vis, board, n, m);
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int battleships = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X' && !vis[i][j]) {
                    dfs(i, j, vis, board, n, m);
                    battleships++;
                }
            }
        }

        return battleships;
    }
};