class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        
        while (i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }

        int start = i;

        std::cout << i << std::endl;
        if (i > 0) {
            int smallest = nums[i];
            int pos = i;
            
            for (int j = i; j < n; j++) {
                if (nums[j] < smallest && nums[j] > nums[i-1]) {
                    smallest = nums[j];
                    pos = j;
                }
            }
            std::cout << nums[pos] << std::endl;
            std::cout << nums[i - 1] << std::endl;
            std::swap(nums[pos], nums[i - 1]);
        
        
        // nums[i-1] = next smallest number ^^
        
        for (int i = start; i < n-1; i++) {
            for (int j = start; j < n-i+start-1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::cout << j << std::endl;
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
        }
        
        // nums[i] se nums [n] tak sort ^^

        if (start==0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i-1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        std::swap(nums[j], nums[j + 1]);
                    }
                }
            }   
        }

    }
};
