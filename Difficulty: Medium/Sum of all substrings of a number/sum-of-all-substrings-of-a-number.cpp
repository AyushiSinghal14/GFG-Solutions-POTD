class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        int result = 0;
        int prev = 0;

        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            prev = (prev * 10 + (i + 1) * digit); 
            result += prev;
        }

        return result;
    }
}; 