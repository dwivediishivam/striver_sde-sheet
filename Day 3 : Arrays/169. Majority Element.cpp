class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int check = NULL;
        for (int i = 0; i<nums.size(); i++){
            if (count == 0) {
                check = nums[i];
            }
            if (nums[i] == check) {
                count++;
            } else {
                count--;
            }
        }
        return check;
    }
};