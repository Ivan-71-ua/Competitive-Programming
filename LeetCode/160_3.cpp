#include <bits/stdc++.h>

struct ListNode {
	int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
	int getlen(ListNode *a) {
		int l = 0;
		while (a != nullptr)
		{
			l++;
			a = a->next;
		}
		return l;
	}
	ListNode * shift(ListNode *a, int step) {
		while (step > 0)
		{
			a = a->next;
			step--;
		}
		return a;	
	}
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int L_a = getlen(headA);
		int L_b = getlen(headB);
		ListNode *a = shift(headA, std::max(0, L_a - L_b));
		ListNode *b = shift(headB, std::max(0, L_b - L_a));
		while (true)
		{
			if(a == b) {
				return a;
			}
			a = a->next;
			b = b->next;
		}
		
	}
};