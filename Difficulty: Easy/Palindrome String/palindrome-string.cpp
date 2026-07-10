class Solution {
    bool flag = true;
  private:
    void check(string &s, int left, int right){
       if(left >= right) return;
       if(s[left] != s[right]){
           flag = false;
       }
       check(s, left+1, right-1);
    }
  public:
    bool isPalindrome(string& s) {
        int n = s.size();
        check(s, 0, n-1);
        
        return flag;
    }
};