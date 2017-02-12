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
       int carry=0;
        ListNode* orgl1 = l1;
        ListNode* orgl2 = l2;
        ListNode* rethead = l1;
        ListNode*carrynode=NULL;
        if(!l1)
        	return l2;
        if(!l2)
        	return l1;
        int a = l1->val;
        int b = l2->val;
        while(1){
        	int tmp = carry+a+b;
        	carry = tmp/10;
        	tmp = tmp%10;
        	l1->val = tmp;
        	l2->val = tmp;
        	if(!l1->next) {
        		l1->next = l2->next;
        		rethead = orgl1;
        		carrynode = l2;
        		l2->next = NULL;
        		break;
        	} 
        	if(!l2->next) {        		
        		rethead = orgl1;
        		carrynode = l2;        		
        		break;
        	}
        	l1 = l1->next; a = l1->val;
        	l2 = l2->next; b = l2->val;        	
        }

        
        while(l1->next) {
        	int tmp =  carry + l1->next->val;
        	carry = tmp/10;
        	l1->next->val = tmp%10;        		
        	l1 = l1->next;
        }
        if(carry) {
	        l1->next = carrynode;
	        l1 = l1->next;        
	        l1->val = carry;
	    }
        return rethead;
    }
};