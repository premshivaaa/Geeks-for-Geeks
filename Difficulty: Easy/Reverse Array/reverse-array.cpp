class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int left = 0, right = arr.size()-1;
        while(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            left++;
            right--;
        }
    }
};