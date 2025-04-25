int main() {
	int t;
	std::vector<int> Hrozhy(t);
	long long tp = 1;
	for (int i = 0; i < t; i++)
	{
		std::cin >> Hrozhy[i];
		tp *= Hrozhy[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cout << tp / Hrozhy[i] << ' ';
	}
}