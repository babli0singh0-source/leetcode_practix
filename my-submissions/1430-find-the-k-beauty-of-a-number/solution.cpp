class Solution {
public:
    int divisorSubstrings(int num, int k) {
        long long div=1;
        for(int i=0;i<k;i++){
            div=div*10;
        }
        int ans=0;
        long long temp=num;
        while(temp>=(div/10)){
            int x=temp%div;
            if(x!=0&&num%x==0)ans++;
            temp=temp/10;
        }
        return ans;
    }
};
