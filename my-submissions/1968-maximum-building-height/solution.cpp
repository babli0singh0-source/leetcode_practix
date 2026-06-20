class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto r=restrictions;
        r.push_back({1,0});
        sort(r.begin(),r.end());
        if(r.back()[0]!=n)r.push_back({n,n-1});
        int s=r.size();
        for(int i=1;i<s;i++){
            r[i][1]=min(r[i][1],r[i-1][1]+(r[i][0]-r[i-1][0]));
        }
        for(int i=s-2;i>=1;i--){
            r[i][1]=min(r[i][1],r[i+1][1]+r[i+1][0]-r[i][0]);
        }
        int best =0;
        for(int i=1;i<s;i++){
            int ans=(r[i][0]-r[i-1][0]+r[i][1]+r[i-1][1])/2;
            best=max(best,ans);
        }
        return best;
    }
};
