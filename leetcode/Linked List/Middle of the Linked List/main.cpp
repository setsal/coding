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
    ListNode* middleNode(ListNode* head) {
        ListNode *first = head;
        ListNode *second = head;

        if ( first->next == nullptr ) {
            return first;
        }
        else if ( first->next->next == nullptr ) {
            return second->next;
        }

        while ( first->next ) {
            if ( first->next->next == nullptr )  {
                second = second->next;
                break;
            }
            first = first->next->next;
            second = second->next;
        }

        return second;
    }
};