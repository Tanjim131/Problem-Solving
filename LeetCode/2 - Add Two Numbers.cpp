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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = NULL, *temp = NULL;
        
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            ListNode *ln = new ListNode(digit);
            
            if(root == NULL){
                root = ln;
                temp = root;
                l1 = l1 -> next;
                l2 = l2 -> next;
                continue;
            } 
            
            temp -> next = ln;
            l1 = l1 -> next;
            l2 = l2 -> next;
            temp = temp -> next;
        }
        
        while(l1 != NULL){
            int sum = l1 -> val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            ListNode *ln = new ListNode(digit);
            temp -> next = ln;
            l1 = l1 -> next;
            temp = temp -> next;
        }
        
         while(l2 != NULL){
            int sum = l2 -> val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            ListNode *ln = new ListNode(digit);
            temp -> next = ln;
            l2 = l2 -> next;
            temp = temp -> next;
        }
        
        if(carry){
            ListNode *ln = new ListNode(carry);
            temp -> next = ln;
        }
    
        return root;
    }
};