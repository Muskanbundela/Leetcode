
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            else if (square < num) {
                low = mid + 1;  // Search in the right half
            }
            else {
                high = mid - 1; // Search in the left half
            }
        }

        return false;
    }
};
