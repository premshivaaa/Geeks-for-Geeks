class Solution {
  private:
    int rec(int i, vector<int>& height, vector<int>& dp){
        if(i == 0) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int singleJ = rec(i-1, height, dp) + abs(height[i-1] - height[i]);
        int doubleJ = INT_MAX;
        if(i > 1){
            doubleJ = rec(i-2, height, dp) + abs(height[i-2] - height[i]);
        }
        
        return dp[i] =min(singleJ, doubleJ);
    }

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, -1);
        return rec(n-1, height, dp);
    }
};