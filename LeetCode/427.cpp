#include <bits/stdc++.h>

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;
	
	Node() {
		val = false;
		isLeaf = false;
		topLeft = nullptr;
		topRight = nullptr;
		bottomLeft = nullptr;
		bottomRight = nullptr;
	}
	
	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = nullptr;
		topRight = nullptr;
		bottomLeft = nullptr;
		bottomRight = nullptr;
	}
	
	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};


class Solution {
	Node* Buld_aquad(int x, int y, int x1, int y1, std::vector<std::vector<int>>& grid) {
		Node* cur = new Node();
		int val = grid[x][y];
		bool valid = true;
		for (int i = x; i < x1; i++) {
			for (int j = y; j < y1; j++) {
					if (grid[i][j] != val) {
						valid = false;
						break;
					}
			}
			if (!valid) break;
		}
		if (valid) {
			cur->isLeaf = true;
			cur->val = val;
		} else {
			cur->isLeaf = false;
			cur->val = true; 
			int midX = (x + x1) / 2;
			int midY = (y + y1) / 2;
			cur->topLeft = Buld_aquad(x, y, midX, midY, grid);
			cur->topRight = Buld_aquad(x, midY, midX, y1, grid);
			cur->bottomLeft = Buld_aquad(midX, y, x1, midY, grid);
			cur->bottomRight = Buld_aquad(midX, midY, x1, y1, grid);
		}
		return cur;
	}
public:
	Node* construct(std::vector<std::vector<int>>& grid) {
		return Buld_aquad(0, 0, grid.size(), grid.size(), grid);
	}
};
