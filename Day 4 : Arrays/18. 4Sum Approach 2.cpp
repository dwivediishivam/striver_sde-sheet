class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        std::set<std::vector<int>> op;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                
                int left = j + 1;
                int right = n - 1;
                long long target2 = static_cast<long long>(target) - nums[i] - nums[j];
                
                while (left < right) {
                    long long sum = static_cast<long long>(nums[left]) + nums[right];
                    
                    if (sum == target2) {
                        op.insert({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target2) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return std::vector<std::vector<int>>(op.begin(), op.end());
    }
};