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
        
        int sizeA = genLength(headA);
        int sizeB = genLength(headB);
        
        if ( sizeA == 0 || sizeB == 0 ) { return nullptr; }

        // get size diff
        int diff = abs(sizeA-sizeB);

        // move 
        if ( sizeA > sizeB ) {
            for ( int i=0; i<diff; i++ ) {
                headA = headA->next;
            }
        }
        else if ( sizeB > sizeA ) {
            for ( int i=0; i<diff; i++ ) {
                headB = headB->next;
            }
        }

        while ( headA != nullptr && headB != nullptr ) { 
            if ( headA == headB ) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    int genLength(ListNode *cur) {
        int cnt = 0;
        ListNode *tmp = cur;
        
        while ( cur != nullptr ) { 
            cur = cur->next;
            cnt++; 
        }
        return cnt;
    }
};