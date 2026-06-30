class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,0);
        int n=s.size();
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            while(v[0]>=1&&v[1]>=1&&v[2]>=1){
                ans+=(n-i);
                v[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};
