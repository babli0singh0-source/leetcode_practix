class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int i=0;
        int ans=INT_MIN;
        while(i<=n){
            int temp=lower_bound(citations.begin(),citations.end(),i)-citations.begin();
            int curr=n-temp;

            if(curr>=i)ans=max(i,ans);
            i++;
        }
        return ans==INT_MIN?-1:ans;
    }
};
