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
	ListNode* removeNodes(ListNode* head) {
		ListNode *cur = head;
		std::deque<int> way;
		while(cur != nullptr) {
			while(!way.empty() && way.back() < cur->val) {
				way.pop_back();
			}
			way.push_back(cur->val);
			cur = cur->next;
		}
		ListNode *res = new ListNode(way.front());
		ListNode *it = res;
		way.pop_front();
		while(!way.empty()) {
			it->next = new ListNode(way.front());
			way.pop_front();
			it = it->next;
		}
		return res;
	}
};