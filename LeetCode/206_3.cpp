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
   ListNode* reverseList(ListNode* head) {
		ListNode *node = new ListNode();
		ListNode *cur = node;
		std::stack<int> rew;
		while (head != nullptr)
		{
			rew.push(head->val);
			head = head->next;	
		}
		while (!rew.empty())
		{
			cur->next = new ListNode(rew.top());
			cur = cur->next;
			rew.pop();
		}
		return node->next;
	}
};