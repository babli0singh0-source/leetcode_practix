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
    int getheight(TreeNode* root){
        if(root==nullptr)return 0;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        return max(lh,rh)+1;
    }
    TreeNode* rotateright(TreeNode* node){
        TreeNode* x=node->left;
        TreeNode* st=x->right;
        x->right=node;
        node->left=st;
        return x;
    }
    TreeNode* rotateleft(TreeNode* node){
        TreeNode* x=node->right;
        TreeNode* st=x->left;
        x->left=node;
        node->right=st;
        return x;
    }
    TreeNode* balance(TreeNode* &root){
        if(root==nullptr)return nullptr;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        if(rh-lh>1)root=rotateleft(root);
        else if(lh-rh>1)root=rotateright(root);
        root->left=balance(root->left);
        root->right=balance(root->right);
        return root;
    }
    TreeNode* build(vector<int>&inorder,int start,int end){
        if(start>end)return nullptr;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=build(inorder,start,mid-1);
        root->right=build(inorder,mid+1,end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>inorder;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* temp=curr->left;
                while(temp->right!=nullptr&&temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==nullptr){
                    temp->right=curr;
                    curr=curr->left;
                }else{
                    temp->right=nullptr;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return build(inorder,0,inorder.size()-1);
    }
};
