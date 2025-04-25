#include <bits/stdc++.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	void get_num(ListNode *hd, std::string &st) {
		if(hd == nullptr)
			return;
		get_num(hd->next, st);
		st += std::to_string(hd->val);
	}
	ListNode* get_list(std::string st, int n) {
		if(n < 0) {
			return nullptr;
		}
		ListNode *res = new ListNode((int)(st[n] - '0'));
		res->next = get_list(st, n - 1);
		return res;
	}
	std::string Add(std::string s1, std::string s2) {
		std::string res;
		int cur = 0;
		int k = s1.size() - 1;
		int t = s2.size() - 1;
		while(k >= 0 || t >= 0 || cur) {
			int tmp = cur;
			if(k >= 0) {
				tmp += s1[k] - '0';
				k--;
			}
			if(t >= 0) {
				tmp += s2[t]- '0';
				t--;
			}
			cur = tmp / 10;
			res += std::to_string(tmp % 10);
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		std::string n1;
		std::string n2;
		get_num(l1, n1);
		get_num(l2, n2);
		std::string sum = Add(n1, n2);
		int sz = sum.size() - 1;
		return get_list(sum, sz);
	}
};