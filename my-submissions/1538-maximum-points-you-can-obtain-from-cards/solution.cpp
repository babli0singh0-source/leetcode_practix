class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=0;i<min(k,n);i++){
            sum+=cardPoints[i];
        }
        int left=min(n,k-1);
        int ans=sum;
        int right=n-1;
        while(left>=0){
            sum=sum-cardPoints[left]+cardPoints[right];
            ans=max(ans,sum);
            right--;
            left--;
        }
        return ans;
    }
};
