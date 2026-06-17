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
class BSTIterator {
public:
    vector<int>inorder;
    int current;
    BSTIterator(TreeNode* root) {
        inorderfind(root);
        current=0;
    }
    void inorderfind(TreeNode* root){
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
    }
    int next() {
        return inorder[current++];
    }
    
    bool hasNext() {
        return current<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
