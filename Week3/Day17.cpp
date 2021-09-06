class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0)
            return 0;

        //extracting the no. of rows and cols
        int rows = matrix[0].size();
        int cols = matrix.size();
        int ans = 0;
        
        //map is used to store the combinations when we move down from cols and increment rows and checking different pairs.
        //it stores the sum encountered and frequency.
        unordered_map<int,int> res;
        
        for(int col = 1;col<cols;col++)
        {
            //we generate the prefic sums here acc to rows
            /* target = 4
            for ex: 1 1 1 1   1 2 3 4
                    1 1 1 1   1 2 3 4 
                    1 1 1 1   1 2 3 4
                    1 1 1 1   1 2 3 4
            */

            for(int row = 0;row<rows;row++)
                matrix[row][col]+= matrix[col][row-1];
        }
        
        for(int startcol = 0;startcol < rows;startcol++)
        {
            for(int currcol = startcol;currcol<rows;currcol++)
            {
                res.clear();
                res[0] = 1;
                int colsum=0;
                for(int r=0;r<cols;r++)
                {
                    colsum += matrix[r][currcol] - (startcol ? matrix[r][startcol-1] : 0);

                    //ans gets increamented by 1 only when sum till that row becomes equal to target
                    //dry run for above example
                    ans += res.find(colsum - target)!=res.end() ? res[colsum-target]:0;
                    res[colsum]++;
                }
            }
        }
        
        //return ans that has count of number of combinations
        return ans;
    }
};
