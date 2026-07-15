class Solution {
    int n;
  private:
    bool check(int idx, int sum, vector<int>& arr, int k){
        if(sum > k) return false;
        if(sum == k) return true;
        if(idx == n){
            if(sum == k) return true;
            return false;
        }
        
        sum += arr[idx];
        if(check(idx+1, sum, arr, k)) return true;
        
        sum -= arr[idx];
        if(check(idx+1, sum, arr, k)) return true;
        
        return false;
    }
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        n = arr.size();
        return check(0, 0, arr, k);
    }
};