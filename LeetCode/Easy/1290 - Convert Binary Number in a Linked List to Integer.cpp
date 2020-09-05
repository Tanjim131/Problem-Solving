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
    int getDecimalValue(ListNode* head) {
        int digits = 0;
        {
            ListNode *start = head;
            while(start != NULL){
                ++digits;
                start = start -> next;
            }
        }
        int power = 1 << (digits - 1);
        int number = 0;
        {
            ListNode *start = head;
            while(start != NULL){
                number += power * (start -> val);
                start = start -> next;
                power >>= 1;
            }
        }
        return number;
    }
};