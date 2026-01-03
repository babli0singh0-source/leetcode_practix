class Solution {
public:
    string reversePrefix(string s, int k) {
        string ans="";
        for(int i=k-1;i>=0;i--){
            ans=ans+s[i];
        }
        for(int i=k;i<s.size();i++){
            ans=ans+s[i];
        }
        return ans;
        
        
    }
};
