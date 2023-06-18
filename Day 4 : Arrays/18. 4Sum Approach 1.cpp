class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, std::vector<std::pair<int, int>>> sum_pairs;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum_pairs[nums[i] + nums[j]].push_back({i, j});
            }
        }
        
        std::set<std::vector<int>> resultSet;
        
        std::set<std::pair<int, int>> seen;
        
        for (auto& sum_pair1 : sum_pairs) {
            int sum1 = sum_pair1.first;
            int sum2 = target - sum1;
            
            if (seen.find({sum1, sum2}) == seen.end() && sum_pairs.find(sum2) != sum_pairs.end()) {
                seen.insert({sum1, sum2});
                seen.insert({sum2, sum1});
                
                auto& pairs1 = sum_pair1.second;
                auto& pairs2 = sum_pairs[sum2];
                
                for (auto& p1 : pairs1) {
                    for (auto& p2 : pairs2) {
                        int i = p1.first, j = p1.second, k = p2.first, l = p2.second;
                        if (i != k && i != l && j != k && j != l) {
                            std::vector<int> four_sum = {nums[i], nums[j], nums[k], nums[l]};
                            std::sort(four_sum.begin(), four_sum.end());
                            resultSet.insert(four_sum);
                        }
                    }
                }
            }
        }
        
        return std::vector<std::vector<int>>(resultSet.begin(), resultSet.end());
    }
};
