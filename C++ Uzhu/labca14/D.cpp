#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

const int MAX = 50001;
std::vector<int> invers(MAX);
int n, t = 0, did;

void merge(std::vector<int>& a, int bleft, int bright, int cleft, int cright) {
	int len = bright - bleft + 1, resCur = 0, q = 0;
	std::vector<int> res(len);
	std::memcpy(&res[0], &a[bleft], len * sizeof(int));
	while ((resCur < len) && (cleft <= cright)) {
		while ((res[q] <= a[cleft] + t) && (q < len)) q++;
		if (res[resCur] <= a[cleft]) {
				a[bleft++] = res[resCur++];
		} else {
				a[bleft++] = a[cleft++];
				did += len - q;
		}
	}
	while (resCur < len) a[bleft++] = res[resCur++];
}

void mergeSort(std::vector<int>& a, int left, int right) {
	if (left >= right) return;
	int middle = (left + right) / 2;
	mergeSort(a, left, middle);
	mergeSort(a, middle + 1, right);
	merge(a, left, middle, middle + 1, right);
}

int main() {
	fast;
	std::cin >> n;
	invers.resize(n);
	for (int i = did = 0; i < n; i++)
		std::cin >> invers[i];
	mergeSort(invers, 0, n - 1);
	std::cout << did << std::endl;
	return 0;
}
