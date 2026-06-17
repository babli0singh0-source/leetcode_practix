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
    int finddecre(vector<int>& preorder,int start){
        for(int i=start+1;i<preorder.size();i++){
            if(preorder[start]<preorder[i])return i;
        }
        return -1;
    }
    TreeNode* construct(int start,int end,vector<int>& preorder){
        if(start>end)return nullptr;
        TreeNode* root=new TreeNode(preorder[start]);
        if(start==end)return root;
        int limit=finddecre(preorder,start);
        if(limit!=-1){
            root->left=construct(start+1,limit-1,preorder);
            root->right=construct(limit,end,preorder);
        }
        else root->left=construct(start+1,end,preorder);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int end=preorder.size();
        return construct(0,end-1,preorder);
    }
};
