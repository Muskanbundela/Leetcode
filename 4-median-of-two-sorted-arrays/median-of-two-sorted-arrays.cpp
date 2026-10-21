
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeArr = nums1;
        mergeArr.insert(mergeArr.end(), nums2.begin(), nums2.end());

        sort(mergeArr.begin(), mergeArr.end());

        int size = mergeArr.size();

        if (size % 2 != 0) {
            return mergeArr[size / 2];
        } else {
            int mid = size / 2;
            return (mergeArr[mid - 1] + mergeArr[mid]) / 2.0;
        }
    }
};
