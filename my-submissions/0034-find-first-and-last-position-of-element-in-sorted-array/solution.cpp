class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,s=-1,e=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                s=mid;
                e=mid;
                while(s>0&&nums[s-1]==target){
                    s--;
                }
                while(e<nums.size()-1&&nums[e+1]==target)e++;
                break;
            }else if(nums[mid]>target)h=mid-1;
            else l=mid+1;
        }
        return {s,e};
    }
};
