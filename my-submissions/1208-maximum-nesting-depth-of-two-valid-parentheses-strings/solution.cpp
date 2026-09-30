class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int c=0;
        vector<int>ans;
        for( auto &ch:seq){
            if(ch=='('){
                c++;
                ans.push_back(c%2);
            }else{
                ans.push_back(c%2);
                c--;
            }
        }
        return ans;
    }
};
