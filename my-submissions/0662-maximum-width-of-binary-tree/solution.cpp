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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<pair<TreeNode*,long long>>q;
        long long width=1;
        q.push({root,0});
        while(!q.empty()){
            long long s=q.size();
            long long ind=q.front().second;
            long long start=0;
            long long end=0;
            for(long long i=0;i<s;i++){
                TreeNode* curr=q.front().first;
                long long currind=q.front().second -ind;
                q.pop();
                if(i==0)start=currind;
                if(i==s-1)end=currind;
                if(curr->left){
                    q.push({curr->left,(currind)*2+1});
                }
                if(curr->right){
                    q.push({curr->right,(currind)*2+2});
                }
            }
            width=max(width,end-start+1);
        }
        return (int)width;
    }
};
