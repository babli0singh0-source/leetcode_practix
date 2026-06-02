class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int i=0;i<numRows;i++){
            vector<int>srow(i+1,1);
            if(i+1>2){
                for(int j=1;j<i;j++){
                    srow[j]=prev[j-1]+prev[j];
                }
            }
            prev=srow;
            ans.push_back(srow);
        }
        return ans;
    }
};
