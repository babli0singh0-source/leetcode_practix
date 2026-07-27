class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            while(!st.empty()&&nums[st.top()]<=nums[ind]){
                st.pop();
            }
            if(st.empty()){
                ans[ind]=-1;
            }else{
                ans[ind]=nums[st.top()];
            }
            st.push(ind);
        }
        return ans;
    }
};
