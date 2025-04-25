#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int N, K, I, r, temp, temp1, quantityty = 0;
	cin >> N >> K;
	vector <int> vec;
	vector<int> vec_of_mining;
	vector<int> vec_of_line;
	for (int i = 0; i < K; i++) {
		cin >> I >> r;
		vec.push_back(I);
		vec.push_back(r);
	}
	for (int i = 0; i < vec.size(); i += 2) {
		for (int j = vec[i]; j <= vec[i + 1]; j++) {
			vec_of_mining.push_back(j);
		}
	}
	for (int i = 1; i <= N; i++) {
		vec_of_line.push_back(i);
	}
	for (int l = 0; l < vec_of_line.size(); l++) {
		temp = vec_of_line[l];
		for (int g = 0; g < vec_of_mining.size(); g++){
			temp1 = vec_of_mining[g];
			if (temp == temp1) {
				quantityty++;
			}
		}
		if (quantityty == 0) {
			cout << "I";
		}
		else {
			cout << ".";
		}
		quantityty = 0; 
	}
}