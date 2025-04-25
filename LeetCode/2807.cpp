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
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		ListNode *cur = head;
		ListNode *next_cur = head->next;
		while(next_cur != nullptr) {
			int tmp = std::gcd(cur->val, next_cur->val);
			ListNode *gsd = new ListNode(tmp, next_cur);
			cur->next = gsd;
			cur = cur->next->next;
			next_cur = next_cur->next;
		}
		return head;
	}
};