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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *pts = nullptr, *prev = nullptr;
        while(current != nullptr){
            prev = current;
            current = current -> next;
            head -> next = pts;
            if(current != nullptr) head = current;
            pts = prev;
        }
	    return head;
    }
};
