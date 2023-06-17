class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int largest = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                        largest = std::max(largest, dp[i][j]);
                    } else {
                        dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                        largest = std::max(largest, dp[i][j]);
                    }
                }
            }
        }

        return largest * largest;
    }
};