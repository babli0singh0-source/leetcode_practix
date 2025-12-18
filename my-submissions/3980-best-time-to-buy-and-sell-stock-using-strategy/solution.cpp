class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<pair<long long,long long>>m;
        long long ans1=prices[0]*strategy[0];
        long long ms1=0,ansm=0;
        for(int j=0;j<(k/2);j++) {ms1+=prices[j]*strategy[j];}
        for(int j=(k/2);j<k;j++){
            ansm+=prices[j];
            ms1+=prices[j]*strategy[j];
        }
        m.push_back({ansm,ms1});
        for(int i=1;i<(prices.size()-k+1);i++){
            ms1=ms1+(prices[i+k-1]*strategy[i+k-1])-(prices[i-1]*strategy[i-1]);
            ansm+=prices[i+k-1]-prices[i+(k/2)-1];
            m.push_back({ansm,ms1});
            ans1+=prices[i]*strategy[i];
        }
        for(int i=(prices.size()-k+1);i<prices.size();i++){
            ans1+=prices[i]*strategy[i];
        }
        long long ans=ans1;
        for(auto it:m){
            ans=max(ans,(ans1+it.first-it.second));
        }
        return ans;
    }
};
