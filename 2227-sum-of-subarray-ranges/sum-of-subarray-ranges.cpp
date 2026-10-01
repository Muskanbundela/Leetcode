class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        stack<int> s;

        for(int i=0;i<=n;i++){

            while(!s.empty() && (i==n || nums[s.top()]>=nums[i])){
                int mid = s.top();
                s.pop();

                int left = s.empty() ? -1 : s.top();
                
                int right = i;

                ans -= (long long)nums[mid]*(mid-left)*(right-mid);
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i =0;i<=n;i++){
            while(!s.empty() && (i==n || nums[s.top()]<=nums[i])){
                int mid = s.top();
                s.pop();

                int left = s.empty()?-1 : s.top();
                int right = i;

                ans += (long long) nums[mid]*(mid- left)*(right- mid);
            }
            s.push(i);
        }
        return ans;
    }
};