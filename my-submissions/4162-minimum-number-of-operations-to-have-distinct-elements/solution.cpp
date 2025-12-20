class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp,newm;
        int n=nums.size();
        bool check=true;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                newm[nums[i]]++;
                check=false;
            }
        }
        if(check)return 0;
        int count=0;
        if(n<=3)return 1;
        while(!check&&nums.size()>2){
            for(int i=0;i<3;i++){
                if(newm.find(nums[i])!=newm.end()){
                    newm[nums[i]]--;
                    if(newm[nums[i]]==0) newm.erase(nums[i]);
                }    
            }
            nums.erase(nums.begin(),nums.begin()+3);
            count++;
            if(newm.size()==0)check=true;
        }
        if(nums.size()<3&&!check)count++;
        return count;    
    }
};
