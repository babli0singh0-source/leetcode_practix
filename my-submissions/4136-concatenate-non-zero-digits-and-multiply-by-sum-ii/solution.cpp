class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        const int mod = 1e9 + 7;
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }
        vector<long long>val(n+1,0);
        vector<int>sum(n+1,0);
        vector<int>power(n+1,0);
        for(int i=0;i<n;i++){
            int curr=s[i]-'0';
            sum[i+1]=sum[i]+curr;
            power[i+1]=power[i]+(curr!=0);
            val[i+1]=curr==0?val[i]:(val[i]*10+curr)%mod;
        }
        vector<int>ans;
        for(auto &it:queries){
            auto i=it[0];
            auto j=it[1];
            long long temp=((val[j+1]+mod-(val[i]*pow10[power[j+1]-power[i]])%mod)%mod)*(sum[j+1]-sum[i]);
            temp=temp%mod;
            ans.push_back((int)temp);
        }
        return ans;
    }
};
