class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n);
        vector<int>prefixGcd(n);
        int maxi =-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mx[i]=maxi;
            prefixGcd[i]=gcd(nums[i], mx[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        for(int i=0;i<(n/2);i++){
            ans+=gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return ans;
    }
};
