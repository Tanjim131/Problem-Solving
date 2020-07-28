class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = numeric_limits<int>::max();
        int maxProfit = 0;
        for(int i = 0 ; i < prices.size() ; ++i){
            if(prices[i] <= buy){
                buy = prices[i];
                continue;
            }
            maxProfit = max(maxProfit, prices[i] - buy);
        }
        return maxProfit;
    }
};