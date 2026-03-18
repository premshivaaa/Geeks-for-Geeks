class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        queue<int> q;
        
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};