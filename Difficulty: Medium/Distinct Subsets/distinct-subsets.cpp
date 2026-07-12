class Solution {
    vector<int> curr;
    vector<vector<int>> ans;
  private:
    void recursion(int idx, vector<int>& arr){
        if(idx == arr.size()){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(arr[idx]);
        recursion(idx+1, arr);
        curr.pop_back();
        
        while(idx+1 < arr.size() && arr[idx] == arr[idx+1]) idx++;
        
        recursion(idx+1, arr);
    }
  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        recursion(0, arr);
        
        return ans;
    }
};