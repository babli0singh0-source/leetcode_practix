class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int cm=0;
        for(auto &it:mpp){
            if(it.second>1)cm++;
        }
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i=i+3){
            if(cm==0){
                break;
            }
            ans++;
            for(int j=i;j<min(i+3,n);j++){
                mpp[nums[j]]--;
                if(mpp[nums[j]]==1)cm--;
            }
        }
        return ans;
    }
};
