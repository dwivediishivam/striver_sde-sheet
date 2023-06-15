class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> matrix(numRows);
        for (int i=0; i<numRows; i++) {
            matrix[i].resize(i + 1);
            matrix[i][0] = 1;
            for (int j=1; j<i; j++) {
                if (i >= 2) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
                }
            }
            if (i != 0) {
                matrix[i][i] = 1;
            }
        }
        return matrix;
    }
};
