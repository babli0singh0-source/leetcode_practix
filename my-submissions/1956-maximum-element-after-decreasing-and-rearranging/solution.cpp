class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int val=1;
        for(int i=0;i<n;i++){
            if(arr[i]>=val)val++;
        }
        return val-1;
    }
};
