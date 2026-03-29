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
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > mh;
        mh.push({0, src});
        
        while(!mh.empty()){
            int node = mh.top().second;
            int wt = mh.top().first;
            mh.pop();
            
            if (wt > dist[node]) continue;
            
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if(edgeWeight + wt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWeight;
                    mh.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};