#include <bits/stdc++.h>


class Solution {
public:
   std::string pushDominoes(std::string dominoes) {
		std::string &ans = dominoes;
		int prev = -1;
		for (int i = 0; i < dominoes.size(); i++)
		{
			if(dominoes[i] != '.') {
				if(prev == -1) {
					if(dominoes[i] == 'L') {
						for (int j = 0; j < i; j++)
						{
							ans[j] = 'L';
						}
					}
				} else {
					if(dominoes[prev] == 'L' && dominoes[i] == 'L') {
						for (int j = prev + 1; j < i; j++)
						{
							ans[j] = 'L';
						}
					} else if(dominoes[prev] == 'R' && dominoes[i] == 'R') {
						for (int j = prev + 1; j < i; j++)
						{
							ans[j] = 'R';
						}
					} else if(dominoes[prev] ==  'R' && dominoes[i] == 'L') {
						int whole = i - prev - 1;
						int half = whole / 2;
						for (int j = prev + 1; j <= prev + half; j++)
						{
							ans[j] = 'R';
						}
						for (int j = i - half; j <= i - 1 ; j++)
						{
							ans[j] = 'L';
						}
					} else {
						assert(dominoes[prev] == 'L' && dominoes[i] == 'R');
					}
				}
				prev = i;
			} else {
				continue;
			}
		}
		if(prev != 1 && dominoes[prev] == 'R') {
			for (int j = prev +1; j < dominoes.size(); j++)
			{
				ans[j] = 'R';
			}
		}
		return std::move(dominoes);
	}
};

int main() {
	Solution ans;
	std::string dd = ans.pushDominoes(".");
}