class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int zeros = 0, ones = 0;
        for(int x : arr){
            if(x == 0) zeros++;
            else ones++;
        }
        int i=0;
        while(zeros--){
            arr[i] = 0;
            i++;
        }
        while(ones--){
            arr[i] = 1;
            i++;
        }
    }
};