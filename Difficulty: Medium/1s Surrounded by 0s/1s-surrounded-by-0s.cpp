class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
    int n, m;
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
  public:
    int cntOnes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]) dfs(0, j, grid, vis);
            
            if(!vis[n-1][j] && grid[n-1][j]) dfs(n-1, j, grid, vis);
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]) dfs(i, 0, grid, vis);
            
            if(!vis[i][m-1] && grid[i][m-1]) dfs(i, m-1, grid, vis);
        }
        
        int ones = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]) ones++;
            }
        }
        
        return ones;
    }
};