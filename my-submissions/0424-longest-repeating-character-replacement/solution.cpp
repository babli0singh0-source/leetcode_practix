class Solution {
    int find(unordered_map<char,int>&mpp){
        int ans=0;
        for(auto &it:mpp){
            ans=max(ans,it.second);
        }
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int n=s.size(),left=0,ans=1,maxfreq=-1;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            int len=i-left+1;
            maxfreq=max(maxfreq,mpp[s[i]]);
            int valid=len-maxfreq;
            if(valid<=k){
                ans=max(len,ans);
            }else if(valid>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
