class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int v=lights[i];
                int left=max(0,i-v);
                int right=min(n-1,i+v);
                diff[left]++;
                diff[right+1]--;
            }
        }
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(curr>0){
                diff[i]=1;
            }else{
                diff[i]=0;
            }
        }
        int count=0;
        for(int i=0;i<n;){
            if(diff[i]==0){
                i=i+3;
                count++;
            }else i++;
        }
        return count;
    }
};
