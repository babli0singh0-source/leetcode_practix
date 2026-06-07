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
    ListNode* reverse(ListNode* &root){
        ListNode* curr=root;
        ListNode* prev=nullptr;
        ListNode* nex=nullptr;
        while(curr!=nullptr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=reverse(slow->next);
        ListNode* start1=head;
        ListNode* start2=temp;
        while(start2!=nullptr){
            if(start1->val!=start2->val){
                slow->next=reverse(temp);
                return false;
            }
            start1=start1->next;
            start2=start2->next;
        }
        slow->next=reverse(temp);
        return true;
    }
};
