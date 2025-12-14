class Solution {
public:
    int numberOfWays(string corridor) {
        stack<pair<int,int>>s;
        int c=0,k=0;
        long long mod=1000000007;
        long long ans=1;
        char ch;
        for(int i=0;i<corridor.size();i++){
            
            if(corridor[i]=='S'){
                c++;
                if(c==1)k=i;
                else if(c==2){
                    s.push({k,i});
                    c=0;
                }
            }
        }
        if(s.size()==0)return 0;
        if(k!=(s.top().first))return 0;
        if(s.size()==1)return 1;
        while(s.size()!=1){
            int t1=s.top().first;
            s.pop();
            int t2=s.top().second;
            ans=(ans*((t1-t2)%mod))%mod;
        }
        return int(ans);
        
    }
};
