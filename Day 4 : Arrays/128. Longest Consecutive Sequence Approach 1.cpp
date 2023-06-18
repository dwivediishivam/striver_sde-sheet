class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int longest = 1;
        int present = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1]+1) {
                    present++;
                }
                else {
                    longest = max(longest, present);
                    present = 1;
                }
            }
        }
        return max(longest, present);
    }
};