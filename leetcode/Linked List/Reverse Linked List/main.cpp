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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = head, *next;

        if ( !cur || !cur->next ) {
            return cur;
        }

        // first 
        cur = cur->next;

        while ( cur->next ) {

            // remember the cur next
            next = cur->next;

            // reverse
            cur->next = pre;            

            // remember cur
            pre = cur;

            // go to next
            cur = next;

        }

        head->next = nullptr;
        cur->next = pre;

        return cur;
    }
};