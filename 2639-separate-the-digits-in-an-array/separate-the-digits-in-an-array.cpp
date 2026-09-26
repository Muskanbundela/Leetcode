class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            vector<int> temp;

            while(x>0){
                int dig = x%10;
                temp.push_back(dig);
                x =x/10;
            }
            reverse(temp.begin(), temp.end());

            for(int val:temp){
                ans.push_back(val);
            }
        }
        return ans;

    }
};