/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr)return head;
        Node* temp=head;
        Node* side;
        while(temp!=nullptr){
            if(temp->child!=nullptr){
                side=temp->next;
                temp->next=flatten(temp->child);
                temp->child=nullptr;
                if(temp->next)temp->next->prev=temp;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=side;
                if(side!=nullptr){
                    side->prev=temp;
                }
            }else temp=temp->next;
        }
        return head;
    }
};
