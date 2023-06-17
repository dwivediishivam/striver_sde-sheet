class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n == 1) {
            return matrix[0][0] == target;
        }
        int elem = m * n;
        int low = 0;
        int high = elem-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};