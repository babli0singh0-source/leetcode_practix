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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        int x=0;
        while(l1!=nullptr||l2!=nullptr||x){
            if(l1){
                x+=l1->val;
                l1=l1->next;
            }
            if(l2){
                x+=l2->val;
                l2=l2->next;
            }
            temp->next=new ListNode(x%10);
            temp=temp->next;
            //cout<<temp->val<<endl;
            x=x/10;
        }
        return ans->next;   
    }
};
