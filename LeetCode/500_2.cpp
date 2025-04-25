#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> findWords(std::vector<std::string>& words) {
	std::string s1="qwertyuiop";
	std::string s2="asdfghjkl";
	std::string s3="zxcvbnm";
	std::vector<std::string>res;
	std::map<char,int>mp;
	for(auto &it:s1)mp[it]=1;
	for(auto &it:s2)mp[it]=2;
	for(auto &it:s3)mp[it]=3;
	for(auto &it:words){
			int i;
			for( i=1;i<it.size();i++){
				if(mp[tolower(it[i])]!=mp[tolower(it[i-1])]){
					break;
				}
			}
			if(i==it.size())res.push_back(it);
	}
	return res;
	}
};