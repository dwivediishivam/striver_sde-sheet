class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        std::unordered_set<int> map(nums.begin(), nums.end());
        int max = 0;
        for (auto i : nums) {
            if (map.find(i - 1) == map.end()) {
                int nowsize = 1;
                int now = i + 1;

                while (map.find(now) != map.end()) {
                    nowsize++;
                    now++;
                }

                max = std::max(max, nowsize);
            }
        }
        return max;
    }
};
