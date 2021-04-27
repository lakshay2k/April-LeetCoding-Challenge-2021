class Solution {
public:
    
    //initialising global variables
    int sum = 0;
    int depth = 0;
    
    //making the dfs recursive function
    void dfs(TreeNode* node, int level)
    {
        //if we reach last leaf node then we will stop
        if(node == NULL)
            return;
        
        //when we find new depth then we intialise the sum to zero again as we have to only take leaf nodes.
        if(depth < level)
        {
            depth = level;
            sum=0;
        }
        
        if(level == depth)
            sum = sum + node->val;
        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        //we will start with the root node which is at zero level
        dfs(root,0);
        return sum;
    }
    
};