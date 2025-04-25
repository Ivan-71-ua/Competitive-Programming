#include <bits/stdc++.h>




class Solution {
	#define ll long long
	ll k_palindromes = 0;
	std::unordered_set<ll> done;
	std::vector<ll> fact;

	void precomputeFactorial(int& n){
		fact[0] = 1;
		fact[1] = 1;
		for(ll i = 2;i <= 10; i++)
			fact[i] = i*fact[i-1];
	}
	ll countAllPermutations(std::vector<ll> &freq,int n){
		ll count = fact[n];
		for(int i = 0;i <= 9; i++)
			count /= fact[freq[i]];
		return count;
	}
	ll allArrangements(std::string number,int &n){
		std::sort(number.begin(),number.end());
		if(done.count(std::stoll(number)))
			return 0;
		
		done.insert(stoll(number));
		std::vector<ll> freq(10);
		for(char& c: number)
			freq[c - '0']++;
		
		ll total_permutations = countAllPermutations(freq, n);
		ll invalid_permutations = 0;
		if(freq[0] > 0){
			freq[0]--;
			invalid_permutations = countAllPermutations(freq, n - 1);
		}
		return  total_permutations - invalid_permutations;
	}

	bool isKPalindrome(std::string &number, int &n, int &k){
		return (stoll(number) % k == 0);
	}
	void generatePalindromes(int pos, int &n,std::string& number, int &k){
		if(pos >= (n + 1) / 2){
			if(isKPalindrome(number, n, k))
				k_palindromes += allArrangements(number, n);
			return;
		}

		char start = pos == 0 ? '1' : '0';
		while(start <= '9'){
			number[pos] = start;
			number[n - pos - 1] = start;
			generatePalindromes(pos + 1, n, number, k);
			start++;
		}
		number[pos] = ' ';
	}
	public:
	long long countGoodIntegers(int n, int k) {
		fact = std::vector<ll>(11);
		precomputeFactorial(n);
		std::string number(n, ' ');
		generatePalindromes(0, n, number, k);
		return k_palindromes;
	}
};