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
    TreeNode* helper(vector<int>& inorder,int inl,int inr, vector<int>& postorder,int postl,int postr,unordered_map<int,int>&mpp){
        if(inl>inr||postl>postr)return nullptr;
        TreeNode* root=new TreeNode(postorder[postr]);
        int ind=mpp[postorder[postr]];
        int temp=inr-ind;
        root->left= helper(inorder,inl,ind-1,postorder,postl,postr-temp-1,mpp);
        root->right=helper(inorder,ind+1,inr,postorder,postl-temp,postr-1,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return helper(inorder,0,inorder.size()-1,postorder,0,inorder.size()-1,mpp); 
    }
};
