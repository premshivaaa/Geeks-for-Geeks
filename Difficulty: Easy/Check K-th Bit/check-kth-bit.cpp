class Solution {
  public:
    bool checkKthBit(int n, int k) {
        
        int flag = (1<<k);
        
        if( (n&flag) == 0){
            return 0;
        }
        
        return 1;
    }
};