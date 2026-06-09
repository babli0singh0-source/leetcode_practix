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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next==nullptr){
            prev->next=prev->next->next;
        }else{
            slow->next=slow->next->next;
        }
        return head;
    }
};
