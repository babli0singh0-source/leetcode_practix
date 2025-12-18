class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int s=i+1,e=nums.size()-1;
            while(s<e){
                if((nums[i]+nums[s]+nums[e])==0){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s<e&&(nums[s]==nums[s+1]))s++;
                    while(s<e&&(nums[e]==nums[e-1]))e--;
                    s++;
                    e--;
                }else if((nums[i]+nums[s]+nums[e])<0)s++;
                else e--;
            }
        }
        return ans;
        
    }
};
