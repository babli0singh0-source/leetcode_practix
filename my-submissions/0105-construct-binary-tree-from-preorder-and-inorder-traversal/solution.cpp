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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int prel,int prer,int inl,int inr,unordered_map<int,int>&mpp){
        if(inl>inr||prel>prer)return nullptr;
        TreeNode* root=new TreeNode(preorder[prel]);
        int temp=mpp[preorder[prel]];
        int rem=temp-inl;
        root->left=build(preorder,inorder,prel+1,prel+rem,inl,temp-1,mpp);
        root->right=build(preorder,inorder,prel+rem+1,prer,temp+1,inr,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1,0,inorder.size()-1,mpp);
    }
};
