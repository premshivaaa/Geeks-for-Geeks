class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        set<pair<int, int>> st;
        st.insert({0, src});
        
        while(!st.empty()){
            auto top = *st.begin();
            int node = top.second;
            int wt = top.first;
            st.erase(top);
            
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if(edgeWeight + wt < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX) st.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = edgeWeight + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};