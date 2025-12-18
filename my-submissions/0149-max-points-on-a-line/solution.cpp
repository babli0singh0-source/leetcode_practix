class Solution {
public:
    int maxPoints(vector<vector<int>>& points) { 
           
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            unordered_map<float,int>mpp;
            int c=0;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0])c++;
                else if(points[i][1]==points[j][1])mpp[0]++;
                else{
                    float m=(float(points[i][1]-points[j][1]))/(float(points[i][0]-points[j][0]));
                    mpp[m]++;
                }
            }
            ans=max(ans,c);
            for(auto it:mpp){
                ans=max(ans,it.second);
            }
        }
        return ans+1;
        
    }
};
