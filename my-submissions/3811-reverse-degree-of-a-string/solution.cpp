class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int temp='a'-s[i]+26;
            ans+=temp*(i+1);
        }
        return ans;
        
    }
};
