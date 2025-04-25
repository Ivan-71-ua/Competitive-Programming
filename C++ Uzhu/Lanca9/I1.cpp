#include <bits/stdc++.h>
#define ll long long
#define db double

bool geron (db arr[]){
	std::sort(arr, arr + 4);
	if(arr[0] == arr[1] && arr[3] == arr[2]) {
		return true;
	}
	else {
		return false;
	}
}



int main() {
	db arr_v[4] {};
	for (int i = 0; i < 4; i++)
	{
		std::cin >> arr_v[i];
	}
	if(geron(arr_v)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}