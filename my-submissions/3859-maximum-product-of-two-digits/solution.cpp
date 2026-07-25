class Solution {
public:
    int maxProduct(int n) {
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        while(n>0){
            int temp=n%10;
            if(temp>maxi1){
                maxi2=maxi1;
                maxi1=temp;
            }else if(temp>maxi2){
                maxi2=temp;
            }
            n=n/10;
        }
        return maxi1*maxi2;
        
    }
};
