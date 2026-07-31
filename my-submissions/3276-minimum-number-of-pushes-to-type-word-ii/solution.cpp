class Solution {
public:
    int minimumPushes(string word) {
        vector<int>bucket(26);
        for(char &ch:word){
            bucket[ch-'a']++;
        }
        sort(bucket.begin(),bucket.end());
        int ans=0;
        int siz=bucket.size();
        for(int j=siz-1;j>=0;j--){
            int i=bucket[j];
            if((26-j)<9)ans+=i*1;
            else if((26-j)<17)ans+= i*2;
            else if ((26-j)<25)ans+= i*3;
            else ans+=i*4;
        }
        return ans;
    }
};
