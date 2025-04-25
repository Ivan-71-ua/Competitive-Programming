#include <bits/stdc++.h>

std::vector<long long> repeated(31), nonrepeated(31);

long long countNotForbidden(int totalTasks) {
	repeated[1] = 0;
	repeated[2] = 3;
	nonrepeated[1] = 3;
	nonrepeated[2] = 6;
	for (int i = 3; i <= totalTasks; ++i) {
		repeated[i] = repeated[i - 1] + nonrepeated[i - 1];
		nonrepeated[i] = 2 * repeated[i - 1] + nonrepeated[i - 1];
	}

	return repeated[totalTasks] + nonrepeated[totalTasks];
}

int main() {
	int taskCount;
	while (std::cin >> taskCount) {  
		long long result = countNotForbidden(taskCount);  
		std::cout << result << std::endl;  
	}
}
