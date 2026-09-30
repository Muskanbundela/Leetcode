class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        int i = s.size() - 2;

        while (i >=0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0) {
            return -1; // no greater permuatation possible
        }

        int j = s.size() - 1; // find smallest dig greeater than s[i]

        while (s[j] <= s[i]) {
            j--;
        }
        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        if (ans > INT_MAX) {
            return -1;
        }
        return (int)ans;
    }
};