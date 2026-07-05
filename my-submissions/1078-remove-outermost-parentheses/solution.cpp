class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        vector<int>vec;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                int temp=st.top();
                st.pop();
                if(st.empty()){
                    vec.push_back(temp);
                    vec.push_back(i);
                }
            }
        }
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(i==vec[j]){
                j++;
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};
