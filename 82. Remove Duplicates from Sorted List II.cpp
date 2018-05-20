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
        ListNode* h = new ListNode(0), *tail = h;
        ListNode* cur = head;
        while(head){
            while(head && head -> val == cur -> val)
                head = head -> next;
            if(cur -> next == head){
                tail -> next = cur;
                cur = head;
                tail = tail -> next;
                tail -> next = nullptr;
            }
            else{
                while(cur != head){
                    ListNode* t = cur;
                    cur =  cur -> next;
                    delete t;
                }
            }
        }
        head = h -> next;
        delete h;
        return head;
    }
};
