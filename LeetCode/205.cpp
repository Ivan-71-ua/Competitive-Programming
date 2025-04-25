

class Solution {
public:
   bool isIsomorphic(std::string s, std::string t) {
		std::unordered_map<char, char> one_two;
		std::set<char> used;
		if(s.size() != t.size())
			return false;
		for (int i = 0; i < s.size(); i++)
		{
			if(one_two.count(s[i])) {
				if(one_two[s[i]] != t[i])
					return false;
			}
			else if(used.count(t[i]))
				return false;
			used.insert(t[i]);
			one_two[s[i]] = t[i];
		}
		return true;
	}
};

int main() {
	Solution ans;
	ans.isIsomorphic("egg", "add");
}