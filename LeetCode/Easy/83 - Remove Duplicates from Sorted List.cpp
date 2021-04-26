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
    ListNode* deleteDuplicates(ListNode* head) {
	ListNode *cur = head, *prev = nullptr;
    while(cur != nullptr){
            if(cur -> next != nullptr && cur -> val == cur -> next -> val){
                // delete this node
                if(prev != nullptr) prev -> next = cur -> next;
                ListNode *temp = cur;
                cur = cur -> next;
                if(prev == nullptr) head = cur;
                delete(temp); temp = nullptr;
                continue;
            }
            prev = cur;
            cur = cur -> next;
        }
        return head;        
     }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *cur = head;
        while(cur != nullptr){
            if(cur -> next != nullptr && cur -> val == cur -> next -> val){
                ListNode *temp = cur -> next;
                cur -> next = cur -> next -> next;
                delete temp; temp = nullptr;
            }
            else {
                cur = cur -> next;
            }
        }
        return head;
    }
};

