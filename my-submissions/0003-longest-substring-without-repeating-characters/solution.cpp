class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int ans=0;
        int left=0;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(mpp.count(ch)==0||mpp[ch]<left){
                count=i-left+1;
                ans=max(count,ans);
                mpp[ch]=i;
            }else{
                left=mpp[ch]+1;
                mpp[ch]=i;
            }
        }
        return ans;
    }
};
