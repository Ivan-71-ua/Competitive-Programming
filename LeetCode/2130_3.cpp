

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
	int pairSum(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* prev = nullptr;
		// Реверс першої половин  и списку
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			ListNode* tmp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = tmp;
		}
		int res = 0;
		// Пошук максимальної суми пар
		while (slow != nullptr) {
			res = std::max(res, prev->val + slow->val);
			prev = prev->next;
			slow = slow->next;
		}
		return res;
	}
};