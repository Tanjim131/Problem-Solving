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
			    int value_to_delete = cur -> val;
                while(cur != nullptr && cur -> val == value_to_delete){
                    if(prev != nullptr) prev -> next = cur -> next;
                    ListNode *temp = cur;
                    cur = cur -> next;
                    if(prev == nullptr) head = cur;
                    delete(temp); temp = nullptr;
                }
                if(cur == nullptr) break;
                continue;
		    }
            prev = cur;
            cur = cur -> next;
	    }
	    return head;
    }
};

// ================================================================================

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
unordered_set <int> unique;
	unordered_map <int, bool> delete_list;
	ListNode *cur = head;
	while(cur != nullptr){
		if(unique.find(cur -> val) == unique.end()){
			unique.insert(cur -> val);
		} else{
			delete_list[cur -> val] = true;
		}
		cur = cur -> next;
	}
	
	ListNode *prev = nullptr;
cur = head;
	while(cur != nullptr){
		if(delete_list[cur -> val] == true){
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


