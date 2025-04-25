
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
		std::vector<int> dub;
		while(head != nullptr) {
			dub.push_back(head->val);
			head = head->next;
		}
		int res = -1;
		for (int i = 0; i < dub.size() /2; i++)
		{
			res = std::max(res, dub[i] + dub[dub.size() - 1 - i]);
		}
		return res;
	}
};
