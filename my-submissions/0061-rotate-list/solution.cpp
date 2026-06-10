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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* slow=head;
        int l=0;
        while(slow!=nullptr){
            slow=slow->next;
            l++;
        }
        k=k%l;
        int fromstart=l-k;
        slow=head;
        while(fromstart>1){
            slow=slow->next;
            fromstart--;
        }
        if(slow->next==nullptr)return head;
        ListNode* finally=slow->next;
        slow->next=nullptr;
        ListNode* temp=finally;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
        head=finally;
        return head;
    }
};
