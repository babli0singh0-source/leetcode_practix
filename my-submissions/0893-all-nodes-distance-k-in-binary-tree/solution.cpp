/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void getparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(root==nullptr)return;
        if(root->left){
            mpp[root->left]=root;
            getparent(root->left,mpp);
        }
        if(root->right){
            mpp[root->right]=root;
            getparent(root->right,mpp);
        }
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        getparent(root,mpp);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int>vis;
        q.push(target);
        int dis=0;
        vis[target]=1;
        while(!q.empty()){
            int s=q.size();
            if(dis==k)break;
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&vis.count(curr->left)==0){
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right&&vis.count(curr->right)==0){
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(curr!=root&&vis.count(mpp[curr])==0){
                    q.push(mpp[curr]);
                    vis[mpp[curr]]=1;
                }
            }
            dis++;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
