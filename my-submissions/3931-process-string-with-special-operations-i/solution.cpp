class Solution {
public:
    string processStr(string s) {
        string ans="";
        int ia=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                ans+=s[i];
                ia++;
            }else if(s[i]=='*'){
                if(ia>-1){
                    ans.pop_back();
                    ia--;
                }
            }else if(s[i]=='#'){
                ans+=ans;
                ia=ia*2+1;
            }else if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};
