#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(root == nullptr)
			return true;
		std::stack<std::pair<TreeNode *, TreeNode *>, std::vector<std::pair<TreeNode *, TreeNode *>>> st;
		st.push({root->left, root->right});
		while(!st.empty()) {
			TreeNode *right;
			TreeNode *left;
			std::tie(left, right) = st.top();
			st.pop();
			if(left == nullptr && right == nullptr) {
				continue;;
			}
			if(left== nullptr || right == nullptr) {
				return false;
			}
			if(right->val != left->val) {
				return false;
			}
			st.push({left->left, right->right});
			st.push({left->right, right->left});
		}
		return true;
	}
};

/*
std::stack - це контейнер, що реалізує структуру даних стек.

<std::pair<TreeNode *, TreeNode *>> - це тип елементів, які будуть 
зберігатися у стеку. std::pair є контейнером, що містить два елементи, 
які можуть бути різних типів. У цьому випадку обидва елементи є вказівниками 
на TreeNode, що представляють вузли дерева. Пара вказівників представляє два вузли,
які потрібно порівняти на кожному кроці алгоритму.

, std::vector<std::pair<TreeNode *, TreeNode *>>> - ця частина вказує, що 
базовим контейнером для std::stack є std::vector, що зберігає елементи типу
std::pair<TreeNode *, TreeNode *>. Вказання std::vector як базового контейнера 
дозволяє стеку використовувати всі операції вектора для зберігання елементів. Це 
робиться для керування пам'яттю ефективніше, особливо коли необхідно динамічно змінювати 
розмір стеку, заснованого на векторі, що дозволяє ефективно збільшувати або зменшувати кількість елементів у стеку.
*/


/*

std::tie є функцією зі стандартної бібліотеки C++, 
яка дозволяє розпакувати елементи кортежа або пари в змінні. 
У цьому конкретному випадку, std::tie використовується для того, 
щоб одночасно присвоїти значення двох змінних left і right з верхнього
елемента стека (st.top()).
*/