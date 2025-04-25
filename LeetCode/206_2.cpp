#include <bits/stdc++.h>


struct ListNode {
	int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
	void Revers(ListNode *st, ListNode *&ans) {
		if(st == nullptr)
			return;
		Revers(st->next, ans);
		ans->next = new ListNode(st->val);
		ans = ans->next;
	}
public:
   ListNode* reverseList(ListNode* head) {
		ListNode *node = new ListNode();
		ListNode *cur = node;
		Revers(head, cur);
		return node->next;
	}
};