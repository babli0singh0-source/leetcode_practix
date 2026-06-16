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
        map<int,map<int,multiset<int>>>mpp;// distance,level,val
        queue<pair<TreeNode*,pair<int,int>>>q; //node,distance ,level
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* curr=temp.first;
            int dis=temp.second.first;
            int level=temp.second.second;
            mpp[dis][level].insert(curr->val);
            if(curr->left)q.push({curr->left,{dis-1,level+1}});
            if(curr->right)q.push({curr->right,{dis+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto &it:mpp){//distance wise
            vector<int>col;
            for(auto &c:it.second){//adding level wise
                col.insert(col.end(),c.second.begin(),c.second.end());
            }
            ans.push_back(col);//inserted at distance it for all levels ;
        }
        return ans;
    }
};
