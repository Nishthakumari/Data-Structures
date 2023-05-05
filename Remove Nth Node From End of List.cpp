//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int length = 0;

        ListNode* cur = head;
        while(cur!=NULL)
        {
            length++;
            cur = cur->next;
        }

        if(n>length)
        {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int x = length -n;

        ListNode* temp = dummy;

        while(x--)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return dummy->next;
    }
};
