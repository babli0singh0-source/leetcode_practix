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
    bool isValidBST(TreeNode* root){
        bool check=true;
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(prev&&prev->val>=curr->val){
                    check=false;
                }
                prev=curr;
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
                    if(prev&&prev->val>=curr->val){
                        check=false;
                    }
                    prev=curr;
                    curr=curr->right;
                }
            }
        }
        return check;
    }
};
