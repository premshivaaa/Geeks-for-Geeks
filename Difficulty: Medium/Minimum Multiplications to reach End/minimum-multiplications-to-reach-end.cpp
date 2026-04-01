// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        queue<pair<int,int>> q;
        q.push({0, start});
        vector<int> steps(100000, INT_MAX);
        steps[start] = 0;
        int array_size = arr.size();
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().second;
            int step = q.front().first;
            q.pop();
            
            if(step > steps[node]) continue; // dijkstra optm
            
            for(int i=0; i<array_size; i++){
                int val = (node * arr[i]) % mod;
                
                if(step + 1 < steps[val]){
                    steps[val] = step + 1;
                    if(val == end) return step + 1;
                    q.push({step + 1, val});
                }
            }
        }
        return -1;
    }
};
