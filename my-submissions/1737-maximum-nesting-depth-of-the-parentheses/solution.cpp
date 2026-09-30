class Solution {
public:
    int maxDepth(string s) {
        int c=0;
        int ans=0;
        for( auto &ch:s){
            if(ch=='('){
                c++;
                ans=max(ans,c);
            }else if(ch==')'){
                ans=max(ans,c);
                c--;
            }
        }
        return ans;
    }
};
