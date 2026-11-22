
class Solution {
public:
    bool checkString(string s) {
        int size = s.length();

        for(int i = 0; i < size; i++) {
            if(s[i] == 'b' && i + 1 < size && s[i + 1] == 'a') {
                return false;
            }
        }

        return true;
    }
};
