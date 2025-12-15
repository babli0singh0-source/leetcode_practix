class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int i=0,j=1,count=1;
        vector<int>v;
        if(prices.size()<2)return prices.size();
        while(j!=prices.size()){
            if((prices[i]-prices[j])==1){
                count++;
            }
            else{
                v.push_back(count);
                count=1;
            }
            j++;
            i++;
        }
        v.push_back(count);
        long long ans=0;
        for(int k=0;k<v.size();k++){
            while(v[k]>0){
                ans+=v[k];
                v[k]--;
            }
        }
        return ans;    
    }
};
