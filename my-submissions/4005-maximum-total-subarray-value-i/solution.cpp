class Solution {
    bool static custumsort(long long &a,long long &b){
        return a>b;
    }
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1)return 0;
        long long ans=0;
        long long maxi=nums[0];
        long long mini=nums[0];
        for(int i=1;i<n;i++){
            maxi=max(1LL*nums[i],maxi);
            mini=min(1LL*nums[i],mini);
        }
        ans=maxi-mini;
        return k*ans;
        // maxi=nums[n-1];
        // mini=nums[n-1];
        // for(int i=n-1;i>=1;i--){
        //     maxi=max(1LL*nums[i],maxi);
        //     mini=min(1LL*nums[i],mini);
        //     possible.push_back(maxi-mini);
        // }
        // long long ans=0;
        // sort(possible.begin(),possible.end(),custumsort);
        // int i=0;
        // while(k!=0&&i!=n-1){
        //     ans+=possible[i];
        //     k--;
        //     i++;
        // }
        // if(k>0){
        //     ans+=(k*possible[0]);
        // }
        // return ans;
    }
};
