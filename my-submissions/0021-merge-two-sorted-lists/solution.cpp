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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=nullptr&&temp2!=nullptr){
            if(temp1->val>=temp2->val){
                dummy->next=temp2;
                dummy=dummy->next;
                temp2=temp2->next;
            }else{
                dummy->next=temp1;
                dummy=dummy->next;
                temp1=temp1->next;
            }
        }
        while(temp1!=nullptr){
            dummy->next=temp1;
            dummy=dummy->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            dummy->next=temp2;
            dummy=dummy->next;
            temp2=temp2->next;
        }
        return temp->next;
    }
};
