class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,curr=0,ans=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            int gain =gas[i]-cost[i];
            total+=gain;
            curr+=gain;
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        if(total>=0)return ans;
        return -1;
        // for(int i=0;i<n;i++){
        //     if(gas[i]<cost[i])continue;
        //     int curr=gas[i]-cost[i]+gas[(i+1)%n];
        //     int j=i+1;
        //     while(curr>=cost[(j)%n]&&j<2*n){
        //         if(j%n==i)return i;
        //         //cout<<i<<' '<<curr<<endl;
        //         curr=curr-cost[j%n]+gas[(j+1)%n];
        //         j++;
        //     }
        // }
        // return -1;
    }
};
