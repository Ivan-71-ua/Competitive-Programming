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
		while(head != nullptr) {
			used.insert(head);
			if(std::find(used.begin(), used.end(), head->next) != used.end()) {
				return true;
			}
			head = head->next;
		}
		return false;
	}
};