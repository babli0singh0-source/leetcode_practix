class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int curr=0;
        int prev=nums[0];
        bool ch=false;
        while(i<nums.size()){
            while(prev>=nums[i]){
                i=i+1;
                if(i>=nums.size()){
                    ch=true;
                    break;
                }
            }
            if(ch)break;
            swap(nums[curr+1],nums[i]);
            curr++;
            prev=nums[curr];
        }
        nums.erase(nums.begin()+curr+1,nums.end());
        return nums.size();
    }
};
