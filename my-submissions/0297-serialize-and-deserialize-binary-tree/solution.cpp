/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr){
                ans+="null,";
                continue;
            }
            ans+=to_string(curr->val);
            ans+=',';
            q.push(curr->left);
            q.push(curr->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return nullptr;
        vector<string>v;
        string temp="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                v.push_back(temp);
                temp="";
            }else{
                temp+=data[i];
            }
        }
        TreeNode* root=new TreeNode(stoi(v[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty()&&i<v.size()){
            TreeNode* curr=q.front();
            q.pop();
            if(v[i]!="null"){
                TreeNode* lc=new TreeNode(stoi(v[i]));
                curr->left=lc;
                q.push(lc);
            }
            i++;
            if(v[i]!="null"){
                TreeNode* rc=new TreeNode(stoi(v[i]));
                curr->right=rc;
                q.push(rc);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
