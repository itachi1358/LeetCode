class Solution {
public:
    int f(int i,int j,vector<vector<int>> &grid,int &health,vector<vector<int>> &dp){

        if(i>=grid.size() || j>= grid[0].size()) return 1e9;

         if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return max(1, 1 - grid[i][j]);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int right= f(i+1,j,grid,health,dp);
        int bottom=f(i,j+1,grid,health,dp);

        return dp[i][j]=max(1,min(right,bottom)-grid[i][j]);
     }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int health=INT_MAX;
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        int h=f(0,0,dungeon,health,dp);
        return h;
    }
};