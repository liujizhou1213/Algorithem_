int lengthOfLongestSubstring1()
{
  std::string s = "(a)(2";
  if (s.empty()) return 0;
  std::unordered_map<char, int> charIndexMap;
  int maxLength = 0;
  int start = 0;

  for (int end = 0; end < s.size(); ++end) {
    char currentChar = s[end];

    if (charIndexMap.find(currentChar) != charIndexMap.end()) {
      // 更新起始点到重复字符之后的位置（注意可能需要取较大值来保持窗口在右边）
      start = std::max(start, charIndexMap[currentChar] + 1);
    }

    // 更新当前字符的位置
    charIndexMap[currentChar] = end;

    // 更新最大长度
    maxLength = std::max(maxLength, end - start + 1);
  }

  return maxLength;
}
//暴力查找，获取所有子段的长度
int lengthOfLongestSubstring()
{
  lengthOfLongestSubstring1();
  std::string s = "(a)(2";
  std::map<int, std::string> mapS;
  std::string strTemp; 
  std::smatch matches;
  for (int i = 0; i < s.size(); ++i)
  {
    int nFind = strTemp.find(s[i]);
    //找到该字符
    if (nFind !=-1)
    {
      mapS[strTemp.size()] = strTemp;
      strTemp = strTemp.substr(nFind + 1, strTemp.size() - 1- nFind);
      strTemp += s[i];
    }
    else
    {
      strTemp += s[i];
    }
    //std::string str;
    //str += s[i];
    //std::string regexPattern = str + R"(.*$)";
    //if (std::regex_search(strTemp, matches, std::regex(regexPattern)))
    //{
    //  mapS[strTemp.size()] = strTemp;
    //  strTemp = matches[1].str() + str;
    //}
    if (i == s.size() - 1)
    {
      mapS[strTemp.size()] = strTemp;
    }
  }
  
  return std::prev(mapS.end())->first;
}
