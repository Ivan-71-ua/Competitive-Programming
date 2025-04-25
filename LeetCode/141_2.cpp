#include <bits/stdc++.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   bool hasCycle(ListNode *head) {
		std::unordered_set<ListNode *> used;
		while(true) {
			if(head == nullptr) {
				return false;
			}
			auto var = used.insert(head);
			if(!var.second) {
				return true;
			}
			head = head->next;
		}
	}
};