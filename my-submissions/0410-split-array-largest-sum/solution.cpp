class Solution {
    bool is(long long mid,vector<int>&nums,int k){
        int count =1;
        int target=0;
        for(auto &it:nums){
            target+=it;
            if(target>mid){
                target=it;
                count++;
                if(count>k)return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //max sum can be btw numska total sum and max element in nums
        int maxel=INT_MIN;
        long long sum=0;
        for(auto &it:nums){
            sum+=it;
            maxel=max(maxel,it);
        }
        long long left=maxel;
        long long right=sum;
        if(k==1)return (int)sum;
        long long mid;
        while(left<=right){
            mid=(left+right)/2;
            if(is(mid,nums,k)){
                right=mid-1;
            }else{
                left =mid+1;
            }
        }
        return (int)left;
    }
};
