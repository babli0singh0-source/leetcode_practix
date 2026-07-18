class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,-1);
        int n=s.size();
        int ans=0;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']=i;
            int mini=min({v[0],v[1],v[2]});
            ans+=(1+mini);
        }
        return ans;
    }
};
