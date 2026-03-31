class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            int node = q.front().second.first;
            int cost = q.front().second.second;
            int stop = q.front().first;
            q.pop();
            
            if(stop > K) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(cost + edgeW < distance[adjNode] && stop <= K){
                    distance[adjNode] = cost + edgeW;
                    q.push({stop + 1, {adjNode, distance[adjNode]}});
                }
            }
        }
        if(distance[dst] == INT_MAX) return -1;
        
        return distance[dst];
    }
};