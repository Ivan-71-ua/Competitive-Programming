

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
	std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
		int size = 0;
		ListNode *tmp = head;
		while(tmp) {
			size++;
			tmp = tmp->next;
		}
		int hooldp = size / k;
		int ost = size % k;
		std::vector<ListNode*> ans(k, nullptr);
		tmp = head;
		for (int j = 0; j < k; j++) {
			if(tmp) {
				ans[j] = tmp;
				int cur_s = hooldp + (ost > 0 ? 1 : 0);
				ost--;
				for (int h = 0; h < cur_s - 1; h++) {
					tmp = tmp->next;
				}
				ListNode *next = tmp->next;
				tmp->next = nullptr;
				tmp = next;
			}
		}
		return ans;
	}
};