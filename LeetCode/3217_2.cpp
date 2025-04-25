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
	ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
		std::set<int> del;
		for (auto num: nums)
		{
			del.insert(num);
		}
		ListNode *res = new ListNode();
		ListNode *cur = res;
		while(head != nullptr) {
			if(!del.count(head->val)) {
				cur->next = head;
				cur = cur->next;
			}
			head = head->next;
		}
		cur->next = nullptr;
		return res->next;
	}
};