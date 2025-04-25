
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
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode *start_1 = nullptr;
		ListNode *finish_1 = nullptr;
		ListNode *start_2 = list2;
		ListNode *finish_2 = nullptr;
		ListNode *point1 = list1;
		int id = 0;
		while(id <= b + 1) {
			if(id == a - 1) {
				start_1 = point1;
			}
			if(id == b  + 1) {
				finish_1 = point1;
			}
			point1 = point1->next;
			id++;
		}
		while(list2 != nullptr) {
			finish_2 = list2;
			list2 = list2->next;
		}
		start_1->next = start_2;
		finish_2->next = finish_1;
		return list1;
	}
};