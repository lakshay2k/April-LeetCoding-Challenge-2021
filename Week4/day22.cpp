class Solution {
public:

    int leastBricks(vector<vector<int>>& wall) {
        
        //creating an unordered map to store the number of gaps and its frequency for each row
        unordered_map<int,int> mymap;
        
        //we have to return the Crossess which will be wall.size() - gaps
        int crosses = 0;
        
        //the max will have maximum no. of gaps from mymap 
        int Max = 0;
        
        for(int i = 0; i < wall.size(); i++)
        {

            int sum = 0;
            //j < wall.size()-1 to ignore the last gap at the end for all
            for(int j = 0; j < wall[i].size()-1; j++)
            {
                sum += wall[i][j];
                mymap[sum]++;
                Max = max(Max,mymap[sum]);
            }
        }
        
        //returning the crosses
        crosses = wall.size()-Max;
        return crosses;
    }
};