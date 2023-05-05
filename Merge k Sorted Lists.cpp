//https://leetcode.com/problems/merge-k-sorted-lists/

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

struct compare{
    bool operator()( ListNode* l1, ListNode* l2)
    {
        return l1->val>l2->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<ListNode*, vector<ListNode*>, compare> pq;
     int size=lists.size();

     for(int i=0;i<size;i++)
     {
         if(lists[i]!=NULL)
         pq.push(lists[i]);
     }  

     if(pq.empty()) return NULL;
     ListNode* dummy= new ListNode(0);

     ListNode* last = dummy;


     while(!pq.empty())
     {
         ListNode* curr= pq.top();
         pq.pop();

         last->next=curr;
         last=last->next;

         if(curr->next!=NULL)
         pq.push(curr->next);
     }

     return dummy->next;
    }
};
