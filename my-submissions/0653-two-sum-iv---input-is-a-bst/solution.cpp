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
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        TreeNode* curr=root;
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
        int i=0,j=inorder.size()-1;
        while(i<j){
            int sum=inorder[i]+inorder[j];
            if(sum==k)return true;
            else if(sum>k)j--;
            else i++;
        }
        return false;
    }
};
