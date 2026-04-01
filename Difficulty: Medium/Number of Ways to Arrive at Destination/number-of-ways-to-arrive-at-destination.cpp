class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> distances(V, INT_MAX);
        distances[0] = 0;
        vector<int> ways(V, 0);
        ways[0] = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(dist > distances[node]) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeTime = it.second;
                if(edgeTime + dist < distances[adjNode]){
                    distances[adjNode] = edgeTime + dist;
                    ways[adjNode] = ways[node];
                    pq.push({distances[adjNode], adjNode});
                } else if (edgeTime + dist == distances[adjNode]){
                    ways[adjNode] += ways[node];
                }
            }
        }
        
        return ways[V-1];
        
    }
};