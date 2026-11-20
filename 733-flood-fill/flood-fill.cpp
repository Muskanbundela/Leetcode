
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image,
             int n, int m, int originalColor, int color) {

        if (i < 0 || j < 0 || i >= n || j >= m ||
            image[i][j] != originalColor) {
            return;
        }

        image[i][j] = color;

        dfs(i - 1, j, image, n, m, originalColor, color);
        dfs(i, j + 1, image, n, m, originalColor, color);
        dfs(i + 1, j, image, n, m, originalColor, color);
        dfs(i, j - 1, image, n, m, originalColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        dfs(sr, sc, image, n, m, originalColor, color);

        return image;
    }
};
