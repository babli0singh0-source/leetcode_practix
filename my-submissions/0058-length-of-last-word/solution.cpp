class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool check=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')check=true;
            if(s[i]==' '&&check)break;
            if(check)ans++;
        }
        return ans;
        
    }
};
