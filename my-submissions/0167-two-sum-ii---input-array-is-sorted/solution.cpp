class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mpp;
        vector<int>ans(2,0);
        for(int i=0;i<numbers.size();i++){
            //if((numbers[i]>target)&&target>0)return{};
            if(mpp.find(target-numbers[i])!=mpp.end()){
                ans[0]=min(mpp[target-numbers[i]],(i+1));
                ans[1]=max(mpp[target-numbers[i]],(i+1));
                break;
            }else mpp[numbers[i]]=i+1;
        }
        return ans;
        
    }
};
