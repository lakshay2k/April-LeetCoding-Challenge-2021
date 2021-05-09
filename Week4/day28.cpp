class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //calculating number of rows and columns
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        
        //if the starting posn is obstacle then return false
        if(obstacleGrid[0][0]==1)
            return false;
        
        //creating vector to store dynamic programming intermediate results
        vector<vector<int>> dp(R,vector<int>(C,0));
        
        //first element can only be selected in one way so it is assigned as 1
        dp[0][0] = 1;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {

                //the very first starting posn and posn atr which we encounter obstacle is ignored
                //means we will not store that in dp array and hence will be zero hence will make no effect
                if(obstacleGrid[i][j] == 1 || (i==0 && j==0))
                    continue;
                //here we consider all the edge cases and then add from the left and above box
                else //                   above case              left case
                    dp[i][j]= (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0);
            }
        }
        
        // at last the bottom right element has number of ways to reach there.
        return dp[R-1][C-1];
    }
};