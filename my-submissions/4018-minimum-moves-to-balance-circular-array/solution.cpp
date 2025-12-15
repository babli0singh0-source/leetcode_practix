class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        long long posc=0;
        int i=-1;
        for(int j=0;j<n;j++){
            if(balance[j]<0)i=j;
            posc+=balance[j];
        }
        if(i==-1)return 0;
        if(posc<0)return -1;
        long long ans=0;
        for(int j=1;j<n;j++){
            long long  count=0;      
            if((balance[i]<0)&&balance[(i+j)%n]>0){
                long long val=min(abs(balance[i]),balance[(i+j)%n]);
                balance[i]+=val;
                count=count+val;
            }
            int d;
            if((i-j)>0)d=(i-j)%n;
            else d=(abs(n+i-j))%n;
            if((balance[i]<0)&&balance[d]>0){
                long long val=min(abs(balance[i]),balance[d]);
                balance[i]+=val;
                count=count+val;
            }
            ans=ans+count*j;  
            if(balance[i]>=0)break;  
        }
        return ans;   
    }
};
// class Solution {
// public:
//     long long minMoves(vector<int>& balance) {
//         int n=balance.size();
//         long long posc=0;
//         int i=-1;
//         for(int j=0;j<n;j++){
//             if(balance[j]<0)i=j;
//             posc+=balance[j];
//         }
//         if(i==-1)return 0;
//         if(posc<0)return -1;
//         long long ans=0;
//         for(int j=1;j<n;j++){
//             long long  count=0;      
//             while((balance[i]<0)&&balance[(i+j)%n]>0){
//                 balance[i]++;
//                 balance[(i+j)%n]--;
//                 count++;
//             }
//             int d;
//             if((i-j)>0)d=(i-j)%n;
//             else d=(abs(n+i-j))%n;
//             while((balance[i]<0)&&balance[d]>0){
//                 balance[i]++;
//                 balance[d]--;
//                 count++;
//             }
//             ans=ans+count*j;  
//             if(balance[i]>=0)break;  
//         }
//         for(int i=0;i<n;i++){
//             if(balance[i]<0)return -1;
//         }
//         return ans;   
//     }
// };
