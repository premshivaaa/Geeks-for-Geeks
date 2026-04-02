class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<long long> dist(V, LLONG_MAX);
        dist[src] = 0;
        
        // Relax edges V-1 times
        for(int i = 0; i < V - 1; i++){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != LLONG_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Detect negative cycle
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
                
            if(dist[u] != LLONG_MAX && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        // Convert to int safely
        vector<int> ans(V);
        for(int i = 0; i < V; i++){
            if(dist[i] == LLONG_MAX) {
                ans[i] = 1e8;  // as per problem convention
            } 
            else if(dist[i] > INT_MAX) {
                ans[i] = INT_MAX; // clamp (safety)
            } 
            else {
                ans[i] = (int)dist[i];
            }
        }
        
        return ans;
    }
};