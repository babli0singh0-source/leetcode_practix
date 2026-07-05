class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        int n=s.size();
        while(i<n&&s[i]==' ')i++;
        while(i<n){
            while(i<n&&s[i]!=' '){
                s[j++]=s[i++];
            }
            while(i<n&&s[i]==' '){
                i++;
            }
            if(i<n)s[j++]=' ';
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        int k=0;
        n=s.size();
        for(i=0;i<=n;i++){
            if(i==n||s[i]==' '){
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
        }
        return s;
        // stringstream ss(s);
        // string token;
        // string ans="";
        // while(ss>>token){
        //     ans=token+" "+ans;
        // }
        // ans.pop_back();
        // return ans;
    }
};
