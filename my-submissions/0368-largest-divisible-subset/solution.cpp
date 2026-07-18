class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxi=INT_MIN,last=0;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,0);
        vector<int>child(n,0);
        for(int i=0;i<n;i++){
            child[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    child[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        while(child[last]!=last){
            last=child[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
