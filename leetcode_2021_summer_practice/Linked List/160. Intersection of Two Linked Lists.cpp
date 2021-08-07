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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *curA = headA;
        ListNode *curB = headB;
        
        int lenA = 0, lenB = 0;
        lenA = getLength(curA);
        lenB = getLength(curB);
    
        curA = headA;
        curB = headB;
        
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        
        int diff = lenA - lenB;
        while (diff--) {
            curA = curA->next;
        }
        
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
    
    
    int getLength(ListNode *node) {
        int len = 0;
        while (node != nullptr) {
            len++;
            node = node->next;
        }
        return len;
    }

    
};