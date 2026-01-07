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
    long long helper(TreeNode* &copy){
        if(copy==nullptr)return 0;
        long long l=helper(copy->left);
        long long r=helper(copy->right);
        copy->val=(l+r+copy->val);
        return copy->val;
    }
    int maxProduct(TreeNode* root) {
        long long ans=0,total=helper(root);
        int mod=1e9+7;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* curr=q.front();
            long long prd=(1LL*curr->val * (total-curr->val));
            ans=max(prd,ans);
            if(curr->left!=nullptr)q.push(curr->left);
            if(curr->right!=nullptr)q.push(curr->right);
            q.pop();
        }
        return ans%mod;    
    }
};
