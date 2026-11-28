class Solution {
public:
    void DFS(int i, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[i] = true;

        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == 1 && !vis[j]) {
                DFS(j, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvinces = 0;
        int n = isConnected.size();
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS(i, isConnected, vis);
                numOfProvinces++;
            }
        }
        return numOfProvinces;
    }
};