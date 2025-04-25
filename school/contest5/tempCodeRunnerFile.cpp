
	{
		int k;
		std::cin >> k;
		if(bals.empty()) {
			bals.push({k, 1});
			sz++;
			std::cout << sz << '\n';
		} else {
			if(bals.top().first == k) {
				bals.top().second++;
				sz++;