class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'==0)continue;
            else {
                str+=s[i];
                sum+=(s[i]-'0');
            }
        }
        if(str=="")return 0;
        int x= stoi(str);
        return x*sum;
    }
};
