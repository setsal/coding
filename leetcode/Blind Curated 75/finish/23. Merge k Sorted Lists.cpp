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
class Comparsion {
public:
    bool operator() (const ListNode* a, const ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode* >, Comparsion> pq;

        for (auto item : lists) {
            if (item) {
                // cout << item->val << endl;
                pq.push(item);
            }
        }
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *ptr = dummyHead;
        
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            
            ptr->next = tmp;
            ptr = tmp;
            
            if (ptr->next) {
                pq.push(ptr->next);
            }
        }
        return dummyHead->next;
    }
};

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode dummy(0);
//         ListNode *cur = &dummy;
        
//         while (true) {  
//             ListNode** min_head = nullptr;
          
//             for (auto& head : lists) {          
//                 if (!head) 
//                     continue; 
            
//                 // cout << head->val << endl;
//                 if (!min_head || head->val < (*min_head)->val)  
//                     min_head = &head;
//             }
          
//             if (!min_head) 
//                 break;
            
//             cur->next = new ListNode((*min_head)->val);
//             cur = cur->next;
//             *min_head = (*min_head)->next;    
//             // cout << "---round---" << endl;
//         }
        
//         return dummy.next;
//         // return {};
//     }
// };