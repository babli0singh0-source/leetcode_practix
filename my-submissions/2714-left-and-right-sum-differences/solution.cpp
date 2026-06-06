class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size(),ls=0,rs=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(i>0){
                ls+=nums[i-1];
                ans[i]=abs(ls-ans[i]);
            }
            int x=(n-1)-i;
            if(x<n-1){
                rs+=nums[x+1];
                ans[x]=abs(rs-ans[x]);
            }
        }
        return ans;
    }
};
