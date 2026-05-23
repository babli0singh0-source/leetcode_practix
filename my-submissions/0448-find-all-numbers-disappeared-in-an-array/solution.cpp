class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto &it:nums){
            mpp[it]=1;
        } 
        int i=1;
        vector<int>ans;
        for(int i=1;i<=nums.size();i++){
            if(!mpp.count(i))ans.push_back(i);
        }  
        return ans;
    }
};
