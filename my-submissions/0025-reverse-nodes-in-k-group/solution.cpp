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
    ListNode* kthnode(ListNode* copy,int k){
        while(k>1&&copy){
            copy=copy->next;
            k--;
        }
        return copy;
    }
    ListNode* reverse(ListNode* &copy){
        ListNode* curr=copy;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode* copy=head;
        ListNode* prevnode=nullptr;
        while(copy!=nullptr){
            ListNode* kth=kthnode(copy,k);
            if(kth==nullptr){
                if(prevnode)prevnode->next=copy;
                break;
            }
            ListNode* newhead=kth->next;
            kth->next=nullptr;
            ListNode* t1=reverse(copy);
            if(copy==head)head=kth;
            else{
                prevnode->next=kth;
            }
            prevnode=copy;
            copy=newhead;
        }
        return head;
    }
};
