// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         unordered_map<int,int>mpp;
//         vector<int>ans;
//         for(int i=0;i<A.size();i++){
//             mpp.insert({A[i],0});
//             int c=0;
//             for(int j=0;j<=i;j++){
//                 if(mpp.count(B[j]))c++;
//             } 
//             ans.push_back(c);  
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         unordered_map<int,int>mpp;
//         int n=A.size();
//         vector<int>ans;
//         int c=0;
//         for(int i=0;i<n;i++){
//             mpp[A[i]]++;
//             if(mpp[A[i]]==2)c++;
//             mpp[B[i]]++;
//             if(mpp[B[i]]==2)c++; 
//             ans.push_back(c);  
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n=A.size();
//         vector<int>ans,freq(n+1,0);
//         int c=0;
//         for(int i=0;i<n;i++){
//             freq[A[i]]++;
//             if(freq[A[i]]==2)c++;
//             freq[B[i]]++;
//             if(freq[B[i]]==2)c++; 
//             ans.push_back(c);  
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        int c=0;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2)c++;
            freq[B[i]]++;
            if(freq[B[i]]==2)c++; 
            A[i]=c;  
        }
        return A;
    }
};
