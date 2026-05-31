class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+2,0);
        for (int &x :nums) {
            if(x<=n)freq[x]++;
        }
        vector<int>result;
        int i=0;
        while (i<n) {
            int mex = 0;
            while(freq[mex]>0) mex++;
            if (mex==0){
                result.push_back(0);
                if (nums[i] <= n) freq[nums[i]]--;
                i++;continue;
            }
            vector<int>seen(mex,0);
            int need=mex;
            int j=i;
            while (j<n && need>0) {
                int x = nums[j];
                if (x < mex && seen[x] == 0) {
                    seen[x] = 1;
                    need--;
                }
                if (x <= n) freq[x]--;
                j++;
            }
            result.push_back(mex);
            i=j;
        }
        return result; 
    }
};
