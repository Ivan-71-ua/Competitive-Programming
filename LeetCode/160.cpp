#include <bits/stdc++.h>

struct ListNode {
	int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		std::unordered_map<ListNode *, int> used;
		while(headA != nullptr) {
			used[headA]++;
			headA = headA->next;
		}
		while(headB != nullptr) {
			used[headB]++;
			if(used[headB] > 1)
				return headB;
			headB = headB->next;
		}
		return NULL;
	}
};