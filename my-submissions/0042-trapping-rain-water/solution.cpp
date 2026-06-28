class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int lmax=height[0];
        int n=height.size();
        int rmax=height[n-1];
        int li=0,ri=n-1;
        while(li<ri){
            int temp=0;
            if(lmax<=rmax){
                li++;
                lmax=max(lmax,height[li]);
                temp=min(lmax,rmax)-height[li];
            }else{
                ri--;
                rmax=max(rmax,height[ri]);
                temp=min(lmax,rmax)-height[ri];
            }
            ans=ans+(temp>0?temp:0);
        }
        return ans;
    }
};
