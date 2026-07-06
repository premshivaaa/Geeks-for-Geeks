class Solution {
  public:
    string reverseString(string& s) {
        string result = s;
        reverse(result.begin(), result.end());
        return result;
    }
};
