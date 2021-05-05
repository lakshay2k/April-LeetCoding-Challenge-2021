class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
      
        //we are using the bottom-up approach and value at top i.e t[0][0] gives us the result
        //we simply choose the min from two choices for each element t[r+1][c] , t[r+1][c+1]
        //here ~row means row>=0
        
        for(int row = triangle.size()-2; ~row; row--)
        {
            for(int col = triangle[row].size()-1; ~col; col--)
            {
                triangle[row][col] += min(triangle[row+1][col],triangle[row+1][col+1]);
            }
        }
        
        //returning top most element after using bottom up approach
        return triangle[0][0];
    }
};