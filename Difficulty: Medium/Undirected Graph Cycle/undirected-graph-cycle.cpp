class Solution {
    
  private:
    bool traversal(int src, vector<vector<int>>& adjList, int vis[]){
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adjList[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                } else if(parent != it) {
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int vis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(traversal(i, adjList, vis)) return true;
            }
        }
        
        return false;
    }
};