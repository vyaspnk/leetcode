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
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode *prev = NULL;
     	if(!head || !head->next || !k) {
	     	return head;
     	}
	    int size =0;

	    ListNode *curr = head;
	    while(curr) {
	    	size++; curr = curr->next;
	    }
	    if(k>size)
	        k = k%size;
	    int rotations = size-k;
	    if(rotations%size==0)
	        return head;
	    curr = head;
	    ListNode *nextnode = head->next;
	    while(rotations) {	    	
	    	rotations--;
	    	prev = curr;
	    	curr = curr->next;
	    	if(!curr){	    	
	    		prev = NULL;
	    		curr = head;	    		
	    	}
	    	nextnode = curr->next;
     	}
     	prev->next = NULL;
        if(!curr->next) {
            curr->next = head;
            
        } else {
     	    while(nextnode->next) nextnode = nextnode->next; //take it to the end
     	    nextnode->next = head;
     	}
     	head = curr;     	
     	return head;
    }
};