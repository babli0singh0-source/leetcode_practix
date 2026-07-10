class Solution {
public:
    int maxArea(vector<int>& height) {
        int li=0;
        int ri=height.size()-1;
        int ans=INT_MIN;
        int lmax=height[li];
        int rmax=height[ri];
        while(li<ri){
            int temp=(ri-li)*min(lmax,rmax);
            ans=max(ans,temp);
            if(lmax<=rmax){
                li++;
                lmax=max(lmax,height[li]);
            }else {
                ri--;
                rmax=max(rmax,height[ri]);
            }
        }
        return ans;
    }
};
