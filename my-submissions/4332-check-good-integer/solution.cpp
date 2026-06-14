class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sqsum=0;
        long long sum=0;
        while(n>0){
            int x=n%10;
            sqsum+=x*x;
            sum+=x;
            n=n/10;
        }
        if((sqsum-sum)>=50)return true;
        return false;
    }
};
