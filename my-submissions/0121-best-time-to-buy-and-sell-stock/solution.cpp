class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,buy=prices[0];
        for(int i=1;i<prices.size();i++){
            int cost =prices[i]-buy;
            profit=max(profit,cost);
            buy=min(prices[i],buy);
        }
        return profit;
    }
};
