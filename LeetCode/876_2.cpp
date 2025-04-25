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
		int size = 0;
		ListNode *tmp = head;
		while(tmp != nullptr) {
			size++;
			tmp = tmp->next;
		}
		int cur = 0;
		while(cur != size / 2) {
			cur++;
			head = head->next;
		}
		return head;
	}
};	