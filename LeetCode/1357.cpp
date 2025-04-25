#include <bits/stdc++.h>


class Cashier {
	int cnt = 0;
	int freq;
	int disct;
	std::unordered_map<int, int> prd_prise;
public:
	Cashier(int n, int discount, std::vector<int>& products, std::vector<int>& prices) {
		freq = n;
		disct = discount;
		for (int i = 0; i < products.size(); i++)
		{
			prd_prise[products[i]] = prices[i];
		}
	}
	double getBill(std::vector<int> product, std::vector<int> amount) {
		cnt++;
		double res = 0;
		for (int i = 0; i < product.size(); i++)
		{
			res += prd_prise[product[i]] * amount[i];
		}
		if(cnt % freq == 0) {
			res *= ((100.0 - disct) / 100.0);
		}
		return res;
	}
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */


