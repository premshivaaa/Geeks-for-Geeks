// User function Template for C++

class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
    int n, m;
    
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& vec,int in_row, int in_col){
        vis[row][col] = 1;
        vec.push_back({row - in_row, col - in_col});
        
        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, vec, in_row, in_col);
            }
            
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> store;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    store.insert(vec);
                }
            }
        }
        
        return store.size();
    }
};
