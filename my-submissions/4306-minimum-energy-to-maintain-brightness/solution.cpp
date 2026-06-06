class Solution {
    bool static custumsort(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])return true;
        else if(a[0]==b[0])return a[1]<b[1];
        return false;
    }
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long count =0;
        if(brightness>n)return -1;
        else if(brightness<=2)count=1;
        else{
            count=ceil((brightness*1.0)/3);
        }
        long long active=0;
        sort(intervals.begin(),intervals.end(),custumsort);
        int s=intervals[0][0];
        int e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>e){
                active+=e-s+1;
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else if(intervals[i][0]<=e){
                e=max(e,intervals[i][1]);
            }
        }
        active+=e-s+1;
        return active*count;
    }
};
