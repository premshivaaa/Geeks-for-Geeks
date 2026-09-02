class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        int zero = 0, one = 0, ans = 0;

        for (int x : arr) {
            if (x == 0) {
                zero++;
                one = 0;
            } else {
                one++;
                zero = 0;
            }
            ans = max(ans, max(zero, one));
        }

        return ans;
    }
};