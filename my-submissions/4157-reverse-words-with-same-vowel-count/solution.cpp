class Solution {
public:
    int count(string &word){
        int c=0;
        for(auto &ch:word){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                c++;
            }
        }
        return c;
    }
    string reverseWords(string s) {
        
        string token;
        int given=0;
        string first="";
        for(auto &ch:s){
            if(isspace(ch))break;
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')given++;
            first+=(ch);
        }
        string ans=" ";
        if(s.size()==first.size())return s;
        else s=s.substr(first.size()+1);
        stringstream ss (s);
        while(ss>>token){
            if(count(token)==given){
                reverse(token.begin(),token.end()); 
                ans+=token;
                ans+=(" ");
            }else {
                ans+=(token);
                ans+=(" ");
            }        
        }
        first+=ans;
        first.pop_back();
        return first;
    }
};
