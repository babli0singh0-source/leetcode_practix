class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        if(k==0||prices.size()==0)return 0;
        long long neg=-1e18;  //Never use INT_MIN or LLONG_MIN as “−∞” in DP if you do arithmetic on it
        vector<vector<long long>>dp(k+1,vector<long long>(3,neg));
        dp[0][0]=0; //no transaction zero state is 0
        // dp is at most k so every k <0,1,2...> state define 0,1,2
        //state 0= hold
        //state 1= already buy seeking to hold or sell to complete cycle
        //state 1-> already +price similar max 
        //state 2= already sold seeking to hold or buy to complete cycle
        // state 2->(max) already -price || curr state ka original value
    
        for(auto price: prices ){
            vector<vector<long long>>currdp=dp;
            for(int i=0;i<=k;i++){
                // state 0
                currdp[i][0]=max(currdp[i][0],dp[i][0]); //hold
                if(i>0&&dp[i-1][1]!=neg)//state 1
                currdp[i][0]=max(currdp[i][0],(dp[i-1][1]+price));
                if(i>0&&dp[i-1][2]!=neg)//state 2
                currdp[i][0]=max(currdp[i][0],(dp[i-1][2]-price));
                //state 1
                currdp[i][1]=max(currdp[i][1],dp[i][1]);//hold
                //buy today only from dp[][0]
                if(dp[i][0]!=neg)
                currdp[i][1]=max(currdp[i][1],(dp[i][0]-price));
                //state 2
                currdp[i][2]=max(currdp[i][2],dp[i][2]); // hold
                //sell roday only from dp[][0]
                if(dp[i][0]!=neg)
                currdp[i][2]=max(currdp[i][2],(dp[i][0]+price));
            }
            dp=currdp;
        }
        long long ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,dp[i][0]);//only those in zero state / completed state 
        }
        return ans;    
    }
};

// class Solution {
// public:
//     long long maximumProfit(vector<int>& prices, int k) {
//         if(k==0||prices.size()==0)return 0;
//         long long neg=-1e18;  //Never use INT_MIN or LLONG_MIN as “−∞” in DP if you do arithmetic on it
//         // vector<vector<long long>>dp(k+1,vector<long long>(3,neg));
//         // dp[0][0]=0; //no transaction zero state is 0
//         // dp is at most k so every k <0,1,2...> state define 0,1,2
//         //state 0= hold
//         //state 1= already buy seeking to hold or sell to complete cycle
//         //state 1-> already +price similar max 
//         //state 2= already sold seeking to hold or buy to complete cycle
//         // state 2->(max) already -price || curr state ka original value
//         vector<long long>curr(3,neg);
//         vector<long long>prev(3,neg);
//         curr[0]=0;
//         long long ans=0;
//         for(auto price: prices ){
//             vector<long long>ncurr=curr;
//             //vector<long long>nprev(3,neg);
//             for(int i=0;i<=k;i++){
//                 // state 0
//                 ncurr[0]=max(ncurr[0],curr[0]); //hold
//                 if(i>0&&prev[1]!=neg)//state 1
//                 ncurr[0]=max(ncurr[0],(prev[1]+price));
//                 if(i>0&&prev[2]!=neg)//state 2
//                 ncurr[0]=max(ncurr[0],(prev[2]-price));
//                 //state 1
//                 ncurr[1]=max(ncurr[1],curr[1]);//hold
//                 //buy today only from dp[][0]
//                 if(curr[0]!=neg)
//                 ncurr[1]=max(ncurr[1],(curr[0]-price));
//                 //state 2
//                 ncurr[2]=max(ncurr[2],curr[2]); // hold
//                 //sell roday only from dp[][0]
//                 if(curr[0]!=neg)
//                 ncurr[2]=max(ncurr[2],(curr[0]+price));
//             }
//             ans=max(prev[0],ans);
//             prev=curr;
//             curr=ncurr;
            
//         }
//         ans=max(curr[0],ans);
//         return ans;    
//     }
// };
        
        // if (k >= prices.size() / 2) {
        //     long long cash = 0;              // no position
        //     long long longHold = -prices[0]; // holding long
        //     long long shortHold = prices[0]; // holding short

        //     for (int i = 1; i < prices.size(); i++) {
        //         long long p = prices[i];
        //         long long prevCash = cash;

        //         cash = max({cash, longHold + p, shortHold - p});
        //         longHold = max(longHold, prevCash - p);
        //         shortHold = max(shortHold, prevCash + p);
        //     }
        //     return cash;
        // }

