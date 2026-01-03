class Solution {
public:
    int numOfWays(int n) {
        int mod=1000000007;
        // ABA
        //TO ABA->3
        //TO ABC->2
        //ABC
        //TO ABA->2
        //TO ABC->2
        //BASE CASE ABA->6 and ABC-> 6
        long long dps=6,dpd=6;
        for(int i=2;i<=n;i++){
            long long ns=((dps*3)%mod+(dpd*2)%mod)%mod;
            long long nd=((dps*2)%mod+(dpd*2)%mod)%mod;
            dps=ns;
            dpd=nd;
        }
        return (dps+dpd)%mod;       
    }
};
