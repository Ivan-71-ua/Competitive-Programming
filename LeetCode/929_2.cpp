#include <bits/stdc++.h>

class Solution {
public:
   int numUniqueEmails(std::vector<std::string>& emails) {
      std::set<std::string> unique_emails;
      for(std::string email: emails) {
         std::string local_name = email.substr(0, email.find('@'));
         local_name = local_name.substr(0, email.find('+'));
         local_name = std::regex_replace(local_name, std::regex("\\."), "");
         std::string domain_name = email.substr(email.find('@') + 1, email.length());
         email = local_name + '@' + domain_name;
         unique_emails.insert(email);
      }
      return unique_emails.size();
   }
};
