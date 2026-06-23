class Solution {
    int mod=1000000007;
public:
    int zigZagArrays(int n, int l, int r) {
        int nums=r-l+1;
        vector<int>dp0(nums,1);
        vector<int>dp1(nums,1);
        vector<int>sum0(nums+1,0);
        vector<int>sum1(nums+1,0);
        for(int i=1;i<n;i++){
            for (int j = 0; j <nums; j++) {
                sum0[j + 1] = (sum0[j] + dp0[j]) % mod;
                sum1[j + 1] = (sum1[j] + dp1[j]) % mod;
            }
            for (int j = 0; j < nums; j++) {
                dp0[j] = (sum1[nums] - sum1[j + 1] + mod) % mod;
                dp1[j] = sum0[j];
            }
        }
        int ans0 = 0;
        for (int x : dp0) ans0 = (ans0 + x) % mod;
        int ans1 = 0;
        for (int x : dp1) ans1 = (ans1 + x) % mod;
        return (ans0+ans1)%mod;
    }
};
