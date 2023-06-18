class Solution {
public:
    long long int factorial(int x) {
        std::vector<long long int> dpa(x + 1, 0);
        dpa[0] = 1; 
        for (int i = 1; i <= x; i++) {
            dpa[i] = i * dpa[i - 1]; 
        }
        return dpa[x]; 
    }
    int uniquePaths(int m, int n) {
        int s = m+n-2;
        int y = std:: max(m,n);
        __uint128_t fact1 = 1; // debugged using google as unsigned long long int was giving wrong answers for some test cases
        for (int i = s; i>=y; i--){
            fact1*= i;
        }
        unsigned long long int fact2 = factorial(s-y+1);
        return fact1/fact2;
    }
};