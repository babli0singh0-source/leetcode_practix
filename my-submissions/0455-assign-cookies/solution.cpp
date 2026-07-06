class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ng=g.size();
        int ns=s.size();
        int ans=0;
        while(i<ng&&j<ns){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};
