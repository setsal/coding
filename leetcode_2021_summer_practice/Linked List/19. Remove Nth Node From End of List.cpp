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
        // dummy head
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *slowIndex, *fastIndex;
        slowIndex = dummyHead;
        fastIndex = dummyHead;
        
        while (n-- && fastIndex != nullptr) {
            fastIndex = fastIndex->next;
        }
        fastIndex = fastIndex->next;
        
        while (fastIndex != nullptr) {
            fastIndex = fastIndex->next;
            slowIndex = slowIndex->next;
        }
        slowIndex->next = slowIndex->next->next;
        return dummyHead->next;
    }
};