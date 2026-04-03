class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> vis(V, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            sum += weight;
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(!vis[adjNode]) pq.push({edgeWeight, adjNode});
            }
        }
        return sum;
    }
};