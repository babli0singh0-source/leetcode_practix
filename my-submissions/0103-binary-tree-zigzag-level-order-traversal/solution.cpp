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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        bool check=true;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(!check)reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                temp={};
                check=check?false:true;
                if(!q.empty()){
                    q.push(NULL);
                    continue;
                }else break;
            }
            temp.push_back(curr->val);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);        
        }
        return ans;
    }
};
