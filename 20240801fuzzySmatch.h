#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <map>
#include<locale>


std::vector<std::wstring> main_fuzzySmatch() {
  std::map<std::wstring, int> chineseNumbers1 = {
   {L"一"    , 1 }, {L"二"   , 2 }, {L"三", 3}, {L"四", 4}, {L"五", 5}, {L"六", 6}, {L"七", 7}, {L"八", 8}, {L"九", 9}, {L"十", 10},
   {L"二十"  , 20}, {L"三十"  , 30}, {L"四十", 40}, {L"五十", 50}, {L"六十", 60}, {L"七十", 70}, {L"八十", 80}, {L"九十", 90},
   {L"十一"  , 11}, {L"十二"  , 12}, {L"十三", 13}, {L"十四", 14}, {L"十五", 15}, {L"十六", 16}, {L"十七", 17}, {L"十八", 18}, {L"十九", 19},
   {L"二十一", 21}, {L"二十二", 22}, {L"二十三", 23}, {L"二十四", 24}, {L"二十五", 25}, {L"二十六", 26}, {L"二十七", 27}, {L"二十八", 28}, {L"二十九", 29},
   {L"三十一", 31}, {L"三十二", 32}, {L"三十三", 33}, {L"三十四", 34}, {L"三十五", 35}, {L"三十六", 36}, {L"三十七", 37}, {L"三十八", 38}, {L"三十九", 39},
   {L"四十一", 41}, {L"四十二", 42}, {L"四十三", 43}, {L"四十四", 44}, {L"四十五", 45}, {L"四十六", 46}, {L"四十七", 47}, {L"四十八", 48}, {L"四十九", 49},
   {L"五十一", 51}, {L"五十二", 52}, {L"五十三", 53}, {L"五十四", 54}, {L"五十五", 55}, {L"五十六", 56}, {L"五十七", 57}, {L"五十八", 58}, {L"五十九", 59},
   {L"六十一", 61}, {L"六十二", 62}, {L"六十三", 63}, {L"六十四", 64}, {L"六十五", 65}, {L"六十六", 66}, {L"六十七", 67}, {L"六十八", 68}, {L"六十九", 69},
   {L"七十一", 71}, {L"七十二", 72}, {L"七十三", 73}, {L"七十四", 74}, {L"七十五", 75}, {L"七十六", 76}, {L"七十七", 77}, {L"七十八", 78}, {L"七十九", 79},
   {L"八十一", 81}, {L"八十二", 82}, {L"八十三", 83}, {L"八十四", 84}, {L"八十五", 85}, {L"八十六", 86}, {L"八十七", 87}, {L"八十八", 88}, {L"八十九", 89},
   {L"九十一", 91}, {L"九十二", 92}, {L"九十三", 93}, {L"九十四", 94}, {L"九十五", 95}, {L"九十六", 96}, {L"九十七", 97}, {L"九十八", 98}, {L"九十九", 99},
   {L"一百", 100},
  };
  std::wstring text = L"五十六~四十七简图、7.5 12.0气层、2至70层、十二层不知道和九十九层、一百零六配筋简图";
  // 使用正则表达式匹配中文数字
  std::wregex pattern(L"[零一二三四五六七八九十百千万]+|\\d+(\\.\\d+)?|\\d+[-至~到]+\\d+(\\.\\d+)?");
  auto words_begin = std::wsregex_iterator(text.begin(), text.end(), pattern);
  auto words_end = std::wsregex_iterator();
  std::vector<std::wstring> _vecDigtal;
  for (std::wsregex_iterator i = words_begin; i != words_end; ++i)
  {
    std::wsmatch match = *i;
    std::wstring match_str = match.str();

    // 打印所有匹配的字符串
    if (std::regex_search(match_str, std::wregex(L"\\d+")))
    {
      _vecDigtal.emplace_back(match_str);
    }
    if (std::regex_search(match_str, std::wregex(L"[零一二三四五六七八九十百千万]+")))
    {
      _vecDigtal.emplace_back(match_str);
    }
  }
  return _vecDigtal;
}

