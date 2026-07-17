class Solution {
    bool helper(int i1,int i2,string &s, string &p){
        if(i1<0&&i2<0)return true;
        if(i2<0&&i1>=0)return false;
        if(i1<0&&i2>=0){
            for(i2;i2>=0;i2++){
                if(p[i2]!='*')return false;
            }
            return true;
        }
        if(s[i1]==p[i2]||p[i2]=='?')return helper(i1-1,i2-1,s,p);
        if(p[i2]=='*'){
            return helper(i1,i2-1,s,p)||helper(i1-1,i2,s,p);
        }
        else return false;
    }
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n2;i++){
            if(p[i-1]!='*'){
                break;
            }else dp[0][i]=true;
        }
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s[i1-1]==p[i2-1]||p[i2-1]=='?')dp[i1][i2]=dp[i1-1][i2-1];
                else if(p[i2-1]=='*'){
                    dp[i1][i2]= dp[i1][i2-1]||dp[i1-1][i2];
                }
                else dp[i1][i2]= false;
            }
        }
        return dp[n1][n2];
    }
};
