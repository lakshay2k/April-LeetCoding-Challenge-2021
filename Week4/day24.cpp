class Solution {
public:
    
    //creating adjacent list as global
    unordered_map<int, vector<int>> adj;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) { 
        
        //creating an adjacent matrix to store the adjcacent vertices which helps in dfs for every node
        for(int i = 0; i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        //making vector to store critical connections
        vector<vector<int>> c_c;
        
        //function to find the critical points
        find_cc(n, c_c);
        
        return c_c;
    }
    
    void find_cc(int vertices, vector<vector<int>>& c_c)
    {

        //creating three vectors to track while traversing
        vector<int> disc(vertices,-1), low(vertices,-1), parent(vertices,-1);
        
        for(int i=0;i<vertices;i++)
        {
            if(disc[i] == -1)
                dfs(i,disc,low,parent,c_c);
        }

    }
    
    void dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& c_c)
    {
        
        static int time = 0; //creating a timestamp
        
        //initially while traversig disc and low will equal for every node and while returning we will change it
        disc[u] = low[u] = time;
        time +=1;
        
        //as per dfs we will traverse every adjacent for every particular node
        for(int v: adj[u])
        {
            if(disc[v] == -1)
            {
                parent[v] = u;
                
                //perform dfs for every node
                dfs(v,disc,low,parent,c_c);
                low[u] = min(low[u],low[v]);
                
                //while returninng from recursion if it finds that jump is from high to low then that edge is CC
                if(low[v] > disc[u])
                    c_c.push_back(vector<int>({u,v}));
            }
            //check for the back edge
            else if(v != parent[u])
                low[u] = min(low[u],disc[v]);
            
            //dry run the code above for better explanation
        }
    }
    
};