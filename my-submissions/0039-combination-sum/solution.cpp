class Solution {
    vector<vector<int>>ans;
    void helper(int ind,int target,vector<int>& candidates,vector<int>&curr){
        if(target<0)return ;
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(ind==candidates.size())return;
        curr.push_back(candidates[ind]);
        helper(ind,target-candidates[ind],candidates,curr);
        curr.pop_back();
        helper(ind+1,target,candidates,curr);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        helper(0,target,candidates,curr);
        return ans;
    }
};
