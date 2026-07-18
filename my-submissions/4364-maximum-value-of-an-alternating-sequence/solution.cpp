class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long x=(n-1)/2;
        long long y=n-1-x;
        if(x<y)swap(x,y);
        if(n%2==0)return s+(1LL*m*x)-(1*y);
        if(y!=0)return s+(1LL*m*x)-(1*(y-1));
        return s;
    }
};
