class Solution {
  private:
    void traverse(int l, int r, vector<int>& arr){
        if(l>=r) return;
        
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        
        traverse(l+1, r-1, arr);
    }
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        traverse(0, n-1, arr);
    }
};