class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //removing the extra space
        int count=0,element=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
                count=1;
            }else if(nums[i]==element){
                count++;
            }else count--;
        }count=0;
        for(auto &it: nums){
            if(it==element)count++;
        }
        if(count>(nums.size()/2))return element;
        return -1;
        // unordered_map<int,int>mpp;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]>(int)(n/2))return nums[i];
        // }
        // return 0;
    }
};
