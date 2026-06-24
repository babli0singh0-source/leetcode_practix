class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left=0;
        int right=0;
        int ans=1;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                left=right;
                right=i;
                if(seats[left]!=1){
                    int diff=right-left;
                    ans=max(ans,diff);
                    continue;
                }
                int temp=(right+left)/2;
                int diff=temp-left;
                ans=max(ans,diff);
            }
            if(i==seats.size()-1){
                left=right;
                right=i;
                int diff=right-left;
                ans=max(ans,diff);
            }
        }
        return ans;
    }
};
