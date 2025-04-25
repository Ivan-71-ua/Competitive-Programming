#include <iostream>
#include <set>
using namespace std;

// Структура для зберігання відрізків
struct Segment {
	int length;  // Довжина сегмента
	int start;   // Початок сегмента
	int end;     // Кінець сегмента
	
	// Оператор порівняння для зберігання сегментів у множині
	bool operator<(const Segment &other) const {
		if (length != other.length)
			return length > other.length;  // Спочатку порівнюємо за довжиною (більший сегмент перший)
		return start < other.start;        // Якщо довжина однакова, то за початком (менший індекс перший)
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;

	set<Segment> segments;  // Множина для вільних сегментів
	set<int> occupied;      // Множина для зайнятих місць
	int patient_position[100005] = {0};  // Для збереження позицій пацієнтів (по індексу журналу)

	// Спочатку вся палата є одним великим вільним відрізком
	segments.insert({N, 1, N});

	for (int i = 1; i <= Q; ++i) {
		int query;
		cin >> query;

		if (query == 0) {
			// Надходження пацієнта
			auto it = segments.begin();
			Segment largest = *it;
			segments.erase(it);

			int new_pos;
			if (largest.start == 1) {
					new_pos = largest.start;  // Якщо це крайній сегмент
			} else if (largest.end == N) {
					new_pos = largest.end;  // Якщо крайній з іншого боку
			} else {
					new_pos = (largest.start + largest.end) / 2;  // Вибираємо середину сегмента
			}

			cout << new_pos << endl;  // Виводимо місце для нового пацієнта
			occupied.insert(new_pos);  // Додаємо це місце в зайняті
			patient_position[i] = new_pos;  // Записуємо місце в журнал пацієнтів

			// Оновлюємо вільні сегменти (розбиваємо поточний сегмент на два нові)
			if (new_pos - 1 >= largest.start) {
					segments.insert({new_pos - largest.start, largest.start, new_pos - 1});
			}
			if (new_pos + 1 <= largest.end) {
					segments.insert({largest.end - new_pos, new_pos + 1, largest.end});
			}

		} else {
			// Виписування пацієнта
			int x;
			cin >> x;
			int pos = patient_position[x];  // Знаходимо місце пацієнта
			occupied.erase(pos);  // Видаляємо це місце з зайнятих
			patient_position[x] = 0;

			// Оновлюємо вільні сегменти (з'єднуємо сусідні сегменти)
			int left = pos, right = pos;
			auto it = occupied.lower_bound(pos);
			if (it != occupied.end()) {
					right = *it - 1;
			} else {
					right = N;
			}
			if (it != occupied.begin()) {
					it--;
					left = *it + 1;
			} else {
					left = 1;
			}

			segments.insert({right - left + 1, left, right});  // Додаємо новий об'єднаний сегмент
		}
	}

	return 0;
}
