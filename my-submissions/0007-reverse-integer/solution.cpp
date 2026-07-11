class Solution {
public:
    int reverse(int x) {
        long long revr=0;
        while(x!=0){
            int y=x%10;
            revr=revr*10+y;
            if(revr>INT_MAX||revr<INT_MIN)return 0;
            x/=10;
        }
        return revr;
    }
};
