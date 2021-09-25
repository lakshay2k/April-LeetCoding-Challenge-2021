class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        //initialising priority queue for keeping the ladders on largest diff
        int n = heights.size()-1;
        priority_queue<int> mypq;
        
        for(int i=0;i<n;i++)
        {
            //calculating difference between heights
            int diff = heights[i+1] - heights[i];
            
            //we use either bricks or ladder when H[i+1] is more than Current building height
            if(diff > 0)
            {
                
                //first priority is for ladders that we give for high difference
                if(ladders)
                {
                    mypq.push(-diff);
                    ladders--;
                }
                
                //if the curr diff is more than all observed distances, we push it to PQ and decrease bricks
                else if(!mypq.empty() && diff > -mypq.top())
                {
                    mypq.push(-diff);
                    bricks = bricks - mypq.top();
                    mypq.pop();
                }
                // we use bricks then diff is less and we have no ladders left
                else
                    bricks = bricks - diff;

                //we bricks are finished then that building is the farthest building
                if(bricks < 0)
                    return i;
            }
        }
        return n;
    }
};
