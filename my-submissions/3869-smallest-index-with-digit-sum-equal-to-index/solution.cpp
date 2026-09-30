class Solution {
    int digisum(int x){
        int sum=0;
        while(x>0){
            int y=x%10;
            sum+=y;
            x=x/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int temp=digisum(nums[i]);
            if(temp==i)return i;
        }
        return -1;
    }
};
