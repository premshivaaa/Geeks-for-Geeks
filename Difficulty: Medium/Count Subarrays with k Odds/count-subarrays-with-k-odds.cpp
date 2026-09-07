class Solution {
  private:
    int function(vector<int>& arr, int k){
        if(k < 0) return 0;
        int left = 0, right = 0, count = 0, sum = 0;
        
        while(right < arr.size()){
            sum += (arr[right] % 2);
            while(sum > k){
                sum -= (arr[left] % 2);
                left++;
            }
            count += (right-left+1);
            right++;
        }
        return count;
    }
  public:
    int countSubarrays(vector<int>& arr, int k) {
        return function(arr, k) - function(arr, k-1);
    }
};