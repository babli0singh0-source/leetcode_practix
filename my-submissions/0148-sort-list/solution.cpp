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
    ListNode* merge(ListNode* &start1,ListNode* &start2){
        ListNode* dummy = new ListNode (0);
        ListNode* temp=dummy;
        while(start1!=nullptr&&start2!=nullptr){
            if(start1->val<=start2->val){
                //ListNode* node=new ListNode(start1->val);
                temp->next=start1;
                start1=start1->next;
            }else{
                //ListNode* node=new ListNode(start1->val);
                temp->next=start2;
                start2=start2->next;
            }
            temp=temp->next;
        }
        if(start1!=nullptr)temp->next=start1;
        else temp->next=start2;
        return dummy->next;
    }
    ListNode* getmid(ListNode* &head){
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow=head; 
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* helper(ListNode* &head){
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow=getmid(head);
        ListNode* right= slow->next;
        slow->next=nullptr;
        ListNode* left=head;
        left=helper(left);
        right=helper(right);
        return merge(left,right);
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return helper(head);
    }
};
