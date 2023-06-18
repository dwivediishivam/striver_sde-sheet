class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int check1 = NULL;
        int check2 = NULL;
        std::vector<int> result; 
        for (int i = 0; i<nums.size(); i++){
            if (check1 == nums[i]) {
                count1++;
            } else if (nums[i] == check2){
                count2++;
            } else if (count1 == 0){
                check1 = nums[i];
                count1++;
            } else if (count2 == 0){
                check2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count(nums.begin(), nums.end(), check1);
        count2 = count(nums.begin(), nums.end(), check2);
        if (check1 == check2 && count1 >n/3){
            result.push_back(check1);
        } else {
            if (count1 > n / 3) {
                result.push_back(check1); 
            }
            if (count2 > n / 3) {
                result.push_back(check2);
            }
        }

        return result;
    }
};