#include <bits/stdc++.h>


struct ListNode {
	int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
	void Revers(ListNode *st, ListNode *&ans) {
		if(st == nullptr)
			return;
		Revers(st->next, ans);
		ListNode *tmp = new ListNode(st->val);
		/*
		Проблема у вашому коді полягає у тому, що ви неправильно переміщуєте вказівник ans. 
		У функції Revers ви спочатку встановлюєте ans на новий вузол, а потім переставляєте 
		його на наступний елемент. Це призводить до того, що ans завжди вказує на наступний 
		елемент після поточного, але не оновлюється на кінець списку.
		ans = tmp;
		*/
		ans->next = tmp;
		ans = ans->next;
	}
public:
   ListNode* reverseList(ListNode* head) {
		ListNode *node = new ListNode();
		ListNode *cur = node;
		Revers(head, cur);
		return node->next;
	}
};