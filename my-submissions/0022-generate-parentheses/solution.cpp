class Solution {
    vector<string>ans;
    void helper(string prev,int valid,int count){
        if(valid==0&&count==0)ans.push_back(prev);
        
        if(count>0)helper(prev+'(',valid+1,count-1);
        if(valid>0)helper(prev+')',valid-1,count);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        helper("(",1,n-1);
        return ans;
    }
};
