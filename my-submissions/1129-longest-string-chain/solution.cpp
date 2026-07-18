class Solution {
    static bool custumsort(string &a,string &b){
        int n1=a.size();
        int n2=b.size();
        return n1<n2;
    }
    bool compare(string a,string b){
        int n1=a.size();
        int n2=b.size();
        if(n1-n2!=1)return false;
        int i1=0,i2=0;
        while(i1<n1&&i2<n2){
            if(a[i1]==b[i2]){
                i1++;
                i2++;
            }else{
                i1++;
            }
        }
        if(i2==n2)return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),custumsort);
        int n=words.size(),maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
