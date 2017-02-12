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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next )
        	return false;
        
        Set<ListNode> listset = new HashSet<>();
		while(head!=NULL) {
			if(listset.contains(head))
				return true;
			else
				listset.add(head);
			head = head->next;
		}
		return false;
	}
};