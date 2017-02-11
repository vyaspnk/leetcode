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
	ListNode* removeElements(ListNode* head, int val) {
		if(!head )
			return head;
		while( head &&head->val == val ){
			free(head);
			head = head->next;			
		}
		if(!head)
			return NULL;
		ListNode *prev = head,*rethead = head;
		head = head->next;
		while(head) {
			if(head->val == val){
				prev->next = head->next;
				free(head);				
			} else {
				prev = head;
			}
			head = head->next;
		}
		return rethead;
	}
};