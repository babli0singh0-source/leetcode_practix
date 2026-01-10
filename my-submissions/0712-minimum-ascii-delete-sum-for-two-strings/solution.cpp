//subsequence
class Solution {
public:
    int find(string &s){
        int sum=0;
        for(auto &ch:s){
            sum+=int(ch);
        }
        return sum;

    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),sum1=find(s2);
        vector<int>dpprev(m+1,0),dpcurr(m+1,0);
        for(int i=1;i<=n;i++){
            sum1+=int(s1[i-1]);
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dpcurr[j]=dpprev[j-1]+int(s1[i-1]);
                }else{
                    dpcurr[j]=max(dpcurr[j-1],dpprev[j]);
                }
            }
            dpprev=dpcurr;
        }
        return sum1-2*dpprev[m];
        
    }
};
//substring 
// class Solution {
// public:
//     int find(string &s){
//         int sum=0;
//         for(auto &ch:s){
//             sum+=int(ch);
//         }
//         return sum;

//     }
//     int minimumDeleteSum(string s1, string s2) {
//         int n=s1.size(),m=s2.size(),sum1=find(s2),ans=0;
//         vector<int>dpprev(m+1,0),dpcurr(m+1,0);
//         for(int i=1;i<=n;i++){
//             sum1+=int(s1[i-1]);
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1]){
//                     dpcurr[j]=dpprev[j-1]+1;
//                     for(int k=1;k<=dpcurr[j];k++){
//                         string temp=s1.substr(i-k,k);
//                         ans=max(ans,find(temp));
//                     }
//                 }
//             }
//             dpprev=dpcurr;
//         }
//         return sum1-2*ans;
        
//     }
// };
