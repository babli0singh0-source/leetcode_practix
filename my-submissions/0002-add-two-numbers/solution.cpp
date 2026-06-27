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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* prev1=temp1;
        ListNode* prev2=temp2;
        int carry=0;
        while(temp1&&temp2){
            int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            temp1->val=sum%10;
            prev1=temp1;
            prev2=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int sum=temp1->val+carry;
            carry=sum/10;
            temp1->val=sum%10;
            prev1=temp1;
            temp1=temp1->next;
        }
        while(temp2){
            int sum=temp2->val+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            prev1->next=node;
            prev1=prev1->next;
            temp2=temp2->next;
        }
        if(carry==1){
            ListNode* node=new ListNode(1);
            prev1->next=node;
        }
        return l1;

    }
};
