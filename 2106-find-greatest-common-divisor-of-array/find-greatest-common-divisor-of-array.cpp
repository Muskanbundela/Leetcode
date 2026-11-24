class Solution {
public:
    int GCD(int a , int b){
        while(b!= 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int minEle = nums[0];
        int maxEle = nums[0];

        for(int i=0;i<nums.size();i++){
            if(nums[i]<minEle){
                minEle = nums[i];
            }
            if(nums[i]>maxEle){
                maxEle = nums[i];
            }
        }
        return GCD(minEle , maxEle);
        
    }
};