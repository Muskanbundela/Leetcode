class Solution {
public:

    // NEXT SMALLER ELEMENT
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> NSE(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }

            if(s.empty()) {
                NSE[i] = n;
            } else {
                NSE[i] = s.top();
            }

            s.push(i);
        }

        return NSE;
    }


    // PREVIOUS SMALLER ELEMENT
    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> PSE(n);

        for(int i = 0; i < n; i++) {

            while(!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }

            if(s.empty()) {
                PSE[i] = -1;
            } else {
                PSE[i] = s.top();
            }

            s.push(i);
        }

        return PSE;
    }


    // NEXT GREATER ELEMENT
    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> NGE(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }

            if(s.empty()) {
                NGE[i] = n;
            } else {
                NGE[i] = s.top();
            }

            s.push(i);
        }

        return NGE;
    }


    // PREVIOUS GREATER ELEMENT
    vector<int> findPGE(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> PGE(n);

        for(int i = 0; i < n; i++) {

            while(!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }

            if(s.empty()) {
                PGE[i] = -1;
            } else {
                PGE[i] = s.top();
            }

            s.push(i);
        }

        return PGE;
    }


    // SUM OF SUBARRAY MAXIMUMS
    long long sumOfSubarrayMaximum(vector<int>& nums) {

        int n = nums.size();

        vector<int> NGE = findNGE(nums);
        vector<int> PGE = findPGE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - PGE[i];
            long long right = NGE[i] - i;

            sum += (long long)nums[i] * left * right;
        }

        return sum;
    }


    // SUM OF SUBARRAY MINIMUMS
    long long sumOfSubarrayMinimum(vector<int>& nums) {

        int n = nums.size();

        vector<int> NSE = findNSE(nums);
        vector<int> PSE = findPSE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - PSE[i];
            long long right = NSE[i] - i;

            sum += (long long)nums[i] * left * right;
        }

        return sum;
    }


    long long subArrayRanges(vector<int>& nums) {

        long long maximumSum = sumOfSubarrayMaximum(nums);
        long long minimumSum = sumOfSubarrayMinimum(nums);

        return maximumSum - minimumSum;
    }
};