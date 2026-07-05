class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int glbmaxi=INT_MIN;
        int ans=0;
        for(auto &it:nums){
            string temp=to_string(it);
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=0;j<temp.size();j++){
                maxi=max(maxi,temp[j]-'0');
                mini=min(mini,temp[j]-'0');
            }
            int val=maxi-mini;
            if(val>glbmaxi){
                ans=it;
                glbmaxi=val;
            }else if(val==glbmaxi){
                ans+=it;
            }
        }
        return ans;
    }
};
