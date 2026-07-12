class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
  private:
    void recursion(int idx, vector<int>& arr){
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(arr[idx]);
        recursion(idx+1, arr);
        curr.pop_back();
        
        recursion(idx+1, arr);
    }
  public:
    vector<vector<int>> subsets(vector<int>& arr) {
        n = arr.size();
        recursion(0, arr);
        
        return ans;
    }
};