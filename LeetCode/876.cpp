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
	ListNode* middleNode(ListNode* head) {
		std::vector<ListNode *> ver;
		while(head != nullptr) {
			ver.push_back(head);
			head = head->next;
		}
		return ver[ver.size() / 2];
	}
};	