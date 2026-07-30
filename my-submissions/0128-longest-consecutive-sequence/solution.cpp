class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int &i:nums){
            st.insert(i);
        }
        int ans=0;
        for(int it:st){
            if(st.count(it-1)==1)continue;
            auto curr=it;
            int len=0;
            while(st.count(curr)){
                len++;
                curr++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
