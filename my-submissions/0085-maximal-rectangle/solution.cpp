class Solution {
public:
    // int find(vector<int>&v){
    //     stack<int> s;
    //     int psi=0,val=0,ans=0;
    //     for(int i=0;i<v.size();i++){
    //         while(s.size()!=0&&v[s.top()]>v[i]){
    //             int area =v[s.top()]*(i-psi-1);
    //             ans=max(ans,area);
    //             s.pop();
    //         }
    //         s.push(i);
    //         val=v[i];
    //         psi=s.top();
    //     }
    //     return ans;
    // }
    int find(vector<int>& v) {
    stack<int> s;
    int ans = 0;
    int n = v.size();

    for(int i = 0; i < n; i++) {
        while(!s.empty() && v[s.top()] > v[i]) {
            int height = v[s.top()];
            s.pop();

            int width;
            if(s.empty())
                width = i;
            else
                width = i - s.top() - 1;

            ans = max(ans, height * width);
        }
        s.push(i);
    }

    // Process remaining bars
    while(!s.empty()) {
        int height = v[s.top()];
        s.pop();

        int width;
        if(s.empty())
            width = n;
        else
            width = n - s.top() - 1;

        ans = max(ans, height * width);
    }

    return ans;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int >histo(matrix[0].size(),0);
        int final=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    histo[j]=histo[j]+1;
                }else histo[j]=0;
            }
            final=max(final,find(histo));
        }
        return final;
        
    }
};
