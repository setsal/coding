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
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        stack<int> myst;
        
        // push into stack
        while (cur) {
            myst.push(cur->val);
            cur = cur->next;
        }

        while (head) {
            int val = myst.top(); 
            myst.pop();
            if ( head->val != val) return false;
            head = head->next;
        }
        return true;
    }
};