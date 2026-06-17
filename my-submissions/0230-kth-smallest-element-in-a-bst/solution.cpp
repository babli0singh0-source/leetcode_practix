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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int c=0;
        int ans=-1;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                c++;
                if(c==k)ans= curr->val;
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
                    c++;
                    if(c==k)ans= curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
