/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        ListNode* tmp = head;
        
        while ( cur != nullptr && cur->next != nullptr ) {
            tmp = tmp->next;
            cur = cur->next->next;
            if ( tmp == cur ) {
                return true;
            }
        }
        return false;
    }
};