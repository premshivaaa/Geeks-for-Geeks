class Solution {
  private:
    int rec(int n, vector<int>& height, vector<int>& dp){
        dp[0] = 0;
        dp[1] = abs(height[0] - height[1]);
        
        for(int i=2; i<=n; i++){
            int oneJump = dp[i-1] + abs(height[i] - height[i-1]);
            int twoJump = dp[i-2] + abs(height[i] - height[i-2]);

            dp[i] = min(oneJump, twoJump);
        }
        
        return dp[n];
    }

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, 0);
        return rec(n-1, height, dp);
    }
};