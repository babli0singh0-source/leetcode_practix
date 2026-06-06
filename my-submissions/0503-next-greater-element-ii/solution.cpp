class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            while(!st.empty()&&nums[ind]>=st.top()){
                st.pop();
            }
            if(!st.empty())ans[ind]=st.top();
            st.push(nums[ind]);
        }
        return ans;
    }
};
