class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        if(nums.size()==0)return 0;
        int longest=1;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)!=st.end())continue;
            int c=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                c++;
                x=x+1;
            }
            longest =max(longest,c);
        }
        return longest;
    }
};
