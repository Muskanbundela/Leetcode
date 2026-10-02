class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            while (!s.empty() && heights[s.top()] > heights[i]) {

                int ele = s.top();
                s.pop();

                int nse = i;
                int pse = s.empty() ? -1 : s.top();

                int width = nse - pse - 1;

                maxArea = max(maxArea, heights[ele] * width);
            }

            s.push(i);
        }

        // Remaining elements
        while (!s.empty()) {

            int ele = s.top();
            s.pop();

            int nse = n;
            int pse = s.empty() ? -1 : s.top();

            int width = nse - pse - 1;

            maxArea = max(maxArea, heights[ele] * width);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()){
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum++;
                }else{
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }
        return maxArea;
    }
};