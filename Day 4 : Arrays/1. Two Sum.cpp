class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map1;
        std::vector<int> op(2);
        for (int i = 0; i<nums.size(); i++) {
            map1.insert(std::make_pair(nums[i], i));
            int check = target-nums[i];
            if (map1.find(check) != map1.end() && map1[check] != i ) {
                op[0] = i;
                op[1] = map1[check];
                return op;
            }
        }
        return op;
    }
};