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
        if(head == nullptr || head -> next == nullptr) return false;
        ListNode *tortoise = head, *hare = head;
        do{
            if(hare == nullptr || hare -> next == nullptr) break;
            hare = hare -> next -> next;
            tortoise = tortoise -> next;
        } while(hare != tortoise);	
        return hare == tortoise;
    }
};
