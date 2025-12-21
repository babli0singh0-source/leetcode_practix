class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n;
        int revr=0;
        while(temp>0){
            revr=revr*10+(temp%10);
            temp=temp/10;
        }
        return abs(n-revr);
        
    }
};
