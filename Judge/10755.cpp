#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <cstdint>






long long kadane(const std::vector<long long>& arr) {
	long long max_sum = LLONG_MIN;
	long long cur_sum = 0;
	
	for (long long val : arr) {
		cur_sum += val;
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
		}
		if (cur_sum < 0) {
			cur_sum = 0;
		}
	}
	
	return max_sum;
}

long long maxParallelepipedSum(int A, int B, int C, const  std::vector< std::vector< std::vector<long long>>>& garbage) {
	long long max_sum = LLONG_MIN;

	for (int startA = 0; startA < A; startA++) {
		std::vector< std::vector<long long>> sum2D(B,  std::vector<long long>(C, 0));

		for (int endA = startA; endA < A; endA++) {

			for (int b = 0; b < B; b++) {
				for (int c = 0; c < C; c++) {
					sum2D[b][c] += garbage[endA][b][c];
				}
			}

			for (int startB = 0; startB < B; startB++) {
					std::vector<long long> temp(C, 0);

					for (int endB = startB; endB < B; endB++) {
						for (int c = 0; c < C; ++c) {
							temp[c] += sum2D[endB][c];
						}

						long long current_max_sum = kadane(temp);
						if (current_max_sum > max_sum) {
							max_sum = current_max_sum;
						}
					}
			}
		}
	}

	return max_sum;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int A, B, C;
		std::cin >> A >> B >> C;
		std::vector< std::vector< std::vector<long long>>> garbage(A,  std::vector< std::vector<long long>>(B,  std::vector<long long>(C)));
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
					for (int c = 0; c < C; c++) {
						std::cin >> garbage[a][b][c];
					}
			}
		}
		long long result = maxParallelepipedSum(A, B, C, garbage);
		std::cout << result <<  std::endl;
		if (t > 0) {
			std::cout <<  std::endl;
		}
	}
	return 0;
}
