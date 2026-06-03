class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // int low=0,high=nums.size()-1,ans=nums.size();
        // while(low<=high){
        //     int mid=(high+low)/2;
        //     if(nums[mid]>=target){
        //         ans=min(ans,mid);
        //         high=mid-1;
        //     }else low=mid+1;
        // }
        // return ans;
    }
};
