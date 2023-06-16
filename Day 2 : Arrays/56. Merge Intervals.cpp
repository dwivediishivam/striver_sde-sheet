class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> matrix;
        int a = intervals[0][0];
        int b = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= b) {
                b = std::max(b, intervals[i][1]);
            } else {
                matrix.push_back({a, b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }

        matrix.push_back({a, b});

        return matrix;
    }
};