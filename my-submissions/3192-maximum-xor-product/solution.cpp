class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long mod=1e9+7;
        for(int i=n-1;i>=0;i--){
            long long mask=(1LL<<i);
            if((mask&a)==(mask&b)){
                a=a|mask;
                b=b|mask;
            }else{
                if(a>b){
                    b=b|mask;
                    a=a&(~mask);//clear it from previous otherwise leads to separate resuly for bith numbers 
                }
                else {
                    a=a|mask;
                    b=b&(~mask);
                }
            }
        }
        return (a%mod)*(b%mod)%mod;
    }
};
