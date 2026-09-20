class Solution {
  private:
    bool solve(vector<int>& arr, int k, int left, int right){
        if(left > right) return false;
        int mid = left + (right - left) / 2;
        if(arr[mid] == k) return true;
        
        if(arr[mid] > k) return solve(arr, k, left, mid-1);
        else return solve(arr, k, mid+1, right);
    }
  public:
    bool binarySearch(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(arr, k, 0, n-1);
    }
};