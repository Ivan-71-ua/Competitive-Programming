#include <bits/stdc++.h>


std::vector<int> get_number(const std::string& snum) {
	std::vector<int> vnum(snum.size());
	for (size_t i = 0; i < snum.size(); i++) {
		vnum[snum.size() - 1 - i] = snum[i] - '0';  // Store digits in reverse order
	}
	return vnum;
}

void extend_vec(std::vector<int>& v, size_t len) {
	while (len & (len - 1)) {
		len++ ;
	}
	v.resize(len);
}

std::vector<int> naive_mul(const std::vector<int>& x, const std::vector<int>& y) {
	auto len = x.size();
	std::vector<int> res(2 * len);

	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len; j++) {
			res[i + j] += x[i] * y[j];
		}
	}

	return res;
}

std::vector<int> karatsuba_mul(const std::vector<int>& x, const std::vector<int>& y) {
	auto len = x.size();
	std::vector<int> res(2 * len);

	if (len <= 4) {  // For small vectors use naive multiplication
		return naive_mul(x, y);
	}

	auto k = len / 2;

	std::vector<int> Xr(x.begin(), x.begin() + k);
	std::vector<int> Xl(x.begin() + k, x.end());
	std::vector<int> Yr(y.begin(), y.begin() + k);
	std::vector<int> Yl(y.begin() + k, y.end());

	std::vector<int> P1 = karatsuba_mul(Xl, Yl);
	std::vector<int> P2 = karatsuba_mul(Xr, Yr);

	std::vector<int> Xlr(k);
	std::vector<int> Ylr(k);

	for (size_t i = 0; i < k; i++) {
		Xlr[i] = Xl[i] + Xr[i];
		Ylr[i] = Yl[i] + Yr[i];
	}

	std::vector<int> P3 = karatsuba_mul(Xlr, Ylr);

	for (size_t i = 0; i < len; i++) {
		P3[i] -= P2[i] + P1[i];
	}

	for (size_t i = 0; i < len; i++) {
		res[i] = P2[i];
	}

	for (size_t i = len; i < 2 * len; i++) {
		res[i] = P1[i - len];
	}

	for (size_t i = k; i < len + k; i++) {
		res[i] += P3[i - k];
	}

	return res;
}

void finalize(std::vector<int>& res) {
	int carry = 0;
	for (size_t i = 0; i < res.size(); i++) {
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
	while (carry) {
		res.push_back(carry % 10);
		carry /= 10;
	}
}

std::string print_res(const std::vector<int>& v) {
	std::string result;
	auto it = v.crbegin();

	// Skip leading zeros
	while (it != v.crend() && !*it) {
		++it;
	}

	if (it == v.crend()) {
		result = "0";
	} else {
		while (it != v.crend()) {
			result += std::to_string(*it++);
		}
	}

	return result;
}

int main() {
	std::string str1, str2;
	std::cout << "Enter the first number: ";
	std::cin >> str1;
	std::cout << "Enter the second number: ";
	std::cin >> str2;

	std::vector<int> first = get_number(str1);
	std::vector<int> second = get_number(str2);

	size_t n = std::max(first.size(), second.size());

	extend_vec(first, n);
	extend_vec(second, n);

	std::vector<int> result = karatsuba_mul(first, second);
	finalize(result);

	std::string res_str = print_res(result);

	std::cout << "Multiplication result: " << res_str << std::endl;

	return 0;
}

