//https://leetcode.com/problems/permutation-in-string/
/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"
    Sliding window, expand + count down char, contract + count up char
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool checkInclusion(string pat, string txt) {

  unordered_map <char, int> m;
  for(auto i: pat)
  m[i]++;

  int k = pat.size();
  int count = m.size();

  int i = 0, j = 0;

  while(j < txt.size()) {

  if(m.find(txt[j]) != m.end()) {
  m[txt[j]]--;

  if(m[txt[j]] == 0)
  count--;
  }

  if(j - i + 1 < k) j++;

  else if(j - i + 1 == k) {
  if(count == 0)
 return true;

  if(m.find(txt[i]) != m.end()) {
  m[txt[i]]++;

  if(m[txt[i]] == 1)
  count++;
  }

  i++; j++;
  }
  }

 return false;

    }
};
