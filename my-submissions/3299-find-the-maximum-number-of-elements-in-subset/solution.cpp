class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mpp;
        int maxi=INT_MIN;
        for(int &i:nums){
            mpp[i]++;
            maxi=max(maxi,i);
        }
        int val=1;
        int one=mpp[1];
        for(auto &it:mpp){
            int j=it.first;
            if(j==1){
                continue;
            }
            ans=0;
            long long power=j;
            for(int i=1;;i=i*2){
                if(power > maxi) break;
                if(power > 1LL*maxi/power) break;
                if(i>1)power=power*power;
                if(mpp.count(power)==0)break;
                if(mpp[power]>=2){
                    ans+=2;
                }else if(i>1&&mpp[power]==1){
                    ans+=1;
                    val=max(ans,val);
                    break;
                }
            }
            val=max(val,ans-1);
        }
        if(one%2==0)val=max(val,one-1);
        else val=max(val,one);
        return val;
    }
};
