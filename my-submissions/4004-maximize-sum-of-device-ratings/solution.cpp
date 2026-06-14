class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long rating2=0;
        long long rating=0;
        int globalmin1=INT_MAX;
        int globalmin2=INT_MAX;
        for(int i=0;i<units.size();i++){
            int mini1=INT_MAX;
            int mini2=INT_MAX;
            for(int j=0;j<units[i].size();j++){
                if(units[i][j]<=mini1){
                    mini2=mini1;
                    mini1=units[i][j];
                }else if(units[i][j]<mini2){
                    mini2=units[i][j];
                }
            }
            if(mini2==INT_MAX)mini2=0;
            rating+=mini1;
            globalmin1=min(globalmin1,mini1);
            globalmin2=min(globalmin2,mini2);
            rating2+=mini2;
        }
        return max(rating,rating2-globalmin2+globalmin1);
        
    }
};
