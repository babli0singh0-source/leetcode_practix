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
        TreeNode* copy=root;
        int c=0;
        int ans=-1;
        while(copy!=nullptr){
            if(copy->left==nullptr){
                c++;
                if(c==k)ans= copy->val;
                copy=copy->right;
            }else{
                TreeNode* temp=copy->left;
                while(temp->right!=nullptr&&temp->right!=copy){
                    temp=temp->right;
                }
                if(temp->right==nullptr){
                    temp->right=copy;
                    copy=copy->left;
                }else if(temp->right==copy) {
                    temp->right=nullptr;
                    c++;
                    if(c==k)ans= copy->val;
                    copy=copy->right;
                }
            }
        }
        return ans;
    }
};
