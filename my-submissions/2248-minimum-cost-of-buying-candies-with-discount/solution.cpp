class Solution {
    static bool custumsort(int a,int b){
        return a>b;
    }
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),custumsort);
        int ans=0;
        for(int i=0;i<cost.size();i=i+3){
            if(i+1<cost.size()){
                ans+=cost[i]+cost[i+1];
            }else ans+=cost[i];
        }
        return ans;
    }
};
