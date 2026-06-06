class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count =0;
        int prev=-1;
        if(n==0||n==1)return false;
        while(n>1){
            int curr=n%2;
            if(curr==prev&&curr==1)count++;
            if(count>1)return false;
            n=n/2;
            prev=curr;
        }
        if(prev==1)count++;
        if(count==1)return true;
        return false;
    }
};
