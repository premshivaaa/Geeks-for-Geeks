class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int vis[n][m];
        queue<pair<pair<int,int> , int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({ {i,j}, 0 });
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        int delrow[4] = {1, -1, 0, 0};
        int delcol[4] = {0, 0, 1, -1};
        int time = 0;
        while(!q.empty()){
            
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm  = q.front().second;
            time = max(time, tm);
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && vis[nrow][ncol] != 2 && mat[nrow][ncol] == 1){
                        q.push({{nrow, ncol} , tm + 1});
                        vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && mat[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return time;
    }
};