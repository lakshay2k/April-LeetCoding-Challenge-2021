class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        
        /*
        the approach would be that first we will transpose the matrix 
        afte that we will flip the matrix row by row 
        for ex : 1 *2 #3                 1 4 7                          7 4 1 (this is our final
                 *4 5 @6  afte transpose 2 5 8  now flipping row by row 8 5 2   90 degree roataed matrix)
                 #7 @8 9                 3 6 9                          9 6 3
        */
        
        //first transposing the matrix
        
        int size = matrix.size();
        int i,j,temp;
        
        for(i = 0 ; i<size-1; i++)
        {
            //while transposing we neglect middle elements like see * in above explanation
            for(j = i; j<size; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // now we will flip row by row
        for(int row = 0;row < size; row++)
        {
            int start =0, end =size-1;
            while(start < end)
            {
                temp = matrix[row][start];
                matrix[row][start++] = matrix[row][end];
                matrix[row][end--] = temp;
            }
        }
        
    }
};