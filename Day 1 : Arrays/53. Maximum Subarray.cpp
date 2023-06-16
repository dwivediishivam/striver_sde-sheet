class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = pow(-10,5);
        int prev = 0;
        for (int i = 0; i<nums.size(); i++){
            prev = prev+nums[i];
            largest = max(prev,largest);
            if (prev<0){
                prev = 0;
            }
        }

        return largest;
    }
};
