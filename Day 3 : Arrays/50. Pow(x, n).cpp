class Solution {
public:
    double myPow(double x, long long int n) {
        if(n<0){
            n = -1 * n;
            x = 1/x;
        } else if (n == 0){
            return 1;
        }

        double output = 1;
        while (n > 0) {
            if (n%2==1){
                output = output*x;
                n-=1;
            }
            x = x*x;
            n = n/2;
        }
        return output; 
    }
};