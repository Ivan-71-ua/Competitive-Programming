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
		std::vector<int> val;
		while(cur != nullptr) {
			val.push_back(cur->val);
			cur = cur->next;
		}
		std::stack<int> way;
		way.push(val.back());
		val.pop_back();
		while(!val.empty()) {
			if(way.top() <= val.back()) {
				way.push(val.back());
			}
			val.pop_back();
		}
		ListNode *res = new ListNode(way.top());
		ListNode *it = res;
		way.pop();
		while(!way.empty()) {
			it->next = new ListNode(way.top());
			way.pop();
			it = it->next;
		}
		return res;
	}
};