class Solution {

    bool win(int n, int remove) {
        if (remove <= 0 || n < remove)
            return false;

        return !win(n - remove, remove - 1);
    }

public:
    bool canAliceWin(int n) { return win(n, 10); }
};