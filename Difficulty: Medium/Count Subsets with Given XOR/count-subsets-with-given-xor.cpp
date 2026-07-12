class Solution {
    int n, count;
    
  private:
    void recursion(int idx, vector<int>& arr, int xr, int k){
        if(idx == n){
            if(xr == k) count++;
            return;
        }
        
        recursion(idx+1, arr, xr ^ arr[idx], k);
        
        recursion(idx+1, arr, xr, k);
    }
  public:
    int subsetXOR(vector<int> &arr, int k) {
        n = arr.size();
        count = 0;
        recursion(0, arr, 0, k);
        
        return count;
    }
};