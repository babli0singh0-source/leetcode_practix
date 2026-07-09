class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>v(n+1,0);
        for(int i=0;i<=n;i++){
            if(ranges[i]==0)continue;
            int cs= max(0,i - ranges[i]);
            v[cs]=max(v[cs], i + ranges[i]);   
        }
        int ans=0;
        int farthest=0;
        int curr=0;
        for (int i = 0; i <= n; i++) {
            farthest = max(farthest, v[i]);
            if(farthest<=i)return -1;
            if (i == curr) {
                ans++;
                curr=farthest;
                if(curr>=n)break;
            }
        }
        return ans;
    }
};
