class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = prices[0];
        int end = prices[0];
        int largest = 0;
        for (int i = 1; i<prices.size();i++) {
            if (prices[i] < start) {
                start = prices[i];
                end = prices[i]; 
            } else if (prices[i] > end) {
                end = prices[i];
                largest = max(largest, end - start);
            }
        }
        return largest;
    }
};
