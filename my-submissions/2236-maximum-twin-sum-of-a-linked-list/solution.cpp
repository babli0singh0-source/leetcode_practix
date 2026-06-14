/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast =head;
        vector<int>temp;
        temp.push_back(slow->val);
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            temp.push_back(slow->val);
            fast=fast->next->next;
        }
        slow=slow->next;
        int ans=INT_MIN;
        for(int i=temp.size()-1;i>=0;i--){
            int sum=slow->val+temp[i];
            ans=max(ans,sum);
            slow=slow->next;
        }
        return ans;
    }
};
