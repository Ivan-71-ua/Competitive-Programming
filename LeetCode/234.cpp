#include <bits/stdc++.h>




struct ListNode {
	int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
	void way(ListNode *hd, ListNode *&cur, bool &is, int &n, int size) {
		if(hd == nullptr) {
			return;
		}
		way(hd->next, cur, is, n, size);
		if(n < size) {
			n++;
			if(hd->val != cur->val) {
				is = false;
				return;
			}
			cur = cur->next;
		}
		return;
	}
public:
   bool isPalindrome(ListNode* head) {
		ListNode *tmp = head;
		int size = 0;
		while (tmp != nullptr)
		{
			size++;
			tmp = tmp->next;
		}
		size /= 2;
		int n = 0;
		bool is = true;
		ListNode *k = head;
		way(k, head, is, n, size);
		return is;
	}
};