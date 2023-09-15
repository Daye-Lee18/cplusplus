/*
input: s string 
output: a string where the words are reversed in order 

ex) 
Input: s = "the sky is blue"
Output: "blue is sky the"

ex) 
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());        // Reverse the whole string
    reverseWords(s, s.length());        // Reverse each word
    return cleanSpaces(s, s.length());  // Clean up spaces
  }

 private:
  void reverseWords(string& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')  // Skip spaces
        ++i;
      while (j < i || j < n && s[j] != ' ')  // Skip non spaces
        ++j;
      reverse(s.begin() + i, s.begin() + j);  // Reverse the word
    }
  }

  // Trim leading, trailing, and middle spaces
  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      while (j < n && s[j] != ' ')  // Keep non spaces
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      if (j < n)  // Keep only one space
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};
