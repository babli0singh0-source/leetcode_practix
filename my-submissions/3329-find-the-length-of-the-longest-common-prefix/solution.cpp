class Solution {
    // bool find(vector<int>&arr1,int value,int n1){
    //     int l=0,h=n1;
    //     while(l<h){
    //         int mid=(l+h)/2;
    //         if(arr1[mid]==value)return true;
    //         else if(value<arr1[mid]){
    //             h=mid;
    //         }else l=mid+1;
    //     }
    //     return false;
    // }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n1;i++){
            int x=arr1[i];
            while(x>0){
                mpp[x]=1;
                x=x/10;
            }
        }
        int final=0;
        for(int i=n2-1;i>=0;i--){
            int x=arr2[i];
            int j=0;
            int ans=INT_MAX;
            while(x>0){
                if(mpp.count(x)){
                    ans=min(ans,j);
                }
                x=x/10;
                j++;
            }
            if(ans!=INT_MAX)
            final=max(final,(j-ans));
        }
        return final;  
    }
};
