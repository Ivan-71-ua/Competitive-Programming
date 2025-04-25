#include <bits/stdc++.h>




struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(const std::vector<int>& arr) {
	if (arr.empty()) return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* current = head;
	for (size_t i = 1; i < arr.size(); ++i) {
		current->next = new ListNode(arr[i]);
		current = current->next;
	}
	return head;
}

class Solution {
public:
	std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		std::vector<std::vector<int>> ans(m, std::vector<int>(n, -1));
		std::map<char, char> map{
			{'R', 'D'},
			{'D', 'L'},
			{'L', 'U'},
			{'U', 'R'}
		};
		char way = 'R';
		int i = 0, j = 0;
		ans[0][0] = head->val;
		head = head->next;
		while(head != nullptr) {
			if(way == 'R') {
				while(j + 1 < n && head != nullptr && ans[i][j + 1] == -1) {
					ans[i][j + 1] = head->val;
					head = head->next;
					j++;
				}
				way = map[way];
			} else if(way == 'D') {
				while(i + 1 < m && head != nullptr && ans[i + 1][j] == -1) {
					ans[i + 1][j] = head->val;
					head = head->next;
					i++;
				}
				way = map[way];
			} else if(way == 'L') {
				while(j - 1 > -1 && head != nullptr && ans[i][j - 1] == -1) {
					ans[i][j - 1] = head->val;
					head = head->next;
					j--;
				}
				way = map[way];
			} else if(way == 'U') {
				while(i  - 1 > -1 && head != nullptr && ans[i - 1][j] == -1) {
					ans[i - 1][j] = head->val;
					head = head->next;
					i--;
				}
				way = map[way];
			}
		}
		return ans;
	}
};

int main() {
	std::vector<int> values = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
	ListNode* list = createLinkedList(values);
	Solution ans;
	ans.spiralMatrix(3, 5, list);
}