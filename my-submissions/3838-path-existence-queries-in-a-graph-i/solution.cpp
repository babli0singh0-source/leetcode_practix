class Solution {
    bool find(int i,vector<int>vec){
        int left=0;
        int right=vec.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(vec[mid]==i)return true;
            else if(vec[mid]>i)right=mid-1;
            else left=mid+1;
        }
        return false;
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>upar(n,-1);
        for(int i=0;i<n;i++)upar[i]=i;
        int left=0;
        int right=1;
        while(right<n){
            if(abs(nums[left]-nums[right])<=maxDiff){
                upar[right]=upar[left];
                right++;
            }else{
                if(right-left==1)left=right;
                else left=right-1;
            }
        }
        vector<bool>ans;
        for(auto &it:queries){
            int a=it[0];
            int b=it[1];
            ans.push_back(upar[a]==upar[b]);
        }
        return ans;
    }
};
