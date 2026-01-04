class Solution {
public:
    int divisorcount(int x, int &sum) {
        int count = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                count++;
                sum += i;

                if (i != x / i) {      // avoid double count
                    count++;
                    sum += x / i;
                }
            }
        }
        return count;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            if(divisorcount(nums[i],sum)==4){
                ans=ans+sum;
            }
        }
        return ans;

        
    }
};
