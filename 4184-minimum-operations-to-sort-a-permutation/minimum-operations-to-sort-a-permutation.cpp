class Solution {
public:
    int minOperations(auto& A) {
        int n = A.size();
        int asc = 1, dsc = 1;

        for (int i = 1; i < n; i++) {
            // Check ascending circular order
            asc += A[i] == (A[i - 1] + 1) % n;

            // Check descending circular order
            dsc += A[i - 1] == (A[i] + 1) % n;
        }

        // Array follows ascending circular order
        if (asc == n)
            return A.front()
                ? min(n - A.front(), A.front() + 2)
                : 0;

        // Array follows descending circular order
        if (dsc == n)
            return min(n - A.back(), A.back()) + 1;

        // Neither order is possible
        return -1;
    }
};