class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int &i:nums){
            mpp[i]++;
        }
        int n=nums.size();
        vector<pair<int,int>>hash;
        for(auto &it:mpp){
            hash.push_back({it.second,it.first});
        }
        sort(hash.begin(),hash.end());
        vector<int>ans;
        for(int i=hash.size()-1;i>=0;i--){
            ans.push_back(hash[i].second);
            k--;
            if(k==0)break;
        }
        return ans;
    }
};
