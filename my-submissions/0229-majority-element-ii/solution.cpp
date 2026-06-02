class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=nums[0],n2=nums[0],c1=0,c2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=n2&&c1==0){
                n1=nums[i];
                c1++;
            }
            else if(nums[i]!=n1&&c2==0){
                n2=nums[i];
                c2++;
            }
            else if(nums[i]==n1)c1++;
            else if(nums[i]==n2)c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(auto &it:nums){
            if(it==n1)c1++;
            else if(it==n2)c2++;
        }
        if(c1>nums.size()/3)ans.push_back(n1);
        if(c2>nums.size()/3)ans.push_back(n2);
        return ans;
    }
};
