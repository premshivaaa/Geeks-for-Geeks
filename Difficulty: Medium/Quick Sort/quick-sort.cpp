class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int partIdx = partition(arr, low, high);
            quickSort(arr, low, partIdx-1);
            quickSort(arr, partIdx+1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int left = low;
        int right = high;
        
        while(left < right){
            while(arr[left] <= pivot && left <= high-1) left++;
            
            while(arr[right] > pivot && right >= low+1) right--;
            
            if(left < right) swap(arr[left], arr[right]);
        }
        swap(arr[right], arr[low]);
        return right;
    }
};