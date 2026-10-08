class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int left=0;
        int valid=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(valid>0)ans=ans+'(';
                valid++;
            }else {
                if(valid>1)ans=ans+')';
                valid--;
            }
        }
        return ans;
    }
};
