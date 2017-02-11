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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
  		 if(!head || !head->next) return head;  		
  		ListNode* prev = NULL,*rethead = head;
  		if(m==n)
  		    return head;
  		int cnt = n-m+1;
  		for(int i=1;i<m;i++){
  			prev = head;
  			head = head->next;
  		}
  		
  		ListNode *next = head->next,*oldhead = head,*oldprev = prev;
  		cout << cnt << endl;
  		while(cnt){
  			head->next = prev;
  			prev = head;
  			head = next;
  			if(next)
  			    next = next->next;
  			cnt--;
  			if(m==1)
  			    rethead = prev;
  		}
  		if(oldprev)
  		    oldprev->next = prev;
  		oldhead->next = head;
  		
  		while(prev->next) prev = prev->next;
  		return rethead;
    }
};