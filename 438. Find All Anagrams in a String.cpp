//https://leetcode.com/problems/find-all-anagrams-in-a-string/description/


class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
    vector<int> ans;

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
  if(count == 0){

  ans.push_back(i);
  }


  if(m.find(txt[i]) != m.end()) {
  m[txt[i]]++;

  if(m[txt[i]] == 1)
  count++;
  }

  i++; j++;
  }
  }

  return ans;
    }
};
