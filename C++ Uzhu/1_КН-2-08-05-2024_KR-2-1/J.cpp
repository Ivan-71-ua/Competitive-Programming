#include <iostream>
#include <vector>
#include <set>
#include <algorithm>  // для std::swap

using namespace std;

using Cable = pair<pair<int, int>, pair<int, int>>;

// Функция-компаратор для корректного сравнения кабелей
bool compare_cables(const Cable& a, const Cable& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

long long count_cables_on_path(const set<Cable, decltype(&compare_cables)>& cables, int x, int y) {
    int current_x = 1, current_y = 1;
    int count = 0;

    // Движение к цели (x, y)
    while (current_x < x || current_y < y) {
        if (current_y < y) {
            // Движение вправо
            Cable cable_horiz = {{current_x, current_y}, {current_x, current_y + 1}};
            if (cables.count(cable_horiz)) {
                count++;
            }
            current_y++;
        } else if (current_x < x) {
            // Движение вниз
            Cable cable_vert = {{current_x, current_y}, {current_x + 1, current_y}};
            if (cables.count(cable_vert)) {
                count++;
            }
            current_x++;
        }
    }

    return count;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    set<Cable, decltype(&compare_cables)> cables(compare_cables);

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2 || y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);  // Исправленное использование swap
        }

        cables.insert({{x1, y1}, {x2, y2}});
    }

    int q;
    cin >> q;

    vector<long long> results(q);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        results[i] = count_cables_on_path(cables, x, y);
    }

    for (auto result : results) {
        cout << result << endl;
    }

    return 0;
}
