class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //prefix maximum
        vector<int> pref(n);
        pref[0] = height[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], height[i]);
        }

        //suffix maximum

        vector<int> suff(n);
        suff[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], height[i]);
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            int water = min(pref[i],suff[i]) - height[i];
            total += water;
        }

        return total;
    }
};