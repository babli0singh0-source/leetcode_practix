class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long>presum(2*n+1,0);
        int cnt=n;
        presum[cnt]=1;
        long long ans=0;
        long long temp=0;
        for(int &it:nums){
            if(it==target){
                temp+=presum[cnt];
                cnt++;
                presum[cnt]++;
            }else {
                cnt--;
                temp-=presum[cnt];
                presum[cnt]++;
            }
            ans+=temp;
        }
        return ans;
    }
};
