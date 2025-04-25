#include <bits/stdc++.h>

class DisjointSet {
	std::vector<int> parent, size;
public:
	// Конструктор: Ініціалізує батьківський масив та розмір
	DisjointSet(int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;  // Кожен елемент є своїм власним батьком
			size[i] = 1;    // Розмір кожного дерева спочатку 1
		}
	}
	// Функція знаходження кореня з шляхом стиснення
	int findUPar(int node) {
		if (node == parent[node])
			return node; // Якщо вузол є своїм власним батьком, повертаємо його
		return parent[node] = findUPar(parent[node]); // Знаходимо корінь і оновлюємо батька для всіх вузлів на шляху
	}
	// Функція об'єднання двох множин за розміром
	void unionBySize(int u, int v) {
		int ult_u = findUPar(u); // Знаходимо корінь для u
		int ult_v = findUPar(v); // Знаходимо корінь для v
		if (ult_u == ult_v) return; // Якщо корені однакові, вони вже об'єднані
		// Об'єднуємо менше дерево до більшого
		if (ult_u < ult_v) {
			parent[ult_v] = ult_u; // Робимо ult_u батьком для ult_v
			size[ult_u] += size[ult_v]; // Збільшуємо розмір дерева ult_u
		} else {
			parent[ult_u] = ult_v; // Робимо ult_v батьком для ult_u
			size[ult_v] += size[ult_u]; // Збільшуємо розмір дерева ult_v
		}
	}
};

class Solution {
public:
	std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) {
		int n = s1.length();
		DisjointSet ds(26); // Ініціалізуємо Disjoint Set для 26 літер
		// Об'єднуємо еквівалентні символи
		for (int i = 0; i < n; ++i) {
			ds.unionBySize(s1[i] - 'a', s2[i] - 'a');
		}
		// Знаходимо найменший еквівалентний рядок
		std::string temp = "";
		for (int i = 0; i < baseStr.length(); ++i) {
			char t = ds.findUPar(baseStr[i] - 'a') + 'a'; // Знаходимо еквівалентний символ
			temp += t;
		}
		return temp; // Повертаємо результат
	}
};
