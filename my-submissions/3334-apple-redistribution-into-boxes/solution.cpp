class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int s=0,s1=0,c=0;
        for(auto &it: apple){
            s+=it;
        }
        for(int i=capacity.size()-1;i>=0;i--){
            s1+=capacity[i];
            c++;
            if(s1>=s) return c;
        }
        return -1;
        
    }
};
