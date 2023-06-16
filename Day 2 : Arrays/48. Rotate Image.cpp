class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x;
        if (n%2 == 0){
            x = n/2;
        } else {
            x = (n-1/2);
        }
        for (int i=0; i<x; i++){
            for (int j=i; j<n-i-1; j++){
                int check = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = check;
            }
        }
    }
};