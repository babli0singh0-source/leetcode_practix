class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mpp;
        long long totalsum=0,ans=LLONG_MAX;
        for(int i=0;i<cost.size();i++){
            mpp[s[i]]+=cost[i];
            totalsum+=cost[i];
        }
        cout<<totalsum<<endl;
        for(auto &it:mpp){
            cout<<it.second<<endl;
            ans=min(ans,(totalsum-it.second));
            cout<<ans<<endl;
        }
        return ans;
        
    }
};
