#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;
    
    double distance(const Point& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

struct CircleSets {
    vector<double> min_x, max_x, min_y, max_y;
    vector<int> p, rank;
    int n;

    CircleSets(int n) : n(n), min_x(n), max_x(n), min_y(n), max_y(n), p(n), rank(n) {}

    int find(int i) {
        if (i == p[i]) return i;
        return p[i] = find(p[i]);
    }

    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return;

        if (rank[i] > rank[j]) swap(i, j);
        p[i] = j;
        if (rank[i] == rank[j]) rank[j]++;

        min_x[j] = min(min_x[j], min_x[i]);
        max_x[j] = max(max_x[j], max_x[i]);
        min_y[j] = min(min_y[j], min_y[i]);
        max_y[j] = max(max_y[j], max_y[i]);
    }

    bool hasPath(int x, int y) {
        for (int i = 0; i < n; ++i) {
            if (find(i) != i) continue;

            if (min_x[i] < 0 && max_x[i] > x) return false;
            if (min_y[i] < 0 && max_y[i] > y) return false;
            if (min_x[i] < 0 && min_y[i] < 0) return false;
            if (max_x[i] > x && max_y[i] > y) return false;
        }
        return true;
    }
};

bool isSafe(double radius, const vector<Point>& people, int n, int x, int y) {
    CircleSets circle_sets(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (people[i].distance(people[j]) < 2 * radius)
                circle_sets.join(i, j);
        }
    }
    return circle_sets.hasPath(x, y);
}

double maxSafeDistance(int x, int y, const vector<Point>& people) {
    double left = 0.0, right = min(x, y);
    while (right - left > EPS) {
        double mid = (left + right) / 2;
        if (isSafe(mid, people, people.size(), x, y))
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    
    vector<Point> people(n);
    for (int i = 0; i < n; ++i)
        cin >> people[i].x >> people[i].y;

    cout << maxSafeDistance(x, y, people) << endl;

    return 0;
}
