class Solution {
 public:
  string toGoatLatin(string sentence) {
    string result;
    int    n     = sentence.size();
    int    count = 0;
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        result += ' ';
      }
      int j = isVowel(sentence[i]) ? i : i + 1;
      for (; j < n && sentence[j] != ' '; j++) {
        result += sentence[j];
      }
      if (!isVowel(sentence[i])) {
        result += sentence[i];
      }
      result += "maa";
      for (int c = 0; c < count; c++) {
        result += 'a';
      }
      i = j;
      count++;
    }
    return result;
  }
  bool isVowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U': return true;
      default: return false;
    }
  }
};