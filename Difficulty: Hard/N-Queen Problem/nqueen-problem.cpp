class Solution {
  private:
    void placeQueens(int row, int n,vector<int>& board, vector<vector<int>>& result, vector<bool>& sameCol, vector<bool>& leftUD, vector<bool>& leftLD){
        if(row == n){
            result.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(!sameCol[col] && !leftUD[n-1+row-col] && !leftLD[row+col]){
                sameCol[col] = leftUD[n-1+row-col] = leftLD[row+col] = true;
                
                board.push_back(col+1);
                placeQueens(row+1, n, board, result, sameCol, leftUD, leftLD);
                board.pop_back();
                sameCol[col] = leftUD[n-1+row-col] = leftLD[row+col] = false;
            }
        }
    }
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> board;
        
        vector<bool> sameCol(n, false);
        vector<bool> leftUD(2*n-1, false);
        vector<bool> leftLD(2*n-1, false);
        
        placeQueens(0, n, board, result, sameCol, leftUD, leftLD);
        
        return result;
    }
};