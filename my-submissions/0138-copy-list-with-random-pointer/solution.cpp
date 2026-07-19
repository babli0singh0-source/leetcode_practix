/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=nullptr){
            Node* copy=temp->next;
            if(temp->random)copy->random=temp->random->next;
            else copy->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* ans=new Node(-1);
        Node* copy=ans;
        while(temp!=nullptr){
            ans->next=temp->next;
            temp->next=temp->next->next;
            ans=ans->next;
            temp=temp->next;
        }
        return copy->next;
        
    }
};
