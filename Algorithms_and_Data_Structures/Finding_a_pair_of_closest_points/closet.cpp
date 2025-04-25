#include <bits/stdc++.h>

struct Point {
	int x, y, id;
};

// Comparison of points by x-coordinate (with additional check for y-coordinate for stable sorting)
bool cmp_x(const Point &a, const Point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Comparison of points by y-coordinate
bool cmp_y(const Point &a, const Point &b) {
	return a.y < b.y;
}

double min_dist = std::numeric_limits<double>::infinity();
int ansa, ansb;

void update_answer(const Point &a, const Point &b) {
	double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	if (dist < min_dist) {
		min_dist = dist;
		ansa = a.id;
		ansb = b.id;
	}
}

void recursive_find(std::vector<Point> &points, int left, int right, std::vector<Point> &temp) {
	if (right - left <= 3) {
		// Base case: if the number of points is small, use the trivial algorithm
		for (int i = left; i <= right; i++) {
			for (int j = i + 1; j <= right; j++) {
				update_answer(points[i], points[j]);
			}
		}
		std::sort(points.begin() + left, points.begin() + right + 1, cmp_y);
		return;
	}

	int mid = (left + right) / 2;
	int mid_x = points[mid].x;

	// Recursively call the function for both halves
	recursive_find(points, left, mid, temp);
	recursive_find(points, mid + 1, right, temp);

	// Merge the two subsets, sorting them by y-coordinate
	std::merge(points.begin() + left, points.begin() + mid + 1, points.begin() + mid + 1, points.begin() + right + 1, temp.begin(), cmp_y);
	std::copy(temp.begin(), temp.begin() + (right - left + 1), points.begin() + left);

	// Collect points that are close to the dividing line
	int tsz = 0;
	for (int i = left; i <= right; i++) {
		if (std::abs(points[i].x - mid_x) < min_dist) {
			for (int j = tsz - 1; j >= 0 && points[i].y - temp[j].y < min_dist; j--) {
				update_answer(points[i], temp[j]);
			}
			temp[tsz++] = points[i];
		}
	}
}

// Trivial algorithm O(n^2)
void trivial_find(const std::vector<Point> &points) {
	double local_min_dist = std::numeric_limits<double>::infinity();
	int local_ansa = -1, local_ansb = -1;
	int n = points.size();

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y));
			if (dist < local_min_dist) {
				local_min_dist = dist;
				local_ansa = points[i].id;
				local_ansb = points[j].id;
			}
		}
	}

	std::cout << "Trivial algorithm:\n";
	std::cout << "Closest points: " << local_ansa << " and " << local_ansb << std::endl;
	std::cout << "Minimum distance: " << local_min_dist << std::endl;
}

int main() {
	int n;
	std::cin >> n;

	std::vector<Point> points(n);
	for (int i = 0; i < n; i++) {
		std::cin >> points[i].x >> points[i].y;
		points[i].id = i;
	}

	// Call the trivial algorithm
	trivial_find(points);

	// Sort points by x-coordinate
	std::sort(points.begin(), points.end(), cmp_x);

	// Call the efficient divide-and-conquer algorithm
	std::vector<Point> temp(n);
	min_dist = std::numeric_limits<double>::infinity(); // Reset the minimum distance for the recursive algorithm
	recursive_find(points, 0, n - 1, temp);

	// Output the result of the efficient algorithm
	std::cout << "Efficient algorithm:\n";
	std::cout << "Closest points: " << ansa << " and " << ansb << std::endl;
	std::cout << "Minimum distance: " << min_dist << std::endl;

	return 0;
}
