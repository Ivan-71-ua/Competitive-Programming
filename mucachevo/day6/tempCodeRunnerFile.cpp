#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	if (m < 13) {
		cout << -1 << endl;
		return 0;
	}

	long long min_boxes = (n + m - 1) / m;

	while (true) {
		if (min_boxes % 13 != 0) {
			long long max_in_one_box = (n + min_boxes - 1) / min_boxes;

			if (max_in_one_box <= m && max_in_one_box % 13 != 0) {
					cout << min_boxes << endl;
					return 0;
			}
		}

		min_boxes++;

		if (min_boxes > n) {
			cout << -1 << endl;
			return 0;
		}
	}
}