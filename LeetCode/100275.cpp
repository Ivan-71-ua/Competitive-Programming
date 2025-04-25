#include <bits/stdc++.h>

class Solution {
	void computeLPSArray(std::string pat, int M, int lps[])
	{
		int len = 0;
		int i = 1;
		lps[0] = 0;
		while (i < M) {
			if (pat[i] == pat[len]) {
					len++;
					lps[i] = len;
					i++;
			}
			else 
			{
					if (len != 0) {
						len = lps[len - 1];
					}
					else 
					{
						lps[i] = len;
						i++;
					}
			}
		}
	}

	int KMPSearch(std::string pat, std::string txt)
	{
		int M = pat.length();
		int N = txt.length();
		int lps[M];
		int j = 0; 
		computeLPSArray(pat, M, lps);
		int i = 0;
		int res = 0;
		int next_i = 0;
		while (i < N) {
			if (pat[j] == txt[i]) {
					j++;
					i++;
			}
			if (j == M) {
					j = lps[j - 1];
					res++;
			}
			else if (i < N && pat[j] != txt[i]) {
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
		return res;
	}
public:
	int minimumOperationsToMakeKPeriodic(std::string word, int k) {
		std::unordered_map<std::string, int> sub;
		for (int i = 0; i < word.size(); i += k) {
			sub[word.substr(i, std::min(k, (int)(word.size()) - i))]++;
		}
		
		int max_count = 0;
		for (auto &entry : sub) {
			max_count = std::max(max_count, entry.second);
		}
		
		return (word.size() / k) - max_count;
	}
};