
class Solution {
public:
    bool isCycle(int src, vector<bool>& vis,
                 vector<bool>& recPath,
                 vector<vector<int>>& edges,
                 vector<int>& ans) {

        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < edges.size(); i++) {

            int v = edges[i][0];
            int u = edges[i][1];

            // Edge direction: u -> v
            if (u == src) {

                if (!vis[v]) {
                    if (isCycle(v, vis, recPath, edges, ans)) {
                        return true;
                    }
                }
                else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;

        // Store node after DFS
        ans.push_back(src);

        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                if (isCycle(i, vis, recPath, edges, ans)) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
