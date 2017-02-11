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
    ListNode* reverseList(ListNode* head) {
  		if(!head || !head->next) return head;  		
  		ListNode* prev = NULL, *next = head->next;  		
  		while(next){
  			head->next = prev;
  			prev = head;
  			head = next;
  			if(next)
  				next = next->next;
  		}
  		return prev;
    }
};