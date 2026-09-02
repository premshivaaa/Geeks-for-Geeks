class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left=0,right=0,zeros=0,maxlen = 0;
        
        while(right < arr.size()){
            if(arr[right] == 0) zeros++;
            if(zeros > k){
                if(arr[left] == 0) zeros--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};
