class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        queue<pair<int, int>> q;
        q.push({src, 0});
        vis[src] = 1;
        bool flag = false;
        
        while(!q.empty()){
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            
            if(node == dest){
                return wt;
            }
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, wt+1});
                }
            }
        }
        
        if(flag == false) return -1;
    }
};
