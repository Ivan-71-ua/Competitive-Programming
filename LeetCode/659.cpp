#include <bits/stdc++.h>

class Solution {
public:
   /*
   * @param strs: a list of strings
   * @return: encodes a list of strings to a single string.
   */
   std::string encode(std::vector<std::string> &strs) {
		std::string encode_str;
      for (int i = 0; i < strs.size(); i++)
		{
			encode_str += strs[i];
			encode_str += "#@#";
		}
		return encode_str;
	}
   /*
   * @param str: A string
   * @return: decodes a single string to a list of strings
   */
   std::vector<std::string> decode(std::string &str) {
		std::vector<std::string> ans;
		std::string stemp;
		for (int i = 0; i < str.size(); i++)
		{
			if(str[i] == '#' && str[i +1] == '@' && str[i +2] == '#') {
				i += 2;
				ans.push_back(stemp);
				stemp = "";
			}
			else {
				stemp += str[i];
			}
		}
	}
};