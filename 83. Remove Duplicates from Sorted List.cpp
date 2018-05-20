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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* cur = head, *p = head -> next;
        while(p){
            while(p && p -> val == cur -> val){
                ListNode* t = p;
                cur -> next = p -> next;
                p = p -> next;
                delete t;
            }
            cur = p;
            p = p? p -> next : p;
        }
        return head;
    }
};
