#include <bits/stdc++.h>

class Solution {
private:
   std::map<std::string, std::string> encodeMap;
   std::map<std::string, std::string> decodeMap;
   std::string base = "http://tinyurl.com/";
public:
   std::string encode(std::string longUrl) {
      if(!encodeMap.count(longUrl)) {
         std::string shortUrl = base + std::to_string(encodeMap.size() + 1);
         encodeMap[longUrl] = shortUrl;
         decodeMap[shortUrl] = longUrl;
      }
      return encodeMap[longUrl];
   }
    // Decodes a shortened URL to its original URL.
   std::string decode(std::string shortUrl) {
      return decodeMap[shortUrl];
   }
};
