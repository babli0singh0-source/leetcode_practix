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
    void recoverTree(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        TreeNode* third=nullptr;
        TreeNode* prev;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(prev&&curr->val<prev->val){
                    if(first==nullptr){
                        first=prev;
                        second=curr;
                    }else{
                        third=curr;
                    }
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
                    if(prev&&curr->val<prev->val){
                        if(first==nullptr){
                            first=prev;
                            second=curr;
                        }else{
                            third=curr;
                        }
                    }
                    prev=curr;
                    curr=curr->right;
                }
            }
        }
        if(third==nullptr)swap(first->val,second->val);
        else swap(third->val,first->val);
    }
};
