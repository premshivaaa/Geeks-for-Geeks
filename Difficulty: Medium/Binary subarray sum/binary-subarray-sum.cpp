class Solution {
  private:
    int function(vector<int>& arr, int target){
        if(target < 0) return 0;
        
        int left = 0, right = 0, sum = 0, count = 0;
        while(right < arr.size()){
            sum += arr[right];
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            count += (right-left+1);
            right++;
        }
        return count;
    }
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        return function(arr, target) - function(arr, target-1);
    }
};