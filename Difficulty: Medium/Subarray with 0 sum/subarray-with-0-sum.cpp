class Solution {
  public:
    
    bool subArrayExists(vector<int>& arr) {
        
        unordered_set<int> st;
        st.insert(0);
        int n = arr.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(st.find(sum) != st.end()){
                return true;
            }
            else{
                st.insert(sum);
            }
        }
        
        return false;
    }
};