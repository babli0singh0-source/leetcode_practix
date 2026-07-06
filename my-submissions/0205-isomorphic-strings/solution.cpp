class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>freq1(128,-1);
        vector<int>freq2(128,-1);
        int i=0,n=s.size();
        while(i<n){
            if(freq1[s[i]]==-1&&freq2[t[i]]==-1){
                freq1[s[i]]=(int)t[i];
                freq2[t[i]]=(int)s[i];
                i++;
            }else {
                if(freq1[s[i]]==(int)t[i]&&freq2[t[i]]==(int)s[i]){
                    i++;
                    continue;
                }
                else return false;
            }
        }
        return true;
    }
};
