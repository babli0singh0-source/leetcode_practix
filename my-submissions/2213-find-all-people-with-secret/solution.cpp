class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<int> knows(n, 0);
        knows[0] = knows[firstPerson] = 1;

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];

            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            // Build graph for same time
            while (i < meetings.size() && meetings[i][2] == t) {
                int x = meetings[i][0], y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            // Start BFS from people who already know the secret
            for (int p : people) {
                if (knows[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // BFS inside this time frame
            while (!q.empty()) {
                int u = q.front(); q.pop();
                knows[u] = 1;
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (knows[i]) ans.push_back(i);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         sort(meetings.begin(),meetings.end(),[&](vector<int> a,vector<int> b){
//             return a[2]<b[2];
//         }
//         );
//         unordered_map<int,int>mpp;
//         //queue<pair<int,int>>q;
//         mpp[0]=1;
//         mpp[firstPerson]=1;
//         int t=meetings[0][2];
//         int i=0;
//         while(i<meetings.size()){
//             t=meetings[i][2];
//             queue<pair<int,int>>q;
//             while(i<meetings.size()&&(meetings[i][2]==t)){
//                 auto x=meetings[i][0],y=meetings[i][1];
//                 if((mpp.find(x)!=mpp.end())||(mpp.find(y)!=mpp.end())){
//                     mpp[x]=1;
//                     mpp[y]=1;
//                 }else{
//                     q.push({x,y});
//                 }
//                 i++;
//             }
//             bool changed = true;
//             while (!q.empty() && changed) {
//                 changed = false;
//                 int sz = q.size();
//                 while (sz--) {
//                     auto [x, y] = q.front(); q.pop();
//                     if (mpp.count(x) || mpp.count(y)) {
//                         mpp[x] = mpp[y] = 1;
//                         changed = true;
//                     } else {
//                         q.push({x, y});
//                     }
//                 }
//             }  
//         }
//         vector<int>ans;
//         for(auto &it :mpp){
//             ans.push_back(it.first);
//         }
//         return ans;        
//     }
// };

