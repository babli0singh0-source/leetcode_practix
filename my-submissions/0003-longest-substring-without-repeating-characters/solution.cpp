class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(!mpp.count(s[i])){
                mpp[s[i]]=i;
                ans=max(ans,int(mpp.size()));
            }else{
                int temp=mpp[s[i]];
                for (auto it = mpp.begin(); it != mpp.end(); ) {
                    if (it->second <= temp)
                        it = mpp.erase(it);   // erase returns next iterator
                    else
                        ++it;
                }
                mpp[s[i]]=i;
            }
        }
        return ans;   
    }
};
