class Solution {
  private:
    void solve(vector<int>& arr, int key, int& idx, int left, int right){
        if(left > right) return;
        int mid = left + (right - left) / 2;
        if(arr[mid] == key){
            idx = mid;
            return;
        }
        if(arr[left] <= arr[mid]){
            if(arr[left] <= key && key < arr[mid]) solve(arr, key, idx, left, mid-1);
            else solve(arr, key, idx, mid+1, right);
        }
        else{
            if(key <= arr[right] && key > arr[mid]) solve(arr, key, idx, mid+1, right);
            else solve(arr, key, idx, left, mid-1);
        }
    }
  public:
    int search(vector<int>& arr, int key) {
        int idx = -1;
        solve(arr, key, idx, 0, arr.size()-1);
        return idx;
    }
};