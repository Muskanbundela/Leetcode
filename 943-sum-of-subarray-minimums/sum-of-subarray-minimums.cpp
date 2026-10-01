class Solution {
public:
    // NEXT SMALLER ELEMENT
    vector<int> findNextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> NSE(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            if (s.empty()) {
                NSE[i] = n;
            } else {
                NSE[i] = s.top();
            }

            s.push(i);
        }

        return NSE;
    }

    // PREVIOS SMALLLER ELEMENT
    vector<int> findPreviousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> PSE(n);

        for (int i = 0; i < n; i++) {

            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            if (s.empty()) {
                PSE[i] = -1;
            } else {
                PSE[i] = s.top();
            }

            s.push(i);
        }

        return PSE;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSE = findNextSmallerElement(arr);
        vector<int> PSE = findPreviousSmallerElement(arr);

        long long sum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int left = i - PSE[i];
            int right = NSE[i] - i;

            long long contri = (long long)arr[i] * left * right;
            sum = (sum + contri) % mod;
        }
        return sum;
    }
};