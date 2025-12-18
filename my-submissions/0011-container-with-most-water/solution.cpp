class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,ans=0,j=height.size()-1;
        while(i<j){
            int val=(j-i)*(min(height[i],height[j]));
            ans=max(ans,val);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return ans;
        
    }
};
