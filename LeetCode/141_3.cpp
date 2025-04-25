#include <bits/stdc++.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   bool hasCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		while(true) {
			if(fast == nullptr) {
				return false;
			}
			fast = fast->next;
			if(fast == nullptr) {
				return false;
			}
			fast = fast->next;
			slow = slow->next;
			if(slow == fast) {
				return true;
			}
		}
	}
};