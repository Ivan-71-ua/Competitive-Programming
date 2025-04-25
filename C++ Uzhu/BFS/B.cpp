#include <bits/stdc++.h>
#define int long long

const int SIZE = 8; 

int mincountstep; 
std::vector<int> scan_date(SIZE); 
std::vector<int> way_to_loc(SIZE, -1); 

bool good_pos(int row) {
	if (way_to_loc[row] < 0) return false; 
	for (int i = 0; i < SIZE; i++) {
		if (i == row) continue;
		if (way_to_loc[i] < 0) continue; 
		if (way_to_loc[row] == way_to_loc[i]) return false; 
		if ((row + way_to_loc[row]) == (i + way_to_loc[i])) return false; 
		if ((row - way_to_loc[row]) == (i - way_to_loc[i])) return false; 
	}
	return true;
}

void count_min_step() {
	int cur_count = 0;
	for (int i = 0; i < SIZE; i++) {
		if (scan_date[i] != way_to_loc[i]) cur_count++;
	}
	if (mincountstep > cur_count) mincountstep = cur_count;
}

void locate_fer(int i) {
	if (i >= SIZE) return;
	for (int j = 0; j < SIZE; j++) {
		way_to_loc[i] = j;
		if (good_pos(i)) {
				if (i == SIZE - 1) {   
					count_min_step();
				} else {
					locate_fer(i + 1);
				}
		}
		way_to_loc[i] = -1;
	}
}

int32_t main() {
	int test; 
	std::cin >> test;
	for (int j = 0; j < test; j++) {
		mincountstep = SIZE + 1;
		std::fill(way_to_loc.begin(), way_to_loc.end(), -1);
		for (int i = 0; i < SIZE; i++) {
				std::cin >> scan_date[i];
				scan_date[i]--;
		}
		locate_fer(0);
		std::cout << mincountstep;
	}
}
