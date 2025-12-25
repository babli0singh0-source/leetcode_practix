class Solution {
public:
    static bool customsort(int a,int b){
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end(),customsort);
        for(int i=0;i<k&&i<happiness.size();i++){
            if(happiness[i]-i<=0)break;
            ans=ans+happiness[i]-i;
        }
        return ans;    
    }
}; 
