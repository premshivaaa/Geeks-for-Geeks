class Solution {
  private:
    bool func(int n, long long val){
        if(val == n) return true;
        if(val > n) return false;
        
        return func(n, val*4);
    }
  public:
    bool isPowerOfFour(int n){
        if(n <= 0) return false;
        return func(n, 1);
    }    
};