
#include <bits/stdc++.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
	void Max_dub(ListNode* last, ListNode* &first, int &res) {
		if(last == nullptr)
			return;
		Max_dub(last->next, first, res);
		res = std::max(res, last->val + first->val);
		first = first->next;
	}
public:
	int pairSum(ListNode* head) {
		int res = -1;
		ListNode *point = head;
		Max_dub(head, point, res);
		return res;
	}
};

