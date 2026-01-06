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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        int sum=0,ans=INT_MIN,level=1,count=1;
        while(q.size()!=0&&q.front()!=nullptr){
            while(q.front()!=nullptr){
                cout<<q.front()->val<<endl;
                sum+=q.front()->val;
                TreeNode* y=q.front();
                q.pop();
                if(y->left!=nullptr)q.push(y->left);
                if(y->right!=nullptr)q.push(y->right);
            }
            q.pop();
            if(sum>ans){
                ans=sum;
                level=count;
            }
            count++;
            ans=max(ans,sum);
            cout<<sum<<' '<<ans<<endl;
            sum=0;
            q.push(nullptr);   
        }
        return level;
        
    }
};
