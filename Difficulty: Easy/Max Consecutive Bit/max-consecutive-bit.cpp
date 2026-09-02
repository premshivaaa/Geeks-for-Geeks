class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        int n = arr.size();
        int zleft = 0, zright = 0, oleft = n-1, oright = n-1, zmax = 0, omax = 0, maxlen = 0;
        
        while(zright < n){
            if(arr[zright] == 1) zleft = zright + 1;
            zmax = max(zmax, zright - zleft + 1);
            
            if(arr[oleft] == 0) oright = oleft - 1;
            omax = max(omax, oright - oleft + 1);
            
            int regmax = max(zmax, omax);
            maxlen = max(regmax, maxlen);
            zright++;
            oleft--;
        }
        return maxlen;
    }
};