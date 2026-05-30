class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_set<int>r;
        unordered_set<int>c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0)continue;
                r.insert(i);
                c.insert(j);
            }
        }
        for(auto &it:r){
            for(int x=0;x<m;x++)matrix[it][x]=0;    
        }
        for(auto &it:c){
            for(int x=0;x<n;x++)matrix[x][it]=0;    
        }
        
    }
};
