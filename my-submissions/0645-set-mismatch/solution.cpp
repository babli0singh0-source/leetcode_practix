class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2,0);
        sort(nums.begin(),nums.end());
        stack<int>st;
        for(int i=0;i<n;i++){
            if(i!=n-1&&nums[i]==nums[i+1]){
                ans[0]=nums[i];
                continue;
            }
            st.push(nums[i]);
        }
        while(st.size()>0){
            if(st.top()==n)st.pop();
            else {
                ans[1]=n;
                break;
            }
            n--;   
        }
        if(ans[1]==0)ans[1]=1;
        return ans;
        
    }
};
