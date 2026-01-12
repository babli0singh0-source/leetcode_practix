class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        if(haystack.size()<needle.size())return ans;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,needle.size())==needle){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
        
    }
};
