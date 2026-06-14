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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>ans(101,-101);
        int d=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int dis=q.front().second;
            if(ans[dis]==-101){
                ans[dis]=curr->val;
                d++;
            }
            q.pop();
            if(curr->right)q.push({curr->right,dis+1});
            if(curr->left)q.push({curr->left,dis+1});
        }
        ans.resize(d);
        return ans;
    }
};
