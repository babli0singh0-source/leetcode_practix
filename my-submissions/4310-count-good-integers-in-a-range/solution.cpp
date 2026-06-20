class Solution {
    long long dp[16][11][2];
    long long dfs(int pos,int prev,bool tight,bool started ,string &s,int k){
        if(pos==s.size())return started?1:0;
        if(tight==0&&dp[pos][prev+1][started]!=-1){
            return dp[pos][prev+1][started];
        }
        int limit=tight==1?(s[pos]-'0'):9;
        long long ans=0;
        for(int i=0;i<=limit;i++){
            bool istight=tight&&(i==limit);
            if(!started){
                if(i==0)ans+=dfs(pos+1,-1,istight,0,s,k);
                else ans+=dfs(pos+1,i,istight,1,s,k);
            }else {
                if(abs(i-prev)<=k)ans+=dfs(pos+1,i,istight,1,s,k);
            }
        }
        if(tight==0){
            dp[pos][prev+1][started]=ans;
        }
        return ans;
    }
    long long countgood(long long x,int k){
        if(x<=0)return 0;
        string s=to_string(x);
        memset(dp,-1,sizeof(dp));
        return dfs(0,-1,true,false,s,k);
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        return countgood(r,k)-countgood(l-1,k);
    }
};
