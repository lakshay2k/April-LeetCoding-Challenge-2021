class Solution {
public:

    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        //creating set to remove duplicates 
        set<int> res;
        
        //incrementing bounds by x to have all combinations which are less than bound
        for(int i=1;i<bound;i=i*x)
        {
            for(int j=1;j<bound;j=j*y)
            {
                int temp = i + j;;
                if( temp <= bound)
                    res.insert(temp);
                //if the number is 1 then it does not matter, its power will always be 1
                if(y == 1)
                    break;
            }

            //if the number is 1 then it does not matter, its power will always be 1
            if(x==1)
                break;
        }
        
        //converting set into vector and returning
        vector<int> myres(res.begin(),res.end());
        return myres;
    }
};
