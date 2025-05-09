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
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode res(0);
		ListNode *ans = &res;
		while(true){
			if(list1 == nullptr && list2 == nullptr) {
				return res.next;
			}
			else if(list1 == nullptr) {
				ans->next = list2;
				return res.next;
			} else if(list2 == nullptr){
				ans->next = list1;
				return res.next;
			} else if(list1->val > list2->val) {
				ans->next = list2;
				list2 = list2->next;
				ans = ans->next;
				/*
				ans->next = list2;
				ans = list2;
				list2 = list2->next;
				*/
			} else {
				ans->next = list1;
				list1 = list1->next;
				ans = ans->next;
			}
		}
		return res.next;
	}
};