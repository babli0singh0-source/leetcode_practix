class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>v(numRows,"");
        string ans="";
        queue<int>q;
        int i=0;
        for(i=0;i<numRows;i++){
            q.push(i);
        }i=i-2;
        while(i>0){
            q.push(i);
            i--;
        }
        for(i=0;i<s.size();i++){
            int index=q.front();
            v[index].push_back(s[i]);
            q.push(index);
            q.pop();
        }
        for(i=0;i<numRows;i++){
            ans=ans+v[i];
        }
        return ans;
        
    }
};
