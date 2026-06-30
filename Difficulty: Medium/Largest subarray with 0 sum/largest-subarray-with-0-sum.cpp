class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int n = arr.size();
        int sum = 0;
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum) != mp.end()){
                int A = mp[sum];
                int B = i;
                maxi = max(maxi, B-A);
            }
            else{
                mp.insert({sum, i});
            }
        }
        
        return maxi;
    }
};