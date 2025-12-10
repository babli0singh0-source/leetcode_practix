class Solution {
public:
    long long factorial(int val,long long mod){
        long long value=1;
        for(int i=1;i<=val;i++){
            value=(value*i)%mod;
        }
        return value;
    }
    int countPermutations(vector<int>& complexity) {
        bool check=true;
        int initial=complexity[0],count=0;
        long long mod=1000000007;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=initial){
                check=false;
                break;
            }
        }
        if(!check)return 0;  
        long long ans=factorial(complexity.size()-1,mod);
        return ans;
    }
};
