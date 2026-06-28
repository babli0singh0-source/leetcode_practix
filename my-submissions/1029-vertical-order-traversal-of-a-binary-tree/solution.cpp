/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        unordered_map<int,vector<int>>mpp;
        TreeNode* temp=root;
        q.push({temp,{0,0}});
        int start=INT_MAX;
        int end=INT_MIN;
        while(!q.empty()){
            int s=q.size();
            unordered_map<int,vector<int>>temp;
            for(int i=0;i<s;i++){
                auto [curr,p]=q.front();
                q.pop();
                auto [level,dis]=p;
                start=min(start,dis);
                end=max(end,dis);
                temp[dis].push_back(curr->val);
                if(curr->left)q.push({curr->left,{level+1,dis-1}});
                if(curr->right)q.push({curr->right,{level+1,dis+1}});
            }
            for(auto &it:temp){
                auto x=it.second;
                sort(x.begin(),x.end());
                mpp[it.first].insert(mpp[it.first].end(),x.begin(),x.end());
            }
        }
        vector<vector<int>>ans;
        for(int i=start;i<=end;i++){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};
