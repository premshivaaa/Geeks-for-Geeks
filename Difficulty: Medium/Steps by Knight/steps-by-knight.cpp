class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));
        grid[knightPos[0]][knightPos[1]] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {knightPos[0], knightPos[1]}});
        
        int delrow[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
        int delcol[8] = {1, 2, -1, -2, -2, -1, 2, 1};
        
        while(!q.empty()){
            int wt = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            if(row == targetPos[0] && col == targetPos[1]) return wt;
            
            if(wt > grid[row][col]) continue;
            
            for(int i=0; i<8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>0 && nrow<=n && ncol>0 && ncol<=n && grid[nrow][ncol] > wt+1){
                    grid[nrow][ncol] = wt+1;
                    q.push({wt+1, {nrow, ncol}});
                }
            }
        }
        
        return -1;
    }
};