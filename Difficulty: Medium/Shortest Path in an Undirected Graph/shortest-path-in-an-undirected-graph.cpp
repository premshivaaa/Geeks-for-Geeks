class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        vector<int> parent(n+1, -1);
        parent[1] = 1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(wt > dist[node]) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                
                if(wt + edgeW < dist[adjNode]){
                    dist[adjNode] = wt + edgeW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node; 
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        while(node != parent[node]){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        
        return path;
    }
};