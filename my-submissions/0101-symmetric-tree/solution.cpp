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
 //recursive
class Solution {
    bool helper(TreeNode* leftnode,TreeNode* rightnode){
        if(leftnode==nullptr||rightnode==nullptr)return leftnode==rightnode;
        return ((leftnode->val==rightnode->val)&&helper(leftnode->left,rightnode->right)&&helper(leftnode->right,rightnode->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return helper(root->left,root->right);
    }
};
//iterative
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root->left==nullptr&&root->right==nullptr)return true;
//         vector<int>temp;
//         queue<TreeNode*>q;
//         if(!(root->left&&root->right))return false;
//         q.push(root->left);
//         while(!q.empty()){
//             TreeNode* curr=q.front();
//             if(curr==nullptr)temp.push_back(-101);
//             else temp.push_back(curr->val);
//             q.pop();
//             if(curr)q.push(curr->left);
//             if(curr)q.push(curr->right);
//         }
//         q.push(root->right);
//         int i=0;
//         while(!q.empty()){
//             TreeNode* curr=q.front();
//             if(curr==nullptr){
//                 if(temp[i]!=-101)return false;
//             }
//             else if(i<temp.size()&&(temp[i]!=curr->val))return false;
//             i++;
//             q.pop();
//             if(curr)q.push(curr->right);
//             if(curr)q.push(curr->left);
//         }
//         return true;
//     }
// };
