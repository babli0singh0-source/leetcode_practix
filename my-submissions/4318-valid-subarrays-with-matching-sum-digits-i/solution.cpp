class Solution {
    bool isvalid(long long sum,int x){
        if(sum%10!=x)return false;
        string temp=to_string(sum);
        if((temp[0]-'0')!=x)return false;
        return true;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            long long sum=nums[i];
            if (isvalid(sum,x))count++;
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(isvalid(sum,x))count++;
            }
        }
        return count;
    }
};
