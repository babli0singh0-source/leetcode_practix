class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long mod=1e9+7;
        long long resources = k;
        long long operations = 0;
        long long ans = 0;
        for (int x : nums) {
            if (resources < x) {
                long long need = x - resources;
                long long ops = (need + k - 1) / k;
                __int128 cost=(__int128)ops*(2 * (__int128)operations + ops + 1) / 2;
                ans = (ans + (long long)(cost % mod)) % mod;
                operations += ops;
                resources += ops * 1LL * k;
            }
            resources -= x;
        }
        return ans % mod;
    }
};
