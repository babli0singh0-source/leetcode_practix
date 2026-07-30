class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<9)return n;
        if(n<17)return 8+(n-8)*2;
        if (n<25)return 8+8*2+ (n-16)*3;
        return 8+8*2+ 8*3 +(n-24)*4;
    }
};
