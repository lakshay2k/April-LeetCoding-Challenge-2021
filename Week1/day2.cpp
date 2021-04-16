class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        //creating a 2d vector of nxm
        vector<vector<int> > subresults(n+1, vector<int>(m+1, 0));
        int n_ones,n_zeroes;
        
        //taking one str element one by one
        for (auto str : strs)
        {
            
            //counting number of zeroes and ones in each string element
            n_ones = count(str.begin(),str.end(),'1');
            n_zeroes = count(str.begin(),str.end(),'0');
            
            //we get a decision whether to choose the string or leave it
            //we use max function to take a decision
            //when we dont want to use the string - we take subresults[i][j] i.e previous value
            //when we want to use the string - we take subresults[i-n_ones][j-n_zeroes] and add 1 to mark used.
            for(int i = n; i >= n_ones; i--)
            {
                for(int j = m; j >= n_zeroes; j--)
                {
                    subresults[i][j] = max( subresults[i][j] , subresults[i - n_ones][j - n_zeroes] + 1);
                }
            }
        }
        return subresults[n][m];
    }
};