class Solution {
public:
    void pre(Node* node, vector<int> *ans)
    {
        // as we are passing vector by address and taking it as pointer w have to use ->
        //adding the value of root or center node and moving to its children till we reach null
        ans->push_back(node->val);
        
        //node->children here means it goes throgh all the children associated with that node
        for(Node* child: node->children)
        {
            pre(child,ans);
        }
    }
    
    vector<int> preorder(Node* root)
    {    
        vector<int> ans;
        
        //we simply pass the root element in the pre function that checks the preorder and saves in ans
        if(root)
            pre(root,&ans);
        
        return ans;
    }
};