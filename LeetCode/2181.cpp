#include <bits/stdc++.h>




struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeNodes(ListNode* head) {
		ListNode *modify = new ListNode();
		ListNode *cur = modify;
		int sum_node = 0;
		head = head->next;
		while(head != nullptr) {
			if(head->val == 0) {
				cur->next = new ListNode(sum_node);
				cur = cur->next;
				sum_node = 0;
			} else {
				sum_node += head->val;
			}
			head = head->next;
		}
		return modify->next	;
	}
};