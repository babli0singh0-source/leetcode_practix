class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int x=nums1.size(),y=nums2.size(), i,j;

        for( i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        if(i<x){
            for(i;i<x;i++)ans.push_back(nums1[i]);
        }
        if(j<y){
            for(j;j<y;j++)ans.push_back(nums2[j]);
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;

        }
        if(ans.size()%2==0){
            return (double(ans[ans.size()/2]+ans[ans.size()/2-1]))/2;
        }else{
            return ans[ans.size()/2];
        }
        
    }
};
