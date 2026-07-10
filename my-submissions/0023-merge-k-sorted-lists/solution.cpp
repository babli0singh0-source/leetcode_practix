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
 struct custumheap{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return nullptr;
        vector<ListNode*>currind=lists;
        ListNode* ans=new ListNode(0);
        ListNode* fin=ans;
        priority_queue<ListNode*,vector<ListNode*>,custumheap>pq;
        for(int i=0;i<n;i++){
            if(currind[i]!=nullptr)pq.push(currind[i]);
        }
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            ans->next=node;
            ans=ans->next;
            if(node->next!=nullptr)pq.push(node->next);
        }
        return fin->next;
    }
};
