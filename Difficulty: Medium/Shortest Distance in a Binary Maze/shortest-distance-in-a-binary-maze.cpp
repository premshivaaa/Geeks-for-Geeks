// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector(m, INT_MAX));
        distance[source.first][source.second] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0, source});
        
        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dis+1 < distance[nrow][ncol] && grid[nrow][ncol] == 1 ){
                    distance[nrow][ncol] = dis + 1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        
        if(distance[destination.first][destination.second] == INT_MAX) return -1;
        
        return distance[destination.first][destination.second];
        
    }
};
