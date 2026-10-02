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
                maxArea = max(heights[ele] * (nse - pse - 1), maxArea);
            }
            s.push(i);
        }

            while (!s.empty()) {
                int ele = s.top();
                s.pop();
                int nse = n;
                int pse = s.empty() ? -1 : s.top();

                maxArea = max(maxArea, (nse - pse - 1) * heights[ele]);
            }
        
        return maxArea;
    }
};