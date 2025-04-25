

#include <bits/stdc++.h>

double lagrange(const std::vector<std::pair<double, double>>& points, double Z) {
	double result = 0.0;
	int N = points.size();
	for (int i = 0; i < N; i++) {
		double term = points[i].second;  
		for (int j = 0; j < N; j++) {
			if (i != j) {
				term *= (Z - points[j].first) / (points[i].first - points[j].first);
			}
		}
		result += term;
	}
	return result;
}

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<double, double>> points(N);
	for (int i = 0; i < N; i++) {
		std::cin >> points[i].first >> points[i].second;  
	}

	double Z;
	std::cin >> Z;

	double result = lagrange(points, Z);

	std::cout << std::fixed << std::setprecision(2) << result << '\n';

}
