#include <bits/stdc++.h>

int main()
{
	int n;
	while (std::cin >> n)
	{
		int i = 2, k;
		while(i<=n)
		{
		k=0;
		while(n%i==0)
		{
		k++;
		n=n/i;
		} 
		if(i<n)
		{
			if (k==1) std::cout<<i<<"*"; 
			else if (k>1)std::cout<<i<<"^"<<k<<"*";
		}
		else
		{
			if (k==1) std::cout<<i;
			else if (k>1) std::cout<<i<<"^"<<k;
		}
		i++;
		}
		std::cout<<std::endl;
	}
}