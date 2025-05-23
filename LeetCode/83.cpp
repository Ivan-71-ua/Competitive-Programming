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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == nullptr)
			return head;
		ListNode *k = head;
		while(k->next != nullptr) {
			if(k->val == k->next->val) {
				k->next = k->next->next;
			} else {
				k = k->next;
			}
		}
		return head;
	}
};