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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>st;
        for(auto &it:descriptions){
            int parent=it[0];
            int child=it[1];
            int lorr=it[2];
            if(mpp.count(parent)==0){
                mpp[parent]=new TreeNode(parent);
            }
            if(mpp.count(child)==0){
                mpp[child]=new TreeNode(child);
            }
            if(lorr){
                mpp[parent]->left=mpp[child];
            }else{
                mpp[parent]->right=mpp[child];
            }
            st.insert(child);
        }
        //to find the parent root
        //only root is the one who is not present as child in set
        for(auto &it:descriptions){
            if(st.count(it[0])==0)return mpp[it[0]];
        }
        return nullptr;
    }
};
