
#include <bits/stdc++.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	void Dub(ListNode *hd, int &add) {
		if(hd == nullptr)
			return;
		Dub(hd->next, add);
		int tmp = (hd->val * 2 + add);
		hd->val = tmp % 10;
		add = tmp / 10;
	}
public:
	ListNode* doubleIt(ListNode* head) {
		int add = 0;
		Dub(head, add);
		if(add == 0) {
			return head;
		}
		ListNode *res = new ListNode(add, head);
		return res;
	}
};